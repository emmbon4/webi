/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE617_Reachable_Assertion__fscanf_68a.c
Label Definition File: CWE617_Reachable_Assertion.label.xml
Template File: sources-sink-68a.tmpl.c
*/
/*
 * @description
 * CWE: 617 Reachable Assertion
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Number greater than ASSERT_VALUE
 * Sink:
 *    BadSink : Assert if n is less than ASSERT_VALUE
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <assert.h>

#define ASSERT_VALUE 5

int CWE617_Reachable_Assertion__fscanf_68_bad_data;
int CWE617_Reachable_Assertion__fscanf_68_goodG2B_data;

#ifndef OMITBAD

/* bad function declaration */
void CWE617_Reachable_Assertion__fscanf_68b_bad_sink();

void CWE617_Reachable_Assertion__fscanf_68_bad()
{
    int data;
    /* Initialize data */
    data = -1;
    fscanf (stdin, "%d", &data);
    CWE617_Reachable_Assertion__fscanf_68_bad_data = data;
    CWE617_Reachable_Assertion__fscanf_68b_bad_sink();
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declarations */
void CWE617_Reachable_Assertion__fscanf_68b_goodG2B_sink();

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    int data;
    /* Initialize data */
    data = -1;
    /* FLAW: Use a value greater than the assert value */
    data = ASSERT_VALUE+1;
    CWE617_Reachable_Assertion__fscanf_68_goodG2B_data = data;
    CWE617_Reachable_Assertion__fscanf_68b_goodG2B_sink();
}

void CWE617_Reachable_Assertion__fscanf_68_good()
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
    CWE617_Reachable_Assertion__fscanf_68_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE617_Reachable_Assertion__fscanf_68_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
