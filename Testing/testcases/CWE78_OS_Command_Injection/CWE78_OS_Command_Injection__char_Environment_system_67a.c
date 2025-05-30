/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE78_OS_Command_Injection__char_Environment_system_67a.c
Label Definition File: CWE78_OS_Command_Injection.fullpath.label.xml
Template File: sources-sink-67a.tmpl.c
*/
/*
 * @description
 * CWE: 78 OS Command Injection
 * BadSource: Environment Read input from an environment variable
 * GoodSource: Benign input
 * Sinks: system
 *    BadSink : Execute command using system()
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

typedef struct _CWE78_OS_Command_Injection__char_Environment_system_67_struct_type
{
    char * a;
} CWE78_OS_Command_Injection__char_Environment_system_67_struct_type;

#ifndef OMITBAD

/* bad function declaration */
void CWE78_OS_Command_Injection__char_Environment_system_67b_bad_sink(CWE78_OS_Command_Injection__char_Environment_system_67_struct_type my_struct);

void CWE78_OS_Command_Injection__char_Environment_system_67_bad()
{
    char * data;
    CWE78_OS_Command_Injection__char_Environment_system_67_struct_type my_struct;
    char data_buf[100] = FULL_COMMAND;
    data = data_buf;
    {
        /* Read input from an environment variable */
        size_t data_len = strlen(data);
        char * environment = GETENV(ENV_VARIABLE);
        /* If there is data in the environment variable */
        if (environment != NULL)
        {
            strncat(data+data_len, environment, 100-data_len-1);
        }
    }
    my_struct.a = data;
    CWE78_OS_Command_Injection__char_Environment_system_67b_bad_sink(my_struct);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE78_OS_Command_Injection__char_Environment_system_67b_goodG2B_sink(CWE78_OS_Command_Injection__char_Environment_system_67_struct_type my_struct);

static void goodG2B()
{
    char * data;
    CWE78_OS_Command_Injection__char_Environment_system_67_struct_type my_struct;
    char data_buf[100] = FULL_COMMAND;
    data = data_buf;
    /* FIX: Benign input preventing command injection */
    strcat(data, "*.*");
    my_struct.a = data;
    CWE78_OS_Command_Injection__char_Environment_system_67b_goodG2B_sink(my_struct);
}

void CWE78_OS_Command_Injection__char_Environment_system_67_good()
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
    CWE78_OS_Command_Injection__char_Environment_system_67_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE78_OS_Command_Injection__char_Environment_system_67_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
