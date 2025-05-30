/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE321_Hard_Coded_Cryptographic_Key__w32_wchar_t_68a.c
Label Definition File: CWE321_Hard_Coded_Cryptographic_Key__w32.label.xml
Template File: sources-sink-68a.tmpl.c
*/
/*
 * @description
 * CWE: 321 Use of Hard-coded Cryptographic Key
 * BadSource: hardcoded Copy a hardcoded value into cryptokey
 * GoodSource: Read cryptokey from the console
 * Sink:
 *    BadSink : Hash cryptokey and use the value to encrypt a string
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#define CRYPTOKEY L"Hardcoded"

#ifdef _WIN32
#include <windows.h>
#include <wincrypt.h>

/* Link with the Advapi32.lib file for Crypt* functions */
#pragma comment (lib, "Advapi32")
#endif

wchar_t * CWE321_Hard_Coded_Cryptographic_Key__w32_wchar_t_68_bad_data;
wchar_t * CWE321_Hard_Coded_Cryptographic_Key__w32_wchar_t_68_goodG2B_data;

#ifndef OMITBAD

/* bad function declaration */
void CWE321_Hard_Coded_Cryptographic_Key__w32_wchar_t_68b_bad_sink();

void CWE321_Hard_Coded_Cryptographic_Key__w32_wchar_t_68_bad()
{
    wchar_t * cryptokey;
    wchar_t cryptokey_buf[100] = L"";
    cryptokey = cryptokey_buf;
    /* FLAW: Use a hardcoded value for the hash input causing a hardcoded crypto key in the sink */
    wcscpy(cryptokey, CRYPTOKEY);
    CWE321_Hard_Coded_Cryptographic_Key__w32_wchar_t_68_bad_data = cryptokey;
    CWE321_Hard_Coded_Cryptographic_Key__w32_wchar_t_68b_bad_sink();
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declarations */
void CWE321_Hard_Coded_Cryptographic_Key__w32_wchar_t_68b_goodG2B_sink();

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    wchar_t * cryptokey;
    wchar_t cryptokey_buf[100] = L"";
    cryptokey = cryptokey_buf;
    {
        size_t cryptokey_len = wcslen(cryptokey);
        /* if there is room in cryptokey, read into it from the console */
        if(100-cryptokey_len > 1)
        {
            /* FIX: Obtain the hash input from the console */
            fgetws(cryptokey+cryptokey_len, (int)(100-cryptokey_len), stdin);
            /* The next 3 lines remove the carriage return from the string that is
             * inserted by fgetws() */
            cryptokey_len = wcslen(cryptokey);
            if (cryptokey_len > 0)
            {
                cryptokey[cryptokey_len-1] = L'\0';
            }
        }
    }
    CWE321_Hard_Coded_Cryptographic_Key__w32_wchar_t_68_goodG2B_data = cryptokey;
    CWE321_Hard_Coded_Cryptographic_Key__w32_wchar_t_68b_goodG2B_sink();
}

void CWE321_Hard_Coded_Cryptographic_Key__w32_wchar_t_68_good()
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
    CWE321_Hard_Coded_Cryptographic_Key__w32_wchar_t_68_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE321_Hard_Coded_Cryptographic_Key__w32_wchar_t_68_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
