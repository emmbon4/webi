/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE23_Relative_Path_Traversal__wchar_t_Environment_open_66a.c
Label Definition File: CWE23_Relative_Path_Traversal.label.xml
Template File: sources-sink-66a.tmpl.c
*/
/*
 * @description
 * CWE: 23 Relative Path Traversal
 * BadSource: Environment Read input from an environment variable
 * GoodSource: File name without a period or slash
 * Sinks: open
 *    BadSink :
 * Flow Variant: 66 Data flow: data passed in an array from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
#define BASEPATH L"c:\\temp\\"
#else
#define BASEPATH L"/tmp/"
#endif

#define ENV_VARIABLE L"ADD"

#ifdef _WIN32
# define GETENV _wgetenv
#else
# define GETENV wgetenv
#endif

#ifdef _WIN32
# define OPEN _wopen
# define CLOSE _close
#else
# define OPEN wopen
# define CLOSE close
#endif

#ifndef OMITBAD

/* bad function declaration */
void CWE23_Relative_Path_Traversal__wchar_t_Environment_open_66b_bad_sink(wchar_t * data_array[]);

void CWE23_Relative_Path_Traversal__wchar_t_Environment_open_66_bad()
{
    wchar_t * data;
    wchar_t * data_array[5];
    wchar_t data_buf[FILENAME_MAX] = BASEPATH;
    data = data_buf;
    {
        /* Read input from an environment variable */
        size_t data_len = wcslen(data);
        wchar_t * environment = GETENV(ENV_VARIABLE);
        /* If there is data in the environment variable */
        if (environment != NULL)
        {
            wcsncat(data+data_len, environment, 100-data_len-1);
        }
    }
    /* put data in array */
    data_array[2] = data;
    CWE23_Relative_Path_Traversal__wchar_t_Environment_open_66b_bad_sink(data_array);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE23_Relative_Path_Traversal__wchar_t_Environment_open_66b_goodG2B_sink(wchar_t * data_array[]);

static void goodG2B()
{
    wchar_t * data;
    wchar_t * data_array[5];
    wchar_t data_buf[FILENAME_MAX] = BASEPATH;
    data = data_buf;
    /* FIX: File name does not contain a period or slash */
    wcscat(data, L"file.txt");
    data_array[2] = data;
    CWE23_Relative_Path_Traversal__wchar_t_Environment_open_66b_goodG2B_sink(data_array);
}

void CWE23_Relative_Path_Traversal__wchar_t_Environment_open_66_good()
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
    CWE23_Relative_Path_Traversal__wchar_t_Environment_open_66_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE23_Relative_Path_Traversal__wchar_t_Environment_open_66_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
