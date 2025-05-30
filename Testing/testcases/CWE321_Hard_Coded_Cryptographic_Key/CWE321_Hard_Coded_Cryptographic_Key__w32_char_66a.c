/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE321_Hard_Coded_Cryptographic_Key__w32_char_66a.c
Label Definition File: CWE321_Hard_Coded_Cryptographic_Key__w32.label.xml
Template File: sources-sink-66a.tmpl.c
*/
/*
 * @description
 * CWE: 321 Use of Hard-coded Cryptographic Key
 * BadSource: hardcoded Copy a hardcoded value into cryptokey
 * GoodSource: Read cryptokey from the console
 * Sinks:
 *    BadSink : Hash cryptokey and use the value to encrypt a string
 * Flow Variant: 66 Data flow: data passed in an array from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#define CRYPTOKEY "Hardcoded"

#ifdef _WIN32
#include <windows.h>
#include <wincrypt.h>

/* Link with the Advapi32.lib file for Crypt* functions */
#pragma comment (lib, "Advapi32")
#endif

#ifndef OMITBAD

/* bad function declaration */
void CWE321_Hard_Coded_Cryptographic_Key__w32_char_66b_bad_sink(char * cryptokey_array[]);

void CWE321_Hard_Coded_Cryptographic_Key__w32_char_66_bad()
{
    char * cryptokey;
    char * cryptokey_array[5];
    char cryptokey_buf[100] = "";
    cryptokey = cryptokey_buf;
    /* FLAW: Use a hardcoded value for the hash input causing a hardcoded crypto key in the sink */
    strcpy(cryptokey, CRYPTOKEY);
    /* put cryptokey in array */
    cryptokey_array[2] = cryptokey;
    CWE321_Hard_Coded_Cryptographic_Key__w32_char_66b_bad_sink(cryptokey_array);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE321_Hard_Coded_Cryptographic_Key__w32_char_66b_goodG2B_sink(char * cryptokey_array[]);

static void goodG2B()
{
    char * cryptokey;
    char * cryptokey_array[5];
    char cryptokey_buf[100] = "";
    cryptokey = cryptokey_buf;
    {
        size_t cryptokey_len = strlen(cryptokey);
        /* if there is room in cryptokey, read into it from the console */
        if(100-cryptokey_len > 1)
        {
            /* FIX: Obtain the hash input from the console */
            fgets(cryptokey+cryptokey_len, (int)(100-cryptokey_len), stdin);
            /* The next 3 lines remove the carriage return from the string that is
             * inserted by fgets() */
            cryptokey_len = strlen(cryptokey);
            if (cryptokey_len > 0)
            {
                cryptokey[cryptokey_len-1] = '\0';
            }
        }
    }
    cryptokey_array[2] = cryptokey;
    CWE321_Hard_Coded_Cryptographic_Key__w32_char_66b_goodG2B_sink(cryptokey_array);
}

void CWE321_Hard_Coded_Cryptographic_Key__w32_char_66_good()
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
    CWE321_Hard_Coded_Cryptographic_Key__w32_char_66_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE321_Hard_Coded_Cryptographic_Key__w32_char_66_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
