/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE256_Plaintext_Storage_of_Password__w32_wchar_t_61b.c
Label Definition File: CWE256_Plaintext_Storage_of_Password__w32.label.xml
Template File: sources-sink-61b.tmpl.c
*/
/*
 * @description
 * CWE: 256 Plaintext Storage of Password
 * BadSource:  Read the password from a file
 * GoodSource: Read the password from the console
 * Sinks:
 *    BadSink : Authenticate the user using LogonUserW()
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifdef _WIN32
#include <windows.h>
#pragma comment(lib, "advapi32.lib")
#endif

#ifndef OMITBAD

wchar_t * CWE256_Plaintext_Storage_of_Password__w32_wchar_t_61b_bad_source(wchar_t * password)
{
    {
        FILE *password_file;
        password_file = fopen("passwords.txt", "r");
        /* FLAW: Read the password from a file */
        fgetws(password, 100, password_file);
        fclose(password_file);
    }
    return password;
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
wchar_t * CWE256_Plaintext_Storage_of_Password__w32_wchar_t_61b_goodG2B_source(wchar_t * password)
{
    {
        size_t password_len = 0;
        /* FIX: Read the password from the console */
        fgetws(password, 100, stdin);
        /* Remove the carriage return from the string that is inserted by fgetws() */
        password_len = wcslen(password);
        if (password_len > 0)
        {
            password[password_len-1] = L'\0';
        }
    }
    return password;
}

#endif /* OMITGOOD */
