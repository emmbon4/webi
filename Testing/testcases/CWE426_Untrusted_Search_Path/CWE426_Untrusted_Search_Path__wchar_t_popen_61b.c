/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE426_Untrusted_Search_Path__wchar_t_popen_61b.c
Label Definition File: CWE426_Untrusted_Search_Path.label.xml
Template File: sources-sink-61b.tmpl.c
*/
/*
 * @description
 * CWE: 426 Untrusted Search Path
 * BadSource:  Don't specify the full path in the OS command
 * GoodSource: Specify the full path in the OS command
 * Sinks: popen
 *    BadSink : Execute the wpopen function
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifdef _WIN32
# define BAD_OS_COMMAND L"cmd.exe /c dir"

/* REVIEWERS NOTE:
 * This hard-coded path is probably incorrect for Windows systems, as it will
 * function improperly on 9x/NT/2K, possibly on XP+ systems upgraded from 2K,
 * and could introduce code execution vulnerabilities on Windows systems that
 * have a system drive on an alternate drive letter (e.g., d:\windows)
 */
# define GOOD_OS_COMMAND L"c:\\windows\\system32\\cmd.exe /c dir"
#else /* NOT _WIN32 */
# define BAD_OS_COMMAND L"ls -la"
# define GOOD_OS_COMMAND L"/usr/bin/ls -la"
#endif /* end NOT _WIN32 */

/* define POPEN as _wpopen on Windows and wpopen otherwise */
#ifdef _WIN32
# define POPEN _wpopen
# define PCLOSE _pclose
#else /* NOT _WIN32 */
# define POPEN wpopen
# define PCLOSE pclose
#endif

#ifndef OMITBAD

wchar_t * CWE426_Untrusted_Search_Path__wchar_t_popen_61b_bad_source(wchar_t * data)
{
    /* FLAW - the full path is not specified */
    wcscpy(data, BAD_OS_COMMAND);
    return data;
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
wchar_t * CWE426_Untrusted_Search_Path__wchar_t_popen_61b_goodG2B_source(wchar_t * data)
{
    /* FIX - full path is specified */
    wcscpy(data, GOOD_OS_COMMAND);
    return data;
}

#endif /* OMITGOOD */
