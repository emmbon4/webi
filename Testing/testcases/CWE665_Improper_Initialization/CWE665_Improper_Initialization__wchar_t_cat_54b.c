/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE665_Improper_Initialization__wchar_t_cat_54b.c
Label Definition File: CWE665_Improper_Initialization.label.xml
Template File: sources-sink-54b.tmpl.c
*/
/*
 * @description
 * CWE: 665 Improper Initialization
 * BadSource:  Do not initialize data properly
 * GoodSource: Initialize data
 * Sink: cat
 *    BadSink : Copy string to data using wcscat
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

/* bad function declaration */
void CWE665_Improper_Initialization__wchar_t_cat_54c_bad_sink(wchar_t * data);

void CWE665_Improper_Initialization__wchar_t_cat_54b_bad_sink(wchar_t * data)
{
    CWE665_Improper_Initialization__wchar_t_cat_54c_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declaration */
void CWE665_Improper_Initialization__wchar_t_cat_54c_goodG2B_sink(wchar_t * data);

/* goodG2B uses the GoodSource with the BadSink */
void CWE665_Improper_Initialization__wchar_t_cat_54b_goodG2B_sink(wchar_t * data)
{
    CWE665_Improper_Initialization__wchar_t_cat_54c_goodG2B_sink(data);
}

#endif /* OMITGOOD */
