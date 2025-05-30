/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE197_Numeric_Truncation_Error__int_fgets_to_char_63b.c
Label Definition File: CWE197_Numeric_Truncation_Error__int.label.xml
Template File: sources-sink-63b.tmpl.c
*/
/*
 * @description
 * CWE: 197 Numeric Truncation Error
 * BadSource: fgets Read data from the console using fgets()
 * GoodSource: Less than CHAR_MAX
 * Sinks: to_char
 *    BadSink : Convert data to a char
 * Flow Variant: 63 Data flow: pointer to data passed from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#define CHAR_ARRAY_SIZE sizeof(data)*sizeof(data)

#ifndef OMITBAD

void CWE197_Numeric_Truncation_Error__int_fgets_to_char_63b_bad_sink(int * data_ptr)
{
    int data = *data_ptr;
    {
        /* POTENTIAL FLAW: Convert data to a char, possibly causing a truncation error */
        char c = (char)data;
        printHexCharLine(c);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE197_Numeric_Truncation_Error__int_fgets_to_char_63b_goodG2B_sink(int * data_ptr)
{
    int data = *data_ptr;
    {
        /* POTENTIAL FLAW: Convert data to a char, possibly causing a truncation error */
        char c = (char)data;
        printHexCharLine(c);
    }
}

#endif /* OMITGOOD */
