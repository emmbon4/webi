/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__wchar_t_fromConsole_fprintf_52b.c
Label Definition File: CWE134_Uncontrolled_Format_String.label.xml
Template File: sources-sinks-52b.tmpl.c
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * BadSource: fromConsole Read input from the console
 * GoodSource: Copy a fixed string into data
 * Sinks: fprintf
 *    GoodSink: fwprintf with "%s" as the second argument and data as the third
 *    BadSink : fwprintf with data as the second argument
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

/* bad function declaration */
void CWE134_Uncontrolled_Format_String__wchar_t_fromConsole_fprintf_52c_bad_sink(wchar_t * data);

void CWE134_Uncontrolled_Format_String__wchar_t_fromConsole_fprintf_52b_bad_sink(wchar_t * data)
{
    CWE134_Uncontrolled_Format_String__wchar_t_fromConsole_fprintf_52c_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE134_Uncontrolled_Format_String__wchar_t_fromConsole_fprintf_52c_goodG2B_sink(wchar_t * data);

void CWE134_Uncontrolled_Format_String__wchar_t_fromConsole_fprintf_52b_goodG2B_sink(wchar_t * data)
{
    CWE134_Uncontrolled_Format_String__wchar_t_fromConsole_fprintf_52c_goodG2B_sink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE134_Uncontrolled_Format_String__wchar_t_fromConsole_fprintf_52c_goodB2G_sink(wchar_t * data);

void CWE134_Uncontrolled_Format_String__wchar_t_fromConsole_fprintf_52b_goodB2G_sink(wchar_t * data)
{
    CWE134_Uncontrolled_Format_String__wchar_t_fromConsole_fprintf_52c_goodB2G_sink(data);
}

#endif /* OMITGOOD */
