/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE617_Reachable_Assertion__fscanf_63a.c
Label Definition File: CWE617_Reachable_Assertion.label.xml
Template File: sources-sink-63a.tmpl.c
*/
/*
 * @description
 * CWE: 617 Reachable Assertion
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Number greater than ASSERT_VALUE
 * Sinks:
 *    BadSink : Assert if n is less than ASSERT_VALUE
 * Flow Variant: 63 Data flow: pointer to data passed from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <assert.h>

#define ASSERT_VALUE 5

#ifndef OMITBAD

/* bad function declaration */
void CWE617_Reachable_Assertion__fscanf_63b_bad_sink(int * data_ptr);

void CWE617_Reachable_Assertion__fscanf_63_bad()
{
    int data;
    /* Initialize data */
    data = -1;
    fscanf (stdin, "%d", &data);
    CWE617_Reachable_Assertion__fscanf_63b_bad_sink(&data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE617_Reachable_Assertion__fscanf_63b_goodG2B_sink(int * data);

static void goodG2B()
{
    int data;
    /* Initialize data */
    data = -1;
    /* FLAW: Use a value greater than the assert value */
    data = ASSERT_VALUE+1;
    CWE617_Reachable_Assertion__fscanf_63b_goodG2B_sink(&data);
}

void CWE617_Reachable_Assertion__fscanf_63_good()
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
    CWE617_Reachable_Assertion__fscanf_63_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE617_Reachable_Assertion__fscanf_63_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
