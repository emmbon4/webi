/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE121_Stack_Based_Buffer_Overflow__src_wchar_t_alloca_loop_68b.c
Label Definition File: CWE121_Stack_Based_Buffer_Overflow__src.string.label.xml
Template File: sources-sink-68b.tmpl.c
*/
/*
 * @description
 * CWE: 121 Stack Based Buffer Overflow
 * BadSource:  Initialize data as a large string
 * GoodSource: Initialize data as a small string
 * Sink: loop
 *    BadSink : Copy data to string using a loop
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

extern wchar_t * CWE121_Stack_Based_Buffer_Overflow__src_wchar_t_alloca_loop_68_bad_data;
extern wchar_t * CWE121_Stack_Based_Buffer_Overflow__src_wchar_t_alloca_loop_68_goodG2B_data;

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

void CWE121_Stack_Based_Buffer_Overflow__src_wchar_t_alloca_loop_68b_bad_sink()
{
    wchar_t * data = CWE121_Stack_Based_Buffer_Overflow__src_wchar_t_alloca_loop_68_bad_data;
    {
        wchar_t dest[50] = L"";
        size_t i, data_len;
        data_len = wcslen(data);
        /* POTENTIAL FLAW: Possible buffer overflow if data is larger than dest */
        for (i = 0; i < data_len; i++)
        {
            dest[i] = data[i];
        }
        dest[50-1] = L'\0'; /* Ensure the destination buffer is null terminated */
        printWLine(data);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE121_Stack_Based_Buffer_Overflow__src_wchar_t_alloca_loop_68b_goodG2B_sink()
{
    wchar_t * data = CWE121_Stack_Based_Buffer_Overflow__src_wchar_t_alloca_loop_68_goodG2B_data;
    {
        wchar_t dest[50] = L"";
        size_t i, data_len;
        data_len = wcslen(data);
        /* POTENTIAL FLAW: Possible buffer overflow if data is larger than dest */
        for (i = 0; i < data_len; i++)
        {
            dest[i] = data[i];
        }
        dest[50-1] = L'\0'; /* Ensure the destination buffer is null terminated */
        printWLine(data);
    }
}

#endif /* OMITGOOD */
