/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_char_31.c
Label Definition File: CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32.label.xml
Template File: sources-sink-31.tmpl.c
*/
/*
 * @description
 * CWE: 591 Sensitive Data Storage in Improperly Locked Memory
 * BadSource:  Allocate memory for sensitive data and use VirtualLock() to lock the buffer into memory
 * GoodSource: Allocate memory for sensitive data and use VirtualLock() to lock the buffer into memory
 * Sinks:
 *    BadSink : Authenticate the user using LogonUserA()
 * Flow Variant: 31 Data flow using a copy of data within the same function
 *
 * */

#include "std_testcase.h"

#include <wchar.h>
#ifdef _WIN32
#include <windows.h>
#endif

#ifdef _WIN32
#pragma comment(lib, "advapi32.lib")
#endif

#ifndef OMITBAD

void CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_char_31_bad()
{
    char * password;
    /* Initialize Data */
    password = "";
    password = (char *)malloc(100*sizeof(char));
    /* FLAW: Do not lock the memory */
    /* INCIDENTAL FLAW: CWE-259 Hardcoded Password */
    strcpy(password, "Password1234!");
    {
        char * password_copy = password;
        char * password = password_copy;
        {
#ifdef _WIN32 /* this is WIN32 specific */
            HANDLE pHandle;
            char * username = "User";
            char * domain = "Domain";
            /* Use the password in LogonUser() to establish that it is "sensitive" */
            if (LogonUserA(
                        username,
                        domain,
                        password,
                        LOGON32_LOGON_NETWORK,
                        LOGON32_PROVIDER_DEFAULT,
                        &pHandle) != 0)
            {
                printLine("User logged in successfully.");
                CloseHandle(pHandle);
            }
            else
            {
                printLine("Unable to login.");
            }
            /* POTENTIAL FLAW: Sensitive data possibly improperly locked */
#endif
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    char * password;
    /* Initialize Data */
    password = "";
#ifdef _WIN32 /* this is WIN32 specific */
    password = (char *)malloc(100*sizeof(char));
    /* FIX: Use VirtualLock() to lock the buffer into memory */
    if(!VirtualLock(password, 100*sizeof(char)))
    {
        printLine("Memory could not be locked");
        exit(1);
    }
    /* INCIDENTAL FLAW: CWE-259 Hardcoded Password */
    strcpy(password, "Password1234!");
#endif
    {
        char * password_copy = password;
        char * password = password_copy;
        {
#ifdef _WIN32 /* this is WIN32 specific */
            HANDLE pHandle;
            char * username = "User";
            char * domain = "Domain";
            /* Use the password in LogonUser() to establish that it is "sensitive" */
            if (LogonUserA(
                        username,
                        domain,
                        password,
                        LOGON32_LOGON_NETWORK,
                        LOGON32_PROVIDER_DEFAULT,
                        &pHandle) != 0)
            {
                printLine("User logged in successfully.");
                CloseHandle(pHandle);
            }
            else
            {
                printLine("Unable to login.");
            }
            /* POTENTIAL FLAW: Sensitive data possibly improperly locked */
#endif
        }
    }
}

void CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_char_31_good()
{
    goodG2B();
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
    CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_char_31_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_char_31_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
