/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE124_Buffer_Underwrite__wchar_t_alloca_ncpy_54c.c
Label Definition File: CWE124_Buffer_Underwrite.stack.label.xml
Template File: sources-sink-54c.tmpl.c
*/
/*
 * @description
 * CWE: 124 Buffer Underwrite
 * BadSource:  Set data pointer to before the allocated memory buffer
 * GoodSource: Set data pointer to the allocated memory buffer
 * Sink: ncpy
 *    BadSink : Copy string to data using wcsncpy
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

/* bad function declaration */
void CWE124_Buffer_Underwrite__wchar_t_alloca_ncpy_54d_bad_sink(wchar_t * data);

void CWE124_Buffer_Underwrite__wchar_t_alloca_ncpy_54c_bad_sink(wchar_t * data)
{
    CWE124_Buffer_Underwrite__wchar_t_alloca_ncpy_54d_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declaration */
void CWE124_Buffer_Underwrite__wchar_t_alloca_ncpy_54d_goodG2B_sink(wchar_t * data);

/* goodG2B uses the GoodSource with the BadSink */
void CWE124_Buffer_Underwrite__wchar_t_alloca_ncpy_54c_goodG2B_sink(wchar_t * data)
{
    CWE124_Buffer_Underwrite__wchar_t_alloca_ncpy_54d_goodG2B_sink(data);
}

#endif /* OMITGOOD */
