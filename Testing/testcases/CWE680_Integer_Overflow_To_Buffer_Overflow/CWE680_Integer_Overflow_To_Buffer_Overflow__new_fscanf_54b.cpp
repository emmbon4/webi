/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE680_Integer_Overflow_To_Buffer_Overflow__new_fscanf_54b.cpp
Label Definition File: CWE680_Integer_Overflow_To_Buffer_Overflow__new.label.xml
Template File: sources-sink-54b.tmpl.cpp
*/
/*
 * @description
 * CWE: 680 Integer Overflow to Buffer Overflow
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Small number greater than zero that will not cause an integer overflow in the sink
 * Sink:
 *    BadSink : Attempt to allocate array using length value from source
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

namespace CWE680_Integer_Overflow_To_Buffer_Overflow__new_fscanf_54
{

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

/* bad function declaration */
void bad_sink_c(int data);

void bad_sink_b(int data)
{
    bad_sink_c(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void goodG2B_sink_c(int data);

void goodG2B_sink_b(int data)
{
    goodG2B_sink_c(data);
}

#endif /* OMITGOOD */

} // close namespace
