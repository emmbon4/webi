/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__cpp_dest_class_memmove_52c.cpp
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__cpp_dest.label.xml
Template File: sources-sink-52c.tmpl.cpp
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Allocate using new[] and set data pointer to a small buffer
 * GoodSource: Allocate using new[] and set data pointer to a large buffer
 * Sink: memmove
 *    BadSink : Copy twointsclass array to data using memmove
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"

namespace CWE122_Heap_Based_Buffer_Overflow__cpp_dest_class_memmove_52
{

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

void bad_sink_c(twointsclass * data)
{
    {
        twointsclass src[100];
        {
            size_t i;
            /* Initialize array */
            for (i = 0; i < 100; i++)
            {
                src[i].a = 0;
                src[i].b = 0;
            }
        }
        /* POTENTIAL FLAW: Possible buffer overflow if data < 100 */
        memmove(data, src, 100*sizeof(twointsclass));
        printIntLine(data[0].a);
        delete [] data;
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void goodG2B_sink_c(twointsclass * data)
{
    {
        twointsclass src[100];
        {
            size_t i;
            /* Initialize array */
            for (i = 0; i < 100; i++)
            {
                src[i].a = 0;
                src[i].b = 0;
            }
        }
        /* POTENTIAL FLAW: Possible buffer overflow if data < 100 */
        memmove(data, src, 100*sizeof(twointsclass));
        printIntLine(data[0].a);
        delete [] data;
    }
}

#endif /* OMITGOOD */

} // close namespace
