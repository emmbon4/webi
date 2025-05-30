/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE272_Least_Privilege_Principal__wchar_t_w32RegOpenKeyEx_01.c
Label Definition File: CWE272_Least_Privilege_Principal.label.xml
Template File: point-flaw-01.tmpl.c
*/
/*
 * @description
 * CWE: 272 Least Privilege Principal
 * Sinks: w32RegOpenKeyEx
 *    GoodSink: Open a registry key using RegOpenKeyExW() and HKEY_CURRENT_USER
 *    BadSink : Open a registry key using RegOpenKeyExW() and HKEY_LOCAL_MACHINE
 * Flow Variant: 01 Baseline
 *
 * */

#include "std_testcase.h"

#include <windows.h>
#pragma comment( lib, "advapi32" )

#ifndef OMITBAD

void CWE272_Least_Privilege_Principal__wchar_t_w32RegOpenKeyEx_01_bad()
{
#ifdef _WIN32
    {
        wchar_t * key = L"TEST\\TestKey";
        HKEY hKey;

        /* FLAW: Call RegOpenKeyExW() with HKEY_LOCAL_MACHINE violating the least privilege principal */
        if (RegOpenKeyExW(
            HKEY_LOCAL_MACHINE,
            key,
            0,
            KEY_WRITE,
            &hKey) != ERROR_SUCCESS)
        {
            printLine("Registry key could not be opened");
        }
        else {
            printLine("Registry key opened successfully");
        }
    }
#endif
}

#endif /* OMITBAD */

#ifndef OMITGOOD

static void good1()
{
#ifdef _WIN32
    {
        wchar_t * key = L"TEST\\TestKey";
        HKEY hKey;

        /* FIX: Call RegOpenKeyExW() with HKEY_CURRENT_USER */
        if (RegOpenKeyExW(
            HKEY_CURRENT_USER,
            key,
            0,
            KEY_WRITE,
            &hKey) != ERROR_SUCCESS)
        {
            printLine("Registry key could not be opened");
        }
        else {
            printLine("Registry key opened successfully");
        }
    }
#endif
}

void CWE272_Least_Privilege_Principal__wchar_t_w32RegOpenKeyEx_01_good()
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
    CWE272_Least_Privilege_Principal__wchar_t_w32RegOpenKeyEx_01_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE272_Least_Privilege_Principal__wchar_t_w32RegOpenKeyEx_01_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
