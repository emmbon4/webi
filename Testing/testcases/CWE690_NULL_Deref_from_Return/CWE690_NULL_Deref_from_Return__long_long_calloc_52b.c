/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_from_Return__long_long_calloc_52b.c
Label Definition File: CWE690_NULL_Deref_from_Return.free.label.xml
Template File: source-sinks-52b.tmpl.c
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * BadSource: calloc Allocate data using calloc()
 * Sinks:
 *    GoodSink: Check to see if the data allocation failed and if not, use data
 *    BadSink : Don't check for NULL and use data
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

/* bad function declaration */
void CWE690_NULL_Deref_from_Return__long_long_calloc_52c_bad_sink(long long * data);

void CWE690_NULL_Deref_from_Return__long_long_calloc_52b_bad_sink(long long * data)
{
    CWE690_NULL_Deref_from_Return__long_long_calloc_52c_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G uses the BadSource with the GoodSink */
void CWE690_NULL_Deref_from_Return__long_long_calloc_52c_goodB2G_sink(long long * data);

void CWE690_NULL_Deref_from_Return__long_long_calloc_52b_goodB2G_sink(long long * data)
{
    CWE690_NULL_Deref_from_Return__long_long_calloc_52c_goodB2G_sink(data);
}

#endif /* OMITGOOD */
