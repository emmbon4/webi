/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__cpp_dest_class_memcpy_67b.cpp
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__cpp_dest.label.xml
Template File: sources-sink-67b.tmpl.cpp
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Allocate using new[] and set data pointer to a small buffer
 * GoodSource: Allocate using new[] and set data pointer to a large buffer
 * Sinks: memcpy
 *    BadSink : Copy twointsclass array to data using memcpy
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

namespace CWE122_Heap_Based_Buffer_Overflow__cpp_dest_class_memcpy_67
{

typedef struct _struct_type
{
    twointsclass * a;
} struct_type;

#ifndef OMITBAD

void bad_sink(struct_type my_struct)
{
    twointsclass * data = my_struct.a;
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
        memcpy(data, src, 100*sizeof(twointsclass));
        printIntLine(data[0].a);
        delete [] data;
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void goodG2B_sink(struct_type my_struct)
{
    twointsclass * data = my_struct.a;
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
        memcpy(data, src, 100*sizeof(twointsclass));
        printIntLine(data[0].a);
        delete [] data;
    }
}

#endif /* OMITGOOD */

} // close namespace
