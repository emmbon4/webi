/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE459_Incomplete_Cleanup__wchar_t_01.c
Label Definition File: CWE459_Incomplete_Cleanup.label.xml
Template File: point-flaw-01.tmpl.c
*/
/*
 * @description
 * CWE: 459 Incomplete Cleanup
 * Sinks:
 *    GoodSink: Clean up properly
 *    BadSink : Don't unlink
 * Flow Variant: 01 Baseline
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
# define UNLINK _wunlink
# define FOPEN _wfopen
#else
# define UNLINK wunlink
# define FOPEN fopen
#endif

#ifndef OMITBAD

void CWE459_Incomplete_Cleanup__wchar_t_01_bad()
{
    {
        FILE *f;
        f = FOPEN(L"temp.txt", L"w");
        if (f != NULL)
        {
            fwprintf(f, L"Temporary file");
            fclose(f);
            /* FLAW: We don't unlink */
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

static void good1()
{
    {
        FILE *f;
        f = FOPEN(L"temp.txt", L"w");
        if (f != NULL)
        {
            fwprintf(f, L"Temporary file");
            fclose(f);
            /* FIX: Unlink the temporary file */
            UNLINK(L"temp.txt"); /* EXPECTED INCIDENTAL: CWE367 TOCTOU - This POSIX API is essentially insecure by design */
        }
    }
}

void CWE459_Incomplete_Cleanup__wchar_t_01_good()
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
    CWE459_Incomplete_Cleanup__wchar_t_01_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE459_Incomplete_Cleanup__wchar_t_01_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
