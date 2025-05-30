/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__unsigned_char_rand_add_54b.c
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-54b.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: rand Set data to result of rand()
 * GoodSource: Small, non-zero
 * Sinks: add
 *    GoodSink: Ensure there is no overflow before performing the addition
 *    BadSink : Add 1 to data
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

/* bad function declaration */
void CWE190_Integer_Overflow__unsigned_char_rand_add_54c_bad_sink(unsigned char data);

void CWE190_Integer_Overflow__unsigned_char_rand_add_54b_bad_sink(unsigned char data)
{
    CWE190_Integer_Overflow__unsigned_char_rand_add_54c_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE190_Integer_Overflow__unsigned_char_rand_add_54c_goodG2B_sink(unsigned char data);

void CWE190_Integer_Overflow__unsigned_char_rand_add_54b_goodG2B_sink(unsigned char data)
{
    CWE190_Integer_Overflow__unsigned_char_rand_add_54c_goodG2B_sink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE190_Integer_Overflow__unsigned_char_rand_add_54c_goodB2G_sink(unsigned char data);

void CWE190_Integer_Overflow__unsigned_char_rand_add_54b_goodB2G_sink(unsigned char data)
{
    CWE190_Integer_Overflow__unsigned_char_rand_add_54c_goodB2G_sink(data);
}

#endif /* OMITGOOD */
