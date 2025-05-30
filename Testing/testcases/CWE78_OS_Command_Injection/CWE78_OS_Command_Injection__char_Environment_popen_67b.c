/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE78_OS_Command_Injection__char_Environment_popen_67b.c
Label Definition File: CWE78_OS_Command_Injection.fullpath.label.xml
Template File: sources-sink-67b.tmpl.c
*/
/*
 * @description
 * CWE: 78 OS Command Injection
 * BadSource: Environment Read input from an environment variable
 * GoodSource: Benign input
 * Sinks: popen
 *    BadSink : Execute command using popen()
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifdef _WIN32
# define COMMAND_INT_PATH "%WINDIR%\\system32\\cmd.exe"
# define COMMAND_INT "cmd.exe"
# define COMMAND_ARG1 "/c"
# define COMMAND_ARG2 "dir"
# define FULL_COMMAND COMMAND_INT_PATH " " COMMAND_ARG1 " "COMMAND_ARG2 " "
#else /* NOT _WIN32 */
# define COMMAND_INT "sh"
# define COMMAND_ARG1 "ls"
# define FULL_COMMAND COMMAND_INT_PATH " " COMMAND_ARG1 " "
#endif

#define ENV_VARIABLE "ADD"

#ifdef _WIN32
# define GETENV getenv
#else
# define GETENV getenv
#endif

/* define POPEN as _popen on Windows and popen otherwise */
#ifdef _WIN32
# define POPEN _popen
# define PCLOSE _pclose
#else /* NOT _WIN32 */
# define POPEN popen
# define PCLOSE pclose
#endif

typedef struct _CWE78_OS_Command_Injection__char_Environment_popen_67_struct_type
{
    char * a;
} CWE78_OS_Command_Injection__char_Environment_popen_67_struct_type;

#ifndef OMITBAD

void CWE78_OS_Command_Injection__char_Environment_popen_67b_bad_sink(CWE78_OS_Command_Injection__char_Environment_popen_67_struct_type my_struct)
{
    char * data = my_struct.a;
    {
        FILE *pipe;
        /* POSSIBLE FLAW: Execute command without validating input possibly leading to command injection */
        pipe = POPEN(data, "wb");
        if (pipe != NULL) PCLOSE(pipe);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE78_OS_Command_Injection__char_Environment_popen_67b_goodG2B_sink(CWE78_OS_Command_Injection__char_Environment_popen_67_struct_type my_struct)
{
    char * data = my_struct.a;
    {
        FILE *pipe;
        /* POSSIBLE FLAW: Execute command without validating input possibly leading to command injection */
        pipe = POPEN(data, "wb");
        if (pipe != NULL) PCLOSE(pipe);
    }
}

#endif /* OMITGOOD */
