/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE127_Buffer_Underread__new_wchar_t_memcpy_52b.cpp
Label Definition File: CWE127_Buffer_Underread__new.label.xml
Template File: sources-sink-52b.tmpl.cpp
*/
/*
 * @description
 * CWE: 127 Buffer Under-read
 * BadSource:  Set data pointer to before the allocated memory buffer
 * GoodSource: Set data pointer to the allocated memory buffer
 * Sink: memcpy
 *    BadSink : Copy data to string using memcpy
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE127_Buffer_Underread__new_wchar_t_memcpy_52
{

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

/* bad function declaration */
void bad_sink_c(wchar_t * data);

void bad_sink_b(wchar_t * data)
{
    bad_sink_c(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void goodG2B_sink_c(wchar_t * data);

void goodG2B_sink_b(wchar_t * data)
{
    goodG2B_sink_c(data);
}

#endif /* OMITGOOD */

} // close namespace
