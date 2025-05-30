/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__char_calloc_12.c
Label Definition File: CWE401_Memory_Leak.c.label.xml
Template File: sources-sinks-12.tmpl.c
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource: calloc Allocate data using calloc()
 * GoodSource: Allocate data on the stack
 * Sinks:
 *    GoodSink: call free() on data
 *    BadSink : no deallocation of data
 * Flow Variant: 12 Control flow: if(global_returns_t_or_f())
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE401_Memory_Leak__char_calloc_12_bad()
{
    char * data;
    data = NULL;
    if(global_returns_t_or_f())
    {
        /* POTENTIAL FLAW: Allocate memory on the heap */
        data = (char *)calloc(100, sizeof(char));
        /* Initialize and make use of data */
        strcpy(data, "A String");
        printLine(data);
    }
    else
    {
        {
            /* FIX: Use memory allocated on the stack */
            char data_goodbuf[100];
            data = data_goodbuf;
            /* Initialize and make use of data */
            strcpy(data, "A String");
            printLine(data);
        }
    }
    if(global_returns_t_or_f())
    {
        /* POTENTIAL FLAW: No deallocation */
        ; /* empty statement needed for some flow variants */
    }
    else
    {
        /* FIX: Deallocate memory */
        free(data);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G() - use badsource and goodsink by changing the first "if" so that
   both branches use the BadSource and the second "if" so that both branches
   use the GoodSink */
static void goodB2G()
{
    char * data;
    data = NULL;
    if(global_returns_t_or_f())
    {
        /* POTENTIAL FLAW: Allocate memory on the heap */
        data = (char *)calloc(100, sizeof(char));
        /* Initialize and make use of data */
        strcpy(data, "A String");
        printLine(data);
    }
    else
    {
        /* POTENTIAL FLAW: Allocate memory on the heap */
        data = (char *)calloc(100, sizeof(char));
        /* Initialize and make use of data */
        strcpy(data, "A String");
        printLine(data);
    }
    if(global_returns_t_or_f())
    {
        /* FIX: Deallocate memory */
        free(data);
    }
    else
    {
        /* FIX: Deallocate memory */
        free(data);
    }
}

/* goodG2B() - use goodsource and badsink by changing the first "if" so that
   both branches use the GoodSource and the second "if" so that both branches
   use the BadSink */
static void goodG2B()
{
    char * data;
    data = NULL;
    if(global_returns_t_or_f())
    {
        {
            /* FIX: Use memory allocated on the stack */
            char data_goodbuf[100];
            data = data_goodbuf;
            /* Initialize and make use of data */
            strcpy(data, "A String");
            printLine(data);
        }
    }
    else
    {
        {
            /* FIX: Use memory allocated on the stack */
            char data_goodbuf[100];
            data = data_goodbuf;
            /* Initialize and make use of data */
            strcpy(data, "A String");
            printLine(data);
        }
    }
    if(global_returns_t_or_f())
    {
        /* POTENTIAL FLAW: No deallocation */
        ; /* empty statement needed for some flow variants */
    }
    else
    {
        /* POTENTIAL FLAW: No deallocation */
        ; /* empty statement needed for some flow variants */
    }
}

void CWE401_Memory_Leak__char_calloc_12_good()
{
    goodB2G();
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
    CWE401_Memory_Leak__char_calloc_12_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE401_Memory_Leak__char_calloc_12_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
