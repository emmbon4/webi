/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE197_Numeric_Truncation_Error__int_fscanf_to_char_53c.c
Label Definition File: CWE197_Numeric_Truncation_Error__int.label.xml
Template File: sources-sink-53c.tmpl.c
*/
/*
 * @description
 * CWE: 197 Numeric Truncation Error
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Less than CHAR_MAX
 * Sink: to_char
 *    BadSink : Convert data to a char
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

/* bad function declaration */
void CWE197_Numeric_Truncation_Error__int_fscanf_to_char_53d_bad_sink(int data);

void CWE197_Numeric_Truncation_Error__int_fscanf_to_char_53c_bad_sink(int data)
{
    CWE197_Numeric_Truncation_Error__int_fscanf_to_char_53d_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declaration */
void CWE197_Numeric_Truncation_Error__int_fscanf_to_char_53d_goodG2B_sink(int data);

/* goodG2B uses the GoodSource with the BadSink */
void CWE197_Numeric_Truncation_Error__int_fscanf_to_char_53c_goodG2B_sink(int data)
{
    CWE197_Numeric_Truncation_Error__int_fscanf_to_char_53d_goodG2B_sink(data);
}

#endif /* OMITGOOD */
