/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__struct_twoints_malloc_16.c
Label Definition File: CWE401_Memory_Leak.c.label.xml
Template File: sources-sinks-16.tmpl.c
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource: malloc Allocate data using malloc()
 * GoodSource: Allocate data on the stack
 * Sinks:
 *    GoodSink: call free() on data
 *    BadSink : no deallocation of data
 * Flow Variant: 16 Control flow: while(1) and while(0)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE401_Memory_Leak__struct_twoints_malloc_16_bad()
{
    struct _twoints * data;
    data = NULL;
    while(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* FIX: Use memory allocated on the stack */
            struct _twoints data_goodbuf[100];
            data = data_goodbuf;
            /* Initialize and make use of data */
            data[0].a = 0;
            data[0].b = 0;
            printStructLine((twoints *)&data[0]);
        }
        break;
    }
    while(1)
    {
        /* POTENTIAL FLAW: Allocate memory on the heap */
        data = (struct _twoints *)malloc(100*sizeof(struct _twoints));
        /* Initialize and make use of data */
        data[0].a = 0;
        data[0].b = 0;
        printStructLine((twoints *)&data[0]);
        break;
    }
    while(1)
    {
        /* POTENTIAL FLAW: No deallocation */
        ; /* empty statement needed for some flow variants */
        break;
    }
    while(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Deallocate memory */
        free(data);
        break;
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G() - use badsource and goodsink by changing the conditions on the third and fourth while statements */
static void goodB2G()
{
    struct _twoints * data;
    data = NULL;
    while(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* FIX: Use memory allocated on the stack */
            struct _twoints data_goodbuf[100];
            data = data_goodbuf;
            /* Initialize and make use of data */
            data[0].a = 0;
            data[0].b = 0;
            printStructLine((twoints *)&data[0]);
        }
        break;
    }
    while(1)
    {
        /* POTENTIAL FLAW: Allocate memory on the heap */
        data = (struct _twoints *)malloc(100*sizeof(struct _twoints));
        /* Initialize and make use of data */
        data[0].a = 0;
        data[0].b = 0;
        printStructLine((twoints *)&data[0]);
        break;
    }
    while(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* POTENTIAL FLAW: No deallocation */
        ; /* empty statement needed for some flow variants */
        break;
    }
    while(1)
    {
        /* FIX: Deallocate memory */
        free(data);
        break;
    }
}

/* goodG2B() - use goodsource and badsink by changing the conditions on the first and second while statements */
static void goodG2B()
{
    struct _twoints * data;
    data = NULL;
    while(1)
    {
        {
            /* FIX: Use memory allocated on the stack */
            struct _twoints data_goodbuf[100];
            data = data_goodbuf;
            /* Initialize and make use of data */
            data[0].a = 0;
            data[0].b = 0;
            printStructLine((twoints *)&data[0]);
        }
        break;
    }
    while(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* POTENTIAL FLAW: Allocate memory on the heap */
        data = (struct _twoints *)malloc(100*sizeof(struct _twoints));
        /* Initialize and make use of data */
        data[0].a = 0;
        data[0].b = 0;
        printStructLine((twoints *)&data[0]);
        break;
    }
    while(1)
    {
        /* POTENTIAL FLAW: No deallocation */
        ; /* empty statement needed for some flow variants */
        break;
    }
    while(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Deallocate memory */
        free(data);
        break;
    }
}

void CWE401_Memory_Leak__struct_twoints_malloc_16_good()
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
    CWE401_Memory_Leak__struct_twoints_malloc_16_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE401_Memory_Leak__struct_twoints_malloc_16_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
