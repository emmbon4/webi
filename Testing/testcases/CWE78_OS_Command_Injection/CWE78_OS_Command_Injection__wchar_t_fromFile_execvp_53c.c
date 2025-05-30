/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE78_OS_Command_Injection__wchar_t_fromFile_execvp_53c.c
Label Definition File: CWE78_OS_Command_Injection.no_path.label.xml
Template File: sources-sink-53c.tmpl.c
*/
/*
 * @description
 * CWE: 78 OS Command Injection
 * BadSource: fromFile Read input from a file
 * GoodSource: Benign input
 * Sink: execvp
 *    BadSink : execute command with wexecvp
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifdef _WIN32
# define COMMAND_INT_PATH L"%WINDIR%\\system32\\cmd.exe"
# define COMMAND_INT L"cmd.exe"
# define COMMAND_ARG1 L"/c"
# define COMMAND_ARG2 L"dir"
# define COMMAND_ARG3 data
#else /* NOT _WIN32 */
# define COMMAND_INT L"sh"
# define COMMAND_ARG1 L"ls"
# define COMMAND_ARG2 data
# define COMMAND_ARG3 NULL
#endif

#ifdef _WIN32
# define FOPEN _wfopen
#else
/* fopen is used on unix-based OSs */
# define FOPEN fopen
#endif

#ifdef _WIN32
#include <process.h>
# define EXECVP _wexecvp
#else /* NOT _WIN32 */
# define EXECVP wexecvp
#endif

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

/* bad function declaration */
void CWE78_OS_Command_Injection__wchar_t_fromFile_execvp_53d_bad_sink(wchar_t * data);

void CWE78_OS_Command_Injection__wchar_t_fromFile_execvp_53c_bad_sink(wchar_t * data)
{
    CWE78_OS_Command_Injection__wchar_t_fromFile_execvp_53d_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declaration */
void CWE78_OS_Command_Injection__wchar_t_fromFile_execvp_53d_goodG2B_sink(wchar_t * data);

/* goodG2B uses the GoodSource with the BadSink */
void CWE78_OS_Command_Injection__wchar_t_fromFile_execvp_53c_goodG2B_sink(wchar_t * data)
{
    CWE78_OS_Command_Injection__wchar_t_fromFile_execvp_53d_goodG2B_sink(data);
}

#endif /* OMITGOOD */
