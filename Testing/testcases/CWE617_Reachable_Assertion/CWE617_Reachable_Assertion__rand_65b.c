/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE617_Reachable_Assertion__rand_65b.c
Label Definition File: CWE617_Reachable_Assertion.label.xml
Template File: sources-sink-65b.tmpl.c
*/
/*
 * @description
 * CWE: 617 Reachable Assertion
 * BadSource: rand Set data to result of rand(), which may be zero
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

void CWE617_Reachable_Assertion__rand_65b_bad_sink(int data)
{
    /* POTENTIAL FLAW: this assertion could trigger if n < ASSERT_VALUE */
    assert(data > ASSERT_VALUE);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE617_Reachable_Assertion__rand_65b_goodG2B_sink(int data)
{
    /* POTENTIAL FLAW: this assertion could trigger if n < ASSERT_VALUE */
    assert(data > ASSERT_VALUE);
}

#endif /* OMITGOOD */
