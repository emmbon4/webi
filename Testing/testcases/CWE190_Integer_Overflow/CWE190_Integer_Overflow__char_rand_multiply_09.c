/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__char_rand_multiply_09.c
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-09.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: rand Set data to result of rand()
 * GoodSource: Small, non-zero
 * Sinks: multiply
 *    GoodSink: Ensure there is no overflow before performing the multiplication
 *    BadSink : Multiply data by 2
 * Flow Variant: 09 Control flow: if(global_const_t) and if(global_const_f)
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE190_Integer_Overflow__char_rand_multiply_09_bad()
{
    char data;
    data = ' ';
    if(global_const_t)
    {
        /* POTENTIAL FLAW: Use a random value */
        data = (char)rand();
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Use a small, non-zero value that will not cause an overflow in the sinks */
        data = 5;
    }
    if(global_const_t)
    {
        {
            /* POTENTIAL FLAW: Multiplying data by 2 could cause an overflow */
            char result = data * 2;
            printHexCharLine(result);
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            char result = -1;
            /* FIX: Add a check to prevent an overflow from occurring */
            if (data <= (CHAR_MAX/2))
            {
                result = data * 2;
                printHexCharLine(result);
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

/* goodB2G1() - use badsource and goodsink by changing the second global_const_t to global_const_f */
static void goodB2G1()
{
    char data;
    data = ' ';
    if(global_const_t)
    {
        /* POTENTIAL FLAW: Use a random value */
        data = (char)rand();
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Use a small, non-zero value that will not cause an overflow in the sinks */
        data = 5;
    }
    if(global_const_f)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* POTENTIAL FLAW: Multiplying data by 2 could cause an overflow */
            char result = data * 2;
            printHexCharLine(result);
        }
    }
    else
    {
        {
            char result = -1;
            /* FIX: Add a check to prevent an overflow from occurring */
            if (data <= (CHAR_MAX/2))
            {
                result = data * 2;
                printHexCharLine(result);
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
    char data;
    data = ' ';
    if(global_const_t)
    {
        /* POTENTIAL FLAW: Use a random value */
        data = (char)rand();
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Use a small, non-zero value that will not cause an overflow in the sinks */
        data = 5;
    }
    if(global_const_t)
    {
        {
            char result = -1;
            /* FIX: Add a check to prevent an overflow from occurring */
            if (data <= (CHAR_MAX/2))
            {
                result = data * 2;
                printHexCharLine(result);
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
            char result = data * 2;
            printHexCharLine(result);
        }
    }
}

/* goodG2B1() - use goodsource and badsink by changing the first global_const_t to global_const_f */
static void goodG2B1()
{
    char data;
    data = ' ';
    if(global_const_f)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* POTENTIAL FLAW: Use a random value */
        data = (char)rand();
    }
    else
    {
        /* FIX: Use a small, non-zero value that will not cause an overflow in the sinks */
        data = 5;
    }
    if(global_const_t)
    {
        {
            /* POTENTIAL FLAW: Multiplying data by 2 could cause an overflow */
            char result = data * 2;
            printHexCharLine(result);
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            char result = -1;
            /* FIX: Add a check to prevent an overflow from occurring */
            if (data <= (CHAR_MAX/2))
            {
                result = data * 2;
                printHexCharLine(result);
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
    char data;
    data = ' ';
    if(global_const_t)
    {
        /* FIX: Use a small, non-zero value that will not cause an overflow in the sinks */
        data = 5;
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* POTENTIAL FLAW: Use a random value */
        data = (char)rand();
    }
    if(global_const_t)
    {
        {
            /* POTENTIAL FLAW: Multiplying data by 2 could cause an overflow */
            char result = data * 2;
            printHexCharLine(result);
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            char result = -1;
            /* FIX: Add a check to prevent an overflow from occurring */
            if (data <= (CHAR_MAX/2))
            {
                result = data * 2;
                printHexCharLine(result);
            }
            else
            {
                printLine("Input value is too large to perform arithmetic safely.");
            }
        }
    }
}

void CWE190_Integer_Overflow__char_rand_multiply_09_good()
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
    CWE190_Integer_Overflow__char_rand_multiply_09_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE190_Integer_Overflow__char_rand_multiply_09_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
