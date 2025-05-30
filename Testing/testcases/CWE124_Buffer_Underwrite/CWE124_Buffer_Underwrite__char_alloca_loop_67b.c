/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE124_Buffer_Underwrite__char_alloca_loop_67b.c
Label Definition File: CWE124_Buffer_Underwrite.stack.label.xml
Template File: sources-sink-67b.tmpl.c
*/
/*
 * @description
 * CWE: 124 Buffer Underwrite
 * BadSource:  Set data pointer to before the allocated memory buffer
 * GoodSource: Set data pointer to the allocated memory buffer
 * Sinks: loop
 *    BadSink : Copy string to data using a loop
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

typedef struct _CWE124_Buffer_Underwrite__char_alloca_loop_67_struct_type
{
    char * a;
} CWE124_Buffer_Underwrite__char_alloca_loop_67_struct_type;

#ifndef OMITBAD

void CWE124_Buffer_Underwrite__char_alloca_loop_67b_bad_sink(CWE124_Buffer_Underwrite__char_alloca_loop_67_struct_type my_struct)
{
    char * data = my_struct.a;
    {
        size_t i;
        char src[100];
        memset(src, 'C', 100-1); /* fill with 'C's */
        src[100-1] = '\0'; /* null terminate */
        /* POTENTIAL FLAW: Possibly copying data to memory before the destination buffer */
        for (i = 0; i < 100; i++)
        {
            data[i] = src[i];
        }
        /* Ensure the destination buffer is null terminated */
        data[100-1] = '\0';
        printLine(data);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE124_Buffer_Underwrite__char_alloca_loop_67b_goodG2B_sink(CWE124_Buffer_Underwrite__char_alloca_loop_67_struct_type my_struct)
{
    char * data = my_struct.a;
    {
        size_t i;
        char src[100];
        memset(src, 'C', 100-1); /* fill with 'C's */
        src[100-1] = '\0'; /* null terminate */
        /* POTENTIAL FLAW: Possibly copying data to memory before the destination buffer */
        for (i = 0; i < 100; i++)
        {
            data[i] = src[i];
        }
        /* Ensure the destination buffer is null terminated */
        data[100-1] = '\0';
        printLine(data);
    }
}

#endif /* OMITGOOD */
