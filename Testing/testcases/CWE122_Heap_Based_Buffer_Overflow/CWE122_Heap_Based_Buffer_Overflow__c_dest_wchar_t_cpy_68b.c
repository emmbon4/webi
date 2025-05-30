/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__c_dest_wchar_t_cpy_68b.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__c_dest.string.label.xml
Template File: sources-sink-68b.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Allocate using malloc() and set data pointer to a small buffer
 * GoodSource: Allocate using malloc() and set data pointer to a large buffer
 * Sink: cpy
 *    BadSink : Copy string to data using wcscpy
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

extern wchar_t * CWE122_Heap_Based_Buffer_Overflow__c_dest_wchar_t_cpy_68_bad_data;
extern wchar_t * CWE122_Heap_Based_Buffer_Overflow__c_dest_wchar_t_cpy_68_goodG2B_data;

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

void CWE122_Heap_Based_Buffer_Overflow__c_dest_wchar_t_cpy_68b_bad_sink()
{
    wchar_t * data = CWE122_Heap_Based_Buffer_Overflow__c_dest_wchar_t_cpy_68_bad_data;
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
void CWE122_Heap_Based_Buffer_Overflow__c_dest_wchar_t_cpy_68b_goodG2B_sink()
{
    wchar_t * data = CWE122_Heap_Based_Buffer_Overflow__c_dest_wchar_t_cpy_68_goodG2B_data;
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
