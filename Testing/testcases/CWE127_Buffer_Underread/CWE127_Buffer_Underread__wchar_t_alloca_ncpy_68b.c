/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE127_Buffer_Underread__wchar_t_alloca_ncpy_68b.c
Label Definition File: CWE127_Buffer_Underread.stack.label.xml
Template File: sources-sink-68b.tmpl.c
*/
/*
 * @description
 * CWE: 127 Buffer Under-read
 * BadSource:  Set data pointer to before the allocated memory buffer
 * GoodSource: Set data pointer to the allocated memory buffer
 * Sink: ncpy
 *    BadSink : Copy data to string using wcsncpy
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

extern wchar_t * CWE127_Buffer_Underread__wchar_t_alloca_ncpy_68_bad_data;
extern wchar_t * CWE127_Buffer_Underread__wchar_t_alloca_ncpy_68_goodG2B_data;

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

void CWE127_Buffer_Underread__wchar_t_alloca_ncpy_68b_bad_sink()
{
    wchar_t * data = CWE127_Buffer_Underread__wchar_t_alloca_ncpy_68_bad_data;
    {
        wchar_t dest[100];
        wmemset(dest, L'C', 100-1); /* fill with 'C's */
        dest[100-1] = L'\0'; /* null terminate */
        /* POTENTIAL FLAW: Possibly copy from a memory location located before the source buffer */
        wcsncpy(dest, data, wcslen(dest));
        /* Ensure null termination */
        dest[100-1] = L'\0';
        printWLine(dest);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE127_Buffer_Underread__wchar_t_alloca_ncpy_68b_goodG2B_sink()
{
    wchar_t * data = CWE127_Buffer_Underread__wchar_t_alloca_ncpy_68_goodG2B_data;
    {
        wchar_t dest[100];
        wmemset(dest, L'C', 100-1); /* fill with 'C's */
        dest[100-1] = L'\0'; /* null terminate */
        /* POTENTIAL FLAW: Possibly copy from a memory location located before the source buffer */
        wcsncpy(dest, data, wcslen(dest));
        /* Ensure null termination */
        dest[100-1] = L'\0';
        printWLine(dest);
    }
}

#endif /* OMITGOOD */
