/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__char_fscanf_15.c
Label Definition File: CWE191_Integer_Underflow.label.xml
Template File: sources-sinks-15.tmpl.c
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Small, non-zero
 * Sinks:
 *    GoodSink: Ensure there is no underflow before performing the subtraction
 *    BadSink : Subtract 1 from data
 * Flow Variant: 15 Control flow: switch(6) and switch(7)
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE191_Integer_Underflow__char_fscanf_15_bad()
{
    char data;
    data = ' ';
    switch(6)
    {
    case 6:
        /* POTENTIAL FLAW: Use a value input from the console */
        fscanf (stdin, "%c", &data);
        break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Use a small value greater than the min value for this data type */
        data = 5;
        break;
    }
    switch(7)
    {
    case 7:
    {
        /* POTENTIAL FLAW: Subtracting 1 from data could cause an integer underflow */
        char result = data - 1;
        printHexCharLine(result);
    }
    break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        char result = 0;
        /* FIX: Add a check to prevent an underflow from occurring */
        if (data > CHAR_MIN)
        {
            result = data - 1;
            printHexCharLine(result);
        }
        else
        {
            printLine("Input value is too small to perform arithmetic safely.");
        }
    }
    break;
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G1() - use badsource and goodsink by changing the second switch to switch(8) */
static void goodB2G1()
{
    char data;
    data = ' ';
    switch(6)
    {
    case 6:
        /* POTENTIAL FLAW: Use a value input from the console */
        fscanf (stdin, "%c", &data);
        break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Use a small value greater than the min value for this data type */
        data = 5;
        break;
    }
    switch(8)
    {
    case 7:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        /* POTENTIAL FLAW: Subtracting 1 from data could cause an integer underflow */
        char result = data - 1;
        printHexCharLine(result);
    }
    break;
    default:
    {
        char result = 0;
        /* FIX: Add a check to prevent an underflow from occurring */
        if (data > CHAR_MIN)
        {
            result = data - 1;
            printHexCharLine(result);
        }
        else
        {
            printLine("Input value is too small to perform arithmetic safely.");
        }
    }
    break;
    }
}

/* goodB2G2() - use badsource and goodsink by reversing the blocks in the second switch */
static void goodB2G2()
{
    char data;
    data = ' ';
    switch(6)
    {
    case 6:
        /* POTENTIAL FLAW: Use a value input from the console */
        fscanf (stdin, "%c", &data);
        break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Use a small value greater than the min value for this data type */
        data = 5;
        break;
    }
    switch(7)
    {
    case 7:
    {
        char result = 0;
        /* FIX: Add a check to prevent an underflow from occurring */
        if (data > CHAR_MIN)
        {
            result = data - 1;
            printHexCharLine(result);
        }
        else
        {
            printLine("Input value is too small to perform arithmetic safely.");
        }
    }
    break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        /* POTENTIAL FLAW: Subtracting 1 from data could cause an integer underflow */
        char result = data - 1;
        printHexCharLine(result);
    }
    break;
    }
}

/* goodG2B1() - use goodsource and badsink by changing the first switch to switch(5) */
static void goodG2B1()
{
    char data;
    data = ' ';
    switch(5)
    {
    case 6:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* POTENTIAL FLAW: Use a value input from the console */
        fscanf (stdin, "%c", &data);
        break;
    default:
        /* FIX: Use a small value greater than the min value for this data type */
        data = 5;
        break;
    }
    switch(7)
    {
    case 7:
    {
        /* POTENTIAL FLAW: Subtracting 1 from data could cause an integer underflow */
        char result = data - 1;
        printHexCharLine(result);
    }
    break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        char result = 0;
        /* FIX: Add a check to prevent an underflow from occurring */
        if (data > CHAR_MIN)
        {
            result = data - 1;
            printHexCharLine(result);
        }
        else
        {
            printLine("Input value is too small to perform arithmetic safely.");
        }
    }
    break;
    }
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the first switch */
static void goodG2B2()
{
    char data;
    data = ' ';
    switch(6)
    {
    case 6:
        /* FIX: Use a small value greater than the min value for this data type */
        data = 5;
        break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* POTENTIAL FLAW: Use a value input from the console */
        fscanf (stdin, "%c", &data);
        break;
    }
    switch(7)
    {
    case 7:
    {
        /* POTENTIAL FLAW: Subtracting 1 from data could cause an integer underflow */
        char result = data - 1;
        printHexCharLine(result);
    }
    break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        char result = 0;
        /* FIX: Add a check to prevent an underflow from occurring */
        if (data > CHAR_MIN)
        {
            result = data - 1;
            printHexCharLine(result);
        }
        else
        {
            printLine("Input value is too small to perform arithmetic safely.");
        }
    }
    break;
    }
}

void CWE191_Integer_Underflow__char_fscanf_15_good()
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
    CWE191_Integer_Underflow__char_fscanf_15_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE191_Integer_Underflow__char_fscanf_15_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
