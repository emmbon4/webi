/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE197_Numeric_Truncation_Error__short_large_61b.c
Label Definition File: CWE197_Numeric_Truncation_Error__short.label.xml
Template File: sources-sink-61b.tmpl.c
*/
/*
 * @description
 * CWE: 197 Numeric Truncation Error
 * BadSource: large Set data to a number larger than CHAR_MAX
 * GoodSource: Less than CHAR_MAX
 * Sinks:
 *    BadSink : Convert data to a char
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

short CWE197_Numeric_Truncation_Error__short_large_61b_bad_source(short data)
{
    /* FLAW: Use a number larger than CHAR_MAX */
    data = CHAR_MAX + 1;
    return data;
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
short CWE197_Numeric_Truncation_Error__short_large_61b_goodG2B_source(short data)
{
    /* FIX: Use a positive integer less than CHAR_MAX*/
    data = CHAR_MAX-5;
    return data;
}

#endif /* OMITGOOD */
