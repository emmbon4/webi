/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE36_Absolute_Path_Traversal__char_fromConsole_w32CreateFile_04.c
Label Definition File: CWE36_Absolute_Path_Traversal.label.xml
Template File: sources-sink-04.tmpl.c
*/
/*
 * @description
 * CWE: 36 Absolute Path Traversal
 * BadSource: fromConsole Read input from the console
 * GoodSource: Full path and file name
 * Sink: w32CreateFile
 *    BadSink :
 * Flow Variant: 04 Control flow: if(static_const_t) and if(static_const_f)
 *
 * */

#include "std_testcase.h"

#include <windows.h>

/* The two variables below are declared "const", so a tool should
   be able to identify that reads of these will always return their
   initialized values. */
static const int static_const_t = 1; /* true */
static const int static_const_f = 0; /* false */

#ifndef OMITBAD

void CWE36_Absolute_Path_Traversal__char_fromConsole_w32CreateFile_04_bad()
{
    char * data;
    char data_buf[FILENAME_MAX] = "";
    data = data_buf;
    if(static_const_t)
    {
        {
            /* Read input from the console */
            size_t data_len = strlen(data);
            /* if there is room in data, read into it from the console */
            if(FILENAME_MAX-data_len > 1)
            {
                fgets(data+data_len, (int)(FILENAME_MAX-data_len), stdin);
                /* The next 3 lines remove the carriage return from the string that is
                 * inserted by fgets() */
                data_len = strlen(data);
                if (data_len > 0)
                {
                    data[data_len-1] = '\0';
                }
            }
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
#ifdef _WIN32
        /* FIX: Full path and file name */
        strcpy(data, "c:\\temp\\file.txt");
#else
        /* FIX: Full path and file name */
        strcpy(data, "/tmp/file.txt");
#endif
    }
    {
        HANDLE hFile;
        /* POTENTIAL FLAW: Possibly creating and opening a file without validating the file name or path */
        hFile = CreateFileA(data,
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

/* goodG2B1() - use goodsource and badsink by changing the static_const_t to static_const_f */
static void goodG2B1()
{
    char * data;
    char data_buf[FILENAME_MAX] = "";
    data = data_buf;
    if(static_const_f)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* Read input from the console */
            size_t data_len = strlen(data);
            /* if there is room in data, read into it from the console */
            if(FILENAME_MAX-data_len > 1)
            {
                fgets(data+data_len, (int)(FILENAME_MAX-data_len), stdin);
                /* The next 3 lines remove the carriage return from the string that is
                 * inserted by fgets() */
                data_len = strlen(data);
                if (data_len > 0)
                {
                    data[data_len-1] = '\0';
                }
            }
        }
    }
    else
    {
#ifdef _WIN32
        /* FIX: Full path and file name */
        strcpy(data, "c:\\temp\\file.txt");
#else
        /* FIX: Full path and file name */
        strcpy(data, "/tmp/file.txt");
#endif
    }
    {
        HANDLE hFile;
        /* POTENTIAL FLAW: Possibly creating and opening a file without validating the file name or path */
        hFile = CreateFileA(data,
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

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the if statement */
static void goodG2B2()
{
    char * data;
    char data_buf[FILENAME_MAX] = "";
    data = data_buf;
    if(static_const_t)
    {
#ifdef _WIN32
        /* FIX: Full path and file name */
        strcpy(data, "c:\\temp\\file.txt");
#else
        /* FIX: Full path and file name */
        strcpy(data, "/tmp/file.txt");
#endif
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* Read input from the console */
            size_t data_len = strlen(data);
            /* if there is room in data, read into it from the console */
            if(FILENAME_MAX-data_len > 1)
            {
                fgets(data+data_len, (int)(FILENAME_MAX-data_len), stdin);
                /* The next 3 lines remove the carriage return from the string that is
                 * inserted by fgets() */
                data_len = strlen(data);
                if (data_len > 0)
                {
                    data[data_len-1] = '\0';
                }
            }
        }
    }
    {
        HANDLE hFile;
        /* POTENTIAL FLAW: Possibly creating and opening a file without validating the file name or path */
        hFile = CreateFileA(data,
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

void CWE36_Absolute_Path_Traversal__char_fromConsole_w32CreateFile_04_good()
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
    CWE36_Absolute_Path_Traversal__char_fromConsole_w32CreateFile_04_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE36_Absolute_Path_Traversal__char_fromConsole_w32CreateFile_04_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
