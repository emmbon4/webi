/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE426_Untrusted_Search_Path__wchar_t_system_68b.c
Label Definition File: CWE426_Untrusted_Search_Path.label.xml
Template File: sources-sink-68b.tmpl.c
*/
/*
 * @description
 * CWE: 426 Untrusted Search Path
 * BadSource:  Don't specify the full path in the OS command
 * GoodSource: Specify the full path in the OS command
 * Sink: system
 *    BadSink : Execute the _wsystem function
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
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

extern wchar_t * CWE426_Untrusted_Search_Path__wchar_t_system_68_bad_data;
extern wchar_t * CWE426_Untrusted_Search_Path__wchar_t_system_68_goodG2B_data;

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

void CWE426_Untrusted_Search_Path__wchar_t_system_68b_bad_sink()
{
    wchar_t * data = CWE426_Untrusted_Search_Path__wchar_t_system_68_bad_data;
    /* POTENTIAL FLAW: Executing the _wsystem() function without specifying the full path to the executable
     * can allow an attacker to run their own program */
    _wsystem(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE426_Untrusted_Search_Path__wchar_t_system_68b_goodG2B_sink()
{
    wchar_t * data = CWE426_Untrusted_Search_Path__wchar_t_system_68_goodG2B_data;
    /* POTENTIAL FLAW: Executing the _wsystem() function without specifying the full path to the executable
     * can allow an attacker to run their own program */
    _wsystem(data);
}

#endif /* OMITGOOD */
