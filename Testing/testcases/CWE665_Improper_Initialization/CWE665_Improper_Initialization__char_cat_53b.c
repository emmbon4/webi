/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE665_Improper_Initialization__char_cat_53b.c
Label Definition File: CWE665_Improper_Initialization.label.xml
Template File: sources-sink-53b.tmpl.c
*/
/*
 * @description
 * CWE: 665 Improper Initialization
 * BadSource:  Do not initialize data properly
 * GoodSource: Initialize data
 * Sink: cat
 *    BadSink : Copy string to data using strcat
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

/* bad function declaration */
void CWE665_Improper_Initialization__char_cat_53c_bad_sink(char * data);

void CWE665_Improper_Initialization__char_cat_53b_bad_sink(char * data)
{
    CWE665_Improper_Initialization__char_cat_53c_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declaration */
void CWE665_Improper_Initialization__char_cat_53c_goodG2B_sink(char * data);

/* goodG2B uses the GoodSource with the BadSink */
void CWE665_Improper_Initialization__char_cat_53b_goodG2B_sink(char * data)
{
    CWE665_Improper_Initialization__char_cat_53c_goodG2B_sink(data);
}

#endif /* OMITGOOD */
