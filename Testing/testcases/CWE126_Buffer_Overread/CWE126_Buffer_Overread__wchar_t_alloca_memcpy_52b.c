/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE126_Buffer_Overread__wchar_t_alloca_memcpy_52b.c
Label Definition File: CWE126_Buffer_Overread.stack.label.xml
Template File: sources-sink-52b.tmpl.c
*/
/*
 * @description
 * CWE: 126 Buffer Over-read
 * BadSource:  Set data pointer to a small buffer
 * GoodSource: Set data pointer to a large buffer
 * Sink: memcpy
 *    BadSink : Copy data to string using memcpy
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

/* bad function declaration */
void CWE126_Buffer_Overread__wchar_t_alloca_memcpy_52c_bad_sink(wchar_t * data);

void CWE126_Buffer_Overread__wchar_t_alloca_memcpy_52b_bad_sink(wchar_t * data)
{
    CWE126_Buffer_Overread__wchar_t_alloca_memcpy_52c_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declaration */
void CWE126_Buffer_Overread__wchar_t_alloca_memcpy_52c_goodG2B_sink(wchar_t * data);

/* goodG2B uses the GoodSource with the BadSink */
void CWE126_Buffer_Overread__wchar_t_alloca_memcpy_52b_goodG2B_sink(wchar_t * data)
{
    CWE126_Buffer_Overread__wchar_t_alloca_memcpy_52c_goodG2B_sink(data);
}

#endif /* OMITGOOD */
