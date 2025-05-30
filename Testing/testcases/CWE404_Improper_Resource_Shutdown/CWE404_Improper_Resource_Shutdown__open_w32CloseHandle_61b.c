/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_61b.c
Label Definition File: CWE404_Improper_Resource_Shutdown__open.label.xml
Template File: source-sinks-61b.tmpl.c
*/
/*
 * @description
 * CWE: 404 Improper Resource Shutdown or Release
 * BadSource:  Open a file using open()
 * Sinks: w32CloseHandle
 *    GoodSink: Close the file using close()
 *    BadSink : Close the file using CloseHandle
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
# define OPEN _open
# define CLOSE _close
#else
# define OPEN open
# define CLOSE close
#endif

#include <windows.h>

#ifndef OMITBAD

int CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_61b_bad_source(int data)
{
    data = OPEN("BadSource_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE);
    return data;
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G() uses the BadSource with the GoodSink */
int CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_61b_goodB2G_source(int data)
{
    data = OPEN("BadSource_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE);
    return data;
}

#endif /* OMITGOOD */
