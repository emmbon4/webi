/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE259_Hard_Coded_Password__w32_wchar_t_53a.c
Label Definition File: CWE259_Hard_Coded_Password__w32.label.xml
Template File: sources-sink-53a.tmpl.c
*/
/*
 * @description
 * CWE: 259 Use of Hard-coded Password
 * BadSource:  Use a hardcoded password
 * GoodSource: Read the password from the console
 * Sink:
 *    BadSink : Authenticate the user using LogonUserW()
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>
#define PASSWORD_SZ 100

#define PASSWORD L"ABCD1234!"

#ifdef _WIN32
#include <windows.h>
#pragma comment(lib, "advapi32.lib")
#endif

#ifndef OMITBAD

/* bad function declaration */
void CWE259_Hard_Coded_Password__w32_wchar_t_53b_bad_sink(wchar_t * password);

void CWE259_Hard_Coded_Password__w32_wchar_t_53_bad()
{
    wchar_t * password;
    wchar_t password_buf[100] = L"";
    password = password_buf;
    /* FLAW: Use a hardcoded password */
    wcscpy(password, PASSWORD);
    CWE259_Hard_Coded_Password__w32_wchar_t_53b_bad_sink(password);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declaration */
void CWE259_Hard_Coded_Password__w32_wchar_t_53b_goodG2B_sink(wchar_t * password);

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
    CWE259_Hard_Coded_Password__w32_wchar_t_53b_goodG2B_sink(password);
}

void CWE259_Hard_Coded_Password__w32_wchar_t_53_good()
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
    CWE259_Hard_Coded_Password__w32_wchar_t_53_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE259_Hard_Coded_Password__w32_wchar_t_53_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
