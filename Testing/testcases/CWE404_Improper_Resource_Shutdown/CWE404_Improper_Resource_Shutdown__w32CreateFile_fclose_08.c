/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_08.c
Label Definition File: CWE404_Improper_Resource_Shutdown__w32CreateFile.label.xml
Template File: source-sinks-08.tmpl.c
*/
/*
 * @description
 * CWE: 404 Improper Resource Shutdown or Release
 * BadSource:  Open a file using CreateFile()
 * Sinks: fclose
 *    GoodSink: Close the file using CloseHandle()
 *    BadSink : Close the file using fclose()
 * Flow Variant: 08 Control flow: if(static_returns_t()) and if(static_returns_f())
 *
 * */

#include "std_testcase.h"

#include <windows.h>

/* The two function below always return the same value, so a tool
   should be able to identify that calls to the functions will always
   return a fixed value. */
static int static_returns_t()
{
    return 1;
}

static int static_returns_f()
{
    return 0;
}

#ifndef OMITBAD

void CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_08_bad()
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
    if(static_returns_t())
    {
        if (data != INVALID_HANDLE_VALUE)
        {
            /* FLAW: Attempt to close the file using fclose() instead of CloseHandle() */
            fclose((FILE *)data);
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        if (data != INVALID_HANDLE_VALUE)
        {
            /* FIX: Close the file using CloseHandle() */
            CloseHandle(data);
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G1() - use badsource and goodsink by changing static_returns_t() to static_returns_f() */
static void goodB2G1()
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
    if(static_returns_f())
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        if (data != INVALID_HANDLE_VALUE)
        {
            /* FLAW: Attempt to close the file using fclose() instead of CloseHandle() */
            fclose((FILE *)data);
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

/* goodB2G2() - use badsource and goodsink by reversing statements in if  */
static void goodB2G2()
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
    if(static_returns_t())
    {
        if (data != INVALID_HANDLE_VALUE)
        {
            /* FIX: Close the file using CloseHandle() */
            CloseHandle(data);
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        if (data != INVALID_HANDLE_VALUE)
        {
            /* FLAW: Attempt to close the file using fclose() instead of CloseHandle() */
            fclose((FILE *)data);
        }
    }
}

void CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_08_good()
{
    goodB2G1();
    goodB2G2();
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
    CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_08_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_08_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
