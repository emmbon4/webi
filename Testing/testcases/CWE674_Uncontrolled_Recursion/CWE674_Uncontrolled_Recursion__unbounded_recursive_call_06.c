/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE674_Uncontrolled_Recursion__unbounded_recursive_call_06.c
Label Definition File: CWE674_Uncontrolled_Recursion.label.xml
Template File: point-flaw-06.tmpl.c
*/
/*
 * @description
 * CWE: 674 Uncontrolled Recursion
 * Sinks: unbounded_recursive_call
 *    GoodSink: Limit recursion to a managed level
 *    BadSink : Recursion not limited to a managed level
 * Flow Variant: 06 Control flow: if(static_const_five==5) and if(static_const_five!=5)
 *
 * */

#include "std_testcase.h"

static void helper_bad(unsigned level)
{
    /* FLAW: Although this cannot cause "infinite" recursion, it is essentially limited to UINT_MAX
     * which is rather large on most systems
     */
    if (level == 0) return;
    helper_bad(level - 1);
}

#define MAX_RECURSION 10

static void helper_good(unsigned level)
{
    /* FIX: limit recursion to a sane level */
    if (level > MAX_RECURSION)
    {
        printLine("ERROR IN RECURSION");
        return;
    }
    if (level == 0)
    {
        return;
    }
    helper_good(level - 1);
}

/* The variable below is declared "const", so a tool should be able
   to identify that reads of this will always give its initialized
   value. */
static const int static_const_five = 5;

#ifndef OMITBAD

void CWE674_Uncontrolled_Recursion__unbounded_recursive_call_06_bad()
{
    if(static_const_five==5)
    {
        helper_bad(UINT_MAX);
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        helper_good(UINT_MAX);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() uses if(static_const_five!=5) instead of if(static_const_five==5) */
static void good1()
{
    if(static_const_five!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        helper_bad(UINT_MAX);
    }
    else
    {
        helper_good(UINT_MAX);
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(static_const_five==5)
    {
        helper_good(UINT_MAX);
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        helper_bad(UINT_MAX);
    }
}

void CWE674_Uncontrolled_Recursion__unbounded_recursive_call_06_good()
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
    CWE674_Uncontrolled_Recursion__unbounded_recursive_call_06_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE674_Uncontrolled_Recursion__unbounded_recursive_call_06_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
