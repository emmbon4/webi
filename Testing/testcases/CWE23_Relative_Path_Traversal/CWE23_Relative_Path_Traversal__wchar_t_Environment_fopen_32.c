/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE23_Relative_Path_Traversal__wchar_t_Environment_fopen_32.c
Label Definition File: CWE23_Relative_Path_Traversal.label.xml
Template File: sources-sink-32.tmpl.c
*/
/*
 * @description
 * CWE: 23 Relative Path Traversal
 * BadSource: Environment Read input from an environment variable
 * GoodSource: File name without a period or slash
 * Sink: fopen
 *    BadSink :
 * Flow Variant: 32 Data flow using two pointers to the same value within the same function
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
# define FOPEN _wfopen
#else
/* fopen is used on unix-based OSs */
# define FOPEN fopen
#endif

#ifndef OMITBAD

void CWE23_Relative_Path_Traversal__wchar_t_Environment_fopen_32_bad()
{
    wchar_t * data;
    wchar_t * *data_ptr1 = &data;
    wchar_t * *data_ptr2 = &data;
    wchar_t data_buf[FILENAME_MAX] = BASEPATH;
    data = data_buf;
    {
        wchar_t * data = *data_ptr1;
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
        *data_ptr1 = data;
    }
    {
        wchar_t * data = *data_ptr2;
        {
            FILE *file = NULL;
            /* POTENTIAL FLAW: Possibly opening a file without validating the file name or path */
            file = FOPEN(data, L"wb+");
            if (file != NULL) fclose(file);
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    wchar_t * data;
    wchar_t * *data_ptr1 = &data;
    wchar_t * *data_ptr2 = &data;
    wchar_t data_buf[FILENAME_MAX] = BASEPATH;
    data = data_buf;
    {
        wchar_t * data = *data_ptr1;
        /* FIX: File name does not contain a period or slash */
        wcscat(data, L"file.txt");
        *data_ptr1 = data;
    }
    {
        wchar_t * data = *data_ptr2;
        {
            FILE *file = NULL;
            /* POTENTIAL FLAW: Possibly opening a file without validating the file name or path */
            file = FOPEN(data, L"wb+");
            if (file != NULL) fclose(file);
        }
    }
}

void CWE23_Relative_Path_Traversal__wchar_t_Environment_fopen_32_good()
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
    CWE23_Relative_Path_Traversal__wchar_t_Environment_fopen_32_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE23_Relative_Path_Traversal__wchar_t_Environment_fopen_32_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
