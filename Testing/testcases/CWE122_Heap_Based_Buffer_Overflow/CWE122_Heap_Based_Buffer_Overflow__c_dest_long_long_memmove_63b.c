/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__c_dest_long_long_memmove_63b.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__c_dest.label.xml
Template File: sources-sink-63b.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Allocate using malloc() and set data pointer to a small buffer
 * GoodSource: Allocate using malloc() and set data pointer to a large buffer
 * Sinks: memmove
 *    BadSink : Copy long long array to data using memmove
 * Flow Variant: 63 Data flow: pointer to data passed from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE122_Heap_Based_Buffer_Overflow__c_dest_long_long_memmove_63b_bad_sink(long long * * data_ptr)
{
    long long * data = *data_ptr;
    {
        long long src[100] = {0}; /* fill with 0's */
        /* POTENTIAL FLAW: Possible buffer overflow if data < 100 */
        memmove(data, src, 100*sizeof(long long));
        printLongLongLine(data[0]);
        free(data);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE122_Heap_Based_Buffer_Overflow__c_dest_long_long_memmove_63b_goodG2B_sink(long long * * data_ptr)
{
    long long * data = *data_ptr;
    {
        long long src[100] = {0}; /* fill with 0's */
        /* POTENTIAL FLAW: Possible buffer overflow if data < 100 */
        memmove(data, src, 100*sizeof(long long));
        printLongLongLine(data[0]);
        free(data);
    }
}

#endif /* OMITGOOD */
