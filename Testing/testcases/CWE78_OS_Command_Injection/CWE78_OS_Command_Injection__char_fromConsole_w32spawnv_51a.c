/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE78_OS_Command_Injection__char_fromConsole_w32spawnv_51a.c
Label Definition File: CWE78_OS_Command_Injection.no_path.label.xml
Template File: sources-sink-51a.tmpl.c
*/
/*
 * @description
 * CWE: 78 OS Command Injection
 * BadSource: fromConsole Read input from the console
 * GoodSource: Benign input
 * Sink: w32spawnv
 *    BadSink : execute command with spawnv
 * Flow Variant: 51 Data flow: data passed as an argument from one function to another in different source files
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

#ifndef OMITBAD

/* bad function declaration */
void CWE78_OS_Command_Injection__char_fromConsole_w32spawnv_51b_bad_sink(char * data);

void CWE78_OS_Command_Injection__char_fromConsole_w32spawnv_51_bad()
{
    char * data;
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
    CWE78_OS_Command_Injection__char_fromConsole_w32spawnv_51b_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declarations */
void CWE78_OS_Command_Injection__char_fromConsole_w32spawnv_51b_goodG2B_sink(char * data);

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    char * data;
    char data_buf[100] = "";
    data = data_buf;
    /* FIX: Benign input preventing command injection */
    strcat(data, "*.*");
    CWE78_OS_Command_Injection__char_fromConsole_w32spawnv_51b_goodG2B_sink(data);
}

void CWE78_OS_Command_Injection__char_fromConsole_w32spawnv_51_good()
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
    CWE78_OS_Command_Injection__char_fromConsole_w32spawnv_51_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE78_OS_Command_Injection__char_fromConsole_w32spawnv_51_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
