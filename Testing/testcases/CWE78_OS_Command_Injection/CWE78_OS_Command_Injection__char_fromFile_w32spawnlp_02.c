/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE78_OS_Command_Injection__char_fromFile_w32spawnlp_02.c
Label Definition File: CWE78_OS_Command_Injection.no_path.label.xml
Template File: sources-sink-02.tmpl.c
*/
/*
 * @description
 * CWE: 78 OS Command Injection
 * BadSource: fromFile Read input from a file
 * GoodSource: Benign input
 * Sink: w32spawnlp
 *    BadSink : execute command with spawnlp
 * Flow Variant: 02 Control flow: if(1) and if(0)
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

#include <process.h>

#ifndef OMITBAD

void CWE78_OS_Command_Injection__char_fromFile_w32spawnlp_02_bad()
{
    char * data;
    char data_buf[100] = "";
    data = data_buf;
    if(1)
    {
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
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Benign input preventing command injection */
        strcat(data, "*.*");
    }
    /* spawnlp - searches for the location of the command among
     * the directories specified by the PATH environment variable */
    /* POSSIBLE FLAW: Execute command without validating input possibly leading to command injection */
    _spawnlp(_P_WAIT, COMMAND_INT, COMMAND_INT, COMMAND_ARG1, COMMAND_ARG2, COMMAND_ARG3, NULL);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B1() - use goodsource and badsink by changing the 1 to 0 */
static void goodG2B1()
{
    char * data;
    char data_buf[100] = "";
    data = data_buf;
    if(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
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
    }
    else
    {
        /* FIX: Benign input preventing command injection */
        strcat(data, "*.*");
    }
    /* spawnlp - searches for the location of the command among
     * the directories specified by the PATH environment variable */
    /* POSSIBLE FLAW: Execute command without validating input possibly leading to command injection */
    _spawnlp(_P_WAIT, COMMAND_INT, COMMAND_INT, COMMAND_ARG1, COMMAND_ARG2, COMMAND_ARG3, NULL);
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the if statement */
static void goodG2B2()
{
    char * data;
    char data_buf[100] = "";
    data = data_buf;
    if(1)
    {
        /* FIX: Benign input preventing command injection */
        strcat(data, "*.*");
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
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
    }
    /* spawnlp - searches for the location of the command among
     * the directories specified by the PATH environment variable */
    /* POSSIBLE FLAW: Execute command without validating input possibly leading to command injection */
    _spawnlp(_P_WAIT, COMMAND_INT, COMMAND_INT, COMMAND_ARG1, COMMAND_ARG2, COMMAND_ARG3, NULL);
}

void CWE78_OS_Command_Injection__char_fromFile_w32spawnlp_02_good()
{
    goodG2B1();
    goodG2B2();
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
    CWE78_OS_Command_Injection__char_fromFile_w32spawnlp_02_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE78_OS_Command_Injection__char_fromFile_w32spawnlp_02_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
