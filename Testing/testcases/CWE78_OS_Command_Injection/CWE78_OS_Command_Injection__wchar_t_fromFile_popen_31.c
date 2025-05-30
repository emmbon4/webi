/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE78_OS_Command_Injection__wchar_t_fromFile_popen_31.c
Label Definition File: CWE78_OS_Command_Injection.fullpath.label.xml
Template File: sources-sink-31.tmpl.c
*/
/*
 * @description
 * CWE: 78 OS Command Injection
 * BadSource: fromFile Read input from a file
 * GoodSource: Benign input
 * Sinks: popen
 *    BadSink : Execute command using popen()
 * Flow Variant: 31 Data flow using a copy of data within the same function
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

#ifdef _WIN32
# define FOPEN _wfopen
#else
/* fopen is used on unix-based OSs */
# define FOPEN fopen
#endif

/* define POPEN as _popen on Windows and popen otherwise */
#ifdef _WIN32
# define POPEN _wpopen
# define PCLOSE _pclose
#else /* NOT _WIN32 */
# define POPEN wpopen
# define PCLOSE pclose
#endif

#ifndef OMITBAD

void CWE78_OS_Command_Injection__wchar_t_fromFile_popen_31_bad()
{
    wchar_t * data;
    wchar_t data_buf[100] = FULL_COMMAND;
    data = data_buf;
    {
        /* Read input from a file */
        size_t data_len = wcslen(data);
        FILE * pFile;
        /* if there is room in data, attempt to read the input from a file */
        if(100-data_len > 1)
        {
            pFile = FOPEN(L"C:\\temp\\file.txt", L"r");
            if (pFile != NULL)
            {
                fgetws(data+data_len, (int)(100-data_len), pFile);
                fclose(pFile);
            }
        }
    }
    {
        wchar_t * data_copy = data;
        wchar_t * data = data_copy;
        {
            FILE *pipe;
            /* POSSIBLE FLAW: Execute command without validating input possibly leading to command injection */
            pipe = POPEN(data, L"wb");
            if (pipe != NULL) PCLOSE(pipe);
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    wchar_t * data;
    wchar_t data_buf[100] = FULL_COMMAND;
    data = data_buf;
    /* FIX: Benign input preventing command injection */
    wcscat(data, L"*.*");
    {
        wchar_t * data_copy = data;
        wchar_t * data = data_copy;
        {
            FILE *pipe;
            /* POSSIBLE FLAW: Execute command without validating input possibly leading to command injection */
            pipe = POPEN(data, L"wb");
            if (pipe != NULL) PCLOSE(pipe);
        }
    }
}

void CWE78_OS_Command_Injection__wchar_t_fromFile_popen_31_good()
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
    CWE78_OS_Command_Injection__wchar_t_fromFile_popen_31_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE78_OS_Command_Injection__wchar_t_fromFile_popen_31_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
