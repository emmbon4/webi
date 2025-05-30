/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__struct_twoints_calloc_42.c
Label Definition File: CWE401_Memory_Leak.c.label.xml
Template File: sources-sinks-42.tmpl.c
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource: calloc Allocate data using calloc()
 * GoodSource: Allocate data on the stack
 * Sinks:
 *    GoodSink: call free() on data
 *    BadSink : no deallocation of data
 * Flow Variant: 42 Data flow: data returned from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

static struct _twoints * bad_source(struct _twoints * data)
{

    /* POTENTIAL FLAW: Allocate memory on the heap */
    data = (struct _twoints *)calloc(100, sizeof(struct _twoints));

    /* Initialize and make use of data */

    data[0].a = 0;
    data[0].b = 0;

    printStructLine((twoints *)&data[0]);

    return data;
}

void CWE401_Memory_Leak__struct_twoints_calloc_42_bad()
{
    struct _twoints * data;
    data = NULL;
    data = bad_source(data);
    /* POTENTIAL FLAW: No deallocation */
    ; /* empty statement needed for some flow variants */
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
static struct _twoints * goodG2B_source(struct _twoints * data)
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

    return data;
}

static void goodG2B()
{
    struct _twoints * data;
    data = NULL;
    data = goodG2B_source(data);
    /* POTENTIAL FLAW: No deallocation */
    ; /* empty statement needed for some flow variants */
}

/* goodB2G uses the BadSource with the GoodSink */
static struct _twoints * goodB2G_source(struct _twoints * data)
{

    /* POTENTIAL FLAW: Allocate memory on the heap */
    data = (struct _twoints *)calloc(100, sizeof(struct _twoints));

    /* Initialize and make use of data */

    data[0].a = 0;
    data[0].b = 0;

    printStructLine((twoints *)&data[0]);

    return data;
}

static void goodB2G()
{
    struct _twoints * data;
    data = NULL;
    data = goodB2G_source(data);
    /* FIX: Deallocate memory */
    free(data);
}

void CWE401_Memory_Leak__struct_twoints_calloc_42_good()
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
    CWE401_Memory_Leak__struct_twoints_calloc_42_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE401_Memory_Leak__struct_twoints_calloc_42_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
