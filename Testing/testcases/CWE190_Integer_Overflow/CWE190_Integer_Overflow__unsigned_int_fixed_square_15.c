/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__unsigned_int_fixed_square_15.c
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-15.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: fixed Fixed value
 * GoodSource: Small, non-zero
 * Sinks: square
 *    GoodSink: Ensure there is no overflow before performing the squaring operation
 *    BadSink : Square data
 * Flow Variant: 15 Control flow: switch(6) and switch(7)
 *
 * */

#include "std_testcase.h"

#include <math.h>

#ifndef OMITBAD

void CWE190_Integer_Overflow__unsigned_int_fixed_square_15_bad()
{
    unsigned int data;
    data = 0;
    switch(6)
    {
    case 6:
        /* FLAW: Use the maximum size of the data type */
        data = UINT_MAX;
        break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Use a small, non-zero value that will not cause an overflow in the sinks */
        data = 5;
        break;
    }
    switch(7)
    {
    case 7:
    {
        /* POTENTIAL FLAW: Squaring data could cause an overflow */
        unsigned int result = data * data;
        printUnsignedLine(result);
    }
    break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        unsigned int result = -1;
        /* FIX: Add a check to prevent an overflow from occurring */
        if (data <= (unsigned int)sqrt((unsigned int)UINT_MAX))
        {
            result = data * data;
            printUnsignedLine(result);
        }
        else
        {
            printLine("Input value is too large to perform arithmetic safely.");
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
    unsigned int data;
    data = 0;
    switch(6)
    {
    case 6:
        /* FLAW: Use the maximum size of the data type */
        data = UINT_MAX;
        break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Use a small, non-zero value that will not cause an overflow in the sinks */
        data = 5;
        break;
    }
    switch(8)
    {
    case 7:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        /* POTENTIAL FLAW: Squaring data could cause an overflow */
        unsigned int result = data * data;
        printUnsignedLine(result);
    }
    break;
    default:
    {
        unsigned int result = -1;
        /* FIX: Add a check to prevent an overflow from occurring */
        if (data <= (unsigned int)sqrt((unsigned int)UINT_MAX))
        {
            result = data * data;
            printUnsignedLine(result);
        }
        else
        {
            printLine("Input value is too large to perform arithmetic safely.");
        }
    }
    break;
    }
}

/* goodB2G2() - use badsource and goodsink by reversing the blocks in the second switch */
static void goodB2G2()
{
    unsigned int data;
    data = 0;
    switch(6)
    {
    case 6:
        /* FLAW: Use the maximum size of the data type */
        data = UINT_MAX;
        break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Use a small, non-zero value that will not cause an overflow in the sinks */
        data = 5;
        break;
    }
    switch(7)
    {
    case 7:
    {
        unsigned int result = -1;
        /* FIX: Add a check to prevent an overflow from occurring */
        if (data <= (unsigned int)sqrt((unsigned int)UINT_MAX))
        {
            result = data * data;
            printUnsignedLine(result);
        }
        else
        {
            printLine("Input value is too large to perform arithmetic safely.");
        }
    }
    break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        /* POTENTIAL FLAW: Squaring data could cause an overflow */
        unsigned int result = data * data;
        printUnsignedLine(result);
    }
    break;
    }
}

/* goodG2B1() - use goodsource and badsink by changing the first switch to switch(5) */
static void goodG2B1()
{
    unsigned int data;
    data = 0;
    switch(5)
    {
    case 6:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FLAW: Use the maximum size of the data type */
        data = UINT_MAX;
        break;
    default:
        /* FIX: Use a small, non-zero value that will not cause an overflow in the sinks */
        data = 5;
        break;
    }
    switch(7)
    {
    case 7:
    {
        /* POTENTIAL FLAW: Squaring data could cause an overflow */
        unsigned int result = data * data;
        printUnsignedLine(result);
    }
    break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        unsigned int result = -1;
        /* FIX: Add a check to prevent an overflow from occurring */
        if (data <= (unsigned int)sqrt((unsigned int)UINT_MAX))
        {
            result = data * data;
            printUnsignedLine(result);
        }
        else
        {
            printLine("Input value is too large to perform arithmetic safely.");
        }
    }
    break;
    }
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the first switch */
static void goodG2B2()
{
    unsigned int data;
    data = 0;
    switch(6)
    {
    case 6:
        /* FIX: Use a small, non-zero value that will not cause an overflow in the sinks */
        data = 5;
        break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FLAW: Use the maximum size of the data type */
        data = UINT_MAX;
        break;
    }
    switch(7)
    {
    case 7:
    {
        /* POTENTIAL FLAW: Squaring data could cause an overflow */
        unsigned int result = data * data;
        printUnsignedLine(result);
    }
    break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        unsigned int result = -1;
        /* FIX: Add a check to prevent an overflow from occurring */
        if (data <= (unsigned int)sqrt((unsigned int)UINT_MAX))
        {
            result = data * data;
            printUnsignedLine(result);
        }
        else
        {
            printLine("Input value is too large to perform arithmetic safely.");
        }
    }
    break;
    }
}

void CWE190_Integer_Overflow__unsigned_int_fixed_square_15_good()
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
    CWE190_Integer_Overflow__unsigned_int_fixed_square_15_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE190_Integer_Overflow__unsigned_int_fixed_square_15_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
