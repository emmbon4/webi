/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE121_Stack_Based_Buffer_Overflow__dest_wchar_t_alloca_snprintf_68b.c
Label Definition File: CWE121_Stack_Based_Buffer_Overflow__dest.string.label.xml
Template File: sources-sink-68b.tmpl.c
*/
/*
 * @description
 * CWE: 121 Stack Based Buffer Overflow
 * BadSource:  Set data pointer to the bad buffer
 * GoodSource: Set data pointer to the good buffer
 * Sink: snprintf
 *    BadSink : Copy string to data using snwprintf
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

extern wchar_t * CWE121_Stack_Based_Buffer_Overflow__dest_wchar_t_alloca_snprintf_68_bad_data;
extern wchar_t * CWE121_Stack_Based_Buffer_Overflow__dest_wchar_t_alloca_snprintf_68_goodG2B_data;

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

void CWE121_Stack_Based_Buffer_Overflow__dest_wchar_t_alloca_snprintf_68b_bad_sink()
{
    wchar_t * data = CWE121_Stack_Based_Buffer_Overflow__dest_wchar_t_alloca_snprintf_68_bad_data;
    {
        wchar_t src[100];
        wmemset(src, L'C', 100-1); /* fill with L'C's */
        src[100-1] = L'\0'; /* null terminate */
        /* POTENTIAL FLAW: Possible buffer overflow if the size of data is less than the length of src */
        _snwprintf(data, 100, L"%s", src);
        printWLine(data);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE121_Stack_Based_Buffer_Overflow__dest_wchar_t_alloca_snprintf_68b_goodG2B_sink()
{
    wchar_t * data = CWE121_Stack_Based_Buffer_Overflow__dest_wchar_t_alloca_snprintf_68_goodG2B_data;
    {
        wchar_t src[100];
        wmemset(src, L'C', 100-1); /* fill with L'C's */
        src[100-1] = L'\0'; /* null terminate */
        /* POTENTIAL FLAW: Possible buffer overflow if the size of data is less than the length of src */
        _snwprintf(data, 100, L"%s", src);
        printWLine(data);
    }
}

#endif /* OMITGOOD */
