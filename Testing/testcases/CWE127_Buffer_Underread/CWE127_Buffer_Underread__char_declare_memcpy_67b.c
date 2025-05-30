/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE127_Buffer_Underread__char_declare_memcpy_67b.c
Label Definition File: CWE127_Buffer_Underread.stack.label.xml
Template File: sources-sink-67b.tmpl.c
*/
/*
 * @description
 * CWE: 127 Buffer Under-read
 * BadSource:  Set data pointer to before the allocated memory buffer
 * GoodSource: Set data pointer to the allocated memory buffer
 * Sinks: memcpy
 *    BadSink : Copy data to string using memcpy
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

typedef struct _CWE127_Buffer_Underread__char_declare_memcpy_67_struct_type
{
    char * a;
} CWE127_Buffer_Underread__char_declare_memcpy_67_struct_type;

#ifndef OMITBAD

void CWE127_Buffer_Underread__char_declare_memcpy_67b_bad_sink(CWE127_Buffer_Underread__char_declare_memcpy_67_struct_type my_struct)
{
    char * data = my_struct.a;
    {
        char dest[100];
        memset(dest, 'C', 100-1); /* fill with 'C's */
        dest[100-1] = '\0'; /* null terminate */
        /* POTENTIAL FLAW: Possibly copy from a memory location located before the source buffer */
        memcpy(dest, data, 100*sizeof(char));
        /* Ensure null termination */
        dest[100-1] = '\0';
        printLine(dest);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE127_Buffer_Underread__char_declare_memcpy_67b_goodG2B_sink(CWE127_Buffer_Underread__char_declare_memcpy_67_struct_type my_struct)
{
    char * data = my_struct.a;
    {
        char dest[100];
        memset(dest, 'C', 100-1); /* fill with 'C's */
        dest[100-1] = '\0'; /* null terminate */
        /* POTENTIAL FLAW: Possibly copy from a memory location located before the source buffer */
        memcpy(dest, data, 100*sizeof(char));
        /* Ensure null termination */
        dest[100-1] = '\0';
        printLine(dest);
    }
}

#endif /* OMITGOOD */
