/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__cpp_dest_int_memmove_67b.cpp
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__cpp_dest.label.xml
Template File: sources-sink-67b.tmpl.cpp
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Allocate using new[] and set data pointer to a small buffer
 * GoodSource: Allocate using new[] and set data pointer to a large buffer
 * Sinks: memmove
 *    BadSink : Copy int array to data using memmove
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

namespace CWE122_Heap_Based_Buffer_Overflow__cpp_dest_int_memmove_67
{

typedef struct _struct_type
{
    int * a;
} struct_type;

#ifndef OMITBAD

void bad_sink(struct_type my_struct)
{
    int * data = my_struct.a;
    {
        int src[100] = {0}; /* fill with 0's */
        /* POTENTIAL FLAW: Possible buffer overflow if data < 100 */
        memmove(data, src, 100*sizeof(int));
        printIntLine(data[0]);
        delete [] data;
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void goodG2B_sink(struct_type my_struct)
{
    int * data = my_struct.a;
    {
        int src[100] = {0}; /* fill with 0's */
        /* POTENTIAL FLAW: Possible buffer overflow if data < 100 */
        memmove(data, src, 100*sizeof(int));
        printIntLine(data[0]);
        delete [] data;
    }
}

#endif /* OMITGOOD */

} // close namespace
