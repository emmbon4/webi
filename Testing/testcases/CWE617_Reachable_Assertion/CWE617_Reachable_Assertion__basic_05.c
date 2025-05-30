/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE617_Reachable_Assertion__basic_05.c
Label Definition File: CWE617_Reachable_Assertion__basic.label.xml
Template File: point-flaw-05.tmpl.c
*/
/*
 * @description
 * CWE: 617 Reachable Assertion
 * Sinks: simple
 *    GoodSink: assert(true), which will never trigger
 *    BadSink : assert(false), which will always trigger
 * Flow Variant: 05 Control flow: if(static_t) and if(static_f)
 *
 * */

#include "std_testcase.h"

#include <assert.h>

/* The two variables below are not defined as "const", but are never
   assigned any other value, so a tool should be able to identify that
   reads of these will always return their initialized values. */
static int static_t = 1; /* true */
static int static_f = 0; /* false */

#ifndef OMITBAD

void CWE617_Reachable_Assertion__basic_05_bad()
{
    if(static_t)
    {
        /* FLAW: if this assertion can be reached, and will always trigger */
        assert(0); /* INCIDENTAL: CWE 571 - expression is always true - it's "true" because assert(e) basically does if (!(e)) */
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: ensure assertions cannot be triggered, in this case, to avoid an empty
         * function, assert(1)
         */
        assert(1); /* INCIDENTAL: CWE 570 - expression is always false - it's "false" because assert(e) basically does if (!(e)) */
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
        /* FLAW: if this assertion can be reached, and will always trigger */
        assert(0); /* INCIDENTAL: CWE 571 - expression is always true - it's "true" because assert(e) basically does if (!(e)) */
    }
    else
    {
        /* FIX: ensure assertions cannot be triggered, in this case, to avoid an empty
         * function, assert(1)
         */
        assert(1); /* INCIDENTAL: CWE 570 - expression is always false - it's "false" because assert(e) basically does if (!(e)) */
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(static_t)
    {
        /* FIX: ensure assertions cannot be triggered, in this case, to avoid an empty
         * function, assert(1)
         */
        assert(1); /* INCIDENTAL: CWE 570 - expression is always false - it's "false" because assert(e) basically does if (!(e)) */
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FLAW: if this assertion can be reached, and will always trigger */
        assert(0); /* INCIDENTAL: CWE 571 - expression is always true - it's "true" because assert(e) basically does if (!(e)) */
    }
}

void CWE617_Reachable_Assertion__basic_05_good()
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
    CWE617_Reachable_Assertion__basic_05_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE617_Reachable_Assertion__basic_05_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
