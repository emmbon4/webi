/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE476_NULL_Pointer_Dereference__long_long_61a.c
Label Definition File: CWE476_NULL_Pointer_Dereference.label.xml
Template File: sources-sink-61a.tmpl.c
*/
/*
 * @description
 * CWE: 476 NULL Pointer Dereference
 * BadSource:  Set data to NULL
 * GoodSource: Initialize data
 * Sinks:
 *    BadSink : Print data
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

/* bad function declaration */
long long * CWE476_NULL_Pointer_Dereference__long_long_61b_bad_source(long long * data);

void CWE476_NULL_Pointer_Dereference__long_long_61_bad()
{
    long long * data;
    /* Initialize data */
    data = NULL;
    data = CWE476_NULL_Pointer_Dereference__long_long_61b_bad_source(data);
    /* POTENTIAL FLAW: Attempt to use data, which may be NULL */
    printLongLongLine(*data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
long long * CWE476_NULL_Pointer_Dereference__long_long_61b_goodG2B_source(long long * data);

static void goodG2B()
{
    long long * data;
    /* Initialize data */
    data = NULL;
    data = CWE476_NULL_Pointer_Dereference__long_long_61b_goodG2B_source(data);
    /* POTENTIAL FLAW: Attempt to use data, which may be NULL */
    printLongLongLine(*data);
}

void CWE476_NULL_Pointer_Dereference__long_long_61_good()
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
    CWE476_NULL_Pointer_Dereference__long_long_61_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE476_NULL_Pointer_Dereference__long_long_61_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
