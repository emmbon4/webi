/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE36_Absolute_Path_Traversal__wchar_t_fromConsole_fopen_16.c
Label Definition File: CWE36_Absolute_Path_Traversal.label.xml
Template File: sources-sink-16.tmpl.c
*/
/*
 * @description
 * CWE: 36 Absolute Path Traversal
 * BadSource: fromConsole Read input from the console
 * GoodSource: Full path and file name
 * Sink: fopen
 *    BadSink :
 * Flow Variant: 16 Control flow: while(1) and while(0)
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
# define FOPEN _wfopen
#else
/* fopen is used on unix-based OSs */
# define FOPEN fopen
#endif

#ifndef OMITBAD

void CWE36_Absolute_Path_Traversal__wchar_t_fromConsole_fopen_16_bad()
{
    wchar_t * data;
    wchar_t data_buf[FILENAME_MAX] = L"";
    data = data_buf;
    while(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
#ifdef _WIN32
        /* FIX: Full path and file name */
        wcscpy(data, L"c:\\temp\\file.txt");
#else
        /* FIX: Full path and file name */
        wcscpy(data, L"/tmp/file.txt");
#endif
        break;
    }
    while(1)
    {
        {
            /* Read input from the console */
            size_t data_len = wcslen(data);
            /* if there is room in data, read into it from the console */
            if(FILENAME_MAX-data_len > 1)
            {
                fgetws(data+data_len, (int)(FILENAME_MAX-data_len), stdin);
                /* The next 3 lines remove the carriage return from the string that is
                 * inserted by fgetws() */
                data_len = wcslen(data);
                if (data_len > 0)
                {
                    data[data_len-1] = L'\0';
                }
            }
        }
        break;
    }
    {
        FILE *file = NULL;
        /* POTENTIAL FLAW: Possibly opening a file without validating the file name or path */
        file = FOPEN(data, L"wb+");
        if (file != NULL) fclose(file);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() - use goodsource and badsink by changing the conditions on the while statements */
static void goodG2B()
{
    wchar_t * data;
    wchar_t data_buf[FILENAME_MAX] = L"";
    data = data_buf;
    while(1)
    {
#ifdef _WIN32
        /* FIX: Full path and file name */
        wcscpy(data, L"c:\\temp\\file.txt");
#else
        /* FIX: Full path and file name */
        wcscpy(data, L"/tmp/file.txt");
#endif
        break;
    }
    while(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* Read input from the console */
            size_t data_len = wcslen(data);
            /* if there is room in data, read into it from the console */
            if(FILENAME_MAX-data_len > 1)
            {
                fgetws(data+data_len, (int)(FILENAME_MAX-data_len), stdin);
                /* The next 3 lines remove the carriage return from the string that is
                 * inserted by fgetws() */
                data_len = wcslen(data);
                if (data_len > 0)
                {
                    data[data_len-1] = L'\0';
                }
            }
        }
        break;
    }
    {
        FILE *file = NULL;
        /* POTENTIAL FLAW: Possibly opening a file without validating the file name or path */
        file = FOPEN(data, L"wb+");
        if (file != NULL) fclose(file);
    }
}

void CWE36_Absolute_Path_Traversal__wchar_t_fromConsole_fopen_16_good()
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
    CWE36_Absolute_Path_Traversal__wchar_t_fromConsole_fopen_16_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE36_Absolute_Path_Traversal__wchar_t_fromConsole_fopen_16_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
