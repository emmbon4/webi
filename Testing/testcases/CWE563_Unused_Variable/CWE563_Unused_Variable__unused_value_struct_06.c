/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE563_Unused_Variable__unused_value_struct_06.c
Label Definition File: CWE563_Unused_Variable__unused_value.label.xml
Template File: sources-sinks-06.tmpl.c
*/
/*
 * @description
 * CWE: 563 Unused Variable
 * BadSource:  Initialize data
 * GoodSource: Initialize and use data
 * Sinks:
 *    GoodSink: Use data
 *    BadSink : Initialize and use data
 * Flow Variant: 06 Control flow: if(static_const_five==5) and if(static_const_five!=5)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

/* The variable below is declared "const", so a tool should be able
   to identify that reads of this will always give its initialized
   value. */
static const int static_const_five = 5;

#ifndef OMITBAD

void CWE563_Unused_Variable__unused_value_struct_06_bad()
{
    twoints data;
    if(static_const_five==5)
    {
        /* POTENTIAL FLAW: Initialize, but do not use data */
        data.a = 0;
        data.b = 0;
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Initialize and use data before it is overwritten */
        data.a = 0;
        data.b = 0;
        printStructLine(&data);
    }
    if(static_const_five==5)
    {
        /* POTENTIAL FLAW: Possibly over-write the initial value of data before using it */
        data.a = 1;
        data.b = 1;
        printStructLine(&data);
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Use data without over-writing its value */
        printStructLine(&data);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G1() - use badsource and goodsink by changing the second static_const_five==5 to static_const_five!=5 */
static void goodB2G1()
{
    twoints data;
    if(static_const_five==5)
    {
        /* POTENTIAL FLAW: Initialize, but do not use data */
        data.a = 0;
        data.b = 0;
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Initialize and use data before it is overwritten */
        data.a = 0;
        data.b = 0;
        printStructLine(&data);
    }
    if(static_const_five!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* POTENTIAL FLAW: Possibly over-write the initial value of data before using it */
        data.a = 1;
        data.b = 1;
        printStructLine(&data);
    }
    else
    {
        /* FIX: Use data without over-writing its value */
        printStructLine(&data);
    }
}

/* goodB2G2() - use badsource and goodsink by reversing the blocks in the second if */
static void goodB2G2()
{
    twoints data;
    if(static_const_five==5)
    {
        /* POTENTIAL FLAW: Initialize, but do not use data */
        data.a = 0;
        data.b = 0;
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Initialize and use data before it is overwritten */
        data.a = 0;
        data.b = 0;
        printStructLine(&data);
    }
    if(static_const_five==5)
    {
        /* FIX: Use data without over-writing its value */
        printStructLine(&data);
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* POTENTIAL FLAW: Possibly over-write the initial value of data before using it */
        data.a = 1;
        data.b = 1;
        printStructLine(&data);
    }
}

/* goodG2B1() - use goodsource and badsink by changing the first static_const_five==5 to static_const_five!=5 */
static void goodG2B1()
{
    twoints data;
    if(static_const_five!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* POTENTIAL FLAW: Initialize, but do not use data */
        data.a = 0;
        data.b = 0;
    }
    else
    {
        /* FIX: Initialize and use data before it is overwritten */
        data.a = 0;
        data.b = 0;
        printStructLine(&data);
    }
    if(static_const_five==5)
    {
        /* POTENTIAL FLAW: Possibly over-write the initial value of data before using it */
        data.a = 1;
        data.b = 1;
        printStructLine(&data);
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Use data without over-writing its value */
        printStructLine(&data);
    }
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the first if */
static void goodG2B2()
{
    twoints data;
    if(static_const_five==5)
    {
        /* FIX: Initialize and use data before it is overwritten */
        data.a = 0;
        data.b = 0;
        printStructLine(&data);
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* POTENTIAL FLAW: Initialize, but do not use data */
        data.a = 0;
        data.b = 0;
    }
    if(static_const_five==5)
    {
        /* POTENTIAL FLAW: Possibly over-write the initial value of data before using it */
        data.a = 1;
        data.b = 1;
        printStructLine(&data);
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Use data without over-writing its value */
        printStructLine(&data);
    }
}

void CWE563_Unused_Variable__unused_value_struct_06_good()
{
    goodB2G1();
    goodB2G2();
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
    CWE563_Unused_Variable__unused_value_struct_06_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE563_Unused_Variable__unused_value_struct_06_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
