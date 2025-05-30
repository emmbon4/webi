/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE284_Access_Control_Issues__wchar_t_w32RegCreateKeyEx_17.c
Label Definition File: CWE284_Access_Control_Issues.label.xml
Template File: point-flaw-17.tmpl.c
*/
/*
 * @description
 * CWE: 284 Access Control Issues
 * Sinks: w32RegCreateKeyEx
 *    GoodSink: Create a registry key using RegCreateKeyExW() without excessive privileges
 *    BadSink : Create a registry key using RegCreateKeyExW() with excessive privileges
 * Flow Variant: 17 Control flow: for loops
 *
 * */

#include "std_testcase.h"

#include <windows.h>
#pragma comment( lib, "advapi32" )

#ifndef OMITBAD

void CWE284_Access_Control_Issues__wchar_t_w32RegCreateKeyEx_17_bad()
{
    int j,k;
    for(j = 0; j < 1; j++)
    {
#ifdef _WIN32
        {
            wchar_t * key = L"TEST\\TestKey";
            HKEY hKey;

            /* FLAW: Call RegCreateKeyExW() with KEY_ALL_ACCESS as the 6th parameter */
            if (RegCreateKeyExW(
                HKEY_CURRENT_USER,
                key,
                0,
                NULL,
                REG_OPTION_NON_VOLATILE,
                KEY_ALL_ACCESS,
                NULL,
                &hKey,
                NULL) != ERROR_SUCCESS)
            {
                printLine("Registry key could not be created");
            }
            else {
                printLine("Registry key created successfully");
            }
        }
#endif
    }
    for(k = 0; k < 0; k++)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
#ifdef _WIN32
        {
            wchar_t * key = L"TEST\\TestKey";
            HKEY hKey;
            /* FIX: Call RegCreateKeyExW() without KEY_ALL_ACCESS as the 6th parameter to limit access */
            if (RegCreateKeyExW(
                        HKEY_CURRENT_USER,
                        key,
                        0,
                        NULL,
                        REG_OPTION_NON_VOLATILE,
                        KEY_WRITE,
                        NULL,
                        &hKey,
                        NULL) != ERROR_SUCCESS)
            {
                printLine("Registry key could not be created");
            }
            else
            {
                printLine("Registry key created successfully");
            }
        }
#endif
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() changes the conditions on the for statements */
static void good1()
{
    int j,k;
    for(j = 0; j < 0; j++)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
#ifdef _WIN32
        {
            wchar_t * key = L"TEST\\TestKey";
            HKEY hKey;
            /* FLAW: Call RegCreateKeyExW() with KEY_ALL_ACCESS as the 6th parameter */
            if (RegCreateKeyExW(
                        HKEY_CURRENT_USER,
                        key,
                        0,
                        NULL,
                        REG_OPTION_NON_VOLATILE,
                        KEY_ALL_ACCESS,
                        NULL,
                        &hKey,
                        NULL) != ERROR_SUCCESS)
            {
                printLine("Registry key could not be created");
            }
            else
            {
                printLine("Registry key created successfully");
            }
        }
#endif
    }
    for(k = 0; k < 1; k++)
    {
#ifdef _WIN32
        {
            wchar_t * key = L"TEST\\TestKey";
            HKEY hKey;

            /* FIX: Call RegCreateKeyExW() without KEY_ALL_ACCESS as the 6th parameter to limit access */
            if (RegCreateKeyExW(
                HKEY_CURRENT_USER,
                key,
                0,
                NULL,
                REG_OPTION_NON_VOLATILE,
                KEY_WRITE,
                NULL,
                &hKey,
                NULL) != ERROR_SUCCESS)
            {
                printLine("Registry key could not be created");
            }
            else {
                printLine("Registry key created successfully");
            }
        }
#endif
    }
}

void CWE284_Access_Control_Issues__wchar_t_w32RegCreateKeyEx_17_good()
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
    CWE284_Access_Control_Issues__wchar_t_w32RegCreateKeyEx_17_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE284_Access_Control_Issues__wchar_t_w32RegCreateKeyEx_17_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
