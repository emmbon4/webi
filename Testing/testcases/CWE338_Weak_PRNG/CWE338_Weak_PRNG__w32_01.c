/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE338_Weak_PRNG__w32_01.c
Label Definition File: CWE338_Weak_PRNG__w32.label.xml
Template File: point-flaw-01.tmpl.c
*/
/*
 * @description
 * CWE: 338 Use of Cryptographically Weak PRNG
 * Sinks:
 *    GoodSink: Use CryptGenRandom() to generate a random number
 *    BadSink : Use rand() to generate a random number
 * Flow Variant: 01 Baseline
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
# include <windows.h>
# include <wincrypt.h>
#pragma comment(lib, "advapi32.lib")
#endif

#ifndef OMITBAD

void CWE338_Weak_PRNG__w32_01_bad()
{
    {
        /* FLAW: Use of rand() as a PRNG */
        int data = rand();
        printIntLine(data);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

static void good1()
{
    {
#ifdef _WIN32 /* this is WIN32 specific */
        HCRYPTPROV hCryptProv;
        BYTE pbData[4];
        int data;
        if (!CryptAcquireContextW(&hCryptProv, 0, 0, PROV_RSA_FULL, 0)) exit(1);
        /* FIX: Use of CryptGenRandom() as a more secure PRNG */
        if (!CryptGenRandom(hCryptProv, 4, pbData))
        {
            CryptReleaseContext(hCryptProv, 0);
            exit(1);
        }
        CryptReleaseContext(hCryptProv, 0);
        data = (int)*pbData;
        printIntLine(data);
#endif
    }
}

void CWE338_Weak_PRNG__w32_01_good()
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
    CWE338_Weak_PRNG__w32_01_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE338_Weak_PRNG__w32_01_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
