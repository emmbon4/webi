/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE617_Reachable_Assertion__fscanf_52b.c
Label Definition File: CWE617_Reachable_Assertion.label.xml
Template File: sources-sink-52b.tmpl.c
*/
/*
 * @description
 * CWE: 617 Reachable Assertion
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Number greater than ASSERT_VALUE
 * Sink:
 *    BadSink : Assert if n is less than ASSERT_VALUE
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"

#include <assert.h>

#define ASSERT_VALUE 5

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

/* bad function declaration */
void CWE617_Reachable_Assertion__fscanf_52c_bad_sink(int data);

void CWE617_Reachable_Assertion__fscanf_52b_bad_sink(int data)
{
    CWE617_Reachable_Assertion__fscanf_52c_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declaration */
void CWE617_Reachable_Assertion__fscanf_52c_goodG2B_sink(int data);

/* goodG2B uses the GoodSource with the BadSink */
void CWE617_Reachable_Assertion__fscanf_52b_goodG2B_sink(int data)
{
    CWE617_Reachable_Assertion__fscanf_52c_goodG2B_sink(data);
}

#endif /* OMITGOOD */
