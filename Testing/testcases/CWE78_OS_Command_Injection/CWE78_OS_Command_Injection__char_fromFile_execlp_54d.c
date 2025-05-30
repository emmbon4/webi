/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE78_OS_Command_Injection__char_fromFile_execlp_54d.c
Label Definition File: CWE78_OS_Command_Injection.no_path.label.xml
Template File: sources-sink-54d.tmpl.c
*/
/*
 * @description
 * CWE: 78 OS Command Injection
 * BadSource: fromFile Read input from a file
 * GoodSource: Benign input
 * Sink: execlp
 *    BadSink : execute command with execlp
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifdef _WIN32
# define COMMAND_INT_PATH "%WINDIR%\\system32\\cmd.exe"
# define COMMAND_INT "cmd.exe"
# define COMMAND_ARG1 "/c"
# define COMMAND_ARG2 "dir"
# define COMMAND_ARG3 data
#else /* NOT _WIN32 */
# define COMMAND_INT "sh"
# define COMMAND_ARG1 "ls"
# define COMMAND_ARG2 data
# define COMMAND_ARG3 NULL
#endif

#ifdef _WIN32
# define FOPEN fopen
#else
/* fopen is used on unix-based OSs */
# define FOPEN fopen
#endif

#ifdef _WIN32
#include <process.h>
# define EXECLP _execlp
#else /* NOT _WIN32 */
# define EXECLP execlp
#endif

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

/* bad function declaration */
void CWE78_OS_Command_Injection__char_fromFile_execlp_54e_bad_sink(char * data);

void CWE78_OS_Command_Injection__char_fromFile_execlp_54d_bad_sink(char * data)
{
    CWE78_OS_Command_Injection__char_fromFile_execlp_54e_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declaration */
void CWE78_OS_Command_Injection__char_fromFile_execlp_54e_goodG2B_sink(char * data);

/* goodG2B uses the GoodSource with the BadSink */
void CWE78_OS_Command_Injection__char_fromFile_execlp_54d_goodG2B_sink(char * data)
{
    CWE78_OS_Command_Injection__char_fromFile_execlp_54e_goodG2B_sink(data);
}

#endif /* OMITGOOD */
