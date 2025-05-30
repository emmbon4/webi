/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_68a.c
Label Definition File: CWE404_Improper_Resource_Shutdown.label.xml
Template File: source-sinks-68a.tmpl.c
*/
/*
 * @description
 * CWE: 404 Improper Resource Shutdown or Release
 * BadSource: freopen Open a file using freopen()
 * Sinks: w32CloseHandle
 *    GoodSink: Close the file using fclose()
 *    BadSink : Close the file using CloseHandle
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <windows.h>

FILE * CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_68_bad_data_for_bad_sink;

FILE * CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_68_bad_data_for_good_sink;

#ifndef OMITBAD

/* bad function declaration */
void CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_68b_bad_sink();

void CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_68_bad()
{
    FILE * data;
    /* Initialize data */
    data = NULL;
    data = freopen("BadSource_freopen.txt","w+",stdin);
    CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_68_bad_data_for_bad_sink = data;
    CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_68b_bad_sink();
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declarations */
void CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_68b_goodB2G_sink();

/* goodB2G uses the BadSource with the GoodSink */
static void goodB2G()
{
    FILE * data;
    /* Initialize data */
    data = NULL;
    data = freopen("BadSource_freopen.txt","w+",stdin);
    CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_68_bad_data_for_good_sink = data;
    CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_68b_goodB2G_sink();
}

void CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_68_good()
{
    goodB2G();
}

#endif /* OMITGOOD */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_68_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_68_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
