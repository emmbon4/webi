/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE78_OS_Command_Injection__wchar_t_Environment_execl_54d.c
Label Definition File: CWE78_OS_Command_Injection.no_path.label.xml
Template File: sources-sink-54d.tmpl.c
*/
/*
 * @description
 * CWE: 78 OS Command Injection
 * BadSource: Environment Read input from an environment variable
 * GoodSource: Benign input
 * Sink: execl
 *    BadSink : execute command with wexecl
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
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

#define ENV_VARIABLE L"ADD"

#ifdef _WIN32
# define GETENV _wgetenv
#else
# define GETENV wgetenv
#endif

#ifdef _WIN32
#include <process.h>
# define EXECL _wexecl
#else /* NOT _WIN32 */
# define EXECL wexecl
#endif

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

/* bad function declaration */
void CWE78_OS_Command_Injection__wchar_t_Environment_execl_54e_bad_sink(wchar_t * data);

void CWE78_OS_Command_Injection__wchar_t_Environment_execl_54d_bad_sink(wchar_t * data)
{
    CWE78_OS_Command_Injection__wchar_t_Environment_execl_54e_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declaration */
void CWE78_OS_Command_Injection__wchar_t_Environment_execl_54e_goodG2B_sink(wchar_t * data);

/* goodG2B uses the GoodSource with the BadSink */
void CWE78_OS_Command_Injection__wchar_t_Environment_execl_54d_goodG2B_sink(wchar_t * data)
{
    CWE78_OS_Command_Injection__wchar_t_Environment_execl_54e_goodG2B_sink(data);
}

#endif /* OMITGOOD */
