/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE369_Divide_By_Zero__float_rand_14.c
Label Definition File: CWE369_Divide_By_Zero__float.label.xml
Template File: sources-sink-14.tmpl.c
*/
/*
 * @description
 * CWE: 369 Divide By Zero
 * BadSource: rand Set data to result of rand(), which may be zero
 * GoodSource: Non-zero
 * Sink:
 *    BadSink : Divide a constant by data
 * Flow Variant: 14 Control flow: if(global_five==5) and if(global_five!=5)
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE369_Divide_By_Zero__float_rand_14_bad()
{
    float data;
    /* Initialize data */
    data = 0.0F;
    if(global_five==5)
    {
        /* POTENTIAL FLAW: Use a random number that could possibly equal zero */
        data = (float)RAND32();
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Use a value not equal to zero */
        data = 7.0F;
    }
    /* POTENTIAL FLAW: Possibly divide by zero */
    printDoubleLine((double)(100.0 / data));
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B1() - use goodsource and badsink by changing the global_five==5 to global_five!=5 */
static void goodG2B1()
{
    float data;
    /* Initialize data */
    data = 0.0F;
    if(global_five!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* POTENTIAL FLAW: Use a random number that could possibly equal zero */
        data = (float)RAND32();
    }
    else
    {
        /* FIX: Use a value not equal to zero */
        data = 7.0F;
    }
    /* POTENTIAL FLAW: Possibly divide by zero */
    printDoubleLine((double)(100.0 / data));
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the if statement */
static void goodG2B2()
{
    float data;
    /* Initialize data */
    data = 0.0F;
    if(global_five==5)
    {
        /* FIX: Use a value not equal to zero */
        data = 7.0F;
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* POTENTIAL FLAW: Use a random number that could possibly equal zero */
        data = (float)RAND32();
    }
    /* POTENTIAL FLAW: Possibly divide by zero */
    printDoubleLine((double)(100.0 / data));
}

void CWE369_Divide_By_Zero__float_rand_14_good()
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
    CWE369_Divide_By_Zero__float_rand_14_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE369_Divide_By_Zero__float_rand_14_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
