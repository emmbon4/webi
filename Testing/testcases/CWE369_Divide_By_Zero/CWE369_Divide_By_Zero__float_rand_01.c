/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE369_Divide_By_Zero__float_rand_01.c
Label Definition File: CWE369_Divide_By_Zero__float.label.xml
Template File: sources-sink-01.tmpl.c
*/
/*
 * @description
 * CWE: 369 Divide By Zero
 * BadSource: rand Set data to result of rand(), which may be zero
 * GoodSource: Non-zero
 * Sink:
 *    BadSink : Divide a constant by data
 * Flow Variant: 01 Baseline
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE369_Divide_By_Zero__float_rand_01_bad()
{
    float data;
    /* Initialize data */
    data = 0.0F;
    /* POTENTIAL FLAW: Use a random number that could possibly equal zero */
    data = (float)RAND32();
    /* POTENTIAL FLAW: Possibly divide by zero */
    printDoubleLine((double)(100.0 / data));
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    float data;
    /* Initialize data */
    data = 0.0F;
    /* FIX: Use a value not equal to zero */
    data = 7.0F;
    /* POTENTIAL FLAW: Possibly divide by zero */
    printDoubleLine((double)(100.0 / data));
}

void CWE369_Divide_By_Zero__float_rand_01_good()
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
    CWE369_Divide_By_Zero__float_rand_01_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE369_Divide_By_Zero__float_rand_01_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
