/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__unsigned_int_fixed_12.c
Label Definition File: CWE191_Integer_Underflow.label.xml
Template File: sources-sinks-12.tmpl.c
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: fixed Fixed value
 * GoodSource: Small, non-zero
 * Sinks:
 *    GoodSink: Ensure there is no underflow before performing the subtraction
 *    BadSink : Subtract 1 from data
 * Flow Variant: 12 Control flow: if(global_returns_t_or_f())
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE191_Integer_Underflow__unsigned_int_fixed_12_bad()
{
    unsigned int data;
    data = 0;
    if(global_returns_t_or_f())
    {
        /* FLAW: Use the minimum size of the data type */
        data = 0;
    }
    else
    {
        /* FIX: Use a small value greater than the min value for this data type */
        data = 5;
    }
    if(global_returns_t_or_f())
    {
        {
            /* POTENTIAL FLAW: Subtracting 1 from data could cause an integer underflow */
            unsigned int result = data - 1;
            printUnsignedLine(result);
        }
    }
    else
    {
        {
            unsigned int result = 0;
            /* FIX: Add a check to prevent an underflow from occurring */
            if (data > 0)
            {
                result = data - 1;
                printUnsignedLine(result);
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

/* goodB2G() - use badsource and goodsink by changing the first "if" so that
   both branches use the BadSource and the second "if" so that both branches
   use the GoodSink */
static void goodB2G()
{
    unsigned int data;
    data = 0;
    if(global_returns_t_or_f())
    {
        /* FLAW: Use the minimum size of the data type */
        data = 0;
    }
    else
    {
        /* FLAW: Use the minimum size of the data type */
        data = 0;
    }
    if(global_returns_t_or_f())
    {
        {
            unsigned int result = 0;
            /* FIX: Add a check to prevent an underflow from occurring */
            if (data > 0)
            {
                result = data - 1;
                printUnsignedLine(result);
            }
            else
            {
                printLine("Input value is too small to perform arithmetic safely.");
            }
        }
    }
    else
    {
        {
            unsigned int result = 0;
            /* FIX: Add a check to prevent an underflow from occurring */
            if (data > 0)
            {
                result = data - 1;
                printUnsignedLine(result);
            }
            else
            {
                printLine("Input value is too small to perform arithmetic safely.");
            }
        }
    }
}

/* goodG2B() - use goodsource and badsink by changing the first "if" so that
   both branches use the GoodSource and the second "if" so that both branches
   use the BadSink */
static void goodG2B()
{
    unsigned int data;
    data = 0;
    if(global_returns_t_or_f())
    {
        /* FIX: Use a small value greater than the min value for this data type */
        data = 5;
    }
    else
    {
        /* FIX: Use a small value greater than the min value for this data type */
        data = 5;
    }
    if(global_returns_t_or_f())
    {
        {
            /* POTENTIAL FLAW: Subtracting 1 from data could cause an integer underflow */
            unsigned int result = data - 1;
            printUnsignedLine(result);
        }
    }
    else
    {
        {
            /* POTENTIAL FLAW: Subtracting 1 from data could cause an integer underflow */
            unsigned int result = data - 1;
            printUnsignedLine(result);
        }
    }
}

void CWE191_Integer_Underflow__unsigned_int_fixed_12_good()
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
    CWE191_Integer_Underflow__unsigned_int_fixed_12_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE191_Integer_Underflow__unsigned_int_fixed_12_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
