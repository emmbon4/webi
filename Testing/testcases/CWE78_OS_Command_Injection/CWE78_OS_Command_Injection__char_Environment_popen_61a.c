/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE78_OS_Command_Injection__char_Environment_popen_61a.c
Label Definition File: CWE78_OS_Command_Injection.fullpath.label.xml
Template File: sources-sink-61a.tmpl.c
*/
/*
 * @description
 * CWE: 78 OS Command Injection
 * BadSource: Environment Read input from an environment variable
 * GoodSource: Benign input
 * Sinks: popen
 *    BadSink : Execute command using popen()
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
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

#ifndef OMITBAD

/* bad function declaration */
char * CWE78_OS_Command_Injection__char_Environment_popen_61b_bad_source(char * data);

void CWE78_OS_Command_Injection__char_Environment_popen_61_bad()
{
    char * data;
    char data_buf[100] = FULL_COMMAND;
    data = data_buf;
    data = CWE78_OS_Command_Injection__char_Environment_popen_61b_bad_source(data);
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
char * CWE78_OS_Command_Injection__char_Environment_popen_61b_goodG2B_source(char * data);

static void goodG2B()
{
    char * data;
    char data_buf[100] = FULL_COMMAND;
    data = data_buf;
    data = CWE78_OS_Command_Injection__char_Environment_popen_61b_goodG2B_source(data);
    {
        FILE *pipe;
        /* POSSIBLE FLAW: Execute command without validating input possibly leading to command injection */
        pipe = POPEN(data, "wb");
        if (pipe != NULL) PCLOSE(pipe);
    }
}

void CWE78_OS_Command_Injection__char_Environment_popen_61_good()
{
    goodG2B();
}

#endif /* OMITGOOD */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    CWE78_OS_Command_Injection__char_Environment_popen_61_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE78_OS_Command_Injection__char_Environment_popen_61_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
