/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE124_Buffer_Underwrite__new_wchar_t_memcpy_54d.cpp
Label Definition File: CWE124_Buffer_Underwrite__new.label.xml
Template File: sources-sink-54d.tmpl.cpp
*/
/*
 * @description
 * CWE: 124 Buffer Underwrite
 * BadSource:  Set data pointer to before the allocated memory buffer
 * GoodSource: Set data pointer to the allocated memory buffer
 * Sink: memcpy
 *    BadSink : Copy string to data using memcpy
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE124_Buffer_Underwrite__new_wchar_t_memcpy_54
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
