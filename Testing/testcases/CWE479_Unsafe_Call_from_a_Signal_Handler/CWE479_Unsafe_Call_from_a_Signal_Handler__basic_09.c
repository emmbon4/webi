/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE479_Unsafe_Call_from_a_Signal_Handler__basic_09.c
Label Definition File: CWE479_Unsafe_Call_from_a_Signal_Handler__basic.label.xml
Template File: point-flaw-09.tmpl.c
*/
/*
 * @description
 * CWE: 479 Unsafe Call From a Signal Handler
 * Sinks:
 *    GoodSink: Don't call a function from within the signal handler
 *    BadSink : malloc() and free() inside a signal handler
 * Flow Variant: 09 Control flow: if(global_const_t) and if(global_const_f)
 *
 * */

#include "std_testcase.h"

#include <signal.h>

static void helper_bad(int sig)
{
    /* FLAW: malloc and free are not re-entrant */
    /* Used to be printf in here, but we are trying to avoid that.
     * Detecting that printLine ultimately calls printf requires inter-
     * procedural analysis, so we cannot do that either.  So instead,
     * do something very contrived with malloc/free
     */
    void *p = malloc(10);
    if (p) free(p);
}

static int CWE479_Unsafe_Call_from_a_Signal_Handler__basic_09_g_sig = 0;

static void helper_good(int sig)
{
    /* FIX: Basically, "don't do anything" in signal handlers.  Set a flag at
     * best, and if you have to call a function, ensure it's a re-entrant
     * asynchronous-safe one that doesn't eat up a lot of time
     */
    CWE479_Unsafe_Call_from_a_Signal_Handler__basic_09_g_sig = sig;
}

#ifndef OMITBAD

void CWE479_Unsafe_Call_from_a_Signal_Handler__basic_09_bad()
{
    if(global_const_t)
    {
        signal(SIGINT, helper_bad);
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        signal(SIGINT, helper_good);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() uses if(global_const_f) instead of if(global_const_t) */
static void good1()
{
    if(global_const_f)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        signal(SIGINT, helper_bad);
    }
    else
    {
        signal(SIGINT, helper_good);
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(global_const_t)
    {
        signal(SIGINT, helper_good);
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        signal(SIGINT, helper_bad);
    }
}

void CWE479_Unsafe_Call_from_a_Signal_Handler__basic_09_good()
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
    CWE479_Unsafe_Call_from_a_Signal_Handler__basic_09_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE479_Unsafe_Call_from_a_Signal_Handler__basic_09_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
