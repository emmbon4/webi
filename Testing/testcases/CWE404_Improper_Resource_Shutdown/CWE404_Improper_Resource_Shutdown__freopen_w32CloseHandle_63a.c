/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_63a.c
Label Definition File: CWE404_Improper_Resource_Shutdown.label.xml
Template File: source-sinks-63a.tmpl.c
*/
/*
 * @description
 * CWE: 404 Improper Resource Shutdown or Release
 * BadSource: freopen Open a file using freopen()
 * Sinks: w32CloseHandle
 *    GoodSink: Close the file using fclose()
 *    BadSink : Close the file using CloseHandle
 * Flow Variant: 63 Data flow: pointer to data passed from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <windows.h>

#ifndef OMITBAD

/* bad function declaration */
void CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_63b_bad_sink(FILE * * data_ptr);

void CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_63_bad()
{
    FILE * data;
    /* Initialize data */
    data = NULL;
    data = freopen("BadSource_freopen.txt","w+",stdin);
    CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_63b_bad_sink(&data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G uses the BadSource with the GoodSink */
void CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_63b_goodB2G_sink(FILE * * data);

static void goodB2G()
{
    FILE * data;
    /* Initialize data */
    data = NULL;
    data = freopen("BadSource_freopen.txt","w+",stdin);
    CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_63b_goodB2G_sink(&data);
}

void CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_63_good()
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
    CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_63_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_63_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
