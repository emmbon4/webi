/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE23_Relative_Path_Traversal__char_Environment_w32CreateFile_52c.c
Label Definition File: CWE23_Relative_Path_Traversal.label.xml
Template File: sources-sink-52c.tmpl.c
*/
/*
 * @description
 * CWE: 23 Relative Path Traversal
 * BadSource: Environment Read input from an environment variable
 * GoodSource: File name without a period or slash
 * Sink: w32CreateFile
 *    BadSink :
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
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

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

void CWE23_Relative_Path_Traversal__char_Environment_w32CreateFile_52c_bad_sink(char * data)
{
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

/* goodG2B uses the GoodSource with the BadSink */
void CWE23_Relative_Path_Traversal__char_Environment_w32CreateFile_52c_goodG2B_sink(char * data)
{
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

#endif /* OMITGOOD */
