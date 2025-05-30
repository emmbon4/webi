/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__cpp_dest_class_loop_52b.cpp
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__cpp_dest.label.xml
Template File: sources-sink-52b.tmpl.cpp
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Allocate using new[] and set data pointer to a small buffer
 * GoodSource: Allocate using new[] and set data pointer to a large buffer
 * Sink: loop
 *    BadSink : Copy twointsclass array to data using a loop
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"

namespace CWE122_Heap_Based_Buffer_Overflow__cpp_dest_class_loop_52
{

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

/* bad function declaration */
void bad_sink_c(twointsclass * data);

void bad_sink_b(twointsclass * data)
{
    bad_sink_c(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void goodG2B_sink_c(twointsclass * data);

void goodG2B_sink_b(twointsclass * data)
{
    goodG2B_sink_c(data);
}

#endif /* OMITGOOD */

} // close namespace
