/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__unsigned_int_rand_66b.c
Label Definition File: CWE191_Integer_Underflow.label.xml
Template File: sources-sinks-66b.tmpl.c
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: rand Set data to result of rand()
 * GoodSource: Small, non-zero
 * Sinks:
 *    GoodSink: Ensure there is no underflow before performing the subtraction
 *    BadSink : Subtract 1 from data
 * Flow Variant: 66 Data flow: data passed in an array from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE191_Integer_Underflow__unsigned_int_rand_66b_bad_sink(unsigned int data_array[])
{
    /* copy data out of data_array */
    unsigned int data = data_array[2];
    {
        /* POTENTIAL FLAW: Subtracting 1 from data could cause an integer underflow */
        unsigned int result = data - 1;
        printUnsignedLine(result);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE191_Integer_Underflow__unsigned_int_rand_66b_goodG2B_sink(unsigned int data_array[])
{
    unsigned int data = data_array[2];
    {
        /* POTENTIAL FLAW: Subtracting 1 from data could cause an integer underflow */
        unsigned int result = data - 1;
        printUnsignedLine(result);
    }
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE191_Integer_Underflow__unsigned_int_rand_66b_goodB2G_sink(unsigned int data_array[])
{
    unsigned int data = data_array[2];
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

#endif /* OMITGOOD */
