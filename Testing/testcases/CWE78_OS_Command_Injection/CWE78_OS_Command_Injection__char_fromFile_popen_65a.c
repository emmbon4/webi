/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE78_OS_Command_Injection__char_fromFile_popen_65a.c
Label Definition File: CWE78_OS_Command_Injection.fullpath.label.xml
Template File: sources-sink-65a.tmpl.c
*/
/*
 * @description
 * CWE: 78 OS Command Injection
 * BadSource: fromFile Read input from a file
 * GoodSource: Benign input
 * Sinks: popen
 *    BadSink : Execute command using popen()
 * Flow Variant: 65 Data/control flow: data passed as an argument from one function to a function in a different source file called via a function pointer
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

/* bad function declaration */
void CWE78_OS_Command_Injection__char_fromFile_popen_65b_bad_sink(char * data);

void CWE78_OS_Command_Injection__char_fromFile_popen_65_bad()
{
    char * data;
    /* define a function pointer */
    void (*func_ptr) (char *) = CWE78_OS_Command_Injection__char_fromFile_popen_65b_bad_sink;
    char data_buf[100] = FULL_COMMAND;
    data = data_buf;
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
    /* use the function pointer */
    func_ptr(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE78_OS_Command_Injection__char_fromFile_popen_65b_goodG2B_sink(char * data);

static void goodG2B()
{
    char * data;
    void (*func_ptr) (char *) = CWE78_OS_Command_Injection__char_fromFile_popen_65b_goodG2B_sink;
    char data_buf[100] = FULL_COMMAND;
    data = data_buf;
    /* FIX: Benign input preventing command injection */
    strcat(data, "*.*");
    func_ptr(data);
}

void CWE78_OS_Command_Injection__char_fromFile_popen_65_good()
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
    CWE78_OS_Command_Injection__char_fromFile_popen_65_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE78_OS_Command_Injection__char_fromFile_popen_65_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
