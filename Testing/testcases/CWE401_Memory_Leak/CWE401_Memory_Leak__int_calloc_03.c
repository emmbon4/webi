/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__int_calloc_03.c
Label Definition File: CWE401_Memory_Leak.c.label.xml
Template File: sources-sinks-03.tmpl.c
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource: calloc Allocate data using calloc()
 * GoodSource: Allocate data on the stack
 * Sinks:
 *    GoodSink: call free() on data
 *    BadSink : no deallocation of data
 * Flow Variant: 03 Control flow: if(5==5) and if(5!=5)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE401_Memory_Leak__int_calloc_03_bad()
{
    int * data;
    data = NULL;
    if(5==5)
    {
        /* POTENTIAL FLAW: Allocate memory on the heap */
        data = (int *)calloc(100, sizeof(int));
        /* Initialize and make use of data */
        data[0] = 5;
        printIntLine(data[0]);
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* FIX: Use memory allocated on the stack */
            int data_goodbuf[100];
            data = data_goodbuf;
            /* Initialize and make use of data */
            data[0] = 5;
            printIntLine(data[0]);
        }
    }
    if(5==5)
    {
        /* POTENTIAL FLAW: No deallocation */
        ; /* empty statement needed for some flow variants */
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Deallocate memory */
        free(data);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G1() - use badsource and goodsink by changing the second 5==5 to 5!=5 */
static void goodB2G1()
{
    int * data;
    data = NULL;
    if(5==5)
    {
        /* POTENTIAL FLAW: Allocate memory on the heap */
        data = (int *)calloc(100, sizeof(int));
        /* Initialize and make use of data */
        data[0] = 5;
        printIntLine(data[0]);
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* FIX: Use memory allocated on the stack */
            int data_goodbuf[100];
            data = data_goodbuf;
            /* Initialize and make use of data */
            data[0] = 5;
            printIntLine(data[0]);
        }
    }
    if(5!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* POTENTIAL FLAW: No deallocation */
        ; /* empty statement needed for some flow variants */
    }
    else
    {
        /* FIX: Deallocate memory */
        free(data);
    }
}

/* goodB2G2() - use badsource and goodsink by reversing the blocks in the second if */
static void goodB2G2()
{
    int * data;
    data = NULL;
    if(5==5)
    {
        /* POTENTIAL FLAW: Allocate memory on the heap */
        data = (int *)calloc(100, sizeof(int));
        /* Initialize and make use of data */
        data[0] = 5;
        printIntLine(data[0]);
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* FIX: Use memory allocated on the stack */
            int data_goodbuf[100];
            data = data_goodbuf;
            /* Initialize and make use of data */
            data[0] = 5;
            printIntLine(data[0]);
        }
    }
    if(5==5)
    {
        /* FIX: Deallocate memory */
        free(data);
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* POTENTIAL FLAW: No deallocation */
        ; /* empty statement needed for some flow variants */
    }
}

/* goodG2B1() - use goodsource and badsink by changing the first 5==5 to 5!=5 */
static void goodG2B1()
{
    int * data;
    data = NULL;
    if(5!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* POTENTIAL FLAW: Allocate memory on the heap */
        data = (int *)calloc(100, sizeof(int));
        /* Initialize and make use of data */
        data[0] = 5;
        printIntLine(data[0]);
    }
    else
    {
        {
            /* FIX: Use memory allocated on the stack */
            int data_goodbuf[100];
            data = data_goodbuf;
            /* Initialize and make use of data */
            data[0] = 5;
            printIntLine(data[0]);
        }
    }
    if(5==5)
    {
        /* POTENTIAL FLAW: No deallocation */
        ; /* empty statement needed for some flow variants */
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Deallocate memory */
        free(data);
    }
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the first if */
static void goodG2B2()
{
    int * data;
    data = NULL;
    if(5==5)
    {
        {
            /* FIX: Use memory allocated on the stack */
            int data_goodbuf[100];
            data = data_goodbuf;
            /* Initialize and make use of data */
            data[0] = 5;
            printIntLine(data[0]);
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* POTENTIAL FLAW: Allocate memory on the heap */
        data = (int *)calloc(100, sizeof(int));
        /* Initialize and make use of data */
        data[0] = 5;
        printIntLine(data[0]);
    }
    if(5==5)
    {
        /* POTENTIAL FLAW: No deallocation */
        ; /* empty statement needed for some flow variants */
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Deallocate memory */
        free(data);
    }
}

void CWE401_Memory_Leak__int_calloc_03_good()
{
    goodB2G1();
    goodB2G2();
    goodG2B1();
    goodG2B2();
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
    CWE401_Memory_Leak__int_calloc_03_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE401_Memory_Leak__int_calloc_03_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
