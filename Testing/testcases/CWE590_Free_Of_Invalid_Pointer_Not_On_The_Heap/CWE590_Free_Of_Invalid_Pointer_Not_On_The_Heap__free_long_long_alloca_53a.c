/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__free_long_long_alloca_53a.c
Label Definition File: CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__free.label.xml
Template File: sources-sink-53a.tmpl.c
*/
/*
 * @description
 * CWE: 590 Free of Invalid Pointer Not on the Heap
 * BadSource: alloca Data buffer is allocated on the stack with alloca()
 * GoodSource: Allocate memory on the heap
 * Sink:
 *    BadSink : Print then free data
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

/* bad function declaration */
void CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__free_long_long_alloca_53b_bad_sink(long long * data);

void CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__free_long_long_alloca_53_bad()
{
    long long * data;
    data = NULL; /* Initialize data */
    {
        /* FLAW: data is allocated on the stack and deallocated in the BadSink */
        long long * data_buf = (long long *)ALLOCA(100*sizeof(long long));
        {
            size_t i;
            for (i = 0; i < 100; i++)
            {
                data_buf[i] = 5L;
            }
        }
        data = data_buf;
    }
    CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__free_long_long_alloca_53b_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declaration */
void CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__free_long_long_alloca_53b_goodG2B_sink(long long * data);

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    long long * data;
    data = NULL; /* Initialize data */
    {
        /* FIX: data is allocated on the heap and deallocated in the BadSink */
        long long * data_buf = (long long *)malloc(100*sizeof(long long));
        {
            size_t i;
            for (i = 0; i < 100; i++)
            {
                data_buf[i] = 5L;
            }
        }
        data = data_buf;
    }
    CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__free_long_long_alloca_53b_goodG2B_sink(data);
}

void CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__free_long_long_alloca_53_good()
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
    CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__free_long_long_alloca_53_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__free_long_long_alloca_53_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
