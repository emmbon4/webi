/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE253_Incorrect_Check_of_Return_Value__wchar_t_w32CreateNamedPipe_04.c
Label Definition File: CWE253_Incorrect_Check_of_Return_Value.string.label.xml
Template File: point-flaw-04.tmpl.c
*/
/*
 * @description
 * CWE: 253 Incorrect Check of Return Value
 * Sinks: w32CreateNamedPipe
 *    GoodSink: Correctly check if CreateNamedPipeW() failed
 *    BadSink : Incorrectly check if CreateNamedPipeW() failed
 * Flow Variant: 04 Control flow: if(static_const_t) and if(static_const_f)
 *
 * */

#include "std_testcase.h"

#include <windows.h>
#define BUFSIZE 1024

/* The two variables below are declared "const", so a tool should
   be able to identify that reads of these will always return their
   initialized values. */
static const int static_const_t = 1; /* true */
static const int static_const_f = 0; /* false */

#ifndef OMITBAD

void CWE253_Incorrect_Check_of_Return_Value__wchar_t_w32CreateNamedPipe_04_bad()
{
    if(static_const_t)
    {
        {
            wchar_t * pipeName = L"\\\\.\\pipe\\mypipe";
            HANDLE hPipe = INVALID_HANDLE_VALUE;
            BOOL fConnected = FALSE;
            hPipe = CreateNamedPipeW(
                        pipeName,
                        FILE_FLAG_FIRST_PIPE_INSTANCE, /* FILE_FLAG_FIRST_PIPE_INSTANCE - this flag must be set */
                        PIPE_TYPE_MESSAGE |
                        PIPE_READMODE_MESSAGE |
                        PIPE_WAIT,
                        PIPE_UNLIMITED_INSTANCES,
                        BUFSIZE,
                        BUFSIZE,
                        NMPWAIT_USE_DEFAULT_WAIT,
                        NULL);
            /* FLAW: If CreateNamedPipeW() failed, the return value will be INVALID_HANDLE_VALUE,
               but we are checking to see if the return value is NULL */
            if (hPipe == NULL)
            {
                exit(1);
            }
            /* FLAW: If CreateNamedPipeW() failed, GetLastError() could return ERROR_ACCESS_DENIED
               but we are checking to see if the return value is negative */
            if (GetLastError() == -1)
            {
                exit(1);
            }
            fConnected = ConnectNamedPipe(hPipe, NULL) ? TRUE : (GetLastError() == ERROR_PIPE_CONNECTED);
            /* We'll leave out most of the implementation since it has nothing to do with the CWE
             * and since the checkers are looking for certain function calls anyway */
            CloseHandle(hPipe);
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            wchar_t * pipeName = L"\\\\.\\pipe\\mypipe";
            HANDLE hPipe = INVALID_HANDLE_VALUE;
            BOOL fConnected = FALSE;
            hPipe = CreateNamedPipeW(
                        pipeName,
                        FILE_FLAG_FIRST_PIPE_INSTANCE, /* FILE_FLAG_FIRST_PIPE_INSTANCE - this flag must be set */
                        PIPE_TYPE_MESSAGE |
                        PIPE_READMODE_MESSAGE |
                        PIPE_WAIT,
                        PIPE_UNLIMITED_INSTANCES,
                        BUFSIZE,
                        BUFSIZE,
                        NMPWAIT_USE_DEFAULT_WAIT,
                        NULL);
            /* FIX: check for the correct return value */
            if (hPipe == INVALID_HANDLE_VALUE)
            {
                exit(1);
            }
            /* FIX: check for the correct return value */
            if (GetLastError() == ERROR_ACCESS_DENIED)
            {
                exit(1);
            }
            fConnected = ConnectNamedPipe(hPipe, NULL) ? TRUE : (GetLastError() == ERROR_PIPE_CONNECTED);
            /* We'll leave out most of the implementation since it has nothing to do with the CWE
             * and since the checkers are looking for certain function calls anyway */
            CloseHandle(hPipe);
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() uses if(static_const_f) instead of if(static_const_t) */
static void good1()
{
    if(static_const_f)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            wchar_t * pipeName = L"\\\\.\\pipe\\mypipe";
            HANDLE hPipe = INVALID_HANDLE_VALUE;
            BOOL fConnected = FALSE;
            hPipe = CreateNamedPipeW(
                        pipeName,
                        FILE_FLAG_FIRST_PIPE_INSTANCE, /* FILE_FLAG_FIRST_PIPE_INSTANCE - this flag must be set */
                        PIPE_TYPE_MESSAGE |
                        PIPE_READMODE_MESSAGE |
                        PIPE_WAIT,
                        PIPE_UNLIMITED_INSTANCES,
                        BUFSIZE,
                        BUFSIZE,
                        NMPWAIT_USE_DEFAULT_WAIT,
                        NULL);
            /* FLAW: If CreateNamedPipeW() failed, the return value will be INVALID_HANDLE_VALUE,
               but we are checking to see if the return value is NULL */
            if (hPipe == NULL)
            {
                exit(1);
            }
            /* FLAW: If CreateNamedPipeW() failed, GetLastError() could return ERROR_ACCESS_DENIED
               but we are checking to see if the return value is negative */
            if (GetLastError() == -1)
            {
                exit(1);
            }
            fConnected = ConnectNamedPipe(hPipe, NULL) ? TRUE : (GetLastError() == ERROR_PIPE_CONNECTED);
            /* We'll leave out most of the implementation since it has nothing to do with the CWE
             * and since the checkers are looking for certain function calls anyway */
            CloseHandle(hPipe);
        }
    }
    else
    {
        {
            wchar_t * pipeName = L"\\\\.\\pipe\\mypipe";
            HANDLE hPipe = INVALID_HANDLE_VALUE;
            BOOL fConnected = FALSE;
            hPipe = CreateNamedPipeW(
                        pipeName,
                        FILE_FLAG_FIRST_PIPE_INSTANCE, /* FILE_FLAG_FIRST_PIPE_INSTANCE - this flag must be set */
                        PIPE_TYPE_MESSAGE |
                        PIPE_READMODE_MESSAGE |
                        PIPE_WAIT,
                        PIPE_UNLIMITED_INSTANCES,
                        BUFSIZE,
                        BUFSIZE,
                        NMPWAIT_USE_DEFAULT_WAIT,
                        NULL);
            /* FIX: check for the correct return value */
            if (hPipe == INVALID_HANDLE_VALUE)
            {
                exit(1);
            }
            /* FIX: check for the correct return value */
            if (GetLastError() == ERROR_ACCESS_DENIED)
            {
                exit(1);
            }
            fConnected = ConnectNamedPipe(hPipe, NULL) ? TRUE : (GetLastError() == ERROR_PIPE_CONNECTED);
            /* We'll leave out most of the implementation since it has nothing to do with the CWE
             * and since the checkers are looking for certain function calls anyway */
            CloseHandle(hPipe);
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(static_const_t)
    {
        {
            wchar_t * pipeName = L"\\\\.\\pipe\\mypipe";
            HANDLE hPipe = INVALID_HANDLE_VALUE;
            BOOL fConnected = FALSE;
            hPipe = CreateNamedPipeW(
                        pipeName,
                        FILE_FLAG_FIRST_PIPE_INSTANCE, /* FILE_FLAG_FIRST_PIPE_INSTANCE - this flag must be set */
                        PIPE_TYPE_MESSAGE |
                        PIPE_READMODE_MESSAGE |
                        PIPE_WAIT,
                        PIPE_UNLIMITED_INSTANCES,
                        BUFSIZE,
                        BUFSIZE,
                        NMPWAIT_USE_DEFAULT_WAIT,
                        NULL);
            /* FIX: check for the correct return value */
            if (hPipe == INVALID_HANDLE_VALUE)
            {
                exit(1);
            }
            /* FIX: check for the correct return value */
            if (GetLastError() == ERROR_ACCESS_DENIED)
            {
                exit(1);
            }
            fConnected = ConnectNamedPipe(hPipe, NULL) ? TRUE : (GetLastError() == ERROR_PIPE_CONNECTED);
            /* We'll leave out most of the implementation since it has nothing to do with the CWE
             * and since the checkers are looking for certain function calls anyway */
            CloseHandle(hPipe);
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            wchar_t * pipeName = L"\\\\.\\pipe\\mypipe";
            HANDLE hPipe = INVALID_HANDLE_VALUE;
            BOOL fConnected = FALSE;
            hPipe = CreateNamedPipeW(
                        pipeName,
                        FILE_FLAG_FIRST_PIPE_INSTANCE, /* FILE_FLAG_FIRST_PIPE_INSTANCE - this flag must be set */
                        PIPE_TYPE_MESSAGE |
                        PIPE_READMODE_MESSAGE |
                        PIPE_WAIT,
                        PIPE_UNLIMITED_INSTANCES,
                        BUFSIZE,
                        BUFSIZE,
                        NMPWAIT_USE_DEFAULT_WAIT,
                        NULL);
            /* FLAW: If CreateNamedPipeW() failed, the return value will be INVALID_HANDLE_VALUE,
               but we are checking to see if the return value is NULL */
            if (hPipe == NULL)
            {
                exit(1);
            }
            /* FLAW: If CreateNamedPipeW() failed, GetLastError() could return ERROR_ACCESS_DENIED
               but we are checking to see if the return value is negative */
            if (GetLastError() == -1)
            {
                exit(1);
            }
            fConnected = ConnectNamedPipe(hPipe, NULL) ? TRUE : (GetLastError() == ERROR_PIPE_CONNECTED);
            /* We'll leave out most of the implementation since it has nothing to do with the CWE
             * and since the checkers are looking for certain function calls anyway */
            CloseHandle(hPipe);
        }
    }
}

void CWE253_Incorrect_Check_of_Return_Value__wchar_t_w32CreateNamedPipe_04_good()
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
    CWE253_Incorrect_Check_of_Return_Value__wchar_t_w32CreateNamedPipe_04_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE253_Incorrect_Check_of_Return_Value__wchar_t_w32CreateNamedPipe_04_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
