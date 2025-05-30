/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE272_Least_Privilege_Principal__wchar_t_w32SHRegCreateUSKey_08.c
Label Definition File: CWE272_Least_Privilege_Principal.label.xml
Template File: point-flaw-08.tmpl.c
*/
/*
 * @description
 * CWE: 272 Least Privilege Principal
 * Sinks: w32SHRegCreateUSKey
 *    GoodSink: Create a registry key using SHRegCreateUSKeyW() and HKEY_CURRENT_USER
 *    BadSink : Create a registry key using SHRegCreateUSKeyW() and HKEY_LOCAL_MACHINE
 * Flow Variant: 08 Control flow: if(static_returns_t()) and if(static_returns_f())
 *
 * */

#include "std_testcase.h"

#include <windows.h>
#include <shlwapi.h>
#pragma comment( lib, "shlwapi" )

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

void CWE272_Least_Privilege_Principal__wchar_t_w32SHRegCreateUSKey_08_bad()
{
    if(static_returns_t())
    {
#ifdef _WIN32
        {
            wchar_t * key = L"TEST\\TestKey";
            HUSKEY hKey = HKEY_LOCAL_MACHINE;

            /* FLAW: Call SHRegCreateUSKeyW() with HKEY_LOCAL_MACHINE violating the least privilege principal */
            if (SHRegCreateUSKeyW(
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
            wchar_t * key = L"TEST\\TestKey";
            HUSKEY hKey = HKEY_CURRENT_USER;
            /* FIX: Call SHRegCreateUSKeyW() with HKEY_CURRENT_USER */
            if (SHRegCreateUSKeyW(
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

/* good1() uses if(static_returns_f()) instead of if(static_returns_t()) */
static void good1()
{
    if(static_returns_f())
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
#ifdef _WIN32
        {
            wchar_t * key = L"TEST\\TestKey";
            HUSKEY hKey = HKEY_LOCAL_MACHINE;
            /* FLAW: Call SHRegCreateUSKeyW() with HKEY_LOCAL_MACHINE violating the least privilege principal */
            if (SHRegCreateUSKeyW(
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
    else
    {
#ifdef _WIN32
        {
            wchar_t * key = L"TEST\\TestKey";
            HUSKEY hKey = HKEY_CURRENT_USER;

            /* FIX: Call SHRegCreateUSKeyW() with HKEY_CURRENT_USER */
            if (SHRegCreateUSKeyW(
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
    if(static_returns_t())
    {
#ifdef _WIN32
        {
            wchar_t * key = L"TEST\\TestKey";
            HUSKEY hKey = HKEY_CURRENT_USER;

            /* FIX: Call SHRegCreateUSKeyW() with HKEY_CURRENT_USER */
            if (SHRegCreateUSKeyW(
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
            wchar_t * key = L"TEST\\TestKey";
            HUSKEY hKey = HKEY_LOCAL_MACHINE;
            /* FLAW: Call SHRegCreateUSKeyW() with HKEY_LOCAL_MACHINE violating the least privilege principal */
            if (SHRegCreateUSKeyW(
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

void CWE272_Least_Privilege_Principal__wchar_t_w32SHRegCreateUSKey_08_good()
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
    CWE272_Least_Privilege_Principal__wchar_t_w32SHRegCreateUSKey_08_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE272_Least_Privilege_Principal__wchar_t_w32SHRegCreateUSKey_08_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
