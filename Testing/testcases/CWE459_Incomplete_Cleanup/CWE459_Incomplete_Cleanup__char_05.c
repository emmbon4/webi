/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE459_Incomplete_Cleanup__char_05.c
Label Definition File: CWE459_Incomplete_Cleanup.label.xml
Template File: point-flaw-05.tmpl.c
*/
/*
 * @description
 * CWE: 459 Incomplete Cleanup
 * Sinks:
 *    GoodSink: Clean up properly
 *    BadSink : Don't unlink
 * Flow Variant: 05 Control flow: if(static_t) and if(static_f)
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

/* The two variables below are not defined as "const", but are never
   assigned any other value, so a tool should be able to identify that
   reads of these will always return their initialized values. */
static int static_t = 1; /* true */
static int static_f = 0; /* false */

#ifndef OMITBAD

void CWE459_Incomplete_Cleanup__char_05_bad()
{
    if(static_t)
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

/* good1() uses if(static_f) instead of if(static_t) */
static void good1()
{
    if(static_f)
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
    if(static_t)
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

void CWE459_Incomplete_Cleanup__char_05_good()
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
    CWE459_Incomplete_Cleanup__char_05_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE459_Incomplete_Cleanup__char_05_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
