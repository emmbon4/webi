/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE127_Buffer_Underread__wchar_t_alloca_memmove_53b.c
Label Definition File: CWE127_Buffer_Underread.stack.label.xml
Template File: sources-sink-53b.tmpl.c
*/
/*
 * @description
 * CWE: 127 Buffer Under-read
 * BadSource:  Set data pointer to before the allocated memory buffer
 * GoodSource: Set data pointer to the allocated memory buffer
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
void CWE127_Buffer_Underread__wchar_t_alloca_memmove_53c_bad_sink(wchar_t * data);

void CWE127_Buffer_Underread__wchar_t_alloca_memmove_53b_bad_sink(wchar_t * data)
{
    CWE127_Buffer_Underread__wchar_t_alloca_memmove_53c_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declaration */
void CWE127_Buffer_Underread__wchar_t_alloca_memmove_53c_goodG2B_sink(wchar_t * data);

/* goodG2B uses the GoodSource with the BadSink */
void CWE127_Buffer_Underread__wchar_t_alloca_memmove_53b_goodG2B_sink(wchar_t * data)
{
    CWE127_Buffer_Underread__wchar_t_alloca_memmove_53c_goodG2B_sink(data);
}

#endif /* OMITGOOD */
