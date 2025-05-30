/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE404_Improper_Resource_Shutdown__w32CreateFile_close_66a.c
Label Definition File: CWE404_Improper_Resource_Shutdown__w32CreateFile.label.xml
Template File: source-sinks-66a.tmpl.c
*/
/*
 * @description
 * CWE: 404 Improper Resource Shutdown or Release
 * BadSource:  Open a file using CreateFile()
 * Sinks: close
 *    GoodSink: Close the file using CloseHandle()
 *    BadSink : Close the file using close()
 * Flow Variant: 66 Data flow: data passed in an array from one function to another in different source files
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

/* bad function declaration */
void CWE404_Improper_Resource_Shutdown__w32CreateFile_close_66b_bad_sink(HANDLE data_array[]);

void CWE404_Improper_Resource_Shutdown__w32CreateFile_close_66_bad()
{
    HANDLE data;
    HANDLE data_array[5];
    /* Initialize data */
    data = INVALID_HANDLE_VALUE;
    data = CreateFile("BadSource_w32CreateFile.txt",
                      (GENERIC_WRITE|GENERIC_READ),
                      0,
                      NULL,
                      OPEN_ALWAYS,
                      FILE_ATTRIBUTE_NORMAL,
                      NULL);
    /* put data in array */
    data_array[2] = data;
    CWE404_Improper_Resource_Shutdown__w32CreateFile_close_66b_bad_sink(data_array);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G uses the BadSource with the GoodSink */
void CWE404_Improper_Resource_Shutdown__w32CreateFile_close_66b_goodB2G_sink(HANDLE data_array[]);

static void goodB2G()
{
    HANDLE data;
    HANDLE data_array[5];
    /* Initialize data */
    data = INVALID_HANDLE_VALUE;
    data = CreateFile("BadSource_w32CreateFile.txt",
                      (GENERIC_WRITE|GENERIC_READ),
                      0,
                      NULL,
                      OPEN_ALWAYS,
                      FILE_ATTRIBUTE_NORMAL,
                      NULL);
    data_array[2] = data;
    CWE404_Improper_Resource_Shutdown__w32CreateFile_close_66b_goodB2G_sink(data_array);
}

void CWE404_Improper_Resource_Shutdown__w32CreateFile_close_66_good()
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
    CWE404_Improper_Resource_Shutdown__w32CreateFile_close_66_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE404_Improper_Resource_Shutdown__w32CreateFile_close_66_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
