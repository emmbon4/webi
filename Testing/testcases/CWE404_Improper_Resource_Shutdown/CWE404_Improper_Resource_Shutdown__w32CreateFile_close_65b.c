/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE404_Improper_Resource_Shutdown__w32CreateFile_close_65b.c
Label Definition File: CWE404_Improper_Resource_Shutdown__w32CreateFile.label.xml
Template File: source-sinks-65b.tmpl.c
*/
/*
 * @description
 * CWE: 404 Improper Resource Shutdown or Release
 * BadSource:  Open a file using CreateFile()
 * Sinks: close
 *    GoodSink: Close the file using CloseHandle()
 *    BadSink : Close the file using close()
 * Flow Variant: 65 Data/control flow: data passed as an argument from one function to a function in a different source file called via a function pointer
 *
 * */

#include "std_testcase.h"

#include <windows.h>

#ifdef _WIN32
# define CLOSE _close
#else
# define CLOSE close
#endif

#ifndef OMITBAD

void CWE404_Improper_Resource_Shutdown__w32CreateFile_close_65b_bad_sink(HANDLE data)
{
    if (data != INVALID_HANDLE_VALUE)
    {
        /* FLAW: Attempt to close the file using close() instead of CloseHandle() */
        CLOSE((int)data);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G uses the BadSource with the GoodSink */
void CWE404_Improper_Resource_Shutdown__w32CreateFile_close_65b_goodB2G_sink(HANDLE data)
{
    if (data != INVALID_HANDLE_VALUE)
    {
        /* FIX: Close the file using CloseHandle() */
        CloseHandle(data);
    }
}

#endif /* OMITGOOD */
