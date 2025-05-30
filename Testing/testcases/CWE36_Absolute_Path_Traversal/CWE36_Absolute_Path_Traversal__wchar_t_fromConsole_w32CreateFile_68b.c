/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE36_Absolute_Path_Traversal__wchar_t_fromConsole_w32CreateFile_68b.c
Label Definition File: CWE36_Absolute_Path_Traversal.label.xml
Template File: sources-sink-68b.tmpl.c
*/
/*
 * @description
 * CWE: 36 Absolute Path Traversal
 * BadSource: fromConsole Read input from the console
 * GoodSource: Full path and file name
 * Sink: w32CreateFile
 *    BadSink :
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <windows.h>

extern wchar_t * CWE36_Absolute_Path_Traversal__wchar_t_fromConsole_w32CreateFile_68_bad_data;
extern wchar_t * CWE36_Absolute_Path_Traversal__wchar_t_fromConsole_w32CreateFile_68_goodG2B_data;

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

void CWE36_Absolute_Path_Traversal__wchar_t_fromConsole_w32CreateFile_68b_bad_sink()
{
    wchar_t * data = CWE36_Absolute_Path_Traversal__wchar_t_fromConsole_w32CreateFile_68_bad_data;
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

/* goodG2B uses the GoodSource with the BadSink */
void CWE36_Absolute_Path_Traversal__wchar_t_fromConsole_w32CreateFile_68b_goodG2B_sink()
{
    wchar_t * data = CWE36_Absolute_Path_Traversal__wchar_t_fromConsole_w32CreateFile_68_goodG2B_data;
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

#endif /* OMITGOOD */
