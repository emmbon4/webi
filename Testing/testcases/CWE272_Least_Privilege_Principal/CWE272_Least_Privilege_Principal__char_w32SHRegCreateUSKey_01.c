/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE272_Least_Privilege_Principal__char_w32SHRegCreateUSKey_01.c
Label Definition File: CWE272_Least_Privilege_Principal.label.xml
Template File: point-flaw-01.tmpl.c
*/
/*
 * @description
 * CWE: 272 Least Privilege Principal
 * Sinks: w32SHRegCreateUSKey
 *    GoodSink: Create a registry key using SHRegCreateUSKeyA() and HKEY_CURRENT_USER
 *    BadSink : Create a registry key using SHRegCreateUSKeyA() and HKEY_LOCAL_MACHINE
 * Flow Variant: 01 Baseline
 *
 * */

#include "std_testcase.h"

#include <windows.h>
#include <shlwapi.h>
#pragma comment( lib, "shlwapi" )

#ifndef OMITBAD

void CWE272_Least_Privilege_Principal__char_w32SHRegCreateUSKey_01_bad()
{
#ifdef _WIN32
    {
        char * key = "TEST\\TestKey";
        HUSKEY hKey = HKEY_LOCAL_MACHINE;

        /* FLAW: Call SHRegCreateUSKeyA() with HKEY_LOCAL_MACHINE violating the least privilege principal */
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

#endif /* OMITBAD */

#ifndef OMITGOOD

static void good1()
{
#ifdef _WIN32
    {
        char * key = "TEST\\TestKey";
        HUSKEY hKey = HKEY_CURRENT_USER;

        /* FIX: Call SHRegCreateUSKeyA() with HKEY_CURRENT_USER */
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

void CWE272_Least_Privilege_Principal__char_w32SHRegCreateUSKey_01_good()
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
    CWE272_Least_Privilege_Principal__char_w32SHRegCreateUSKey_01_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE272_Least_Privilege_Principal__char_w32SHRegCreateUSKey_01_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
