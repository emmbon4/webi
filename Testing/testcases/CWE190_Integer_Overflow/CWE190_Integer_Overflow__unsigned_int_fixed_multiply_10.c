/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__unsigned_int_fixed_multiply_10.c
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-10.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: fixed Fixed value
 * GoodSource: Small, non-zero
 * Sinks: multiply
 *    GoodSink: Ensure there is no overflow before performing the multiplication
 *    BadSink : Multiply data by 2
 * Flow Variant: 10 Control flow: if(global_t) and if(global_f)
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE190_Integer_Overflow__unsigned_int_fixed_multiply_10_bad()
{
    unsigned int data;
    data = 0;
    if(global_t)
    {
        /* FLAW: Use the maximum size of the data type */
        data = UINT_MAX;
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Use a small, non-zero value that will not cause an overflow in the sinks */
        data = 5;
    }
    if(global_t)
    {
        {
            /* POTENTIAL FLAW: Multiplying data by 2 could cause an overflow */
            unsigned int result = data * 2;
            printUnsignedLine(result);
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            unsigned int result = -1;
            /* FIX: Add a check to prevent an overflow from occurring */
            if (data <= (UINT_MAX/2))
            {
                result = data * 2;
                printUnsignedLine(result);
            }
            else
            {
                printLine("Input value is too large to perform arithmetic safely.");
            }
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G1() - use badsource and goodsink by changing the second global_t to global_f */
static void goodB2G1()
{
    unsigned int data;
    data = 0;
    if(global_t)
    {
        /* FLAW: Use the maximum size of the data type */
        data = UINT_MAX;
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Use a small, non-zero value that will not cause an overflow in the sinks */
        data = 5;
    }
    if(global_f)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* POTENTIAL FLAW: Multiplying data by 2 could cause an overflow */
            unsigned int result = data * 2;
            printUnsignedLine(result);
        }
    }
    else
    {
        {
            unsigned int result = -1;
            /* FIX: Add a check to prevent an overflow from occurring */
            if (data <= (UINT_MAX/2))
            {
                result = data * 2;
                printUnsignedLine(result);
            }
            else
            {
                printLine("Input value is too large to perform arithmetic safely.");
            }
        }
    }
}

/* goodB2G2() - use badsource and goodsink by reversing the blocks in the second if */
static void goodB2G2()
{
    unsigned int data;
    data = 0;
    if(global_t)
    {
        /* FLAW: Use the maximum size of the data type */
        data = UINT_MAX;
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Use a small, non-zero value that will not cause an overflow in the sinks */
        data = 5;
    }
    if(global_t)
    {
        {
            unsigned int result = -1;
            /* FIX: Add a check to prevent an overflow from occurring */
            if (data <= (UINT_MAX/2))
            {
                result = data * 2;
                printUnsignedLine(result);
            }
            else
            {
                printLine("Input value is too large to perform arithmetic safely.");
            }
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* POTENTIAL FLAW: Multiplying data by 2 could cause an overflow */
            unsigned int result = data * 2;
            printUnsignedLine(result);
        }
    }
}

/* goodG2B1() - use goodsource and badsink by changing the first global_t to global_f */
static void goodG2B1()
{
    unsigned int data;
    data = 0;
    if(global_f)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FLAW: Use the maximum size of the data type */
        data = UINT_MAX;
    }
    else
    {
        /* FIX: Use a small, non-zero value that will not cause an overflow in the sinks */
        data = 5;
    }
    if(global_t)
    {
        {
            /* POTENTIAL FLAW: Multiplying data by 2 could cause an overflow */
            unsigned int result = data * 2;
            printUnsignedLine(result);
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            unsigned int result = -1;
            /* FIX: Add a check to prevent an overflow from occurring */
            if (data <= (UINT_MAX/2))
            {
                result = data * 2;
                printUnsignedLine(result);
            }
            else
            {
                printLine("Input value is too large to perform arithmetic safely.");
            }
        }
    }
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the first if */
static void goodG2B2()
{
    unsigned int data;
    data = 0;
    if(global_t)
    {
        /* FIX: Use a small, non-zero value that will not cause an overflow in the sinks */
        data = 5;
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FLAW: Use the maximum size of the data type */
        data = UINT_MAX;
    }
    if(global_t)
    {
        {
            /* POTENTIAL FLAW: Multiplying data by 2 could cause an overflow */
            unsigned int result = data * 2;
            printUnsignedLine(result);
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            unsigned int result = -1;
            /* FIX: Add a check to prevent an overflow from occurring */
            if (data <= (UINT_MAX/2))
            {
                result = data * 2;
                printUnsignedLine(result);
            }
            else
            {
                printLine("Input value is too large to perform arithmetic safely.");
            }
        }
    }
}

void CWE190_Integer_Overflow__unsigned_int_fixed_multiply_10_good()
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
    CWE190_Integer_Overflow__unsigned_int_fixed_multiply_10_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE190_Integer_Overflow__unsigned_int_fixed_multiply_10_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
