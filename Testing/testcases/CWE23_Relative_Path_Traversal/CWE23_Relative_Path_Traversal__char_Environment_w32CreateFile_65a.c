/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE23_Relative_Path_Traversal__char_Environment_w32CreateFile_65a.c
Label Definition File: CWE23_Relative_Path_Traversal.label.xml
Template File: sources-sink-65a.tmpl.c
*/
/*
 * @description
 * CWE: 23 Relative Path Traversal
 * BadSource: Environment Read input from an environment variable
 * GoodSource: File name without a period or slash
 * Sinks: w32CreateFile
 *    BadSink :
 * Flow Variant: 65 Data/control flow: data passed as an argument from one function to a function in a different source file called via a function pointer
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
#define BASEPATH "c:\\temp\\"
#else
#define BASEPATH "/tmp/"
#endif

#define ENV_VARIABLE "ADD"

#ifdef _WIN32
# define GETENV getenv
#else
# define GETENV getenv
#endif

#include <windows.h>

#ifndef OMITBAD

/* bad function declaration */
void CWE23_Relative_Path_Traversal__char_Environment_w32CreateFile_65b_bad_sink(char * data);

void CWE23_Relative_Path_Traversal__char_Environment_w32CreateFile_65_bad()
{
    char * data;
    /* define a function pointer */
    void (*func_ptr) (char *) = CWE23_Relative_Path_Traversal__char_Environment_w32CreateFile_65b_bad_sink;
    char data_buf[FILENAME_MAX] = BASEPATH;
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
    /* use the function pointer */
    func_ptr(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE23_Relative_Path_Traversal__char_Environment_w32CreateFile_65b_goodG2B_sink(char * data);

static void goodG2B()
{
    char * data;
    void (*func_ptr) (char *) = CWE23_Relative_Path_Traversal__char_Environment_w32CreateFile_65b_goodG2B_sink;
    char data_buf[FILENAME_MAX] = BASEPATH;
    data = data_buf;
    /* FIX: File name does not contain a period or slash */
    strcat(data, "file.txt");
    func_ptr(data);
}

void CWE23_Relative_Path_Traversal__char_Environment_w32CreateFile_65_good()
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
    CWE23_Relative_Path_Traversal__char_Environment_w32CreateFile_65_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE23_Relative_Path_Traversal__char_Environment_w32CreateFile_65_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
