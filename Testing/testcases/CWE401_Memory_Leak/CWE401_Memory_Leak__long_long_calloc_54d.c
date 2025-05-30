/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__long_long_calloc_54d.c
Label Definition File: CWE401_Memory_Leak.c.label.xml
Template File: sources-sinks-54d.tmpl.c
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource: calloc Allocate data using calloc()
 * GoodSource: Allocate data on the stack
 * Sinks:
 *    GoodSink: call free() on data
 *    BadSink : no deallocation of data
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

/* bad function declaration */
void CWE401_Memory_Leak__long_long_calloc_54e_bad_sink(long long * data);

void CWE401_Memory_Leak__long_long_calloc_54d_bad_sink(long long * data)
{
    CWE401_Memory_Leak__long_long_calloc_54e_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE401_Memory_Leak__long_long_calloc_54e_goodG2B_sink(long long * data);

void CWE401_Memory_Leak__long_long_calloc_54d_goodG2B_sink(long long * data)
{
    CWE401_Memory_Leak__long_long_calloc_54e_goodG2B_sink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE401_Memory_Leak__long_long_calloc_54e_goodB2G_sink(long long * data);

void CWE401_Memory_Leak__long_long_calloc_54d_goodB2G_sink(long long * data)
{
    CWE401_Memory_Leak__long_long_calloc_54e_goodB2G_sink(data);
}

#endif /* OMITGOOD */
