/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE272_Least_Privilege_Principal__wchar_t_w32RegCreateKey_06.c
Label Definition File: CWE272_Least_Privilege_Principal.label.xml
Template File: point-flaw-06.tmpl.c
*/
/*
 * @description
 * CWE: 272 Least Privilege Principal
 * Sinks: w32RegCreateKey
 *    GoodSink: Create a registry key using RegCreateKeyW() and HKEY_CURRENT_USER
 *    BadSink : Create a registry key using RegCreateKeyW() and HKEY_LOCAL_MACHINE
 * Flow Variant: 06 Control flow: if(static_const_five==5) and if(static_const_five!=5)
 *
 * */

#include "std_testcase.h"

#include <windows.h>
#pragma comment( lib, "advapi32" )

/* The variable below is declared "const", so a tool should be able
   to identify that reads of this will always give its initialized
   value. */
static const int static_const_five = 5;

#ifndef OMITBAD

void CWE272_Least_Privilege_Principal__wchar_t_w32RegCreateKey_06_bad()
{
    if(static_const_five==5)
    {
#ifdef _WIN32
        {
            wchar_t * key = L"TEST\\TestKey";
            HKEY hKey;

            /* FLAW: Call RegCreateKeyW() with HKEY_LOCAL_MACHINE violating the least privilege principal */
            if (RegCreateKeyW(
                HKEY_LOCAL_MACHINE,
                key,
                &hKey) != ERROR_SUCCESS)
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
            HKEY hKey;
            /* FIX: Call RegCreateKeyW() with HKEY_CURRENT_USER */
            if (RegCreateKeyW(
                        HKEY_CURRENT_USER,
                        key,
                        &hKey) != ERROR_SUCCESS)
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

/* good1() uses if(static_const_five!=5) instead of if(static_const_five==5) */
static void good1()
{
    if(static_const_five!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
#ifdef _WIN32
        {
            wchar_t * key = L"TEST\\TestKey";
            HKEY hKey;
            /* FLAW: Call RegCreateKeyW() with HKEY_LOCAL_MACHINE violating the least privilege principal */
            if (RegCreateKeyW(
                        HKEY_LOCAL_MACHINE,
                        key,
                        &hKey) != ERROR_SUCCESS)
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
            HKEY hKey;

            /* FIX: Call RegCreateKeyW() with HKEY_CURRENT_USER */
            if (RegCreateKeyW(
                HKEY_CURRENT_USER,
                key,
                &hKey) != ERROR_SUCCESS)
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
    if(static_const_five==5)
    {
#ifdef _WIN32
        {
            wchar_t * key = L"TEST\\TestKey";
            HKEY hKey;

            /* FIX: Call RegCreateKeyW() with HKEY_CURRENT_USER */
            if (RegCreateKeyW(
                HKEY_CURRENT_USER,
                key,
                &hKey) != ERROR_SUCCESS)
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
            HKEY hKey;
            /* FLAW: Call RegCreateKeyW() with HKEY_LOCAL_MACHINE violating the least privilege principal */
            if (RegCreateKeyW(
                        HKEY_LOCAL_MACHINE,
                        key,
                        &hKey) != ERROR_SUCCESS)
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

void CWE272_Least_Privilege_Principal__wchar_t_w32RegCreateKey_06_good()
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
    CWE272_Least_Privilege_Principal__wchar_t_w32RegCreateKey_06_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE272_Least_Privilege_Principal__wchar_t_w32RegCreateKey_06_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
