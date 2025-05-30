/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE563_Unused_Variable__unused_value_int_17.c
Label Definition File: CWE563_Unused_Variable__unused_value.label.xml
Template File: sources-sinks-17.tmpl.c
*/
/*
 * @description
 * CWE: 563 Unused Variable
 * BadSource:  Initialize data
 * GoodSource: Initialize and use data
 * Sinks:
 *    GoodSink: Use data
 *    BadSink : Initialize and use data
 * Flow Variant: 17 Control flow: for loops
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE563_Unused_Variable__unused_value_int_17_bad()
{
    int h,i,j,k;
    int data;
    for(h = 0; h < 0; h++)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Initialize and use data before it is overwritten */
        data = 5;
        printIntLine(data);
    }
    for(i = 0; i < 1; i++)
    {
        /* POTENTIAL FLAW: Initialize, but do not use data */
        data = 5;
    }
    for(j = 0; j < 1; j++)
    {
        /* POTENTIAL FLAW: Possibly over-write the initial value of data before using it */
        data = 10;
        printIntLine(data);
    }
    for(k = 0; k < 0; k++)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Use data without over-writing its value */
        printIntLine(data);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G() - use badsource and goodsink by changing the conditions on the third and fourth for statements */
static void goodB2G()
{
    int h,i,j,k;
    int data;
    for(h = 0; h < 0; h++)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Initialize and use data before it is overwritten */
        data = 5;
        printIntLine(data);
    }
    for(i = 0; i < 1; i++)
    {
        /* POTENTIAL FLAW: Initialize, but do not use data */
        data = 5;
    }
    for(j = 0; j < 0; j++)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* POTENTIAL FLAW: Possibly over-write the initial value of data before using it */
        data = 10;
        printIntLine(data);
    }
    for(k = 0; k < 1; k++)
    {
        /* FIX: Use data without over-writing its value */
        printIntLine(data);
    }
}

/* goodG2B() - use goodsource and badsink by changing the conditions on the first and second for statements */
static void goodG2B()
{
    int h,i,j,k;
    int data;
    for(h = 0; h < 1; h++)
    {
        /* FIX: Initialize and use data before it is overwritten */
        data = 5;
        printIntLine(data);
    }
    for(i = 0; i < 0; i++)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* POTENTIAL FLAW: Initialize, but do not use data */
        data = 5;
    }
    for(j = 0; j < 1; j++)
    {
        /* POTENTIAL FLAW: Possibly over-write the initial value of data before using it */
        data = 10;
        printIntLine(data);
    }
    for(k = 0; k < 0; k++)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Use data without over-writing its value */
        printIntLine(data);
    }
}

void CWE563_Unused_Variable__unused_value_int_17_good()
{
    goodB2G();
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
    CWE563_Unused_Variable__unused_value_int_17_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE563_Unused_Variable__unused_value_int_17_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
