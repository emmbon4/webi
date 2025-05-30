/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__w32CreateFile_no_close_45.c
Label Definition File: CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__w32CreateFile_no_close.label.xml
Template File: source-sinks-45.tmpl.c
*/
/*
 * @description
 * CWE: 772 Missing Release of Resource after Effective Lifetime
 * BadSource:  Open a file using CreateFile()
 * Sinks:
 *    GoodSink: Close the file using CloseHandle()
 *    BadSink : Do not close file
 * Flow Variant: 45 Data flow: data passed as a static global variable from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

#include <windows.h>

static HANDLE CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__w32CreateFile_no_close_45_bad_data;
static HANDLE CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__w32CreateFile_no_close_45_goodB2G_data;

#ifndef OMITBAD

static void bad_sink()
{
    HANDLE data = CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__w32CreateFile_no_close_45_bad_data;
    /* FLAW: No attempt to close the file */
    ; /* empty statement needed for some flow variants */
}

void CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__w32CreateFile_no_close_45_bad()
{
    HANDLE data;
    /* Initialize data */
    data = INVALID_HANDLE_VALUE;
    data = CreateFile("BadSource_w32CreateFile.txt",
                      (GENERIC_WRITE|GENERIC_READ),
                      0,
                      NULL,
                      OPEN_ALWAYS,
                      FILE_ATTRIBUTE_NORMAL,
                      NULL);
    CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__w32CreateFile_no_close_45_bad_data = data;
    bad_sink();
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G() uses the BadSource with the GoodSink */
static void goodB2G_sink()
{
    HANDLE data = CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__w32CreateFile_no_close_45_goodB2G_data;
    /* FIX: If the file is still opened, close it */
    if (data != INVALID_HANDLE_VALUE)
    {
        CloseHandle(data);
    }
}

static void goodB2G()
{
    HANDLE data;
    /* Initialize data */
    data = INVALID_HANDLE_VALUE;
    data = CreateFile("BadSource_w32CreateFile.txt",
                      (GENERIC_WRITE|GENERIC_READ),
                      0,
                      NULL,
                      OPEN_ALWAYS,
                      FILE_ATTRIBUTE_NORMAL,
                      NULL);
    CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__w32CreateFile_no_close_45_goodB2G_data = data;
    goodB2G_sink();
}

void CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__w32CreateFile_no_close_45_good()
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
    CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__w32CreateFile_no_close_45_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__w32CreateFile_no_close_45_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
