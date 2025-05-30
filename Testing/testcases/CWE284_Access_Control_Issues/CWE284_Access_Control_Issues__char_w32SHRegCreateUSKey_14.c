/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE284_Access_Control_Issues__char_w32SHRegCreateUSKey_14.c
Label Definition File: CWE284_Access_Control_Issues.label.xml
Template File: point-flaw-14.tmpl.c
*/
/*
 * @description
 * CWE: 284 Access Control Issues
 * Sinks: w32SHRegCreateUSKey
 *    GoodSink: Create a registry key using SHRegCreateUSKeyA() without excessive privileges
 *    BadSink : Create a registry key using SHRegCreateUSKeyA() with excessive privileges
 * Flow Variant: 14 Control flow: if(global_five==5) and if(global_five!=5)
 *
 * */

#include "std_testcase.h"

#include <windows.h>
#pragma comment( lib, "shlwapi" )
#include <shlwapi.h>

#ifndef OMITBAD

void CWE284_Access_Control_Issues__char_w32SHRegCreateUSKey_14_bad()
{
    if(global_five==5)
    {
#ifdef _WIN32
        {
            char * key = "TEST\\TestKey";
            HUSKEY hKey = HKEY_CURRENT_USER;

            /* FLAW: Call SHRegCreateUSKeyA() with KEY_ALL_ACCESS as the 2nd parameter */
            if (SHRegCreateUSKeyA(
                key,
                KEY_ALL_ACCESS,
                NULL,
                &hKey,
                SHREGSET_HKCU) != ERROR_SUCCESS)
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
            HUSKEY hKey = HKEY_CURRENT_USER;
            /* FIX: Call SHRegCreateUSKeyA() without KEY_ALL_ACCESS as the 2nd parameter to limit access */
            if (SHRegCreateUSKeyA(
                        key,
                        KEY_WRITE,
                        NULL,
                        &hKey,
                        SHREGSET_HKCU) != ERROR_SUCCESS)
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

/* good1() uses if(global_five!=5) instead of if(global_five==5) */
static void good1()
{
    if(global_five!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
#ifdef _WIN32
        {
            char * key = "TEST\\TestKey";
            HUSKEY hKey = HKEY_CURRENT_USER;
            /* FLAW: Call SHRegCreateUSKeyA() with KEY_ALL_ACCESS as the 2nd parameter */
            if (SHRegCreateUSKeyA(
                        key,
                        KEY_ALL_ACCESS,
                        NULL,
                        &hKey,
                        SHREGSET_HKCU) != ERROR_SUCCESS)
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
            HUSKEY hKey = HKEY_CURRENT_USER;

            /* FIX: Call SHRegCreateUSKeyA() without KEY_ALL_ACCESS as the 2nd parameter to limit access */
            if (SHRegCreateUSKeyA(
                key,
                KEY_WRITE,
                NULL,
                &hKey,
                SHREGSET_HKCU) != ERROR_SUCCESS)
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
    if(global_five==5)
    {
#ifdef _WIN32
        {
            char * key = "TEST\\TestKey";
            HUSKEY hKey = HKEY_CURRENT_USER;

            /* FIX: Call SHRegCreateUSKeyA() without KEY_ALL_ACCESS as the 2nd parameter to limit access */
            if (SHRegCreateUSKeyA(
                key,
                KEY_WRITE,
                NULL,
                &hKey,
                SHREGSET_HKCU) != ERROR_SUCCESS)
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
            HUSKEY hKey = HKEY_CURRENT_USER;
            /* FLAW: Call SHRegCreateUSKeyA() with KEY_ALL_ACCESS as the 2nd parameter */
            if (SHRegCreateUSKeyA(
                        key,
                        KEY_ALL_ACCESS,
                        NULL,
                        &hKey,
                        SHREGSET_HKCU) != ERROR_SUCCESS)
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

void CWE284_Access_Control_Issues__char_w32SHRegCreateUSKey_14_good()
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
    CWE284_Access_Control_Issues__char_w32SHRegCreateUSKey_14_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE284_Access_Control_Issues__char_w32SHRegCreateUSKey_14_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
