/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_from_Return__struct_realloc_52c.c
Label Definition File: CWE690_NULL_Deref_from_Return.free.label.xml
Template File: source-sinks-52c.tmpl.c
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * BadSource: realloc Allocate data using realloc()
 * Sinks:
 *    GoodSink: Check to see if the data allocation failed and if not, use data
 *    BadSink : Don't check for NULL and use data
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE690_NULL_Deref_from_Return__struct_realloc_52c_bad_sink(twoints * data)
{
    /* POTENTIAL FLAW: Initialize memory buffer without checking to see if the memory allocation function failed */
    data[0].a = 1;
    data[0].b = 1;
    printStructLine(&data[0]);
    free(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

void CWE690_NULL_Deref_from_Return__struct_realloc_52c_goodB2G_sink(twoints * data)
{
    /* FIX: Check to see if the memory allocation function was successful before initializing the memory buffer */
    if (data != NULL)
    {
        data[0].a = 1;
        data[0].b = 1;
        printStructLine(&data[0]);
        free(data);
    }
}

#endif /* OMITGOOD */
