/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__char_rand_multiply_68b.c
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-68b.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: rand Set data to result of rand()
 * GoodSource: Small, non-zero
 * Sinks: multiply
 *    GoodSink: Ensure there is no overflow before performing the multiplication
 *    BadSink : Multiply data by 2
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

extern char CWE190_Integer_Overflow__char_rand_multiply_68_bad_data;
extern char CWE190_Integer_Overflow__char_rand_multiply_68_goodG2B_data;
extern char CWE190_Integer_Overflow__char_rand_multiply_68_goodB2G_data;

#ifndef OMITBAD

void CWE190_Integer_Overflow__char_rand_multiply_68b_bad_sink()
{
    char data = CWE190_Integer_Overflow__char_rand_multiply_68_bad_data;
    {
        /* POTENTIAL FLAW: Multiplying data by 2 could cause an overflow */
        char result = data * 2;
        printHexCharLine(result);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE190_Integer_Overflow__char_rand_multiply_68b_goodG2B_sink()
{
    char data = CWE190_Integer_Overflow__char_rand_multiply_68_goodG2B_data;
    {
        /* POTENTIAL FLAW: Multiplying data by 2 could cause an overflow */
        char result = data * 2;
        printHexCharLine(result);
    }
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE190_Integer_Overflow__char_rand_multiply_68b_goodB2G_sink()
{
    char data = CWE190_Integer_Overflow__char_rand_multiply_68_goodB2G_data;
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
