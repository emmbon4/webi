/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__cpp_src_wchar_t_snprintf_63b.cpp
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__cpp_src.label.xml
Template File: sources-sink-63b.tmpl.cpp
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Initialize data as a large string
 * GoodSource: Initialize data as a small string
 * Sinks: snprintf
 *    BadSink : Copy data to string using snwprintf
 * Flow Variant: 63 Data flow: pointer to data passed from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE122_Heap_Based_Buffer_Overflow__cpp_src_wchar_t_snprintf_63
{

#ifndef OMITBAD

void bad_sink(wchar_t * * data_ptr)
{
    wchar_t * data = *data_ptr;
    {
        wchar_t dest[50] = L"";
        /* POTENTIAL FLAW: Possible buffer overflow if data is larger than dest */
        _snwprintf(dest, wcslen(data), L"%s", data);
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
        wchar_t dest[50] = L"";
        /* POTENTIAL FLAW: Possible buffer overflow if data is larger than dest */
        _snwprintf(dest, wcslen(data), L"%s", data);
        printWLine(data);
        delete [] data;
    }
}

#endif /* OMITGOOD */

} // close namespace
