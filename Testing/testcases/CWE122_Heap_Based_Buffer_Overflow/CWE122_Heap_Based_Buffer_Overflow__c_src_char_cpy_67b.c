/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__c_src_char_cpy_67b.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__c_src.label.xml
Template File: sources-sink-67b.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Initialize data as a large string
 * GoodSource: Initialize data as a small string
 * Sinks: cpy
 *    BadSink : Copy data to string using strcpy
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

typedef struct _CWE122_Heap_Based_Buffer_Overflow__c_src_char_cpy_67_struct_type
{
    char * a;
} CWE122_Heap_Based_Buffer_Overflow__c_src_char_cpy_67_struct_type;

#ifndef OMITBAD

void CWE122_Heap_Based_Buffer_Overflow__c_src_char_cpy_67b_bad_sink(CWE122_Heap_Based_Buffer_Overflow__c_src_char_cpy_67_struct_type my_struct)
{
    char * data = my_struct.a;
    {
        char dest[50] = "";
        /* POTENTIAL FLAW: Possible buffer overflow if data is larger than dest */
        strcpy(dest, data);
        printLine(data);
        free(data);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE122_Heap_Based_Buffer_Overflow__c_src_char_cpy_67b_goodG2B_sink(CWE122_Heap_Based_Buffer_Overflow__c_src_char_cpy_67_struct_type my_struct)
{
    char * data = my_struct.a;
    {
        char dest[50] = "";
        /* POTENTIAL FLAW: Possible buffer overflow if data is larger than dest */
        strcpy(dest, data);
        printLine(data);
        free(data);
    }
}

#endif /* OMITGOOD */
