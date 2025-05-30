/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE617_Reachable_Assertion__fixed_68b.c
Label Definition File: CWE617_Reachable_Assertion.label.xml
Template File: sources-sink-68b.tmpl.c
*/
/*
 * @description
 * CWE: 617 Reachable Assertion
 * BadSource: fixed Fixed value less than the assert value
 * GoodSource: Number greater than ASSERT_VALUE
 * Sink:
 *    BadSink : Assert if n is less than ASSERT_VALUE
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <assert.h>

#define ASSERT_VALUE 5

extern int CWE617_Reachable_Assertion__fixed_68_bad_data;
extern int CWE617_Reachable_Assertion__fixed_68_goodG2B_data;

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

void CWE617_Reachable_Assertion__fixed_68b_bad_sink()
{
    int data = CWE617_Reachable_Assertion__fixed_68_bad_data;
    /* POTENTIAL FLAW: this assertion could trigger if n < ASSERT_VALUE */
    assert(data > ASSERT_VALUE);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE617_Reachable_Assertion__fixed_68b_goodG2B_sink()
{
    int data = CWE617_Reachable_Assertion__fixed_68_goodG2B_data;
    /* POTENTIAL FLAW: this assertion could trigger if n < ASSERT_VALUE */
    assert(data > ASSERT_VALUE);
}

#endif /* OMITGOOD */
