/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE535_Info_Leak_Shell_Error__w32_char_17.c
Label Definition File: CWE535_Info_Leak_Shell_Error__w32.label.xml
Template File: point-flaw-17.tmpl.c
*/
/*
 * @description
 * CWE: 535 Information Leak Through Shell Error Message
 * Sinks:
 *    GoodSink: Write to stderr, but do not write the password
 *    BadSink : Write to stderr and include the password
 * Flow Variant: 17 Control flow: for loops
 *
 * */

#include "std_testcase.h"

# include <wchar.h>

#ifdef _WIN32
#include <windows.h>
#pragma comment(lib, "advapi32.lib")
#endif

#ifndef OMITBAD

void CWE535_Info_Leak_Shell_Error__w32_char_17_bad()
{
    int j,k;
    for(j = 0; j < 1; j++)
    {
        {
#ifdef _WIN32 /* this is WIN32 specific */
            char password[100] = "";
            size_t password_len = 0;
            HANDLE pHandle;
            char * username = "User";
            char * domain = "Domain";
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
            /* FLAW: Write sensitive data to stderr */
            fprintf(stderr, "User attempted access with password: %s\n", password);
#endif
        }
    }
    for(k = 0; k < 0; k++)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
#ifdef _WIN32 /* this is WIN32 specific */
            char password[100] = "";
            size_t password_len = 0;
            HANDLE pHandle;
            char * username = "User";
            char * domain = "Domain";
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
            /* FIX: Do not write sensitive data to stderr */
            fprintf(stderr, "User attempted access\n");
#endif
        }
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
        {
#ifdef _WIN32 /* this is WIN32 specific */
            char password[100] = "";
            size_t password_len = 0;
            HANDLE pHandle;
            char * username = "User";
            char * domain = "Domain";
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
            /* FLAW: Write sensitive data to stderr */
            fprintf(stderr, "User attempted access with password: %s\n", password);
#endif
        }
    }
    for(k = 0; k < 1; k++)
    {
        {
#ifdef _WIN32 /* this is WIN32 specific */
            char password[100] = "";
            size_t password_len = 0;
            HANDLE pHandle;
            char * username = "User";
            char * domain = "Domain";
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
            /* FIX: Do not write sensitive data to stderr */
            fprintf(stderr, "User attempted access\n");
#endif
        }
    }
}

void CWE535_Info_Leak_Shell_Error__w32_char_17_good()
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
    CWE535_Info_Leak_Shell_Error__w32_char_17_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE535_Info_Leak_Shell_Error__w32_char_17_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
