/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__c_src_wchar_t_loop_53c.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__c_src.label.xml
Template File: sources-sink-53c.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Initialize data as a large string
 * GoodSource: Initialize data as a small string
 * Sink: loop
 *    BadSink : Copy data to string using a loop
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

/* bad function declaration */
void CWE122_Heap_Based_Buffer_Overflow__c_src_wchar_t_loop_53d_bad_sink(wchar_t * data);

void CWE122_Heap_Based_Buffer_Overflow__c_src_wchar_t_loop_53c_bad_sink(wchar_t * data)
{
    CWE122_Heap_Based_Buffer_Overflow__c_src_wchar_t_loop_53d_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declaration */
void CWE122_Heap_Based_Buffer_Overflow__c_src_wchar_t_loop_53d_goodG2B_sink(wchar_t * data);

/* goodG2B uses the GoodSource with the BadSink */
void CWE122_Heap_Based_Buffer_Overflow__c_src_wchar_t_loop_53c_goodG2B_sink(wchar_t * data)
{
    CWE122_Heap_Based_Buffer_Overflow__c_src_wchar_t_loop_53d_goodG2B_sink(data);
}

#endif /* OMITGOOD */
