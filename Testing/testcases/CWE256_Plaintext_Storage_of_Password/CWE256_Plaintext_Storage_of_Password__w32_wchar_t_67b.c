/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE256_Plaintext_Storage_of_Password__w32_wchar_t_67b.c
Label Definition File: CWE256_Plaintext_Storage_of_Password__w32.label.xml
Template File: sources-sink-67b.tmpl.c
*/
/*
 * @description
 * CWE: 256 Plaintext Storage of Password
 * BadSource:  Read the password from a file
 * GoodSource: Read the password from the console
 * Sinks:
 *    BadSink : Authenticate the user using LogonUserW()
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifdef _WIN32
#include <windows.h>
#pragma comment(lib, "advapi32.lib")
#endif

typedef struct _CWE256_Plaintext_Storage_of_Password__w32_wchar_t_67_struct_type
{
    wchar_t * a;
} CWE256_Plaintext_Storage_of_Password__w32_wchar_t_67_struct_type;

#ifndef OMITBAD

void CWE256_Plaintext_Storage_of_Password__w32_wchar_t_67b_bad_sink(CWE256_Plaintext_Storage_of_Password__w32_wchar_t_67_struct_type my_struct)
{
    wchar_t * password = my_struct.a;
    {
#ifdef _WIN32 /* this is WIN32 specific */
        HANDLE pHandle;
        wchar_t * username = L"User";
        wchar_t * domain = L"Domain";
        /* POTENTIAL FLAW: Attempt to login user with password from the source */
        if (LogonUserW(
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
#endif
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE256_Plaintext_Storage_of_Password__w32_wchar_t_67b_goodG2B_sink(CWE256_Plaintext_Storage_of_Password__w32_wchar_t_67_struct_type my_struct)
{
    wchar_t * password = my_struct.a;
    {
#ifdef _WIN32 /* this is WIN32 specific */
        HANDLE pHandle;
        wchar_t * username = L"User";
        wchar_t * domain = L"Domain";
        /* POTENTIAL FLAW: Attempt to login user with password from the source */
        if (LogonUserW(
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
#endif
    }
}

#endif /* OMITGOOD */
