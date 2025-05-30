/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__free_struct_static_65a.c
Label Definition File: CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__free.label.xml
Template File: sources-sink-65a.tmpl.c
*/
/*
 * @description
 * CWE: 590 Free of Invalid Pointer Not on the Heap
 * BadSource: static Data buffer is declared static on the stack
 * GoodSource: Allocate memory on the heap
 * Sinks:
 *    BadSink : Print then free data
 * Flow Variant: 65 Data/control flow: data passed as an argument from one function to a function in a different source file called via a function pointer
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

/* bad function declaration */
void CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__free_struct_static_65b_bad_sink(twoints * data);

void CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__free_struct_static_65_bad()
{
    twoints * data;
    /* define a function pointer */
    void (*func_ptr) (twoints *) = CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__free_struct_static_65b_bad_sink;
    data = NULL; /* Initialize data */
    {
        /* FLAW: data is allocated on the stack and deallocated in the BadSink */
        static twoints data_buf[100];
        {
            size_t i;
            for (i = 0; i < 100; i++)
            {
                data_buf[i].a = 1;
                data_buf[i].b = 1;
            }
        }
        data = data_buf;
    }
    /* use the function pointer */
    func_ptr(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__free_struct_static_65b_goodG2B_sink(twoints * data);

static void goodG2B()
{
    twoints * data;
    void (*func_ptr) (twoints *) = CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__free_struct_static_65b_goodG2B_sink;
    data = NULL; /* Initialize data */
    {
        /* FIX: data is allocated on the heap and deallocated in the BadSink */
        twoints * data_buf = (twoints *)malloc(100*sizeof(twoints));
        {
            size_t i;
            for (i = 0; i < 100; i++)
            {
                data_buf[i].a = 1;
                data_buf[i].b = 1;
            }
        }
        data = data_buf;
    }
    func_ptr(data);
}

void CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__free_struct_static_65_good()
{
    goodG2B();
}

#endif /* OMITGOOD */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__free_struct_static_65_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__free_struct_static_65_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
