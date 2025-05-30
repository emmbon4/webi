/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE426_Untrusted_Search_Path__char_popen_52b.c
Label Definition File: CWE426_Untrusted_Search_Path.label.xml
Template File: sources-sink-52b.tmpl.c
*/
/*
 * @description
 * CWE: 426 Untrusted Search Path
 * BadSource:  Don't specify the full path in the OS command
 * GoodSource: Specify the full path in the OS command
 * Sink: popen
 *    BadSink : Execute the popen function
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifdef _WIN32
# define BAD_OS_COMMAND "cmd.exe /c dir"

/* REVIEWERS NOTE:
 * This hard-coded path is probably incorrect for Windows systems, as it will
 * function improperly on 9x/NT/2K, possibly on XP+ systems upgraded from 2K,
 * and could introduce code execution vulnerabilities on Windows systems that
 * have a system drive on an alternate drive letter (e.g., d:\windows)
 */
# define GOOD_OS_COMMAND "c:\\windows\\system32\\cmd.exe /c dir"
#else /* NOT _WIN32 */
# define BAD_OS_COMMAND "ls -la"
# define GOOD_OS_COMMAND "/usr/bin/ls -la"
#endif /* end NOT _WIN32 */

/* define POPEN as _popen on Windows and popen otherwise */
#ifdef _WIN32
# define POPEN _popen
# define PCLOSE _pclose
#else /* NOT _WIN32 */
# define POPEN popen
# define PCLOSE pclose
#endif

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

/* bad function declaration */
void CWE426_Untrusted_Search_Path__char_popen_52c_bad_sink(char * data);

void CWE426_Untrusted_Search_Path__char_popen_52b_bad_sink(char * data)
{
    CWE426_Untrusted_Search_Path__char_popen_52c_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declaration */
void CWE426_Untrusted_Search_Path__char_popen_52c_goodG2B_sink(char * data);

/* goodG2B uses the GoodSource with the BadSink */
void CWE426_Untrusted_Search_Path__char_popen_52b_goodG2B_sink(char * data)
{
    CWE426_Untrusted_Search_Path__char_popen_52c_goodG2B_sink(data);
}

#endif /* OMITGOOD */
