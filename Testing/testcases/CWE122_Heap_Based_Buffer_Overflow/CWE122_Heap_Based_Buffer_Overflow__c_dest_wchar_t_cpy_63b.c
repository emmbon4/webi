/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__c_dest_wchar_t_cpy_63b.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__c_dest.string.label.xml
Template File: sources-sink-63b.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Allocate using malloc() and set data pointer to a small buffer
 * GoodSource: Allocate using malloc() and set data pointer to a large buffer
 * Sinks: cpy
 *    BadSink : Copy string to data using wcscpy
 * Flow Variant: 63 Data flow: pointer to data passed from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE122_Heap_Based_Buffer_Overflow__c_dest_wchar_t_cpy_63b_bad_sink(wchar_t * * data_ptr)
{
    wchar_t * data = *data_ptr;
    {
        wchar_t src[100];
        wmemset(src, L'C', 100-1); /* fill with L'C's */
        src[100-1] = L'\0'; /* null terminate */
        /* POTENTIAL FLAW: Possible buffer overflow if src is larger than data */
        wcscpy(data, src);
        printWLine(data);
        free(data);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE122_Heap_Based_Buffer_Overflow__c_dest_wchar_t_cpy_63b_goodG2B_sink(wchar_t * * data_ptr)
{
    wchar_t * data = *data_ptr;
    {
        wchar_t src[100];
        wmemset(src, L'C', 100-1); /* fill with L'C's */
        src[100-1] = L'\0'; /* null terminate */
        /* POTENTIAL FLAW: Possible buffer overflow if src is larger than data */
        wcscpy(data, src);
        printWLine(data);
        free(data);
    }
}

#endif /* OMITGOOD */
