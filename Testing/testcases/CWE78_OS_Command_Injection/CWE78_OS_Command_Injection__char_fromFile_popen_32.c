/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE78_OS_Command_Injection__char_fromFile_popen_32.c
Label Definition File: CWE78_OS_Command_Injection.fullpath.label.xml
Template File: sources-sink-32.tmpl.c
*/
/*
 * @description
 * CWE: 78 OS Command Injection
 * BadSource: fromFile Read input from a file
 * GoodSource: Benign input
 * Sink: popen
 *    BadSink : Execute command using popen()
 * Flow Variant: 32 Data flow using two pointers to the same value within the same function
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

#ifdef _WIN32
# define FOPEN fopen
#else
/* fopen is used on unix-based OSs */
# define FOPEN fopen
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

void CWE78_OS_Command_Injection__char_fromFile_popen_32_bad()
{
    char * data;
    char * *data_ptr1 = &data;
    char * *data_ptr2 = &data;
    char data_buf[100] = FULL_COMMAND;
    data = data_buf;
    {
        char * data = *data_ptr1;
        {
            /* Read input from a file */
            size_t data_len = strlen(data);
            FILE * pFile;
            /* if there is room in data, attempt to read the input from a file */
            if(100-data_len > 1)
            {
                pFile = FOPEN("C:\\temp\\file.txt", "r");
                if (pFile != NULL)
                {
                    fgets(data+data_len, (int)(100-data_len), pFile);
                    fclose(pFile);
                }
            }
        }
        *data_ptr1 = data;
    }
    {
        char * data = *data_ptr2;
        {
            FILE *pipe;
            /* POSSIBLE FLAW: Execute command without validating input possibly leading to command injection */
            pipe = POPEN(data, "wb");
            if (pipe != NULL) PCLOSE(pipe);
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    char * data;
    char * *data_ptr1 = &data;
    char * *data_ptr2 = &data;
    char data_buf[100] = FULL_COMMAND;
    data = data_buf;
    {
        char * data = *data_ptr1;
        /* FIX: Benign input preventing command injection */
        strcat(data, "*.*");
        *data_ptr1 = data;
    }
    {
        char * data = *data_ptr2;
        {
            FILE *pipe;
            /* POSSIBLE FLAW: Execute command without validating input possibly leading to command injection */
            pipe = POPEN(data, "wb");
            if (pipe != NULL) PCLOSE(pipe);
        }
    }
}

void CWE78_OS_Command_Injection__char_fromFile_popen_32_good()
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
    CWE78_OS_Command_Injection__char_fromFile_popen_32_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE78_OS_Command_Injection__char_fromFile_popen_32_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
