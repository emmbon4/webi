/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE284_Access_Control_Issues__char_w32CreateFile_16.c
Label Definition File: CWE284_Access_Control_Issues.label.xml
Template File: point-flaw-16.tmpl.c
*/
/*
 * @description
 * CWE: 284 Access Control Issues
 * Sinks: w32CreateFile
 *    GoodSink: Create a file using CreateFileA() without excessive privileges
 *    BadSink : Create a file using CreateFileA() with excessive privileges
 * Flow Variant: 16 Control flow: while(1) and while(0)
 *
 * */

#include "std_testcase.h"

#include <windows.h>

#ifndef OMITBAD

void CWE284_Access_Control_Issues__char_w32CreateFile_16_bad()
{
    while(1)
    {
#ifdef _WIN32
        {
            HANDLE hFile;
            char * filename = "C:\\temp\\file.txt";

            /* FLAW: Call CreateFileA() with FILE_ALL_ACCESS as the 2nd parameter */
            hFile = CreateFileA(
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
            else {
                printLine("File created successfully");
                CloseHandle(hFile);
            }
        }
#endif
        break;
    }
    while(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
#ifdef _WIN32
        {
            HANDLE hFile;
            char * filename = "C:\\temp\\file.txt";
            /* FIX: Call CreateFileA() without FILE_ALL_ACCESS as the 2nd parameter to limit access */
            hFile = CreateFileA(
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
        break;
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() changes the conditions on the while statements */
static void good1()
{
    while(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
#ifdef _WIN32
        {
            HANDLE hFile;
            char * filename = "C:\\temp\\file.txt";
            /* FLAW: Call CreateFileA() with FILE_ALL_ACCESS as the 2nd parameter */
            hFile = CreateFileA(
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
        break;
    }
    while(1)
    {
#ifdef _WIN32
        {
            HANDLE hFile;
            char * filename = "C:\\temp\\file.txt";

            /* FIX: Call CreateFileA() without FILE_ALL_ACCESS as the 2nd parameter to limit access */
            hFile = CreateFileA(
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
            else {
                printLine("File created successfully");
                CloseHandle(hFile);
            }
        }
#endif
        break;
    }
}

void CWE284_Access_Control_Issues__char_w32CreateFile_16_good()
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
    CWE284_Access_Control_Issues__char_w32CreateFile_16_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE284_Access_Control_Issues__char_w32CreateFile_16_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
