/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__wchar_t_Environment_vfprintf_54d.c
Label Definition File: CWE134_Uncontrolled_Format_String.vasinks.label.xml
Template File: sources-vasinks-54d.tmpl.c
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * BadSource: Environment Read input from an environment variable
 * GoodSource: Copy a fixed string into data
 * Sinks: vfprintf
 *    GoodSink: vfwprintf with a format string
 *    BadSink : vfwprintf without a format string
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include <stdarg.h>
#include "std_testcase.h"

#define ENV_VARIABLE L"ADD"

#ifdef _WIN32
# define GETENV _wgetenv
#else
# define GETENV wgetenv
#endif

#ifndef OMITBAD

/* bad function declaration */
void CWE134_Uncontrolled_Format_String__wchar_t_Environment_vfprintf_54e_bad_sink(wchar_t * data);

void CWE134_Uncontrolled_Format_String__wchar_t_Environment_vfprintf_54d_bad_sink(wchar_t * data)
{
    CWE134_Uncontrolled_Format_String__wchar_t_Environment_vfprintf_54e_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE134_Uncontrolled_Format_String__wchar_t_Environment_vfprintf_54e_goodG2B_sink(wchar_t * data);

void CWE134_Uncontrolled_Format_String__wchar_t_Environment_vfprintf_54d_goodG2B_sink(wchar_t * data)
{
    CWE134_Uncontrolled_Format_String__wchar_t_Environment_vfprintf_54e_goodG2B_sink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE134_Uncontrolled_Format_String__wchar_t_Environment_vfprintf_54e_goodB2G_sink(wchar_t * data);

void CWE134_Uncontrolled_Format_String__wchar_t_Environment_vfprintf_54d_goodB2G_sink(wchar_t * data)
{
    CWE134_Uncontrolled_Format_String__wchar_t_Environment_vfprintf_54e_goodB2G_sink(data);
}

#endif /* OMITGOOD */
