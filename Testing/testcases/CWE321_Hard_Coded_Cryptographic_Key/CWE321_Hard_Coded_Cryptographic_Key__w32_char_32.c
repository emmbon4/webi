/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE321_Hard_Coded_Cryptographic_Key__w32_char_32.c
Label Definition File: CWE321_Hard_Coded_Cryptographic_Key__w32.label.xml
Template File: sources-sink-32.tmpl.c
*/
/*
 * @description
 * CWE: 321 Use of Hard-coded Cryptographic Key
 * BadSource: hardcoded Copy a hardcoded value into cryptokey
 * GoodSource: Read cryptokey from the console
 * Sink:
 *    BadSink : Hash cryptokey and use the value to encrypt a string
 * Flow Variant: 32 Data flow using two pointers to the same value within the same function
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

void CWE321_Hard_Coded_Cryptographic_Key__w32_char_32_bad()
{
    char * cryptokey;
    char * *cryptokey_ptr1 = &cryptokey;
    char * *cryptokey_ptr2 = &cryptokey;
    char cryptokey_buf[100] = "";
    cryptokey = cryptokey_buf;
    {
        char * cryptokey = *cryptokey_ptr1;
        /* FLAW: Use a hardcoded value for the hash input causing a hardcoded crypto key in the sink */
        strcpy(cryptokey, CRYPTOKEY);
        *cryptokey_ptr1 = cryptokey;
    }
    {
        char * cryptokey = *cryptokey_ptr2;
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
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    char * cryptokey;
    char * *cryptokey_ptr1 = &cryptokey;
    char * *cryptokey_ptr2 = &cryptokey;
    char cryptokey_buf[100] = "";
    cryptokey = cryptokey_buf;
    {
        char * cryptokey = *cryptokey_ptr1;
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
        *cryptokey_ptr1 = cryptokey;
    }
    {
        char * cryptokey = *cryptokey_ptr2;
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
}

void CWE321_Hard_Coded_Cryptographic_Key__w32_char_32_good()
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
    CWE321_Hard_Coded_Cryptographic_Key__w32_char_32_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE321_Hard_Coded_Cryptographic_Key__w32_char_32_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
