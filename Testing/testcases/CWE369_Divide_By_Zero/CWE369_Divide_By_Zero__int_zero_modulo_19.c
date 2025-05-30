/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE369_Divide_By_Zero__int_zero_modulo_19.c
Label Definition File: CWE369_Divide_By_Zero__int.label.xml
Template File: sources-sink-19.tmpl.c
*/
/*
 * @description
 * CWE: 369 Divide By Zero
 * BadSource: zero Fixed value of zero
 * GoodSource: Non-zero
 * Sink: modulo
 *    BadSink : Modulo a constant with data
 * Flow Variant: 19 Control flow: Dead code after a return
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE369_Divide_By_Zero__int_zero_modulo_19_bad()
{
    int data;
    /* Initialize data */
    data = -1;
    /* FLAW: Set data to zero */
    data = 0;
    /* POTENTIAL FLAW: Possibly divide by zero */
    printIntLine(100 % data);
    return;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    /* FIX: Use a value not equal to zero */
    data = 7;
    /* POTENTIAL FLAW: Possibly divide by zero */
    printIntLine(100 % data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() - use goodsource and badsink by swapping the GoodSource and BadSource around the return */
static void goodG2B()
{
    int data;
    /* Initialize data */
    data = -1;
    /* FIX: Use a value not equal to zero */
    data = 7;
    /* POTENTIAL FLAW: Possibly divide by zero */
    printIntLine(100 % data);
    return;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    /* FLAW: Set data to zero */
    data = 0;
    /* POTENTIAL FLAW: Possibly divide by zero */
    printIntLine(100 % data);
}

void CWE369_Divide_By_Zero__int_zero_modulo_19_good()
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
    CWE369_Divide_By_Zero__int_zero_modulo_19_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE369_Divide_By_Zero__int_zero_modulo_19_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
