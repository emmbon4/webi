/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__twoints_realloc_18.c
Label Definition File: CWE401_Memory_Leak.c.label.xml
Template File: sources-sinks-18.tmpl.c
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource: realloc Allocate data using realloc()
 * GoodSource: Allocate data on the stack
 * Sinks:
 *    GoodSink: call free() on data
 *    BadSink : no deallocation of data
 * Flow Variant: 18 Control flow: goto statements
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE401_Memory_Leak__twoints_realloc_18_bad()
{
    twoints * data;
    data = NULL;
    goto source;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        /* FIX: Use memory allocated on the stack */
        twoints data_goodbuf[100];
        data = data_goodbuf;
        /* Initialize and make use of data */
        data[0].a = 0;
        data[0].b = 0;
        printStructLine(&data[0]);
    }
source:
    data = NULL;
    /* POTENTIAL FLAW: Allocate memory on the heap */
    data = (twoints *)realloc(data, 100*sizeof(twoints));
    /* Initialize and make use of data */
    data[0].a = 0;
    data[0].b = 0;
    printStructLine(&data[0]);
    goto sink;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    /* FIX: Deallocate memory */
    free(data);
sink:
    /* POTENTIAL FLAW: No deallocation */
    ; /* empty statement needed for some flow variants */
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G() - use badsource and goodsink by reversing the blocks on the second goto statement */
static void goodB2G()
{
    twoints * data;
    data = NULL;
    goto source;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        /* FIX: Use memory allocated on the stack */
        twoints data_goodbuf[100];
        data = data_goodbuf;
        /* Initialize and make use of data */
        data[0].a = 0;
        data[0].b = 0;
        printStructLine(&data[0]);
    }
source:
    data = NULL;
    /* POTENTIAL FLAW: Allocate memory on the heap */
    data = (twoints *)realloc(data, 100*sizeof(twoints));
    /* Initialize and make use of data */
    data[0].a = 0;
    data[0].b = 0;
    printStructLine(&data[0]);
    goto sink;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    /* POTENTIAL FLAW: No deallocation */
    ; /* empty statement needed for some flow variants */
sink:
    /* FIX: Deallocate memory */
    free(data);
}

/* goodG2B() - use goodsource and badsink by reversing the blocks on the first goto statement */
static void goodG2B()
{
    twoints * data;
    data = NULL;
    goto source;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    data = NULL;
    /* POTENTIAL FLAW: Allocate memory on the heap */
    data = (twoints *)realloc(data, 100*sizeof(twoints));
    /* Initialize and make use of data */
    data[0].a = 0;
    data[0].b = 0;
    printStructLine(&data[0]);
source:
    {
        /* FIX: Use memory allocated on the stack */
        twoints data_goodbuf[100];
        data = data_goodbuf;
        /* Initialize and make use of data */
        data[0].a = 0;
        data[0].b = 0;
        printStructLine(&data[0]);
    }
    goto sink;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    /* FIX: Deallocate memory */
    free(data);
sink:
    /* POTENTIAL FLAW: No deallocation */
    ; /* empty statement needed for some flow variants */
}

void CWE401_Memory_Leak__twoints_realloc_18_good()
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
    CWE401_Memory_Leak__twoints_realloc_18_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE401_Memory_Leak__twoints_realloc_18_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
