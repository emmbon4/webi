/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__int_fixed_08.c
Label Definition File: CWE191_Integer_Underflow__int.label.xml
Template File: sources-sinks-08.tmpl.c
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: fixed Fixed value
 * GoodSource: Greater than INT_MIN
 * Sinks:
 *    GoodSink: Ensure there is no underflow before performing the subtraction
 *    BadSink : Subtract 1 from data
 * Flow Variant: 08 Control flow: if(static_returns_t()) and if(static_returns_f())
 *
 * */

#include "std_testcase.h"

/* The two function below always return the same value, so a tool
   should be able to identify that calls to the functions will always
   return a fixed value. */
static int static_returns_t()
{
    return 1;
}

static int static_returns_f()
{
    return 0;
}

#ifndef OMITBAD

void CWE191_Integer_Underflow__int_fixed_08_bad()
{
    int data;
    /* Initialize data */
    data = -1;
    if(static_returns_t())
    {
        /* FLAW: Use the minimum size of the data type */
        data = INT_MIN;
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Use a small value greater than the min value for this data type */
        data = 5;
    }
    if(static_returns_t())
    {
        {
            /* POTENTIAL FLAW: Subtracting 1 from data could cause an integer underflow */
            int result = data - 1;
            printIntLine(result);
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            int result = 0;
            /* FIX: Add a check to prevent an underflow from occurring */
            if (data > INT_MIN)
            {
                result = data - 1;
                printIntLine(result);
            }
            else
            {
                printLine("Input value is too small to perform arithmetic safely.");
            }
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G1() - use badsource and goodsink by changing the second static_returns_t() to static_returns_f() */
static void goodB2G1()
{
    int data;
    /* Initialize data */
    data = -1;
    if(static_returns_t())
    {
        /* FLAW: Use the minimum size of the data type */
        data = INT_MIN;
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Use a small value greater than the min value for this data type */
        data = 5;
    }
    if(static_returns_f())
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* POTENTIAL FLAW: Subtracting 1 from data could cause an integer underflow */
            int result = data - 1;
            printIntLine(result);
        }
    }
    else
    {
        {
            int result = 0;
            /* FIX: Add a check to prevent an underflow from occurring */
            if (data > INT_MIN)
            {
                result = data - 1;
                printIntLine(result);
            }
            else
            {
                printLine("Input value is too small to perform arithmetic safely.");
            }
        }
    }
}

/* goodB2G2() - use badsource and goodsink by reversing the blocks in the second if */
static void goodB2G2()
{
    int data;
    /* Initialize data */
    data = -1;
    if(static_returns_t())
    {
        /* FLAW: Use the minimum size of the data type */
        data = INT_MIN;
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Use a small value greater than the min value for this data type */
        data = 5;
    }
    if(static_returns_t())
    {
        {
            int result = 0;
            /* FIX: Add a check to prevent an underflow from occurring */
            if (data > INT_MIN)
            {
                result = data - 1;
                printIntLine(result);
            }
            else
            {
                printLine("Input value is too small to perform arithmetic safely.");
            }
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* POTENTIAL FLAW: Subtracting 1 from data could cause an integer underflow */
            int result = data - 1;
            printIntLine(result);
        }
    }
}

/* goodG2B1() - use goodsource and badsink by changing the first static_returns_t() to static_returns_f() */
static void goodG2B1()
{
    int data;
    /* Initialize data */
    data = -1;
    if(static_returns_f())
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FLAW: Use the minimum size of the data type */
        data = INT_MIN;
    }
    else
    {
        /* FIX: Use a small value greater than the min value for this data type */
        data = 5;
    }
    if(static_returns_t())
    {
        {
            /* POTENTIAL FLAW: Subtracting 1 from data could cause an integer underflow */
            int result = data - 1;
            printIntLine(result);
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            int result = 0;
            /* FIX: Add a check to prevent an underflow from occurring */
            if (data > INT_MIN)
            {
                result = data - 1;
                printIntLine(result);
            }
            else
            {
                printLine("Input value is too small to perform arithmetic safely.");
            }
        }
    }
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the first if */
static void goodG2B2()
{
    int data;
    /* Initialize data */
    data = -1;
    if(static_returns_t())
    {
        /* FIX: Use a small value greater than the min value for this data type */
        data = 5;
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FLAW: Use the minimum size of the data type */
        data = INT_MIN;
    }
    if(static_returns_t())
    {
        {
            /* POTENTIAL FLAW: Subtracting 1 from data could cause an integer underflow */
            int result = data - 1;
            printIntLine(result);
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            int result = 0;
            /* FIX: Add a check to prevent an underflow from occurring */
            if (data > INT_MIN)
            {
                result = data - 1;
                printIntLine(result);
            }
            else
            {
                printLine("Input value is too small to perform arithmetic safely.");
            }
        }
    }
}

void CWE191_Integer_Underflow__int_fixed_08_good()
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
    CWE191_Integer_Underflow__int_fixed_08_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE191_Integer_Underflow__int_fixed_08_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
