/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__char_fixed_11.c
Label Definition File: CWE191_Integer_Underflow.label.xml
Template File: sources-sinks-11.tmpl.c
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: fixed Fixed value
 * GoodSource: Small, non-zero
 * Sinks:
 *    GoodSink: Ensure there is no underflow before performing the subtraction
 *    BadSink : Subtract 1 from data
 * Flow Variant: 11 Control flow: if(global_returns_t()) and if(global_returns_f())
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE191_Integer_Underflow__char_fixed_11_bad()
{
    char data;
    data = ' ';
    if(global_returns_t())
    {
        /* FLAW: Use the minimum size of the data type */
        data = CHAR_MIN;
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Use a small value greater than the min value for this data type */
        data = 5;
    }
    if(global_returns_t())
    {
        {
            /* POTENTIAL FLAW: Subtracting 1 from data could cause an integer underflow */
            char result = data - 1;
            printHexCharLine(result);
        }
    }
    else
    {
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
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G1() - use badsource and goodsink by changing the second global_returns_t() to global_returns_f() */
static void goodB2G1()
{
    char data;
    data = ' ';
    if(global_returns_t())
    {
        /* FLAW: Use the minimum size of the data type */
        data = CHAR_MIN;
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Use a small value greater than the min value for this data type */
        data = 5;
    }
    if(global_returns_f())
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* POTENTIAL FLAW: Subtracting 1 from data could cause an integer underflow */
            char result = data - 1;
            printHexCharLine(result);
        }
    }
    else
    {
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
    }
}

/* goodB2G2() - use badsource and goodsink by reversing the blocks in the second if */
static void goodB2G2()
{
    char data;
    data = ' ';
    if(global_returns_t())
    {
        /* FLAW: Use the minimum size of the data type */
        data = CHAR_MIN;
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Use a small value greater than the min value for this data type */
        data = 5;
    }
    if(global_returns_t())
    {
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
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* POTENTIAL FLAW: Subtracting 1 from data could cause an integer underflow */
            char result = data - 1;
            printHexCharLine(result);
        }
    }
}

/* goodG2B1() - use goodsource and badsink by changing the first global_returns_t() to global_returns_f() */
static void goodG2B1()
{
    char data;
    data = ' ';
    if(global_returns_f())
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FLAW: Use the minimum size of the data type */
        data = CHAR_MIN;
    }
    else
    {
        /* FIX: Use a small value greater than the min value for this data type */
        data = 5;
    }
    if(global_returns_t())
    {
        {
            /* POTENTIAL FLAW: Subtracting 1 from data could cause an integer underflow */
            char result = data - 1;
            printHexCharLine(result);
        }
    }
    else
    {
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
    }
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the first if */
static void goodG2B2()
{
    char data;
    data = ' ';
    if(global_returns_t())
    {
        /* FIX: Use a small value greater than the min value for this data type */
        data = 5;
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FLAW: Use the minimum size of the data type */
        data = CHAR_MIN;
    }
    if(global_returns_t())
    {
        {
            /* POTENTIAL FLAW: Subtracting 1 from data could cause an integer underflow */
            char result = data - 1;
            printHexCharLine(result);
        }
    }
    else
    {
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
    }
}

void CWE191_Integer_Underflow__char_fixed_11_good()
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
    CWE191_Integer_Underflow__char_fixed_11_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE191_Integer_Underflow__char_fixed_11_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
