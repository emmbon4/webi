/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE253_Incorrect_Check_of_Return_Value__char_w32CreateMutex_16.c
Label Definition File: CWE253_Incorrect_Check_of_Return_Value.string.label.xml
Template File: point-flaw-16.tmpl.c
*/
/*
 * @description
 * CWE: 253 Incorrect Check of Return Value
 * Sinks: w32CreateMutex
 *    GoodSink: Correctly check if CreateMutexA() failed
 *    BadSink : Incorrectly check if CreateMutexA() failed
 * Flow Variant: 16 Control flow: while(1) and while(0)
 *
 * */

#include "std_testcase.h"

#include <windows.h>
#define BUFSIZE 1024

#ifndef OMITBAD

void CWE253_Incorrect_Check_of_Return_Value__char_w32CreateMutex_16_bad()
{
    while(1)
    {
        {
            HANDLE hMutex = NULL;
            hMutex = CreateMutexA(NULL, FALSE, NULL);
            /* FLAW: If CreateMutexA() failed, the return value will be NULL,
               but we are checking to see if the return value is INVALID_HANDLE_VALUE */
            if (hMutex == INVALID_HANDLE_VALUE)
            {
                exit(1);
            }
            /* FLAW: If CreateMutexA() failed, GetLastError() could return ERROR_ACCESS_DENIED
               but we are checking to see if the return value is negative */
            if (GetLastError() == -1)
            {
                exit(1);
            }
            /* We'll leave out most of the implementation since it has nothing to do with the CWE
             * and since the checkers are looking for certain function calls anyway */
            CloseHandle(hMutex);
        }
        break;
    }
    while(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            HANDLE hMutex = NULL;
            hMutex = CreateMutexA(NULL, FALSE, NULL);
            /* FIX: check for the correct return value */
            if (hMutex == NULL)
            {
                exit(1);
            }
            /* FIX: check for the correct return value */
            if (GetLastError() == ERROR_ALREADY_EXISTS)
            {
                exit(1);
            }
            /* We'll leave out most of the implementation since it has nothing to do with the CWE
             * and since the checkers are looking for certain function calls anyway */
            CloseHandle(hMutex);
        }
        break;
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() changes the conditions on the while statements */
static void good1()
{
    while(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            HANDLE hMutex = NULL;
            hMutex = CreateMutexA(NULL, FALSE, NULL);
            /* FLAW: If CreateMutexA() failed, the return value will be NULL,
               but we are checking to see if the return value is INVALID_HANDLE_VALUE */
            if (hMutex == INVALID_HANDLE_VALUE)
            {
                exit(1);
            }
            /* FLAW: If CreateMutexA() failed, GetLastError() could return ERROR_ACCESS_DENIED
               but we are checking to see if the return value is negative */
            if (GetLastError() == -1)
            {
                exit(1);
            }
            /* We'll leave out most of the implementation since it has nothing to do with the CWE
             * and since the checkers are looking for certain function calls anyway */
            CloseHandle(hMutex);
        }
        break;
    }
    while(1)
    {
        {
            HANDLE hMutex = NULL;
            hMutex = CreateMutexA(NULL, FALSE, NULL);
            /* FIX: check for the correct return value */
            if (hMutex == NULL)
            {
                exit(1);
            }
            /* FIX: check for the correct return value */
            if (GetLastError() == ERROR_ALREADY_EXISTS)
            {
                exit(1);
            }
            /* We'll leave out most of the implementation since it has nothing to do with the CWE
             * and since the checkers are looking for certain function calls anyway */
            CloseHandle(hMutex);
        }
        break;
    }
}

void CWE253_Incorrect_Check_of_Return_Value__char_w32CreateMutex_16_good()
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
    CWE253_Incorrect_Check_of_Return_Value__char_w32CreateMutex_16_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE253_Incorrect_Check_of_Return_Value__char_w32CreateMutex_16_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
