/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE78_OS_Command_Injection__wchar_t_fromConsole_popen_67a.c
Label Definition File: CWE78_OS_Command_Injection.fullpath.label.xml
Template File: sources-sink-67a.tmpl.c
*/
/*
 * @description
 * CWE: 78 OS Command Injection
 * BadSource: fromConsole Read input from the console
 * GoodSource: Benign input
 * Sinks: popen
 *    BadSink : Execute command using popen()
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifdef _WIN32
# define COMMAND_INT_PATH L"%WINDIR%\\system32\\cmd.exe"
# define COMMAND_INT L"cmd.exe"
# define COMMAND_ARG1 L"/c"
# define COMMAND_ARG2 L"dir"
# define FULL_COMMAND COMMAND_INT_PATH L" " COMMAND_ARG1 L" "COMMAND_ARG2 L" "
#else /* NOT _WIN32 */
# define COMMAND_INT L"sh"
# define COMMAND_ARG1 L"ls"
# define FULL_COMMAND COMMAND_INT_PATH L" " COMMAND_ARG1 L" "
#endif

/* define POPEN as _popen on Windows and popen otherwise */
#ifdef _WIN32
# define POPEN _wpopen
# define PCLOSE _pclose
#else /* NOT _WIN32 */
# define POPEN wpopen
# define PCLOSE pclose
#endif

typedef struct _CWE78_OS_Command_Injection__wchar_t_fromConsole_popen_67_struct_type
{
    wchar_t * a;
} CWE78_OS_Command_Injection__wchar_t_fromConsole_popen_67_struct_type;

#ifndef OMITBAD

/* bad function declaration */
void CWE78_OS_Command_Injection__wchar_t_fromConsole_popen_67b_bad_sink(CWE78_OS_Command_Injection__wchar_t_fromConsole_popen_67_struct_type my_struct);

void CWE78_OS_Command_Injection__wchar_t_fromConsole_popen_67_bad()
{
    wchar_t * data;
    CWE78_OS_Command_Injection__wchar_t_fromConsole_popen_67_struct_type my_struct;
    wchar_t data_buf[100] = FULL_COMMAND;
    data = data_buf;
    {
        /* Read input from the console */
        size_t data_len = wcslen(data);
        /* if there is room in data, read into it from the console */
        if(100-data_len > 1)
        {
            fgetws(data+data_len, (int)(100-data_len), stdin);
            /* The next 3 lines remove the carriage return from the string that is
             * inserted by fgetws() */
            data_len = wcslen(data);
            if (data_len > 0)
            {
                data[data_len-1] = L'\0';
            }
        }
    }
    my_struct.a = data;
    CWE78_OS_Command_Injection__wchar_t_fromConsole_popen_67b_bad_sink(my_struct);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE78_OS_Command_Injection__wchar_t_fromConsole_popen_67b_goodG2B_sink(CWE78_OS_Command_Injection__wchar_t_fromConsole_popen_67_struct_type my_struct);

static void goodG2B()
{
    wchar_t * data;
    CWE78_OS_Command_Injection__wchar_t_fromConsole_popen_67_struct_type my_struct;
    wchar_t data_buf[100] = FULL_COMMAND;
    data = data_buf;
    /* FIX: Benign input preventing command injection */
    wcscat(data, L"*.*");
    my_struct.a = data;
    CWE78_OS_Command_Injection__wchar_t_fromConsole_popen_67b_goodG2B_sink(my_struct);
}

void CWE78_OS_Command_Injection__wchar_t_fromConsole_popen_67_good()
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
    CWE78_OS_Command_Injection__wchar_t_fromConsole_popen_67_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE78_OS_Command_Injection__wchar_t_fromConsole_popen_67_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
