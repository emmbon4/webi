/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__cpp_src_wchar_t_snprintf_68b.cpp
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__cpp_src.label.xml
Template File: sources-sink-68b.tmpl.cpp
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Initialize data as a large string
 * GoodSource: Initialize data as a small string
 * Sink: snprintf
 *    BadSink : Copy data to string using snwprintf
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

extern wchar_t * CWE122_Heap_Based_Buffer_Overflow__cpp_src_wchar_t_snprintf_68_bad_data;
extern wchar_t * CWE122_Heap_Based_Buffer_Overflow__cpp_src_wchar_t_snprintf_68_goodG2B_data;

namespace CWE122_Heap_Based_Buffer_Overflow__cpp_src_wchar_t_snprintf_68
{

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

void bad_sink()
{
    wchar_t * data = CWE122_Heap_Based_Buffer_Overflow__cpp_src_wchar_t_snprintf_68_bad_data;
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
void goodG2B_sink()
{
    wchar_t * data = CWE122_Heap_Based_Buffer_Overflow__cpp_src_wchar_t_snprintf_68_goodG2B_data;
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
