/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE284_Access_Control_Issues__wchar_t_w32CreateFile_18.c
Label Definition File: CWE284_Access_Control_Issues.label.xml
Template File: point-flaw-18.tmpl.c
*/
/*
 * @description
 * CWE: 284 Access Control Issues
 * Sinks: w32CreateFile
 *    GoodSink: Create a file using CreateFileW() without excessive privileges
 *    BadSink : Create a file using CreateFileW() with excessive privileges
 * Flow Variant: 18 Control flow: goto statements
 *
 * */

#include "std_testcase.h"

#include <windows.h>

#ifndef OMITBAD

void CWE284_Access_Control_Issues__wchar_t_w32CreateFile_18_bad()
{
    goto sink;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
#ifdef _WIN32
    {
        HANDLE hFile;
        wchar_t * filename = L"C:\\temp\\file.txt";
        /* FIX: Call CreateFileW() without FILE_ALL_ACCESS as the 2nd parameter to limit access */
        hFile = CreateFileW(
                    filename,
                    GENERIC_READ,
                    FILE_SHARE_READ,
                    NULL,
                    CREATE_NEW,
                    FILE_ATTRIBUTE_NORMAL,
                    NULL);
        if (hFile == INVALID_HANDLE_VALUE)
        {
            printLine("File could not be created");
        }
        else
        {
            printLine("File created successfully");
            CloseHandle(hFile);
        }
    }
#endif
sink:
#ifdef _WIN32
    {
        HANDLE hFile;
        wchar_t * filename = L"C:\\temp\\file.txt";
        /* FLAW: Call CreateFileW() with FILE_ALL_ACCESS as the 2nd parameter */
        hFile = CreateFileW(
                    filename,
                    FILE_ALL_ACCESS,
                    FILE_SHARE_READ,
                    NULL,
                    CREATE_NEW,
                    FILE_ATTRIBUTE_NORMAL,
                    NULL);
        if (hFile == INVALID_HANDLE_VALUE)
        {
            printLine("File could not be created");
        }
        else
        {
            printLine("File created successfully");
            CloseHandle(hFile);
        }
    }
#endif
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() reverses the blocks on the goto statement */
static void good1()
{
    goto sink;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
#ifdef _WIN32
    {
        HANDLE hFile;
        wchar_t * filename = L"C:\\temp\\file.txt";
        /* FLAW: Call CreateFileW() with FILE_ALL_ACCESS as the 2nd parameter */
        hFile = CreateFileW(
                    filename,
                    FILE_ALL_ACCESS,
                    FILE_SHARE_READ,
                    NULL,
                    CREATE_NEW,
                    FILE_ATTRIBUTE_NORMAL,
                    NULL);
        if (hFile == INVALID_HANDLE_VALUE)
        {
            printLine("File could not be created");
        }
        else
        {
            printLine("File created successfully");
            CloseHandle(hFile);
        }
    }
#endif
sink:
#ifdef _WIN32
    {
        HANDLE hFile;
        wchar_t * filename = L"C:\\temp\\file.txt";
        /* FIX: Call CreateFileW() without FILE_ALL_ACCESS as the 2nd parameter to limit access */
        hFile = CreateFileW(
                    filename,
                    GENERIC_READ,
                    FILE_SHARE_READ,
                    NULL,
                    CREATE_NEW,
                    FILE_ATTRIBUTE_NORMAL,
                    NULL);
        if (hFile == INVALID_HANDLE_VALUE)
        {
            printLine("File could not be created");
        }
        else
        {
            printLine("File created successfully");
            CloseHandle(hFile);
        }
    }
#endif
}

void CWE284_Access_Control_Issues__wchar_t_w32CreateFile_18_good()
{
    good1();
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
    CWE284_Access_Control_Issues__wchar_t_w32CreateFile_18_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE284_Access_Control_Issues__wchar_t_w32CreateFile_18_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
