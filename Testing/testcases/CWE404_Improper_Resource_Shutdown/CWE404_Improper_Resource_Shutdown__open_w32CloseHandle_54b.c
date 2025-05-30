/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_54b.c
Label Definition File: CWE404_Improper_Resource_Shutdown__open.label.xml
Template File: source-sinks-54b.tmpl.c
*/
/*
 * @description
 * CWE: 404 Improper Resource Shutdown or Release
 * BadSource:  Open a file using open()
 * Sinks: w32CloseHandle
 *    GoodSink: Close the file using close()
 *    BadSink : Close the file using CloseHandle
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
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
void CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_54c_bad_sink(int data);

void CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_54b_bad_sink(int data)
{
    CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_54c_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G uses the BadSource with the GoodSink */
void CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_54c_goodB2G_sink(int data);

void CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_54b_goodB2G_sink(int data)
{
    CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_54c_goodB2G_sink(data);
}

#endif /* OMITGOOD */
