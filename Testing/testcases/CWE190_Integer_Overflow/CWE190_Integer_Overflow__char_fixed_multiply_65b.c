/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__char_fixed_multiply_65b.c
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-65b.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: fixed Fixed value
 * GoodSource: Small, non-zero
 * Sinks: multiply
 *    GoodSink: Ensure there is no overflow before performing the multiplication
 *    BadSink : Multiply data by 2
 * Flow Variant: 65 Data/control flow: data passed as an argument from one function to a function in a different source file called via a function pointer
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE190_Integer_Overflow__char_fixed_multiply_65b_bad_sink(char data)
{
    {
        /* POTENTIAL FLAW: Multiplying data by 2 could cause an overflow */
        char result = data * 2;
        printHexCharLine(result);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE190_Integer_Overflow__char_fixed_multiply_65b_goodG2B_sink(char data)
{
    {
        /* POTENTIAL FLAW: Multiplying data by 2 could cause an overflow */
        char result = data * 2;
        printHexCharLine(result);
    }
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE190_Integer_Overflow__char_fixed_multiply_65b_goodB2G_sink(char data)
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

#endif /* OMITGOOD */
