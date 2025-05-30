/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE187_Partial_Comparison__wchar_t_fromConsole_str_68b.c
Label Definition File: CWE187_Partial_Comparison.label.xml
Template File: sources-sinks-68b.tmpl.c
*/
/*
 * @description
 * CWE: 187 Partial Comparison
 * BadSource: fromConsole Read input from the console
 * GoodSource: Provide a matching password
 * Sinks: str
 *    GoodSink: Compare the 2 passwords correctly
 *    BadSink : use wcsstr() to do password match, which is a partial comparison
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#define PASSWORD L"Password1234"
/* PASSWORD_SZ must equal the length of PASSWORD */
#define PASSWORD_SZ wcslen(PASSWORD)

extern wchar_t * CWE187_Partial_Comparison__wchar_t_fromConsole_str_68_bad_data;
extern wchar_t * CWE187_Partial_Comparison__wchar_t_fromConsole_str_68_goodG2B_data;
extern wchar_t * CWE187_Partial_Comparison__wchar_t_fromConsole_str_68_goodB2G_data;

#ifndef OMITBAD

void CWE187_Partial_Comparison__wchar_t_fromConsole_str_68b_bad_sink()
{
    wchar_t * data = CWE187_Partial_Comparison__wchar_t_fromConsole_str_68_bad_data;
    /* POTENTIAL FLAW: Partially compare the two passwords */
    if (wcsstr(PASSWORD, data) != NULL)
        printLine("Access granted");
    else
        printLine("Access denied!");
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE187_Partial_Comparison__wchar_t_fromConsole_str_68b_goodG2B_sink()
{
    wchar_t * data = CWE187_Partial_Comparison__wchar_t_fromConsole_str_68_goodG2B_data;
    /* POTENTIAL FLAW: Partially compare the two passwords */
    if (wcsstr(PASSWORD, data) != NULL)
        printLine("Access granted");
    else
        printLine("Access denied!");
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE187_Partial_Comparison__wchar_t_fromConsole_str_68b_goodB2G_sink()
{
    wchar_t * data = CWE187_Partial_Comparison__wchar_t_fromConsole_str_68_goodB2G_data;
    /* Ideally, we would want to do a check to see if the passwords are of equal length */
    /* FIX: Compare the two passwords completely and correctly */
    if (wcscmp(PASSWORD, data) == 0)
        printLine("Access granted");
    else
        printLine("Access denied!");
}

#endif /* OMITGOOD */
