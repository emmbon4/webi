/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE665_Improper_Initialization__wchar_t_ncat_65b.c
Label Definition File: CWE665_Improper_Initialization.label.xml
Template File: sources-sink-65b.tmpl.c
*/
/*
 * @description
 * CWE: 665 Improper Initialization
 * BadSource:  Do not initialize data properly
 * GoodSource: Initialize data
 * Sinks: ncat
 *    BadSink : Copy string to data using wcsncat
 * Flow Variant: 65 Data/control flow: data passed as an argument from one function to a function in a different source file called via a function pointer
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE665_Improper_Initialization__wchar_t_ncat_65b_bad_sink(wchar_t * data)
{
    {
        size_t src_len;
        wchar_t src[100];
        wmemset(src, L'C', 100-1); /* fill with L'C's */
        src[100-1] = L'\0'; /* null terminate */
        src_len = wcslen(src);
        /* POTENTIAL FLAW: If data is not initialized properly, wcsncat() may not function correctly */
        wcsncat(data, src, src_len);
        printWLine(data);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE665_Improper_Initialization__wchar_t_ncat_65b_goodG2B_sink(wchar_t * data)
{
    {
        size_t src_len;
        wchar_t src[100];
        wmemset(src, L'C', 100-1); /* fill with L'C's */
        src[100-1] = L'\0'; /* null terminate */
        src_len = wcslen(src);
        /* POTENTIAL FLAW: If data is not initialized properly, wcsncat() may not function correctly */
        wcsncat(data, src, src_len);
        printWLine(data);
    }
}

#endif /* OMITGOOD */
