/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE321_Hard_Coded_Cryptographic_Key__w32_char_42.c
Label Definition File: CWE321_Hard_Coded_Cryptographic_Key__w32.label.xml
Template File: sources-sink-42.tmpl.c
*/
/*
 * @description
 * CWE: 321 Use of Hard-coded Cryptographic Key
 * BadSource: hardcoded Copy a hardcoded value into cryptokey
 * GoodSource: Read cryptokey from the console
 * Sink:
 *    BadSink : Hash cryptokey and use the value to encrypt a string
 * Flow Variant: 42 Data flow: data returned from one function to another in the same source file
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

static char * bad_source(char * cryptokey)
{
    /* FLAW: Use a hardcoded value for the hash input causing a hardcoded crypto key in the sink */
    strcpy(cryptokey, CRYPTOKEY);
    return cryptokey;
}

void CWE321_Hard_Coded_Cryptographic_Key__w32_char_42_bad()
{
    char * cryptokey;
    char cryptokey_buf[100] = "";
    cryptokey = cryptokey_buf;
    cryptokey = bad_source(cryptokey);
    {
#ifdef _WIN32 /* this is WIN32 specific */
        HCRYPTPROV cryptoprov;
        HCRYPTKEY key;
        HCRYPTHASH hash;
        char toBeEncrypted[100] = "String to be encrypted"; /* buffer should be larger than string to have room for IV and padding */
        DWORD toBeEncryptedLen = strlen(toBeEncrypted)*sizeof(char);
        /* Try to get a context with and without a new key set */
        if(!CryptAcquireContext(&cryptoprov, NULL, MS_ENHANCED_PROV, PROV_RSA_FULL, 0))
        {
            if(!CryptAcquireContext(&cryptoprov, NULL, MS_ENHANCED_PROV, PROV_RSA_FULL, CRYPT_NEWKEYSET))
            {
                printLine("Error in acquiring cryptographic context");
                exit(1);
            }
        }
        /* Create Hash handle */
        if(!CryptCreateHash(cryptoprov, CALG_SHA1, 0, 0, &hash))
        {
            printLine("Error in creating hash");
            exit(1);
        }
        /* Hash the cryptokey */
        if(!CryptHashData(hash, (BYTE *) cryptokey, strlen(cryptokey)*sizeof(char), 0))
        {
            printLine("Error in hashing cryptokey");
            exit(1);
        }
        /* Derive a Triple-DES key from the Hashed cryptokey */
        if(!CryptDeriveKey(cryptoprov, CALG_3DES, hash, 0, &key))
        {
            printLine("Error in CryptDeriveKey");
            exit(1);
        }
        /* POTENTIAL FLAW: Possibly using a hardcoded crypto key */
        /* Use the derived key to encrypt something */
        if(!CryptEncrypt(key, (HCRYPTHASH)NULL, 1, 0, (BYTE *)toBeEncrypted, &toBeEncryptedLen, sizeof(toBeEncrypted)))
        {
            printLine("Error in CryptEncryptData");
            exit(1);
        }
        /* use encrypted block */
        printLine(toBeEncrypted);
#endif
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

static char * goodG2B_source(char * cryptokey)
{
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
    return cryptokey;
}

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    char * cryptokey;
    char cryptokey_buf[100] = "";
    cryptokey = cryptokey_buf;
    cryptokey = goodG2B_source(cryptokey);
    {
#ifdef _WIN32 /* this is WIN32 specific */
        HCRYPTPROV cryptoprov;
        HCRYPTKEY key;
        HCRYPTHASH hash;
        char toBeEncrypted[100] = "String to be encrypted"; /* buffer should be larger than string to have room for IV and padding */
        DWORD toBeEncryptedLen = strlen(toBeEncrypted)*sizeof(char);
        /* Try to get a context with and without a new key set */
        if(!CryptAcquireContext(&cryptoprov, NULL, MS_ENHANCED_PROV, PROV_RSA_FULL, 0))
        {
            if(!CryptAcquireContext(&cryptoprov, NULL, MS_ENHANCED_PROV, PROV_RSA_FULL, CRYPT_NEWKEYSET))
            {
                printLine("Error in acquiring cryptographic context");
                exit(1);
            }
        }
        /* Create Hash handle */
        if(!CryptCreateHash(cryptoprov, CALG_SHA1, 0, 0, &hash))
        {
            printLine("Error in creating hash");
            exit(1);
        }
        /* Hash the cryptokey */
        if(!CryptHashData(hash, (BYTE *) cryptokey, strlen(cryptokey)*sizeof(char), 0))
        {
            printLine("Error in hashing cryptokey");
            exit(1);
        }
        /* Derive a Triple-DES key from the Hashed cryptokey */
        if(!CryptDeriveKey(cryptoprov, CALG_3DES, hash, 0, &key))
        {
            printLine("Error in CryptDeriveKey");
            exit(1);
        }
        /* POTENTIAL FLAW: Possibly using a hardcoded crypto key */
        /* Use the derived key to encrypt something */
        if(!CryptEncrypt(key, (HCRYPTHASH)NULL, 1, 0, (BYTE *)toBeEncrypted, &toBeEncryptedLen, sizeof(toBeEncrypted)))
        {
            printLine("Error in CryptEncryptData");
            exit(1);
        }
        /* use encrypted block */
        printLine(toBeEncrypted);
#endif
    }
}

void CWE321_Hard_Coded_Cryptographic_Key__w32_char_42_good()
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
    CWE321_Hard_Coded_Cryptographic_Key__w32_char_42_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE321_Hard_Coded_Cryptographic_Key__w32_char_42_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
