/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE127_Buffer_Underread__malloc_wchar_t_cpy_61b.c
Label Definition File: CWE127_Buffer_Underread__malloc.label.xml
Template File: sources-sink-61b.tmpl.c
*/
/*
 * @description
 * CWE: 127 Buffer Under-read
 * BadSource:  Set data pointer to before the allocated memory buffer
 * GoodSource: Set data pointer to the allocated memory buffer
 * Sinks: cpy
 *    BadSink : Copy data to string using wcscpy
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

wchar_t * CWE127_Buffer_Underread__malloc_wchar_t_cpy_61b_bad_source(wchar_t * data)
{
    {
        wchar_t * data_buf = (wchar_t *)malloc(100*sizeof(wchar_t));
        wmemset(data_buf, L'A', 100-1);
        data_buf[100-1] = L'\0';
        /* FLAW: Set data pointer to before the allocated memory buffer */
        data = data_buf - 8;
    }
    return data;
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
wchar_t * CWE127_Buffer_Underread__malloc_wchar_t_cpy_61b_goodG2B_source(wchar_t * data)
{
    {
        wchar_t * data_buf = (wchar_t *)malloc(100*sizeof(wchar_t));
        wmemset(data_buf, L'A', 100-1);
        data_buf[100-1] = L'\0';
        /* FIX: Set data pointer to the allocated memory buffer */
        data = data_buf;
    }
    return data;
}

#endif /* OMITGOOD */
