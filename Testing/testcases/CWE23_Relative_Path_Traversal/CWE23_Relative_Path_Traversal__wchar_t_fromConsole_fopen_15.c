/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE23_Relative_Path_Traversal__wchar_t_fromConsole_fopen_15.c
Label Definition File: CWE23_Relative_Path_Traversal.label.xml
Template File: sources-sink-15.tmpl.c
*/
/*
 * @description
 * CWE: 23 Relative Path Traversal
 * BadSource: fromConsole Read input from the console
 * GoodSource: File name without a period or slash
 * Sink: fopen
 *    BadSink :
 * Flow Variant: 15 Control flow: switch(6)
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
#define BASEPATH L"c:\\temp\\"
#else
#define BASEPATH L"/tmp/"
#endif

#ifdef _WIN32
# define FOPEN _wfopen
#else
/* fopen is used on unix-based OSs */
# define FOPEN fopen
#endif

#ifndef OMITBAD

void CWE23_Relative_Path_Traversal__wchar_t_fromConsole_fopen_15_bad()
{
    wchar_t * data;
    wchar_t data_buf[FILENAME_MAX] = BASEPATH;
    data = data_buf;
    switch(6)
    {
    case 6:
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
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: File name does not contain a period or slash */
        wcscat(data, L"file.txt");
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

/* goodG2B1() - use goodsource and badsink by changing the switch to switch(5) */
static void goodG2B1()
{
    wchar_t * data;
    wchar_t data_buf[FILENAME_MAX] = BASEPATH;
    data = data_buf;
    switch(5)
    {
    case 6:
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
    default:
        /* FIX: File name does not contain a period or slash */
        wcscat(data, L"file.txt");
        break;
    }
    {
        FILE *file = NULL;
        /* POTENTIAL FLAW: Possibly opening a file without validating the file name or path */
        file = FOPEN(data, L"wb+");
        if (file != NULL) fclose(file);
    }
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the switch */
static void goodG2B2()
{
    wchar_t * data;
    wchar_t data_buf[FILENAME_MAX] = BASEPATH;
    data = data_buf;
    switch(6)
    {
    case 6:
        /* FIX: File name does not contain a period or slash */
        wcscat(data, L"file.txt");
        break;
    default:
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

void CWE23_Relative_Path_Traversal__wchar_t_fromConsole_fopen_15_good()
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
    CWE23_Relative_Path_Traversal__wchar_t_fromConsole_fopen_15_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE23_Relative_Path_Traversal__wchar_t_fromConsole_fopen_15_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
