/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE284_Access_Control_Issues__char_w32CreateWindowStation_03.c
Label Definition File: CWE284_Access_Control_Issues.label.xml
Template File: point-flaw-03.tmpl.c
*/
/*
 * @description
 * CWE: 284 Access Control Issues
 * Sinks: w32CreateWindowStation
 *    GoodSink: Create a windows station using CreateWindowStationA() without excessive privileges
 *    BadSink : Create a windows station using CreateWindowStationA() with excessive privileges
 * Flow Variant: 03 Control flow: if(5==5) and if(5!=5)
 *
 * */

#include "std_testcase.h"

#include <windows.h>
#pragma comment( lib, "user32" )

#ifndef OMITBAD

void CWE284_Access_Control_Issues__char_w32CreateWindowStation_03_bad()
{
    if(5==5)
    {
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
            else {
                printLine("Windows Station created successfully");
                CloseWindowStation(hWStation);
            }
        }
#endif
    }
    else
    {
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
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() uses if(5!=5) instead of if(5==5) */
static void good1()
{
    if(5!=5)
    {
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
    }
    else
    {
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
            else {
                printLine("Windows Station created successfully");
                CloseWindowStation(hWStation);
            }
        }
#endif
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(5==5)
    {
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
            else {
                printLine("Windows Station created successfully");
                CloseWindowStation(hWStation);
            }
        }
#endif
    }
    else
    {
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
    }
}

void CWE284_Access_Control_Issues__char_w32CreateWindowStation_03_good()
{
    good1();
    good2();
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
    CWE284_Access_Control_Issues__char_w32CreateWindowStation_03_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE284_Access_Control_Issues__char_w32CreateWindowStation_03_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
