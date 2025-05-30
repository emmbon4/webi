/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__w32CreateFile_no_close_64b.c
Label Definition File: CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__w32CreateFile_no_close.label.xml
Template File: source-sinks-64b.tmpl.c
*/
/*
 * @description
 * CWE: 772 Missing Release of Resource after Effective Lifetime
 * BadSource:  Open a file using CreateFile()
 * Sinks:
 *    GoodSink: Close the file using CloseHandle()
 *    BadSink : Do not close file
 * Flow Variant: 64 Data flow: void pointer to data passed from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <windows.h>

#ifndef OMITBAD

void CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__w32CreateFile_no_close_64b_bad_sink(void * void_data_ptr)
{
    /* cast void pointer to a pointer of the appropriate type */
    HANDLE * data_ptr = (HANDLE *)void_data_ptr;
    /* dereference data_ptr into data */
    HANDLE data = (*data_ptr);
    /* FLAW: No attempt to close the file */
    ; /* empty statement needed for some flow variants */
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G uses the BadSource with the GoodSink */
void CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__w32CreateFile_no_close_64b_goodB2G_sink(void * void_data_ptr)
{
    /* cast void pointer to a pointer of the appropriate type */
    HANDLE * data_ptr = (HANDLE *)void_data_ptr;
    /* dereference data_ptr into data */
    HANDLE data = (*data_ptr);
    /* FIX: If the file is still opened, close it */
    if (data != INVALID_HANDLE_VALUE)
    {
        CloseHandle(data);
    }
}

#endif /* OMITGOOD */
