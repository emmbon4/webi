/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE404_Improper_Resource_Shutdown__w32CreateFile_close_12.c
Label Definition File: CWE404_Improper_Resource_Shutdown__w32CreateFile.label.xml
Template File: source-sinks-12.tmpl.c
*/
/*
 * @description
 * CWE: 404 Improper Resource Shutdown or Release
 * BadSource:  Open a file using CreateFile()
 * Sinks: close
 *    GoodSink: Close the file using CloseHandle()
 *    BadSink : Close the file using close()
 * Flow Variant: 12 Control flow: if(global_returns_t_or_f())
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

void CWE404_Improper_Resource_Shutdown__w32CreateFile_close_12_bad()
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
    if(global_returns_t_or_f())
    {
        if (data != INVALID_HANDLE_VALUE)
        {
            /* FLAW: Attempt to close the file using close() instead of CloseHandle() */
            CLOSE((int)data);
        }
    }
    else
    {
        if (data != INVALID_HANDLE_VALUE)
        {
            /* FIX: Close the file using CloseHandle() */
            CloseHandle(data);
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G() - use badsource and goodsink by changing the "if" so that
   both branches use the GoodSink */
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
    if(global_returns_t_or_f())
    {
        if (data != INVALID_HANDLE_VALUE)
        {
            /* FIX: Close the file using CloseHandle() */
            CloseHandle(data);
        }
    }
    else
    {
        if (data != INVALID_HANDLE_VALUE)
        {
            /* FIX: Close the file using CloseHandle() */
            CloseHandle(data);
        }
    }
}

void CWE404_Improper_Resource_Shutdown__w32CreateFile_close_12_good()
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
    CWE404_Improper_Resource_Shutdown__w32CreateFile_close_12_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE404_Improper_Resource_Shutdown__w32CreateFile_close_12_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
