/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__unsigned_char_fscanf_02.c
Label Definition File: CWE191_Integer_Underflow.label.xml
Template File: sources-sinks-02.tmpl.c
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Small, non-zero
 * Sinks:
 *    GoodSink: Ensure there is no underflow before performing the subtraction
 *    BadSink : Subtract 1 from data
 * Flow Variant: 02 Control flow: if(1) and if(0)
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE191_Integer_Underflow__unsigned_char_fscanf_02_bad()
{
    unsigned char data;
    data = ' ';
    if(1)
    {
        /* POTENTIAL FLAW: Use a value input from the console */
        fscanf (stdin, "%hc", &data);
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Use a small value greater than the min value for this data type */
        data = 5;
    }
    if(1)
    {
        {
            /* POTENTIAL FLAW: Subtracting 1 from data could cause an integer underflow */
            unsigned char result = data - 1;
            printHexUnsignedCharLine(result);
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            unsigned char result = 0;
            /* FIX: Add a check to prevent an underflow from occurring */
            if (data > 0)
            {
                result = data - 1;
                printHexUnsignedCharLine(result);
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

/* goodB2G1() - use badsource and goodsink by changing the second 1 to 0 */
static void goodB2G1()
{
    unsigned char data;
    data = ' ';
    if(1)
    {
        /* POTENTIAL FLAW: Use a value input from the console */
        fscanf (stdin, "%hc", &data);
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Use a small value greater than the min value for this data type */
        data = 5;
    }
    if(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* POTENTIAL FLAW: Subtracting 1 from data could cause an integer underflow */
            unsigned char result = data - 1;
            printHexUnsignedCharLine(result);
        }
    }
    else
    {
        {
            unsigned char result = 0;
            /* FIX: Add a check to prevent an underflow from occurring */
            if (data > 0)
            {
                result = data - 1;
                printHexUnsignedCharLine(result);
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
    unsigned char data;
    data = ' ';
    if(1)
    {
        /* POTENTIAL FLAW: Use a value input from the console */
        fscanf (stdin, "%hc", &data);
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Use a small value greater than the min value for this data type */
        data = 5;
    }
    if(1)
    {
        {
            unsigned char result = 0;
            /* FIX: Add a check to prevent an underflow from occurring */
            if (data > 0)
            {
                result = data - 1;
                printHexUnsignedCharLine(result);
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
            unsigned char result = data - 1;
            printHexUnsignedCharLine(result);
        }
    }
}

/* goodG2B1() - use goodsource and badsink by changing the first 1 to 0 */
static void goodG2B1()
{
    unsigned char data;
    data = ' ';
    if(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* POTENTIAL FLAW: Use a value input from the console */
        fscanf (stdin, "%hc", &data);
    }
    else
    {
        /* FIX: Use a small value greater than the min value for this data type */
        data = 5;
    }
    if(1)
    {
        {
            /* POTENTIAL FLAW: Subtracting 1 from data could cause an integer underflow */
            unsigned char result = data - 1;
            printHexUnsignedCharLine(result);
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            unsigned char result = 0;
            /* FIX: Add a check to prevent an underflow from occurring */
            if (data > 0)
            {
                result = data - 1;
                printHexUnsignedCharLine(result);
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
    unsigned char data;
    data = ' ';
    if(1)
    {
        /* FIX: Use a small value greater than the min value for this data type */
        data = 5;
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* POTENTIAL FLAW: Use a value input from the console */
        fscanf (stdin, "%hc", &data);
    }
    if(1)
    {
        {
            /* POTENTIAL FLAW: Subtracting 1 from data could cause an integer underflow */
            unsigned char result = data - 1;
            printHexUnsignedCharLine(result);
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            unsigned char result = 0;
            /* FIX: Add a check to prevent an underflow from occurring */
            if (data > 0)
            {
                result = data - 1;
                printHexUnsignedCharLine(result);
            }
            else
            {
                printLine("Input value is too small to perform arithmetic safely.");
            }
        }
    }
}

void CWE191_Integer_Underflow__unsigned_char_fscanf_02_good()
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
    CWE191_Integer_Underflow__unsigned_char_fscanf_02_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE191_Integer_Underflow__unsigned_char_fscanf_02_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
