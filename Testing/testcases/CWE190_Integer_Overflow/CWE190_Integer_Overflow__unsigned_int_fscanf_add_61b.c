/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__unsigned_int_fscanf_add_61b.c
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-61b.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Small, non-zero
 * Sinks: add
 *    GoodSink: Ensure there is no overflow before performing the addition
 *    BadSink : Add 1 to data
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

unsigned int CWE190_Integer_Overflow__unsigned_int_fscanf_add_61b_bad_source(unsigned int data)
{
    /* POTENTIAL FLAW: Use a value input from the console */
    fscanf (stdin, "%u", &data);
    return data;
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
unsigned int CWE190_Integer_Overflow__unsigned_int_fscanf_add_61b_goodG2B_source(unsigned int data)
{
    /* FIX: Use a small, non-zero value that will not cause an overflow in the sinks */
    data = 5;
    return data;
}

/* goodB2G() uses the BadSource with the GoodSink */
unsigned int CWE190_Integer_Overflow__unsigned_int_fscanf_add_61b_goodB2G_source(unsigned int data)
{
    /* POTENTIAL FLAW: Use a value input from the console */
    fscanf (stdin, "%u", &data);
    return data;
}

#endif /* OMITGOOD */
