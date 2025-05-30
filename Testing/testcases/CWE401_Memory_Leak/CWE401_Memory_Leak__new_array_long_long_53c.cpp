/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__new_array_long_long_53c.cpp
Label Definition File: CWE401_Memory_Leak__new_array.label.xml
Template File: sources-sinks-53c.tmpl.cpp
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource:  Allocate data using new[]
 * GoodSource: Point data to a stack buffer
 * Sinks:
 *    GoodSink: call delete[] on data
 *    BadSink : no deallocation of data
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

namespace CWE401_Memory_Leak__new_array_long_long_53
{

#ifndef OMITBAD

/* bad function declaration */
void bad_sink_d(long long * data);

void bad_sink_c(long long * data)
{
    bad_sink_d(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void goodG2B_sink_d(long long * data);

void goodG2B_sink_c(long long * data)
{
    goodG2B_sink_d(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void goodB2G_sink_d(long long * data);

void goodB2G_sink_c(long long * data)
{
    goodB2G_sink_d(data);
}

#endif /* OMITGOOD */

} // close namespace
