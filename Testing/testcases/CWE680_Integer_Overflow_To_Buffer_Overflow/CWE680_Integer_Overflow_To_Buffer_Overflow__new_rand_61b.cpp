/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE680_Integer_Overflow_To_Buffer_Overflow__new_rand_61b.cpp
Label Definition File: CWE680_Integer_Overflow_To_Buffer_Overflow__new.label.xml
Template File: sources-sink-61b.tmpl.cpp
*/
/*
 * @description
 * CWE: 680 Integer Overflow to Buffer Overflow
 * BadSource: rand Set data to result of rand(), which may be zero
 * GoodSource: Small number greater than zero that will not cause an integer overflow in the sink
 * Sinks:
 *    BadSink : Attempt to allocate array using length value from source
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

namespace CWE680_Integer_Overflow_To_Buffer_Overflow__new_rand_61
{

#ifndef OMITBAD

int bad_source(int data)
{
    data = RAND32();
    return data;
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
int goodG2B_source(int data)
{
    /* FIX: Set data to a relatively small number greater than zero */
    data = 20;
    return data;
}

#endif /* OMITGOOD */

} // close namespace
