/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__unsigned_int_rand_multiply_61b.c
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-61b.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: rand Set data to result of rand()
 * GoodSource: Small, non-zero
 * Sinks: multiply
 *    GoodSink: Ensure there is no overflow before performing the multiplication
 *    BadSink : Multiply data by 2
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

unsigned int CWE190_Integer_Overflow__unsigned_int_rand_multiply_61b_bad_source(unsigned int data)
{
    /* POTENTIAL FLAW: Use a random value */
    data = (unsigned int)RAND32();
    return data;
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
unsigned int CWE190_Integer_Overflow__unsigned_int_rand_multiply_61b_goodG2B_source(unsigned int data)
{
    /* FIX: Use a small, non-zero value that will not cause an overflow in the sinks */
    data = 5;
    return data;
}

/* goodB2G() uses the BadSource with the GoodSink */
unsigned int CWE190_Integer_Overflow__unsigned_int_rand_multiply_61b_goodB2G_source(unsigned int data)
{
    /* POTENTIAL FLAW: Use a random value */
    data = (unsigned int)RAND32();
    return data;
}

#endif /* OMITGOOD */
