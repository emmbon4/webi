/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__cpp_dest_int_memcpy_68b.cpp
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__cpp_dest.label.xml
Template File: sources-sink-68b.tmpl.cpp
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Allocate using new[] and set data pointer to a small buffer
 * GoodSource: Allocate using new[] and set data pointer to a large buffer
 * Sink: memcpy
 *    BadSink : Copy int array to data using memcpy
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

extern int * CWE122_Heap_Based_Buffer_Overflow__cpp_dest_int_memcpy_68_bad_data;
extern int * CWE122_Heap_Based_Buffer_Overflow__cpp_dest_int_memcpy_68_goodG2B_data;

namespace CWE122_Heap_Based_Buffer_Overflow__cpp_dest_int_memcpy_68
{

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

void bad_sink()
{
    int * data = CWE122_Heap_Based_Buffer_Overflow__cpp_dest_int_memcpy_68_bad_data;
    {
        int src[100] = {0}; /* fill with 0's */
        /* POTENTIAL FLAW: Possible buffer overflow if data < 100 */
        memcpy(data, src, 100*sizeof(int));
        printIntLine(data[0]);
        delete [] data;
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void goodG2B_sink()
{
    int * data = CWE122_Heap_Based_Buffer_Overflow__cpp_dest_int_memcpy_68_goodG2B_data;
    {
        int src[100] = {0}; /* fill with 0's */
        /* POTENTIAL FLAW: Possible buffer overflow if data < 100 */
        memcpy(data, src, 100*sizeof(int));
        printIntLine(data[0]);
        delete [] data;
    }
}

#endif /* OMITGOOD */

} // close namespace
