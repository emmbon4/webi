/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__new_twointsclass_53b.cpp
Label Definition File: CWE401_Memory_Leak__new.label.xml
Template File: sources-sinks-53b.tmpl.cpp
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource:  Allocate data using new
 * GoodSource: Allocate data on the stack
 * Sinks:
 *    GoodSink: call delete on data
 *    BadSink : no deallocation of data
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

namespace CWE401_Memory_Leak__new_twointsclass_53
{

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

/* goodB2G uses the BadSource with the GoodSink */
void goodB2G_sink_c(twointsclass * data);

void goodB2G_sink_b(twointsclass * data)
{
    goodB2G_sink_c(data);
}

#endif /* OMITGOOD */

} // close namespace
