/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE369_Divide_By_Zero__float_zero_15.c
Label Definition File: CWE369_Divide_By_Zero__float.label.xml
Template File: sources-sink-15.tmpl.c
*/
/*
 * @description
 * CWE: 369 Divide By Zero
 * BadSource: zero Fixed value of zero
 * GoodSource: Non-zero
 * Sink:
 *    BadSink : Divide a constant by data
 * Flow Variant: 15 Control flow: switch(6)
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE369_Divide_By_Zero__float_zero_15_bad()
{
    float data;
    /* Initialize data */
    data = 0.0F;
    switch(6)
    {
    case 6:
        /* FLAW: Set data to zero */
        data = 0.0F;
        break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Use a value not equal to zero */
        data = 7.0F;
        break;
    }
    /* POTENTIAL FLAW: Possibly divide by zero */
    printDoubleLine((double)(100.0 / data));
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B1() - use goodsource and badsink by changing the switch to switch(5) */
static void goodG2B1()
{
    float data;
    /* Initialize data */
    data = 0.0F;
    switch(5)
    {
    case 6:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FLAW: Set data to zero */
        data = 0.0F;
        break;
    default:
        /* FIX: Use a value not equal to zero */
        data = 7.0F;
        break;
    }
    /* POTENTIAL FLAW: Possibly divide by zero */
    printDoubleLine((double)(100.0 / data));
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the switch */
static void goodG2B2()
{
    float data;
    /* Initialize data */
    data = 0.0F;
    switch(6)
    {
    case 6:
        /* FIX: Use a value not equal to zero */
        data = 7.0F;
        break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FLAW: Set data to zero */
        data = 0.0F;
        break;
    }
    /* POTENTIAL FLAW: Possibly divide by zero */
    printDoubleLine((double)(100.0 / data));
}

void CWE369_Divide_By_Zero__float_zero_15_good()
{
    goodG2B1();
    goodG2B2();
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
    CWE369_Divide_By_Zero__float_zero_15_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE369_Divide_By_Zero__float_zero_15_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
