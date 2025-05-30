/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE78_OS_Command_Injection__wchar_t_fromConsole_w32spawnl_53b.c
Label Definition File: CWE78_OS_Command_Injection.no_path.label.xml
Template File: sources-sink-53b.tmpl.c
*/
/*
 * @description
 * CWE: 78 OS Command Injection
 * BadSource: fromConsole Read input from the console
 * GoodSource: Benign input
 * Sink: w32spawnl
 *    BadSink : execute command with wspawnl
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

#include <process.h>

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

/* bad function declaration */
void CWE78_OS_Command_Injection__wchar_t_fromConsole_w32spawnl_53c_bad_sink(wchar_t * data);

void CWE78_OS_Command_Injection__wchar_t_fromConsole_w32spawnl_53b_bad_sink(wchar_t * data)
{
    CWE78_OS_Command_Injection__wchar_t_fromConsole_w32spawnl_53c_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declaration */
void CWE78_OS_Command_Injection__wchar_t_fromConsole_w32spawnl_53c_goodG2B_sink(wchar_t * data);

/* goodG2B uses the GoodSource with the BadSink */
void CWE78_OS_Command_Injection__wchar_t_fromConsole_w32spawnl_53b_goodG2B_sink(wchar_t * data)
{
    CWE78_OS_Command_Injection__wchar_t_fromConsole_w32spawnl_53c_goodG2B_sink(data);
}

#endif /* OMITGOOD */
