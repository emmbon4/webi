/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE284_Access_Control_Issues__char_w32CreateWindowStation_18.c
Label Definition File: CWE284_Access_Control_Issues.label.xml
Template File: point-flaw-18.tmpl.c
*/
/*
 * @description
 * CWE: 284 Access Control Issues
 * Sinks: w32CreateWindowStation
 *    GoodSink: Create a windows station using CreateWindowStationA() without excessive privileges
 *    BadSink : Create a windows station using CreateWindowStationA() with excessive privileges
 * Flow Variant: 18 Control flow: goto statements
 *
 * */

#include "std_testcase.h"

#include <windows.h>
#pragma comment( lib, "user32" )

#ifndef OMITBAD

void CWE284_Access_Control_Issues__char_w32CreateWindowStation_18_bad()
{
    goto sink;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
#ifdef _WIN32
    {
        HWINSTA hWStation;
        char * wStationName = "WindowsStationExample";
        /* FIX: Call CreateWindowStationA() without GENERIC_READ as the 3rd parameter to limit access */
        hWStation = CreateWindowStationA(
                        wStationName,
                        0,
                        GENERIC_READ,
                        NULL);
        if (hWStation == NULL)
        {
            printLine("Windows station could not be created");
        }
        else
        {
            printLine("Windows Station created successfully");
            CloseWindowStation(hWStation);
        }
    }
#endif
sink:
#ifdef _WIN32
    {
        HWINSTA hWStation;
        char * wStationName = "WindowsStationExample";
        /* FLAW: Call CreateWindowStationA() with GENERIC_ALL as the 3rd parameter */
        hWStation = CreateWindowStationA(
                        wStationName,
                        0,
                        GENERIC_ALL,
                        NULL);
        if (hWStation == NULL)
        {
            printLine("Windows station could not be created");
        }
        else
        {
            printLine("Windows Station created successfully");
            CloseWindowStation(hWStation);
        }
    }
#endif
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() reverses the blocks on the goto statement */
static void good1()
{
    goto sink;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
#ifdef _WIN32
    {
        HWINSTA hWStation;
        char * wStationName = "WindowsStationExample";
        /* FLAW: Call CreateWindowStationA() with GENERIC_ALL as the 3rd parameter */
        hWStation = CreateWindowStationA(
                        wStationName,
                        0,
                        GENERIC_ALL,
                        NULL);
        if (hWStation == NULL)
        {
            printLine("Windows station could not be created");
        }
        else
        {
            printLine("Windows Station created successfully");
            CloseWindowStation(hWStation);
        }
    }
#endif
sink:
#ifdef _WIN32
    {
        HWINSTA hWStation;
        char * wStationName = "WindowsStationExample";
        /* FIX: Call CreateWindowStationA() without GENERIC_READ as the 3rd parameter to limit access */
        hWStation = CreateWindowStationA(
                        wStationName,
                        0,
                        GENERIC_READ,
                        NULL);
        if (hWStation == NULL)
        {
            printLine("Windows station could not be created");
        }
        else
        {
            printLine("Windows Station created successfully");
            CloseWindowStation(hWStation);
        }
    }
#endif
}

void CWE284_Access_Control_Issues__char_w32CreateWindowStation_18_good()
{
    good1();
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
    CWE284_Access_Control_Issues__char_w32CreateWindowStation_18_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE284_Access_Control_Issues__char_w32CreateWindowStation_18_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
