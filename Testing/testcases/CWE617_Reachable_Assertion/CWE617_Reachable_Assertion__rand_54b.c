/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE617_Reachable_Assertion__rand_54b.c
Label Definition File: CWE617_Reachable_Assertion.label.xml
Template File: sources-sink-54b.tmpl.c
*/
/*
 * @description
 * CWE: 617 Reachable Assertion
 * BadSource: rand Set data to result of rand(), which may be zero
 * GoodSource: Number greater than ASSERT_VALUE
 * Sink:
 *    BadSink : Assert if n is less than ASSERT_VALUE
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <assert.h>

#define ASSERT_VALUE 5

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

/* bad function declaration */
void CWE617_Reachable_Assertion__rand_54c_bad_sink(int data);

void CWE617_Reachable_Assertion__rand_54b_bad_sink(int data)
{
    CWE617_Reachable_Assertion__rand_54c_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declaration */
void CWE617_Reachable_Assertion__rand_54c_goodG2B_sink(int data);

/* goodG2B uses the GoodSource with the BadSink */
void CWE617_Reachable_Assertion__rand_54b_goodG2B_sink(int data)
{
    CWE617_Reachable_Assertion__rand_54c_goodG2B_sink(data);
}

#endif /* OMITGOOD */
