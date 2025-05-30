/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE256_Plaintext_Storage_of_Password__w32_wchar_t_68a.c
Label Definition File: CWE256_Plaintext_Storage_of_Password__w32.label.xml
Template File: sources-sink-68a.tmpl.c
*/
/*
 * @description
 * CWE: 256 Plaintext Storage of Password
 * BadSource:  Read the password from a file
 * GoodSource: Read the password from the console
 * Sink:
 *    BadSink : Authenticate the user using LogonUserW()
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifdef _WIN32
#include <windows.h>
#pragma comment(lib, "advapi32.lib")
#endif

wchar_t * CWE256_Plaintext_Storage_of_Password__w32_wchar_t_68_bad_data;
wchar_t * CWE256_Plaintext_Storage_of_Password__w32_wchar_t_68_goodG2B_data;

#ifndef OMITBAD

/* bad function declaration */
void CWE256_Plaintext_Storage_of_Password__w32_wchar_t_68b_bad_sink();

void CWE256_Plaintext_Storage_of_Password__w32_wchar_t_68_bad()
{
    wchar_t * password;
    wchar_t password_buf[100] = L"";
    password = password_buf;
    {
        FILE *password_file;
        password_file = fopen("passwords.txt", "r");
        /* FLAW: Read the password from a file */
        fgetws(password, 100, password_file);
        fclose(password_file);
    }
    CWE256_Plaintext_Storage_of_Password__w32_wchar_t_68_bad_data = password;
    CWE256_Plaintext_Storage_of_Password__w32_wchar_t_68b_bad_sink();
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declarations */
void CWE256_Plaintext_Storage_of_Password__w32_wchar_t_68b_goodG2B_sink();

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    wchar_t * password;
    wchar_t password_buf[100] = L"";
    password = password_buf;
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
    CWE256_Plaintext_Storage_of_Password__w32_wchar_t_68_goodG2B_data = password;
    CWE256_Plaintext_Storage_of_Password__w32_wchar_t_68b_goodG2B_sink();
}

void CWE256_Plaintext_Storage_of_Password__w32_wchar_t_68_good()
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
    CWE256_Plaintext_Storage_of_Password__w32_wchar_t_68_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE256_Plaintext_Storage_of_Password__w32_wchar_t_68_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
