/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__cpp_src_wchar_t_cpy_54d.cpp
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__cpp_src.label.xml
Template File: sources-sink-54d.tmpl.cpp
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Initialize data as a large string
 * GoodSource: Initialize data as a small string
 * Sink: cpy
 *    BadSink : Copy data to string using wcscpy
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE122_Heap_Based_Buffer_Overflow__cpp_src_wchar_t_cpy_54
{

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

/* bad function declaration */
void bad_sink_e(wchar_t * data);

void bad_sink_d(wchar_t * data)
{
    bad_sink_e(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void goodG2B_sink_e(wchar_t * data);

void goodG2B_sink_d(wchar_t * data)
{
    goodG2B_sink_e(data);
}

#endif /* OMITGOOD */

} // close namespace
