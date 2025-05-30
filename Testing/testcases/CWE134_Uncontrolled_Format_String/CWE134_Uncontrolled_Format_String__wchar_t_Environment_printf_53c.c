/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__wchar_t_Environment_printf_53c.c
Label Definition File: CWE134_Uncontrolled_Format_String.label.xml
Template File: sources-sinks-53c.tmpl.c
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * BadSource: Environment Read input from an environment variable
 * GoodSource: Copy a fixed string into data
 * Sinks: printf
 *    GoodSink: wprintf with "%s" as the first argument and data as the second
 *    BadSink : wprintf with only data as an argument
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

#define ENV_VARIABLE L"ADD"

#ifdef _WIN32
# define GETENV _wgetenv
#else
# define GETENV wgetenv
#endif

#ifndef OMITBAD

/* bad function declaration */
void CWE134_Uncontrolled_Format_String__wchar_t_Environment_printf_53d_bad_sink(wchar_t * data);

void CWE134_Uncontrolled_Format_String__wchar_t_Environment_printf_53c_bad_sink(wchar_t * data)
{
    CWE134_Uncontrolled_Format_String__wchar_t_Environment_printf_53d_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE134_Uncontrolled_Format_String__wchar_t_Environment_printf_53d_goodG2B_sink(wchar_t * data);

void CWE134_Uncontrolled_Format_String__wchar_t_Environment_printf_53c_goodG2B_sink(wchar_t * data)
{
    CWE134_Uncontrolled_Format_String__wchar_t_Environment_printf_53d_goodG2B_sink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE134_Uncontrolled_Format_String__wchar_t_Environment_printf_53d_goodB2G_sink(wchar_t * data);

void CWE134_Uncontrolled_Format_String__wchar_t_Environment_printf_53c_goodB2G_sink(wchar_t * data)
{
    CWE134_Uncontrolled_Format_String__wchar_t_Environment_printf_53d_goodB2G_sink(data);
}

#endif /* OMITGOOD */
