/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE23_Relative_Path_Traversal__wchar_t_fromFile_w32CreateFile_12.c
Label Definition File: CWE23_Relative_Path_Traversal.label.xml
Template File: sources-sink-12.tmpl.c
*/
/*
 * @description
 * CWE: 23 Relative Path Traversal
 * BadSource: fromFile Read input from a file
 * GoodSource: File name without a period or slash
 * Sink: w32CreateFile
 *    BadSink :
 * Flow Variant: 12 Control flow: if(global_returns_t_or_f())
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

#include <windows.h>

#ifndef OMITBAD

void CWE23_Relative_Path_Traversal__wchar_t_fromFile_w32CreateFile_12_bad()
{
    wchar_t * data;
    wchar_t data_buf[FILENAME_MAX] = BASEPATH;
    data = data_buf;
    if(global_returns_t_or_f())
    {
        {
            /* Read input from a file */
            size_t data_len = wcslen(data);
            FILE * pFile;
            /* if there is room in data, attempt to read the input from a file */
            if(FILENAME_MAX-data_len > 1)
            {
                pFile = FOPEN(L"C:\\temp\\file.txt", L"r");
                if (pFile != NULL)
                {
                    fgetws(data+data_len, (int)(FILENAME_MAX-data_len), pFile);
                    fclose(pFile);
                }
            }
        }
    }
    else
    {
        /* FIX: File name does not contain a period or slash */
        wcscat(data, L"file.txt");
    }
    {
        HANDLE hFile;
        /* POTENTIAL FLAW: Possibly creating and opening a file without validating the file name or path */
        hFile = CreateFileW(data,
                            (GENERIC_WRITE|GENERIC_READ),
                            0,
                            NULL,
                            OPEN_ALWAYS,
                            FILE_ATTRIBUTE_NORMAL,
                            NULL);
        if (hFile != INVALID_HANDLE_VALUE)
        {
            CloseHandle(hFile);
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() - use goodsource and badsink by changing the "if" so that
   both branches use the GoodSource */
static void goodG2B()
{
    wchar_t * data;
    wchar_t data_buf[FILENAME_MAX] = BASEPATH;
    data = data_buf;
    if(global_returns_t_or_f())
    {
        /* FIX: File name does not contain a period or slash */
        wcscat(data, L"file.txt");
    }
    else
    {
        /* FIX: File name does not contain a period or slash */
        wcscat(data, L"file.txt");
    }
    {
        HANDLE hFile;
        /* POTENTIAL FLAW: Possibly creating and opening a file without validating the file name or path */
        hFile = CreateFileW(data,
                            (GENERIC_WRITE|GENERIC_READ),
                            0,
                            NULL,
                            OPEN_ALWAYS,
                            FILE_ATTRIBUTE_NORMAL,
                            NULL);
        if (hFile != INVALID_HANDLE_VALUE)
        {
            CloseHandle(hFile);
        }
    }
}

void CWE23_Relative_Path_Traversal__wchar_t_fromFile_w32CreateFile_12_good()
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
    CWE23_Relative_Path_Traversal__wchar_t_fromFile_w32CreateFile_12_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE23_Relative_Path_Traversal__wchar_t_fromFile_w32CreateFile_12_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
