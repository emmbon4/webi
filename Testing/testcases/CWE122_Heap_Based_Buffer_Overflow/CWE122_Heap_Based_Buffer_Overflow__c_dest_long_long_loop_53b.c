/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__c_dest_long_long_loop_53b.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__c_dest.label.xml
Template File: sources-sink-53b.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Allocate using malloc() and set data pointer to a small buffer
 * GoodSource: Allocate using malloc() and set data pointer to a large buffer
 * Sink: loop
 *    BadSink : Copy long long array to data using a loop
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

/* bad function declaration */
void CWE122_Heap_Based_Buffer_Overflow__c_dest_long_long_loop_53c_bad_sink(long long * data);

void CWE122_Heap_Based_Buffer_Overflow__c_dest_long_long_loop_53b_bad_sink(long long * data)
{
    CWE122_Heap_Based_Buffer_Overflow__c_dest_long_long_loop_53c_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declaration */
void CWE122_Heap_Based_Buffer_Overflow__c_dest_long_long_loop_53c_goodG2B_sink(long long * data);

/* goodG2B uses the GoodSource with the BadSink */
void CWE122_Heap_Based_Buffer_Overflow__c_dest_long_long_loop_53b_goodG2B_sink(long long * data)
{
    CWE122_Heap_Based_Buffer_Overflow__c_dest_long_long_loop_53c_goodG2B_sink(data);
}

#endif /* OMITGOOD */
