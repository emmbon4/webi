/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_from_Return__struct_malloc_67b.c
Label Definition File: CWE690_NULL_Deref_from_Return.free.label.xml
Template File: source-sinks-67b.tmpl.c
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * BadSource: malloc Allocate data using malloc()
 * Sinks:
 *    GoodSink: Check to see if the data allocation failed and if not, use data
 *    BadSink : Don't check for NULL and use data
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

typedef struct _CWE690_NULL_Deref_from_Return__struct_malloc_67_struct_type
{
    twoints * a;
} CWE690_NULL_Deref_from_Return__struct_malloc_67_struct_type;

#ifndef OMITBAD

void CWE690_NULL_Deref_from_Return__struct_malloc_67b_bad_sink(CWE690_NULL_Deref_from_Return__struct_malloc_67_struct_type my_struct)
{
    twoints * data = my_struct.a;
    /* POTENTIAL FLAW: Initialize memory buffer without checking to see if the memory allocation function failed */
    data[0].a = 1;
    data[0].b = 1;
    printStructLine(&data[0]);
    free(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G uses the BadSource with the GoodSink */
void CWE690_NULL_Deref_from_Return__struct_malloc_67b_goodB2G_sink(CWE690_NULL_Deref_from_Return__struct_malloc_67_struct_type my_struct)
{
    twoints * data = my_struct.a;
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
