/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE197_Numeric_Truncation_Error__int_fgets_to_short_65b.c
Label Definition File: CWE197_Numeric_Truncation_Error__int.label.xml
Template File: sources-sink-65b.tmpl.c
*/
/*
 * @description
 * CWE: 197 Numeric Truncation Error
 * BadSource: fgets Read data from the console using fgets()
 * GoodSource: Less than CHAR_MAX
 * Sinks: to_short
 *    BadSink : Convert data to a short
 * Flow Variant: 65 Data/control flow: data passed as an argument from one function to a function in a different source file called via a function pointer
 *
 * */

#include "std_testcase.h"

#define CHAR_ARRAY_SIZE sizeof(data)*sizeof(data)

#ifndef OMITBAD

void CWE197_Numeric_Truncation_Error__int_fgets_to_short_65b_bad_sink(int data)
{
    {
        /* POTENTIAL FLAW: Convert data to a short, possibly causing a truncation error */
        short s = (short)data;
        printf("%hd\n", s);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE197_Numeric_Truncation_Error__int_fgets_to_short_65b_goodG2B_sink(int data)
{
    {
        /* POTENTIAL FLAW: Convert data to a short, possibly causing a truncation error */
        short s = (short)data;
        printf("%hd\n", s);
    }
}

#endif /* OMITGOOD */
