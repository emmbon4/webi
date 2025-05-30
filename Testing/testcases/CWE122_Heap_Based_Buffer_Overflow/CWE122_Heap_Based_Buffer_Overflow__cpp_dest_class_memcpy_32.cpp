/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__cpp_dest_class_memcpy_32.cpp
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__cpp_dest.label.xml
Template File: sources-sink-32.tmpl.cpp
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Allocate using new[] and set data pointer to a small buffer
 * GoodSource: Allocate using new[] and set data pointer to a large buffer
 * Sink: memcpy
 *    BadSink : Copy twointsclass array to data using memcpy
 * Flow Variant: 32 Data flow using two pointers to the same value within the same function
 *
 * */

#include "std_testcase.h"

namespace CWE122_Heap_Based_Buffer_Overflow__cpp_dest_class_memcpy_32
{

#ifndef OMITBAD

void bad()
{
    twointsclass * data;
    twointsclass * *data_ptr1 = &data;
    twointsclass * *data_ptr2 = &data;
    data = NULL;
    {
        twointsclass * data = *data_ptr1;
        /* FLAW: Allocate using new[] and point data to a small buffer that is smaller than the large buffer used in the sinks */
        data = new twointsclass[50];
        *data_ptr1 = data;
    }
    {
        twointsclass * data = *data_ptr2;
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
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    twointsclass * data;
    twointsclass * *data_ptr1 = &data;
    twointsclass * *data_ptr2 = &data;
    data = NULL;
    {
        twointsclass * data = *data_ptr1;
        /* FIX: Allocate using new[] and point data to a large buffer that is at least as large as the large buffer used in the sink */
        data = new twointsclass[100];
        *data_ptr1 = data;
    }
    {
        twointsclass * data = *data_ptr2;
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
}

void good()
{
    goodG2B();
}

#endif /* OMITGOOD */

} // close namespace

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */
#ifdef INCLUDEMAIN

using namespace CWE122_Heap_Based_Buffer_Overflow__cpp_dest_class_memcpy_32; // so that we can use good and bad easily

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
