/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE459_Incomplete_Cleanup__char_08.c
Label Definition File: CWE459_Incomplete_Cleanup.label.xml
Template File: point-flaw-08.tmpl.c
*/
/*
 * @description
 * CWE: 459 Incomplete Cleanup
 * Sinks:
 *    GoodSink: Clean up properly
 *    BadSink : Don't unlink
 * Flow Variant: 08 Control flow: if(static_returns_t()) and if(static_returns_f())
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

/* The two function below always return the same value, so a tool
   should be able to identify that calls to the functions will always
   return a fixed value. */
static int static_returns_t()
{
    return 1;
}

static int static_returns_f()
{
    return 0;
}

#ifndef OMITBAD

void CWE459_Incomplete_Cleanup__char_08_bad()
{
    if(static_returns_t())
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

/* good1() uses if(static_returns_f()) instead of if(static_returns_t()) */
static void good1()
{
    if(static_returns_f())
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
    if(static_returns_t())
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

void CWE459_Incomplete_Cleanup__char_08_good()
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
    CWE459_Incomplete_Cleanup__char_08_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE459_Incomplete_Cleanup__char_08_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
