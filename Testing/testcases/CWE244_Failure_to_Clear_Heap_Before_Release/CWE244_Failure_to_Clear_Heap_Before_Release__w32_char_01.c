/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE244_Failure_to_Clear_Heap_Before_Release__w32_char_01.c
Label Definition File: CWE244_Failure_to_Clear_Heap_Before_Release__w32.label.xml
Template File: point-flaw-01.tmpl.c
*/
/*
 * @description
 * CWE: 244 Failure to Clear Heap Before Release
 * Sinks:
 *    GoodSink: Clear the password buffer before releasing the memory from the heap
 *    BadSink : Release password from the heap without first clearing the buffer
 * Flow Variant: 01 Baseline
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifdef _WIN32
# include <windows.h>
#pragma comment(lib, "advapi32.lib")
#endif

#ifndef OMITBAD

void CWE244_Failure_to_Clear_Heap_Before_Release__w32_char_01_bad()
{
    {
        char * password = (char *)malloc(100*sizeof(char));
        size_t password_len = 0;
        HANDLE pHandle;
        char * username = "User";
        char * domain = "Domain";
        /* Initialize password */
        password[0] = '\0';
        fgets(password, 100, stdin);
        /* Remove the carriage return from the string that is inserted by fgets() */
        password_len = strlen(password);
        if (password_len > 0)
        {
            password[password_len-1] = '\0';
        }
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
        /* FLAW: free() password without clearing the password buffer */
        free(password);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

static void good1()
{
    {
        char * password = (char *)malloc(100*sizeof(char));
        size_t password_len = 0;
        HANDLE pHandle;
        char * username = "User";
        char * domain = "Domain";
        /* Initialize password */
        password[0] = '\0';
        fgets(password, 100, stdin);
        /* Remove the carriage return from the string that is inserted by fgets() */
        password_len = strlen(password);
        if (password_len > 0)
        {
            password[password_len-1] = '\0';
        }
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
        password_len = strlen(password);
        /* FIX: Clear password prior to freeing */
        SecureZeroMemory(password, password_len * sizeof(char));
    }
}

void CWE244_Failure_to_Clear_Heap_Before_Release__w32_char_01_good()
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
    CWE244_Failure_to_Clear_Heap_Before_Release__w32_char_01_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE244_Failure_to_Clear_Heap_Before_Release__w32_char_01_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
