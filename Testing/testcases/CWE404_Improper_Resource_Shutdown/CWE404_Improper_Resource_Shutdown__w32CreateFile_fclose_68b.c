/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_68b.c
Label Definition File: CWE404_Improper_Resource_Shutdown__w32CreateFile.label.xml
Template File: source-sinks-68b.tmpl.c
*/
/*
 * @description
 * CWE: 404 Improper Resource Shutdown or Release
 * BadSource:  Open a file using CreateFile()
 * Sinks: fclose
 *    GoodSink: Close the file using CloseHandle()
 *    BadSink : Close the file using fclose()
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <windows.h>

extern HANDLE CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_68_bad_data_for_bad_sink;

extern HANDLE CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_68_bad_data_for_good_sink;

#ifndef OMITBAD

void CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_68b_bad_sink()
{
    HANDLE data = CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_68_bad_data_for_bad_sink;
    if (data != INVALID_HANDLE_VALUE)
    {
        /* FLAW: Attempt to close the file using fclose() instead of CloseHandle() */
        fclose((FILE *)data);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

void CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_68b_goodB2G_sink()
{
    HANDLE data = CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_68_bad_data_for_good_sink;
    if (data != INVALID_HANDLE_VALUE)
    {
        /* FIX: Close the file using CloseHandle() */
        CloseHandle(data);
    }
}

#endif /* OMITGOOD */
