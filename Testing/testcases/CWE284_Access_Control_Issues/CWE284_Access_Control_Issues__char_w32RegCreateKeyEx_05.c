/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE284_Access_Control_Issues__char_w32RegCreateKeyEx_05.c
Label Definition File: CWE284_Access_Control_Issues.label.xml
Template File: point-flaw-05.tmpl.c
*/
/*
 * @description
 * CWE: 284 Access Control Issues
 * Sinks: w32RegCreateKeyEx
 *    GoodSink: Create a registry key using RegCreateKeyExA() without excessive privileges
 *    BadSink : Create a registry key using RegCreateKeyExA() with excessive privileges
 * Flow Variant: 05 Control flow: if(static_t) and if(static_f)
 *
 * */

#include "std_testcase.h"

#include <windows.h>
#pragma comment( lib, "advapi32" )

/* The two variables below are not defined as "const", but are never
   assigned any other value, so a tool should be able to identify that
   reads of these will always return their initialized values. */
static int static_t = 1; /* true */
static int static_f = 0; /* false */

#ifndef OMITBAD

void CWE284_Access_Control_Issues__char_w32RegCreateKeyEx_05_bad()
{
    if(static_t)
    {
#ifdef _WIN32
        {
            char * key = "TEST\\TestKey";
            HKEY hKey;

            /* FLAW: Call RegCreateKeyExA() with KEY_ALL_ACCESS as the 6th parameter */
            if (RegCreateKeyExA(
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
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
#ifdef _WIN32
        {
            char * key = "TEST\\TestKey";
            HKEY hKey;
            /* FIX: Call RegCreateKeyExA() without KEY_ALL_ACCESS as the 6th parameter to limit access */
            if (RegCreateKeyExA(
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

/* good1() uses if(static_f) instead of if(static_t) */
static void good1()
{
    if(static_f)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
#ifdef _WIN32
        {
            char * key = "TEST\\TestKey";
            HKEY hKey;
            /* FLAW: Call RegCreateKeyExA() with KEY_ALL_ACCESS as the 6th parameter */
            if (RegCreateKeyExA(
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
    else
    {
#ifdef _WIN32
        {
            char * key = "TEST\\TestKey";
            HKEY hKey;

            /* FIX: Call RegCreateKeyExA() without KEY_ALL_ACCESS as the 6th parameter to limit access */
            if (RegCreateKeyExA(
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

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(static_t)
    {
#ifdef _WIN32
        {
            char * key = "TEST\\TestKey";
            HKEY hKey;

            /* FIX: Call RegCreateKeyExA() without KEY_ALL_ACCESS as the 6th parameter to limit access */
            if (RegCreateKeyExA(
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
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
#ifdef _WIN32
        {
            char * key = "TEST\\TestKey";
            HKEY hKey;
            /* FLAW: Call RegCreateKeyExA() with KEY_ALL_ACCESS as the 6th parameter */
            if (RegCreateKeyExA(
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
}

void CWE284_Access_Control_Issues__char_w32RegCreateKeyEx_05_good()
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
    CWE284_Access_Control_Issues__char_w32RegCreateKeyEx_05_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE284_Access_Control_Issues__char_w32RegCreateKeyEx_05_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
