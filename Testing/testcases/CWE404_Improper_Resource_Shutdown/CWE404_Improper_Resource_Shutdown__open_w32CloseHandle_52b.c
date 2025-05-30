/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_52b.c
Label Definition File: CWE404_Improper_Resource_Shutdown__open.label.xml
Template File: source-sinks-52b.tmpl.c
*/
/*
 * @description
 * CWE: 404 Improper Resource Shutdown or Release
 * BadSource:  Open a file using open()
 * Sinks: w32CloseHandle
 *    GoodSink: Close the file using close()
 *    BadSink : Close the file using CloseHandle
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
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

/* bad function declaration */
void CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_52c_bad_sink(int data);

void CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_52b_bad_sink(int data)
{
    CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_52c_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G uses the BadSource with the GoodSink */
void CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_52c_goodB2G_sink(int data);

void CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_52b_goodB2G_sink(int data)
{
    CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_52c_goodB2G_sink(data);
}

#endif /* OMITGOOD */
