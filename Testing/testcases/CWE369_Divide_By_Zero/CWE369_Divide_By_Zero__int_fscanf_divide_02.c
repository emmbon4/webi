/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE369_Divide_By_Zero__int_fscanf_divide_02.c
Label Definition File: CWE369_Divide_By_Zero__int.label.xml
Template File: sources-sink-02.tmpl.c
*/
/*
 * @description
 * CWE: 369 Divide By Zero
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Non-zero
 * Sink: divide
 *    BadSink : Divide a constant by data
 * Flow Variant: 02 Control flow: if(1) and if(0)
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE369_Divide_By_Zero__int_fscanf_divide_02_bad()
{
    int data;
    /* Initialize data */
    data = -1;
    if(1)
    {
        fscanf (stdin, "%d", &data);
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Use a value not equal to zero */
        data = 7;
    }
    /* POTENTIAL FLAW: Possibly divide by zero */
    printIntLine(100 / data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B1() - use goodsource and badsink by changing the 1 to 0 */
static void goodG2B1()
{
    int data;
    /* Initialize data */
    data = -1;
    if(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        fscanf (stdin, "%d", &data);
    }
    else
    {
        /* FIX: Use a value not equal to zero */
        data = 7;
    }
    /* POTENTIAL FLAW: Possibly divide by zero */
    printIntLine(100 / data);
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the if statement */
static void goodG2B2()
{
    int data;
    /* Initialize data */
    data = -1;
    if(1)
    {
        /* FIX: Use a value not equal to zero */
        data = 7;
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        fscanf (stdin, "%d", &data);
    }
    /* POTENTIAL FLAW: Possibly divide by zero */
    printIntLine(100 / data);
}

void CWE369_Divide_By_Zero__int_fscanf_divide_02_good()
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
    CWE369_Divide_By_Zero__int_fscanf_divide_02_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE369_Divide_By_Zero__int_fscanf_divide_02_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
