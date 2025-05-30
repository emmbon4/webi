/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__c_dest_wchar_t_ncat_67b.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__c_dest.string.label.xml
Template File: sources-sink-67b.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Allocate using malloc() and set data pointer to a small buffer
 * GoodSource: Allocate using malloc() and set data pointer to a large buffer
 * Sinks: ncat
 *    BadSink : Copy string to data using wcsncat
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

typedef struct _CWE122_Heap_Based_Buffer_Overflow__c_dest_wchar_t_ncat_67_struct_type
{
    wchar_t * a;
} CWE122_Heap_Based_Buffer_Overflow__c_dest_wchar_t_ncat_67_struct_type;

#ifndef OMITBAD

void CWE122_Heap_Based_Buffer_Overflow__c_dest_wchar_t_ncat_67b_bad_sink(CWE122_Heap_Based_Buffer_Overflow__c_dest_wchar_t_ncat_67_struct_type my_struct)
{
    wchar_t * data = my_struct.a;
    {
        wchar_t src[100];
        wmemset(src, L'C', 100-1); /* fill with L'C's */
        src[100-1] = L'\0'; /* null terminate */
        /* POTENTIAL FLAW: Possible buffer overflow if src is larger than sizeof(data)-strlen(data) */
        wcsncat(data, src, 100);
        printWLine(data);
        free(data);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE122_Heap_Based_Buffer_Overflow__c_dest_wchar_t_ncat_67b_goodG2B_sink(CWE122_Heap_Based_Buffer_Overflow__c_dest_wchar_t_ncat_67_struct_type my_struct)
{
    wchar_t * data = my_struct.a;
    {
        wchar_t src[100];
        wmemset(src, L'C', 100-1); /* fill with L'C's */
        src[100-1] = L'\0'; /* null terminate */
        /* POTENTIAL FLAW: Possible buffer overflow if src is larger than sizeof(data)-strlen(data) */
        wcsncat(data, src, 100);
        printWLine(data);
        free(data);
    }
}

#endif /* OMITGOOD */
