/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE126_Buffer_Overread__new_wchar_t_memmove_54c.cpp
Label Definition File: CWE126_Buffer_Overread__new.label.xml
Template File: sources-sink-54c.tmpl.cpp
*/
/*
 * @description
 * CWE: 126 Buffer Over-read
 * BadSource:  Use a small buffer
 * GoodSource: Use a large buffer
 * Sink: memmove
 *    BadSink : Copy data to string using memmove
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE126_Buffer_Overread__new_wchar_t_memmove_54
{

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

/* bad function declaration */
void bad_sink_d(wchar_t * data);

void bad_sink_c(wchar_t * data)
{
    bad_sink_d(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void goodG2B_sink_d(wchar_t * data);

void goodG2B_sink_c(wchar_t * data)
{
    goodG2B_sink_d(data);
}

#endif /* OMITGOOD */

} // close namespace
