/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE126_Buffer_Overread__wchar_t_alloca_memmove_53b.c
Label Definition File: CWE126_Buffer_Overread.stack.label.xml
Template File: sources-sink-53b.tmpl.c
*/
/*
 * @description
 * CWE: 126 Buffer Over-read
 * BadSource:  Set data pointer to a small buffer
 * GoodSource: Set data pointer to a large buffer
 * Sink: memmove
 *    BadSink : Copy data to string using memmove
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

/* bad function declaration */
void CWE126_Buffer_Overread__wchar_t_alloca_memmove_53c_bad_sink(wchar_t * data);

void CWE126_Buffer_Overread__wchar_t_alloca_memmove_53b_bad_sink(wchar_t * data)
{
    CWE126_Buffer_Overread__wchar_t_alloca_memmove_53c_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declaration */
void CWE126_Buffer_Overread__wchar_t_alloca_memmove_53c_goodG2B_sink(wchar_t * data);

/* goodG2B uses the GoodSource with the BadSink */
void CWE126_Buffer_Overread__wchar_t_alloca_memmove_53b_goodG2B_sink(wchar_t * data)
{
    CWE126_Buffer_Overread__wchar_t_alloca_memmove_53c_goodG2B_sink(data);
}

#endif /* OMITGOOD */
