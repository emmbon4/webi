/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__w32CreateFile_no_close_52c.c
Label Definition File: CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__w32CreateFile_no_close.label.xml
Template File: source-sinks-52c.tmpl.c
*/
/*
 * @description
 * CWE: 772 Missing Release of Resource after Effective Lifetime
 * BadSource:  Open a file using CreateFile()
 * Sinks:
 *    GoodSink: Close the file using CloseHandle()
 *    BadSink : Do not close file
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"

#include <windows.h>

#ifndef OMITBAD

void CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__w32CreateFile_no_close_52c_bad_sink(HANDLE data)
{
    /* FLAW: No attempt to close the file */
    ; /* empty statement needed for some flow variants */
}

#endif /* OMITBAD */

#ifndef OMITGOOD

void CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__w32CreateFile_no_close_52c_goodB2G_sink(HANDLE data)
{
    /* FIX: If the file is still opened, close it */
    if (data != INVALID_HANDLE_VALUE)
    {
        CloseHandle(data);
    }
}

#endif /* OMITGOOD */
