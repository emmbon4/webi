/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_wchar_t_51a.c
Label Definition File: CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32.label.xml
Template File: sources-sink-51a.tmpl.c
*/
/*
 * @description
 * CWE: 591 Sensitive Data Storage in Improperly Locked Memory
 * BadSource:  Allocate memory for sensitive data and use VirtualLock() to lock the buffer into memory
 * GoodSource: Allocate memory for sensitive data and use VirtualLock() to lock the buffer into memory
 * Sink:
 *    BadSink : Authenticate the user using LogonUserW()
 * Flow Variant: 51 Data flow: data passed as an argument from one function to another in different source files
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

/* bad function declaration */
void CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_wchar_t_51b_bad_sink(wchar_t * password);

void CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_wchar_t_51_bad()
{
    wchar_t * password;
    /* Initialize Data */
    password = L"";
    password = (wchar_t *)malloc(100*sizeof(wchar_t));
    /* FLAW: Do not lock the memory */
    /* INCIDENTAL FLAW: CWE-259 Hardcoded Password */
    wcscpy(password, L"Password1234!");
    CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_wchar_t_51b_bad_sink(password);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declarations */
void CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_wchar_t_51b_goodG2B_sink(wchar_t * password);

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    wchar_t * password;
    /* Initialize Data */
    password = L"";
#ifdef _WIN32 /* this is WIN32 specific */
    password = (wchar_t *)malloc(100*sizeof(wchar_t));
    /* FIX: Use VirtualLock() to lock the buffer into memory */
    if(!VirtualLock(password, 100*sizeof(wchar_t)))
    {
        printLine("Memory could not be locked");
        exit(1);
    }
    /* INCIDENTAL FLAW: CWE-259 Hardcoded Password */
    wcscpy(password, L"Password1234!");
#endif
    CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_wchar_t_51b_goodG2B_sink(password);
}

void CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_wchar_t_51_good()
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
    CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_wchar_t_51_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_wchar_t_51_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
