/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE476_NULL_Pointer_Dereference__long_long_51a.c
Label Definition File: CWE476_NULL_Pointer_Dereference.label.xml
Template File: sources-sink-51a.tmpl.c
*/
/*
 * @description
 * CWE: 476 NULL Pointer Dereference
 * BadSource:  Set data to NULL
 * GoodSource: Initialize data
 * Sink:
 *    BadSink : Print data
 * Flow Variant: 51 Data flow: data passed as an argument from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

/* bad function declaration */
void CWE476_NULL_Pointer_Dereference__long_long_51b_bad_sink(long long * data);

void CWE476_NULL_Pointer_Dereference__long_long_51_bad()
{
    long long * data;
    /* Initialize data */
    data = NULL;
    /* FLAW: Set data to NULL - it will be used in the sink */
    data = NULL;
    CWE476_NULL_Pointer_Dereference__long_long_51b_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declarations */
void CWE476_NULL_Pointer_Dereference__long_long_51b_goodG2B_sink(long long * data);

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    long long * data;
    /* Initialize data */
    data = NULL;
    /* FIX: Initialize data - it will be used in the sink */
    {
        long long tmp = 5L;
        data = &tmp;
    }
    CWE476_NULL_Pointer_Dereference__long_long_51b_goodG2B_sink(data);
}

void CWE476_NULL_Pointer_Dereference__long_long_51_good()
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
    CWE476_NULL_Pointer_Dereference__long_long_51_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE476_NULL_Pointer_Dereference__long_long_51_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
