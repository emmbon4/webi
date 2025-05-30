/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE78_OS_Command_Injection__char_fromConsole_w32spawnvp_67a.c
Label Definition File: CWE78_OS_Command_Injection.no_path.label.xml
Template File: sources-sink-67a.tmpl.c
*/
/*
 * @description
 * CWE: 78 OS Command Injection
 * BadSource: fromConsole Read input from the console
 * GoodSource: Benign input
 * Sinks: w32spawnvp
 *    BadSink : execute command with spawnvp
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
# define COMMAND_ARG3 data
#else /* NOT _WIN32 */
# define COMMAND_INT "sh"
# define COMMAND_ARG1 "ls"
# define COMMAND_ARG2 data
# define COMMAND_ARG3 NULL
#endif

#include <process.h>

typedef struct _CWE78_OS_Command_Injection__char_fromConsole_w32spawnvp_67_struct_type
{
    char * a;
} CWE78_OS_Command_Injection__char_fromConsole_w32spawnvp_67_struct_type;

#ifndef OMITBAD

/* bad function declaration */
void CWE78_OS_Command_Injection__char_fromConsole_w32spawnvp_67b_bad_sink(CWE78_OS_Command_Injection__char_fromConsole_w32spawnvp_67_struct_type my_struct);

void CWE78_OS_Command_Injection__char_fromConsole_w32spawnvp_67_bad()
{
    char * data;
    CWE78_OS_Command_Injection__char_fromConsole_w32spawnvp_67_struct_type my_struct;
    char data_buf[100] = "";
    data = data_buf;
    {
        /* Read input from the console */
        size_t data_len = strlen(data);
        /* if there is room in data, read into it from the console */
        if(100-data_len > 1)
        {
            fgets(data+data_len, (int)(100-data_len), stdin);
            /* The next 3 lines remove the carriage return from the string that is
             * inserted by fgets() */
            data_len = strlen(data);
            if (data_len > 0)
            {
                data[data_len-1] = '\0';
            }
        }
    }
    my_struct.a = data;
    CWE78_OS_Command_Injection__char_fromConsole_w32spawnvp_67b_bad_sink(my_struct);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE78_OS_Command_Injection__char_fromConsole_w32spawnvp_67b_goodG2B_sink(CWE78_OS_Command_Injection__char_fromConsole_w32spawnvp_67_struct_type my_struct);

static void goodG2B()
{
    char * data;
    CWE78_OS_Command_Injection__char_fromConsole_w32spawnvp_67_struct_type my_struct;
    char data_buf[100] = "";
    data = data_buf;
    /* FIX: Benign input preventing command injection */
    strcat(data, "*.*");
    my_struct.a = data;
    CWE78_OS_Command_Injection__char_fromConsole_w32spawnvp_67b_goodG2B_sink(my_struct);
}

void CWE78_OS_Command_Injection__char_fromConsole_w32spawnvp_67_good()
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
    CWE78_OS_Command_Injection__char_fromConsole_w32spawnvp_67_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE78_OS_Command_Injection__char_fromConsole_w32spawnvp_67_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
