/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__free_int_alloca_63a.c
Label Definition File: CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__free.label.xml
Template File: sources-sink-63a.tmpl.c
*/
/*
 * @description
 * CWE: 590 Free of Invalid Pointer Not on the Heap
 * BadSource: alloca Data buffer is allocated on the stack with alloca()
 * GoodSource: Allocate memory on the heap
 * Sinks:
 *    BadSink : Print then free data
 * Flow Variant: 63 Data flow: pointer to data passed from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

/* bad function declaration */
void CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__free_int_alloca_63b_bad_sink(int * * data_ptr);

void CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__free_int_alloca_63_bad()
{
    int * data;
    data = NULL; /* Initialize data */
    {
        /* FLAW: data is allocated on the stack and deallocated in the BadSink */
        int * data_buf = (int *)ALLOCA(100*sizeof(int));
        {
            size_t i;
            for (i = 0; i < 100; i++)
            {
                data_buf[i] = 5;
            }
        }
        data = data_buf;
    }
    CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__free_int_alloca_63b_bad_sink(&data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__free_int_alloca_63b_goodG2B_sink(int * * data);

static void goodG2B()
{
    int * data;
    data = NULL; /* Initialize data */
    {
        /* FIX: data is allocated on the heap and deallocated in the BadSink */
        int * data_buf = (int *)malloc(100*sizeof(int));
        {
            size_t i;
            for (i = 0; i < 100; i++)
            {
                data_buf[i] = 5;
            }
        }
        data = data_buf;
    }
    CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__free_int_alloca_63b_goodG2B_sink(&data);
}

void CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__free_int_alloca_63_good()
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
    CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__free_int_alloca_63_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__free_int_alloca_63_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
