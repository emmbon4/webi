/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE36_Absolute_Path_Traversal__char_Environment_fopen_68a.c
Label Definition File: CWE36_Absolute_Path_Traversal.label.xml
Template File: sources-sink-68a.tmpl.c
*/
/*
 * @description
 * CWE: 36 Absolute Path Traversal
 * BadSource: Environment Read input from an environment variable
 * GoodSource: Full path and file name
 * Sink: fopen
 *    BadSink :
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#define ENV_VARIABLE "ADD"

#ifdef _WIN32
# define GETENV getenv
#else
# define GETENV getenv
#endif

#ifdef _WIN32
# define FOPEN fopen
#else
/* fopen is used on unix-based OSs */
# define FOPEN fopen
#endif

char * CWE36_Absolute_Path_Traversal__char_Environment_fopen_68_bad_data;
char * CWE36_Absolute_Path_Traversal__char_Environment_fopen_68_goodG2B_data;

#ifndef OMITBAD

/* bad function declaration */
void CWE36_Absolute_Path_Traversal__char_Environment_fopen_68b_bad_sink();

void CWE36_Absolute_Path_Traversal__char_Environment_fopen_68_bad()
{
    char * data;
    char data_buf[FILENAME_MAX] = "";
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
    CWE36_Absolute_Path_Traversal__char_Environment_fopen_68_bad_data = data;
    CWE36_Absolute_Path_Traversal__char_Environment_fopen_68b_bad_sink();
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declarations */
void CWE36_Absolute_Path_Traversal__char_Environment_fopen_68b_goodG2B_sink();

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    char * data;
    char data_buf[FILENAME_MAX] = "";
    data = data_buf;
#ifdef _WIN32
    /* FIX: Full path and file name */
    strcpy(data, "c:\\temp\\file.txt");
#else
    /* FIX: Full path and file name */
    strcpy(data, "/tmp/file.txt");
#endif
    CWE36_Absolute_Path_Traversal__char_Environment_fopen_68_goodG2B_data = data;
    CWE36_Absolute_Path_Traversal__char_Environment_fopen_68b_goodG2B_sink();
}

void CWE36_Absolute_Path_Traversal__char_Environment_fopen_68_good()
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
    CWE36_Absolute_Path_Traversal__char_Environment_fopen_68_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE36_Absolute_Path_Traversal__char_Environment_fopen_68_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
