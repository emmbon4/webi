/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE369_Divide_By_Zero__int_zero_modulo_18.c
Label Definition File: CWE369_Divide_By_Zero__int.label.xml
Template File: sources-sink-18.tmpl.c
*/
/*
 * @description
 * CWE: 369 Divide By Zero
 * BadSource: zero Fixed value of zero
 * GoodSource: Non-zero
 * Sink: modulo
 *    BadSink : Modulo a constant with data
 * Flow Variant: 18 Control flow: goto statements
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE369_Divide_By_Zero__int_zero_modulo_18_bad()
{
    int data;
    /* Initialize data */
    data = -1;
    goto source;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    /* FIX: Use a value not equal to zero */
    data = 7;
source:
    /* FLAW: Set data to zero */
    data = 0;
    /* POTENTIAL FLAW: Possibly divide by zero */
    printIntLine(100 % data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() - use goodsource and badsink by reversing the blocks on the goto statement */
static void goodG2B()
{
    int data;
    /* Initialize data */
    data = -1;
    goto source;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    /* FLAW: Set data to zero */
    data = 0;
source:
    /* FIX: Use a value not equal to zero */
    data = 7;
    /* POTENTIAL FLAW: Possibly divide by zero */
    printIntLine(100 % data);
}

void CWE369_Divide_By_Zero__int_zero_modulo_18_good()
{
    goodG2B();
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
    CWE369_Divide_By_Zero__int_zero_modulo_18_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE369_Divide_By_Zero__int_zero_modulo_18_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
