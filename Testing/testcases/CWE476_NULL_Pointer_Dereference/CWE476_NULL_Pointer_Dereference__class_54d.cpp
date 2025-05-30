/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE476_NULL_Pointer_Dereference__class_54d.cpp
Label Definition File: CWE476_NULL_Pointer_Dereference__class.label.xml
Template File: sources-sink-54d.tmpl.cpp
*/
/*
 * @description
 * CWE: 476 NULL Pointer Dereference
 * BadSource:  Set data to NULL
 * GoodSource: Initialize data
 * Sink:
 *    BadSink : Print data
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

namespace CWE476_NULL_Pointer_Dereference__class_54
{

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

/* bad function declaration */
void bad_sink_e(twointsclass * data);

void bad_sink_d(twointsclass * data)
{
    bad_sink_e(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void goodG2B_sink_e(twointsclass * data);

void goodG2B_sink_d(twointsclass * data)
{
    goodG2B_sink_e(data);
}

#endif /* OMITGOOD */

} // close namespace
