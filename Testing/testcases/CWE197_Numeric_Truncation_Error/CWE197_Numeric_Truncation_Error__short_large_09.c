/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE197_Numeric_Truncation_Error__short_large_09.c
Label Definition File: CWE197_Numeric_Truncation_Error__short.label.xml
Template File: sources-sink-09.tmpl.c
*/
/*
 * @description
 * CWE: 197 Numeric Truncation Error
 * BadSource: large Set data to a number larger than CHAR_MAX
 * GoodSource: Less than CHAR_MAX
 * Sink:
 *    BadSink : Convert data to a char
 * Flow Variant: 09 Control flow: if(global_const_t) and if(global_const_f)
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE197_Numeric_Truncation_Error__short_large_09_bad()
{
    short data;
    /* Initialize data */
    data = -1;
    if(global_const_t)
    {
        /* FLAW: Use a number larger than CHAR_MAX */
        data = CHAR_MAX + 1;
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Use a positive integer less than CHAR_MAX*/
        data = CHAR_MAX-5;
    }
    {
        /* POTENTIAL FLAW: Convert data to a char, possibly causing a truncation error */
        char c = (char)data;
        printHexCharLine(c);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B1() - use goodsource and badsink by changing the global_const_t to global_const_f */
static void goodG2B1()
{
    short data;
    /* Initialize data */
    data = -1;
    if(global_const_f)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FLAW: Use a number larger than CHAR_MAX */
        data = CHAR_MAX + 1;
    }
    else
    {
        /* FIX: Use a positive integer less than CHAR_MAX*/
        data = CHAR_MAX-5;
    }
    {
        /* POTENTIAL FLAW: Convert data to a char, possibly causing a truncation error */
        char c = (char)data;
        printHexCharLine(c);
    }
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the if statement */
static void goodG2B2()
{
    short data;
    /* Initialize data */
    data = -1;
    if(global_const_t)
    {
        /* FIX: Use a positive integer less than CHAR_MAX*/
        data = CHAR_MAX-5;
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FLAW: Use a number larger than CHAR_MAX */
        data = CHAR_MAX + 1;
    }
    {
        /* POTENTIAL FLAW: Convert data to a char, possibly causing a truncation error */
        char c = (char)data;
        printHexCharLine(c);
    }
}

void CWE197_Numeric_Truncation_Error__short_large_09_good()
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
    CWE197_Numeric_Truncation_Error__short_large_09_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE197_Numeric_Truncation_Error__short_large_09_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
