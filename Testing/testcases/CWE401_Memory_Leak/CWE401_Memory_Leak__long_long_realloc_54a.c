/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__long_long_realloc_54a.c
Label Definition File: CWE401_Memory_Leak.c.label.xml
Template File: sources-sinks-54a.tmpl.c
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource: realloc Allocate data using realloc()
 * GoodSource: Allocate data on the stack
 * Sinks:
 *    GoodSink: call free() on data
 *    BadSink : no deallocation of data
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

/* bad function declaration */
void CWE401_Memory_Leak__long_long_realloc_54b_bad_sink(long long * data);

void CWE401_Memory_Leak__long_long_realloc_54_bad()
{
    long long * data;
    data = NULL;
    data = NULL;
    /* POTENTIAL FLAW: Allocate memory on the heap */
    data = (long long *)realloc(data, 100*sizeof(long long));
    /* Initialize and make use of data */
    data[0] = 5L;
    printLongLongLine(data[0]);
    CWE401_Memory_Leak__long_long_realloc_54b_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE401_Memory_Leak__long_long_realloc_54b_goodG2B_sink(long long * data);

static void goodG2B()
{
    long long * data;
    data = NULL;
    {
        /* FIX: Use memory allocated on the stack */
        long long data_goodbuf[100];
        data = data_goodbuf;
        /* Initialize and make use of data */
        data[0] = 5L;
        printLongLongLine(data[0]);
    }
    CWE401_Memory_Leak__long_long_realloc_54b_goodG2B_sink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE401_Memory_Leak__long_long_realloc_54b_goodB2G_sink(long long * data);

static void goodB2G()
{
    long long * data;
    data = NULL;
    data = NULL;
    /* POTENTIAL FLAW: Allocate memory on the heap */
    data = (long long *)realloc(data, 100*sizeof(long long));
    /* Initialize and make use of data */
    data[0] = 5L;
    printLongLongLine(data[0]);
    CWE401_Memory_Leak__long_long_realloc_54b_goodB2G_sink(data);
}

void CWE401_Memory_Leak__long_long_realloc_54_good()
{
    goodG2B();
    goodB2G();
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
    CWE401_Memory_Leak__long_long_realloc_54_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE401_Memory_Leak__long_long_realloc_54_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
