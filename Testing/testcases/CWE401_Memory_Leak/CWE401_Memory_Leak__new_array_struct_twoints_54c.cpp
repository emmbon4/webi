/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__new_array_struct_twoints_54c.cpp
Label Definition File: CWE401_Memory_Leak__new_array.label.xml
Template File: sources-sinks-54c.tmpl.cpp
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource:  Allocate data using new[]
 * GoodSource: Point data to a stack buffer
 * Sinks:
 *    GoodSink: call delete[] on data
 *    BadSink : no deallocation of data
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

namespace CWE401_Memory_Leak__new_array_struct_twoints_54
{

#ifndef OMITBAD

/* bad function declaration */
void bad_sink_d(struct _twoints * data);

void bad_sink_c(struct _twoints * data)
{
    bad_sink_d(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void goodG2B_sink_d(struct _twoints * data);

void goodG2B_sink_c(struct _twoints * data)
{
    goodG2B_sink_d(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void goodB2G_sink_d(struct _twoints * data);

void goodB2G_sink_c(struct _twoints * data)
{
    goodB2G_sink_d(data);
}

#endif /* OMITGOOD */

} // close namespace
