/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE617_Reachable_Assertion__fixed_65a.c
Label Definition File: CWE617_Reachable_Assertion.label.xml
Template File: sources-sink-65a.tmpl.c
*/
/*
 * @description
 * CWE: 617 Reachable Assertion
 * BadSource: fixed Fixed value less than the assert value
 * GoodSource: Number greater than ASSERT_VALUE
 * Sinks:
 *    BadSink : Assert if n is less than ASSERT_VALUE
 * Flow Variant: 65 Data/control flow: data passed as an argument from one function to a function in a different source file called via a function pointer
 *
 * */

#include "std_testcase.h"

#include <assert.h>

#define ASSERT_VALUE 5

#ifndef OMITBAD

/* bad function declaration */
void CWE617_Reachable_Assertion__fixed_65b_bad_sink(int data);

void CWE617_Reachable_Assertion__fixed_65_bad()
{
    int data;
    /* define a function pointer */
    void (*func_ptr) (int) = CWE617_Reachable_Assertion__fixed_65b_bad_sink;
    /* Initialize data */
    data = -1;
    /* FLAW: Use a value less than the assert value */
    data = ASSERT_VALUE-1;
    /* use the function pointer */
    func_ptr(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE617_Reachable_Assertion__fixed_65b_goodG2B_sink(int data);

static void goodG2B()
{
    int data;
    void (*func_ptr) (int) = CWE617_Reachable_Assertion__fixed_65b_goodG2B_sink;
    /* Initialize data */
    data = -1;
    /* FLAW: Use a value greater than the assert value */
    data = ASSERT_VALUE+1;
    func_ptr(data);
}

void CWE617_Reachable_Assertion__fixed_65_good()
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
    CWE617_Reachable_Assertion__fixed_65_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE617_Reachable_Assertion__fixed_65_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
