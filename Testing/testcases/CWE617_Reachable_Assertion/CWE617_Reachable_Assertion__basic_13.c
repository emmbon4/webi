/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE617_Reachable_Assertion__basic_13.c
Label Definition File: CWE617_Reachable_Assertion__basic.label.xml
Template File: point-flaw-13.tmpl.c
*/
/*
 * @description
 * CWE: 617 Reachable Assertion
 * Sinks: simple
 *    GoodSink: assert(true), which will never trigger
 *    BadSink : assert(false), which will always trigger
 * Flow Variant: 13 Control flow: if(global_const_five==5) and if(global_const_five!=5)
 *
 * */

#include "std_testcase.h"

#include <assert.h>

#ifndef OMITBAD

void CWE617_Reachable_Assertion__basic_13_bad()
{
    if(global_const_five==5)
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

/* good1() uses if(global_const_five!=5) instead of if(global_const_five==5) */
static void good1()
{
    if(global_const_five!=5)
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
    if(global_const_five==5)
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

void CWE617_Reachable_Assertion__basic_13_good()
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
    CWE617_Reachable_Assertion__basic_13_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE617_Reachable_Assertion__basic_13_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
