/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE36_Absolute_Path_Traversal__wchar_t_fromConsole_w32CreateFile_67b.c
Label Definition File: CWE36_Absolute_Path_Traversal.label.xml
Template File: sources-sink-67b.tmpl.c
*/
/*
 * @description
 * CWE: 36 Absolute Path Traversal
 * BadSource: fromConsole Read input from the console
 * GoodSource: Full path and file name
 * Sinks: w32CreateFile
 *    BadSink :
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <windows.h>

typedef struct _CWE36_Absolute_Path_Traversal__wchar_t_fromConsole_w32CreateFile_67_struct_type
{
    wchar_t * a;
} CWE36_Absolute_Path_Traversal__wchar_t_fromConsole_w32CreateFile_67_struct_type;

#ifndef OMITBAD

void CWE36_Absolute_Path_Traversal__wchar_t_fromConsole_w32CreateFile_67b_bad_sink(CWE36_Absolute_Path_Traversal__wchar_t_fromConsole_w32CreateFile_67_struct_type my_struct)
{
    wchar_t * data = my_struct.a;
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
void CWE36_Absolute_Path_Traversal__wchar_t_fromConsole_w32CreateFile_67b_goodG2B_sink(CWE36_Absolute_Path_Traversal__wchar_t_fromConsole_w32CreateFile_67_struct_type my_struct)
{
    wchar_t * data = my_struct.a;
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
