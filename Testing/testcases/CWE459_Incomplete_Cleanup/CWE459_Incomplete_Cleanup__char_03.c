/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE459_Incomplete_Cleanup__char_03.c
Label Definition File: CWE459_Incomplete_Cleanup.label.xml
Template File: point-flaw-03.tmpl.c
*/
/*
 * @description
 * CWE: 459 Incomplete Cleanup
 * Sinks:
 *    GoodSink: Clean up properly
 *    BadSink : Don't unlink
 * Flow Variant: 03 Control flow: if(5==5) and if(5!=5)
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
# define UNLINK _unlink
# define FOPEN fopen
#else
# define UNLINK unlink
# define FOPEN fopen
#endif

#ifndef OMITBAD

void CWE459_Incomplete_Cleanup__char_03_bad()
{
    if(5==5)
    {
        {
            FILE *f;
            f = FOPEN("temp.txt", "w");
            if (f != NULL)
            {
                fprintf(f, "Temporary file");
                fclose(f);
                /* FLAW: We don't unlink */
            }
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            FILE *f;
            f = FOPEN("temp.txt", "w");
            if (f != NULL)
            {
                fprintf(f, "Temporary file");
                fclose(f);
                /* FIX: Unlink the temporary file */
                UNLINK("temp.txt"); /* EXPECTED INCIDENTAL: CWE367 TOCTOU - This POSIX API is essentially insecure by design */
            }
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() uses if(5!=5) instead of if(5==5) */
static void good1()
{
    if(5!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            FILE *f;
            f = FOPEN("temp.txt", "w");
            if (f != NULL)
            {
                fprintf(f, "Temporary file");
                fclose(f);
                /* FLAW: We don't unlink */
            }
        }
    }
    else
    {
        {
            FILE *f;
            f = FOPEN("temp.txt", "w");
            if (f != NULL)
            {
                fprintf(f, "Temporary file");
                fclose(f);
                /* FIX: Unlink the temporary file */
                UNLINK("temp.txt"); /* EXPECTED INCIDENTAL: CWE367 TOCTOU - This POSIX API is essentially insecure by design */
            }
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(5==5)
    {
        {
            FILE *f;
            f = FOPEN("temp.txt", "w");
            if (f != NULL)
            {
                fprintf(f, "Temporary file");
                fclose(f);
                /* FIX: Unlink the temporary file */
                UNLINK("temp.txt"); /* EXPECTED INCIDENTAL: CWE367 TOCTOU - This POSIX API is essentially insecure by design */
            }
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            FILE *f;
            f = FOPEN("temp.txt", "w");
            if (f != NULL)
            {
                fprintf(f, "Temporary file");
                fclose(f);
                /* FLAW: We don't unlink */
            }
        }
    }
}

void CWE459_Incomplete_Cleanup__char_03_good()
{
    good1();
    good2();
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
    CWE459_Incomplete_Cleanup__char_03_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE459_Incomplete_Cleanup__char_03_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
