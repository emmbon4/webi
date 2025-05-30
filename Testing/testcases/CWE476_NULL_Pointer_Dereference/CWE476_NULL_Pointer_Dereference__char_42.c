/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE476_NULL_Pointer_Dereference__char_42.c
Label Definition File: CWE476_NULL_Pointer_Dereference.label.xml
Template File: sources-sink-42.tmpl.c
*/
/*
 * @description
 * CWE: 476 NULL Pointer Dereference
 * BadSource:  Set data to NULL
 * GoodSource: Initialize data
 * Sink:
 *    BadSink : Print data
 * Flow Variant: 42 Data flow: data returned from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

static char * bad_source(char * data)
{
    /* FLAW: Set data to NULL - it will be used in the sink */
    data = NULL;
    return data;
}

void CWE476_NULL_Pointer_Dereference__char_42_bad()
{
    char * data;
    /* Initialize data */
    data = NULL;
    data = bad_source(data);
    /* POTENTIAL FLAW: Attempt to use data, which may be NULL */
    /* printLine() checks for NULL, so we cannot use it here */
    printf("%s\n", data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

static char * goodG2B_source(char * data)
{
    /* FIX: Initialize data - it will be used in the sink */
    data = "Good";
    return data;
}

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    char * data;
    /* Initialize data */
    data = NULL;
    data = goodG2B_source(data);
    /* POTENTIAL FLAW: Attempt to use data, which may be NULL */
    /* printLine() checks for NULL, so we cannot use it here */
    printf("%s\n", data);
}

void CWE476_NULL_Pointer_Dereference__char_42_good()
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
    CWE476_NULL_Pointer_Dereference__char_42_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE476_NULL_Pointer_Dereference__char_42_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
