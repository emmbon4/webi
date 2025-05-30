/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__wchar_t_calloc_13.c
Label Definition File: CWE401_Memory_Leak.c.label.xml
Template File: sources-sinks-13.tmpl.c
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource: calloc Allocate data using calloc()
 * GoodSource: Allocate data on the stack
 * Sinks:
 *    GoodSink: call free() on data
 *    BadSink : no deallocation of data
 * Flow Variant: 13 Control flow: if(global_const_five==5) and if(global_const_five!=5)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE401_Memory_Leak__wchar_t_calloc_13_bad()
{
    wchar_t * data;
    data = NULL;
    if(global_const_five==5)
    {
        /* POTENTIAL FLAW: Allocate memory on the heap */
        data = (wchar_t *)calloc(100, sizeof(wchar_t));
        /* Initialize and make use of data */
        wcscpy(data, L"A String");
        printWLine(data);
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* FIX: Use memory allocated on the stack */
            wchar_t data_goodbuf[100];
            data = data_goodbuf;
            /* Initialize and make use of data */
            wcscpy(data, L"A String");
            printWLine(data);
        }
    }
    if(global_const_five==5)
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

/* goodB2G1() - use badsource and goodsink by changing the second global_const_five==5 to global_const_five!=5 */
static void goodB2G1()
{
    wchar_t * data;
    data = NULL;
    if(global_const_five==5)
    {
        /* POTENTIAL FLAW: Allocate memory on the heap */
        data = (wchar_t *)calloc(100, sizeof(wchar_t));
        /* Initialize and make use of data */
        wcscpy(data, L"A String");
        printWLine(data);
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* FIX: Use memory allocated on the stack */
            wchar_t data_goodbuf[100];
            data = data_goodbuf;
            /* Initialize and make use of data */
            wcscpy(data, L"A String");
            printWLine(data);
        }
    }
    if(global_const_five!=5)
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
    wchar_t * data;
    data = NULL;
    if(global_const_five==5)
    {
        /* POTENTIAL FLAW: Allocate memory on the heap */
        data = (wchar_t *)calloc(100, sizeof(wchar_t));
        /* Initialize and make use of data */
        wcscpy(data, L"A String");
        printWLine(data);
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* FIX: Use memory allocated on the stack */
            wchar_t data_goodbuf[100];
            data = data_goodbuf;
            /* Initialize and make use of data */
            wcscpy(data, L"A String");
            printWLine(data);
        }
    }
    if(global_const_five==5)
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

/* goodG2B1() - use goodsource and badsink by changing the first global_const_five==5 to global_const_five!=5 */
static void goodG2B1()
{
    wchar_t * data;
    data = NULL;
    if(global_const_five!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* POTENTIAL FLAW: Allocate memory on the heap */
        data = (wchar_t *)calloc(100, sizeof(wchar_t));
        /* Initialize and make use of data */
        wcscpy(data, L"A String");
        printWLine(data);
    }
    else
    {
        {
            /* FIX: Use memory allocated on the stack */
            wchar_t data_goodbuf[100];
            data = data_goodbuf;
            /* Initialize and make use of data */
            wcscpy(data, L"A String");
            printWLine(data);
        }
    }
    if(global_const_five==5)
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
    wchar_t * data;
    data = NULL;
    if(global_const_five==5)
    {
        {
            /* FIX: Use memory allocated on the stack */
            wchar_t data_goodbuf[100];
            data = data_goodbuf;
            /* Initialize and make use of data */
            wcscpy(data, L"A String");
            printWLine(data);
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* POTENTIAL FLAW: Allocate memory on the heap */
        data = (wchar_t *)calloc(100, sizeof(wchar_t));
        /* Initialize and make use of data */
        wcscpy(data, L"A String");
        printWLine(data);
    }
    if(global_const_five==5)
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

void CWE401_Memory_Leak__wchar_t_calloc_13_good()
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
    CWE401_Memory_Leak__wchar_t_calloc_13_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE401_Memory_Leak__wchar_t_calloc_13_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
