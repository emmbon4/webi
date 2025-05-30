/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE272_Least_Privilege_Principal__char_w32RegOpenKeyEx_19.c
Label Definition File: CWE272_Least_Privilege_Principal.label.xml
Template File: point-flaw-19.tmpl.c
*/
/*
 * @description
 * CWE: 272 Least Privilege Principal
 * Sinks: w32RegOpenKeyEx
 *    GoodSink: Open a registry key using RegOpenKeyExA() and HKEY_CURRENT_USER
 *    BadSink : Open a registry key using RegOpenKeyExA() and HKEY_LOCAL_MACHINE
 * Flow Variant: 19 Control flow: Dead code after a return
 *
 * */

#include "std_testcase.h"

#include <windows.h>
#pragma comment( lib, "advapi32" )

#ifndef OMITBAD

void CWE272_Least_Privilege_Principal__char_w32RegOpenKeyEx_19_bad()
{
#ifdef _WIN32
    {
        char * key = "TEST\\TestKey";
        HKEY hKey;

        /* FLAW: Call RegOpenKeyExA() with HKEY_LOCAL_MACHINE violating the least privilege principal */
        if (RegOpenKeyExA(
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
    return;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
#ifdef _WIN32
    {
        char * key = "TEST\\TestKey";
        HKEY hKey;
        /* FIX: Call RegOpenKeyExA() with HKEY_CURRENT_USER */
        if (RegOpenKeyExA(
                    HKEY_CURRENT_USER,
                    key,
                    0,
                    KEY_WRITE,
                    &hKey) != ERROR_SUCCESS)
        {
            printLine("Registry key could not be opened");
        }
        else
        {
            printLine("Registry key opened successfully");
        }
    }
#endif
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() reverses the GoodSinkBody and the BadSinkBody so that the BadSinkBody never runs */
static void good1()
{
#ifdef _WIN32
    {
        char * key = "TEST\\TestKey";
        HKEY hKey;

        /* FIX: Call RegOpenKeyExA() with HKEY_CURRENT_USER */
        if (RegOpenKeyExA(
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
    return;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
#ifdef _WIN32
    {
        char * key = "TEST\\TestKey";
        HKEY hKey;
        /* FLAW: Call RegOpenKeyExA() with HKEY_LOCAL_MACHINE violating the least privilege principal */
        if (RegOpenKeyExA(
                    HKEY_LOCAL_MACHINE,
                    key,
                    0,
                    KEY_WRITE,
                    &hKey) != ERROR_SUCCESS)
        {
            printLine("Registry key could not be opened");
        }
        else
        {
            printLine("Registry key opened successfully");
        }
    }
#endif
}

void CWE272_Least_Privilege_Principal__char_w32RegOpenKeyEx_19_good()
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
    CWE272_Least_Privilege_Principal__char_w32RegOpenKeyEx_19_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE272_Least_Privilege_Principal__char_w32RegOpenKeyEx_19_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
