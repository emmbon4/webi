/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__wchar_t_fromConsole_fprintf_66b.c
Label Definition File: CWE134_Uncontrolled_Format_String.label.xml
Template File: sources-sinks-66b.tmpl.c
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * BadSource: fromConsole Read input from the console
 * GoodSource: Copy a fixed string into data
 * Sinks: fprintf
 *    GoodSink: fwprintf with "%s" as the second argument and data as the third
 *    BadSink : fwprintf with data as the second argument
 * Flow Variant: 66 Data flow: data passed in an array from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE134_Uncontrolled_Format_String__wchar_t_fromConsole_fprintf_66b_bad_sink(wchar_t * data_array[])
{
    /* copy data out of data_array */
    wchar_t * data = data_array[2];
    /* POTENTIAL FLAW: Do not specify the format allowing a possible format string vulnerability */
    fwprintf(stdout, data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE134_Uncontrolled_Format_String__wchar_t_fromConsole_fprintf_66b_goodG2B_sink(wchar_t * data_array[])
{
    wchar_t * data = data_array[2];
    /* POTENTIAL FLAW: Do not specify the format allowing a possible format string vulnerability */
    fwprintf(stdout, data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE134_Uncontrolled_Format_String__wchar_t_fromConsole_fprintf_66b_goodB2G_sink(wchar_t * data_array[])
{
    wchar_t * data = data_array[2];
    /* FIX: Specify the format disallowing a format string vulnerability */
    fwprintf(stdout, L"%s\n", data);
}

#endif /* OMITGOOD */
