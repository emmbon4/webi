/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_from_Return__wchar_t_malloc_51b.c
Label Definition File: CWE690_NULL_Deref_from_Return.free.label.xml
Template File: source-sinks-51b.tmpl.c
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * BadSource: malloc Allocate data using malloc()
 * Sinks:
 *    GoodSink: Check to see if the data allocation failed and if not, use data
 *    BadSink : Don't check for NULL and use data
 * Flow Variant: 51 Data flow: data passed as an argument from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE690_NULL_Deref_from_Return__wchar_t_malloc_51b_bad_sink(wchar_t * data)
{
    /* POTENTIAL FLAW: Initialize memory buffer without checking to see if the memory allocation function failed */
    wcscpy(data, L"Initialize");
    printWLine(data);
    free(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

void CWE690_NULL_Deref_from_Return__wchar_t_malloc_51b_goodB2G_sink(wchar_t * data)
{
    /* FIX: Check to see if the memory allocation function was successful before initializing the memory buffer */
    if (data != NULL)
    {
        wcscpy(data, L"Initialize");
        printWLine(data);
        free(data);
    }
}

#endif /* OMITGOOD */
