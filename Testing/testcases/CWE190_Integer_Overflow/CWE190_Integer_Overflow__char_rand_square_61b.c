/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__char_rand_square_61b.c
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-61b.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: rand Set data to result of rand()
 * GoodSource: Small, non-zero
 * Sinks: square
 *    GoodSink: Ensure there is no overflow before performing the squaring operation
 *    BadSink : Square data
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <math.h>

#ifndef OMITBAD

char CWE190_Integer_Overflow__char_rand_square_61b_bad_source(char data)
{
    /* POTENTIAL FLAW: Use a random value */
    data = (char)rand();
    return data;
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
char CWE190_Integer_Overflow__char_rand_square_61b_goodG2B_source(char data)
{
    /* FIX: Use a small, non-zero value that will not cause an overflow in the sinks */
    data = 5;
    return data;
}

/* goodB2G() uses the BadSource with the GoodSink */
char CWE190_Integer_Overflow__char_rand_square_61b_goodB2G_source(char data)
{
    /* POTENTIAL FLAW: Use a random value */
    data = (char)rand();
    return data;
}

#endif /* OMITGOOD */
