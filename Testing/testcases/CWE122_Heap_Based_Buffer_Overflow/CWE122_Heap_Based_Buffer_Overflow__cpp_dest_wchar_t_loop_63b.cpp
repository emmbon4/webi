/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__cpp_dest_wchar_t_loop_63b.cpp
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__cpp_dest.string.label.xml
Template File: sources-sink-63b.tmpl.cpp
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Allocate using new[] and set data pointer to a small buffer
 * GoodSource: Allocate using new[] and set data pointer to a large buffer
 * Sinks: loop
 *    BadSink : Copy string to data using a loop
 * Flow Variant: 63 Data flow: pointer to data passed from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE122_Heap_Based_Buffer_Overflow__cpp_dest_wchar_t_loop_63
{

#ifndef OMITBAD

void bad_sink(wchar_t * * data_ptr)
{
    wchar_t * data = *data_ptr;
    {
        size_t i;
        wchar_t src[100];
        wmemset(src, L'C', 100-1); /* fill with L'C's */
        src[100-1] = L'\0'; /* null terminate */
        /* POTENTIAL FLAW: Possible buffer overflow if src is larger than data */
        for (i = 0; i < 100; i++)
        {
            data[i] = src[i];
        }
        data[100-1] = L'\0'; /* Ensure the destination buffer is null terminated */
        printWLine(data);
        delete [] data;
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void goodG2B_sink(wchar_t * * data_ptr)
{
    wchar_t * data = *data_ptr;
    {
        size_t i;
        wchar_t src[100];
        wmemset(src, L'C', 100-1); /* fill with L'C's */
        src[100-1] = L'\0'; /* null terminate */
        /* POTENTIAL FLAW: Possible buffer overflow if src is larger than data */
        for (i = 0; i < 100; i++)
        {
            data[i] = src[i];
        }
        data[100-1] = L'\0'; /* Ensure the destination buffer is null terminated */
        printWLine(data);
        delete [] data;
    }
}

#endif /* OMITGOOD */

} // close namespace
