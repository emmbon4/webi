/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE187_Partial_Comparison__wchar_t_Environment_str_54d.c
Label Definition File: CWE187_Partial_Comparison.label.xml
Template File: sources-sinks-54d.tmpl.c
*/
/*
 * @description
 * CWE: 187 Partial Comparison
 * BadSource: Environment Read input from an environment variable
 * GoodSource: Provide a matching password
 * Sinks: str
 *    GoodSink: Compare the 2 passwords correctly
 *    BadSink : use wcsstr() to do password match, which is a partial comparison
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#define PASSWORD L"Password1234"
/* PASSWORD_SZ must equal the length of PASSWORD */
#define PASSWORD_SZ wcslen(PASSWORD)

#define ENV_VARIABLE L"ADD"

#ifdef _WIN32
# define GETENV _wgetenv
#else
# define GETENV wgetenv
#endif

#ifndef OMITBAD

/* bad function declaration */
void CWE187_Partial_Comparison__wchar_t_Environment_str_54e_bad_sink(wchar_t * data);

void CWE187_Partial_Comparison__wchar_t_Environment_str_54d_bad_sink(wchar_t * data)
{
    CWE187_Partial_Comparison__wchar_t_Environment_str_54e_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE187_Partial_Comparison__wchar_t_Environment_str_54e_goodG2B_sink(wchar_t * data);

void CWE187_Partial_Comparison__wchar_t_Environment_str_54d_goodG2B_sink(wchar_t * data)
{
    CWE187_Partial_Comparison__wchar_t_Environment_str_54e_goodG2B_sink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE187_Partial_Comparison__wchar_t_Environment_str_54e_goodB2G_sink(wchar_t * data);

void CWE187_Partial_Comparison__wchar_t_Environment_str_54d_goodB2G_sink(wchar_t * data)
{
    CWE187_Partial_Comparison__wchar_t_Environment_str_54e_goodB2G_sink(data);
}

#endif /* OMITGOOD */
