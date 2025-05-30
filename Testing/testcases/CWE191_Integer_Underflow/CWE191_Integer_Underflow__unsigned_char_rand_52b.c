/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__unsigned_char_rand_52b.c
Label Definition File: CWE191_Integer_Underflow.label.xml
Template File: sources-sinks-52b.tmpl.c
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: rand Set data to result of rand()
 * GoodSource: Small, non-zero
 * Sinks:
 *    GoodSink: Ensure there is no underflow before performing the subtraction
 *    BadSink : Subtract 1 from data
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

/* bad function declaration */
void CWE191_Integer_Underflow__unsigned_char_rand_52c_bad_sink(unsigned char data);

void CWE191_Integer_Underflow__unsigned_char_rand_52b_bad_sink(unsigned char data)
{
    CWE191_Integer_Underflow__unsigned_char_rand_52c_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE191_Integer_Underflow__unsigned_char_rand_52c_goodG2B_sink(unsigned char data);

void CWE191_Integer_Underflow__unsigned_char_rand_52b_goodG2B_sink(unsigned char data)
{
    CWE191_Integer_Underflow__unsigned_char_rand_52c_goodG2B_sink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE191_Integer_Underflow__unsigned_char_rand_52c_goodB2G_sink(unsigned char data);

void CWE191_Integer_Underflow__unsigned_char_rand_52b_goodB2G_sink(unsigned char data)
{
    CWE191_Integer_Underflow__unsigned_char_rand_52c_goodB2G_sink(data);
}

#endif /* OMITGOOD */
