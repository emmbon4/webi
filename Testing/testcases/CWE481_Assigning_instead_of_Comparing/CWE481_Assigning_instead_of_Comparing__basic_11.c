/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE481_Assigning_instead_of_Comparing__basic_11.c
Label Definition File: CWE481_Assigning_instead_of_Comparing__basic.label.xml
Template File: point-flaw-11.tmpl.c
*/
/*
 * @description
 * CWE: 481 Assigning instead of Comparing
 * Sinks:
 *    GoodSink: Comparing
 *    BadSink : Assigning instead of comparing
 * Flow Variant: 11 Control flow: if(global_returns_t()) and if(global_returns_f())
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE481_Assigning_instead_of_Comparing__basic_11_bad()
{
    if(global_returns_t())
    {
        {
            int i = rand();
            /* FLAW: should be == and INCIDENTIAL CWE 571 Expression Is Always True */
            if(i = 5)
            {
                printLine("i was 5");
            }
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            int i = rand();
            /* FIX: used == instead of = */
            if(i == 5)
            {
                printLine("i was 5");
            }
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() uses if(global_returns_f()) instead of if(global_returns_t()) */
static void good1()
{
    if(global_returns_f())
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            int i = rand();
            /* FLAW: should be == and INCIDENTIAL CWE 571 Expression Is Always True */
            if(i = 5)
            {
                printLine("i was 5");
            }
        }
    }
    else
    {
        {
            int i = rand();
            /* FIX: used == instead of = */
            if(i == 5)
            {
                printLine("i was 5");
            }
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(global_returns_t())
    {
        {
            int i = rand();
            /* FIX: used == instead of = */
            if(i == 5)
            {
                printLine("i was 5");
            }
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            int i = rand();
            /* FLAW: should be == and INCIDENTIAL CWE 571 Expression Is Always True */
            if(i = 5)
            {
                printLine("i was 5");
            }
        }
    }
}

void CWE481_Assigning_instead_of_Comparing__basic_11_good()
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
    CWE481_Assigning_instead_of_Comparing__basic_11_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE481_Assigning_instead_of_Comparing__basic_11_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
