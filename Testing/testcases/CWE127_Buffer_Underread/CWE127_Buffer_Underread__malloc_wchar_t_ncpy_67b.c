/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE127_Buffer_Underread__malloc_wchar_t_ncpy_67b.c
Label Definition File: CWE127_Buffer_Underread__malloc.label.xml
Template File: sources-sink-67b.tmpl.c
*/
/*
 * @description
 * CWE: 127 Buffer Under-read
 * BadSource:  Set data pointer to before the allocated memory buffer
 * GoodSource: Set data pointer to the allocated memory buffer
 * Sinks: ncpy
 *    BadSink : Copy data to string using wcsncpy
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

typedef struct _CWE127_Buffer_Underread__malloc_wchar_t_ncpy_67_struct_type
{
    wchar_t * a;
} CWE127_Buffer_Underread__malloc_wchar_t_ncpy_67_struct_type;

#ifndef OMITBAD

void CWE127_Buffer_Underread__malloc_wchar_t_ncpy_67b_bad_sink(CWE127_Buffer_Underread__malloc_wchar_t_ncpy_67_struct_type my_struct)
{
    wchar_t * data = my_struct.a;
    {
        wchar_t dest[100];
        wmemset(dest, L'C', 100-1); /* fill with 'C's */
        dest[100-1] = L'\0'; /* null terminate */
        /* POTENTIAL FLAW: Possibly copy from a memory location located before the source buffer */
        wcsncpy(dest, data, wcslen(dest));
        /* Ensure null termination */
        dest[100-1] = L'\0';
        printWLine(dest);
        /* INCIDENTAL CWE-401: Memory Leak - data may not point to location
           returned by malloc() so can't safely call free() on it */
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE127_Buffer_Underread__malloc_wchar_t_ncpy_67b_goodG2B_sink(CWE127_Buffer_Underread__malloc_wchar_t_ncpy_67_struct_type my_struct)
{
    wchar_t * data = my_struct.a;
    {
        wchar_t dest[100];
        wmemset(dest, L'C', 100-1); /* fill with 'C's */
        dest[100-1] = L'\0'; /* null terminate */
        /* POTENTIAL FLAW: Possibly copy from a memory location located before the source buffer */
        wcsncpy(dest, data, wcslen(dest));
        /* Ensure null termination */
        dest[100-1] = L'\0';
        printWLine(dest);
        /* INCIDENTAL CWE-401: Memory Leak - data may not point to location
           returned by malloc() so can't safely call free() on it */
    }
}

#endif /* OMITGOOD */
