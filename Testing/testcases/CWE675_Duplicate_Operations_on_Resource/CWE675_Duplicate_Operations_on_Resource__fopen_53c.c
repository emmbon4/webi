/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE675_Duplicate_Operations_on_Resource__fopen_53c.c
Label Definition File: CWE675_Duplicate_Operations_on_Resource.label.xml
Template File: sources-sinks-53c.tmpl.c
*/
/*
 * @description
 * CWE: 675 Duplicate Operations on Resource
 * BadSource: fopen Open and close a file using fopen() and flose()
 * GoodSource: Open a file using fopen()
 * Sinks:
 *    GoodSink: Do nothing
 *    BadSink : Close the file
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

/* bad function declaration */
void CWE675_Duplicate_Operations_on_Resource__fopen_53d_bad_sink(FILE * data);

void CWE675_Duplicate_Operations_on_Resource__fopen_53c_bad_sink(FILE * data)
{
    CWE675_Duplicate_Operations_on_Resource__fopen_53d_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE675_Duplicate_Operations_on_Resource__fopen_53d_goodG2B_sink(FILE * data);

void CWE675_Duplicate_Operations_on_Resource__fopen_53c_goodG2B_sink(FILE * data)
{
    CWE675_Duplicate_Operations_on_Resource__fopen_53d_goodG2B_sink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE675_Duplicate_Operations_on_Resource__fopen_53d_goodB2G_sink(FILE * data);

void CWE675_Duplicate_Operations_on_Resource__fopen_53c_goodB2G_sink(FILE * data)
{
    CWE675_Duplicate_Operations_on_Resource__fopen_53d_goodB2G_sink(data);
}

#endif /* OMITGOOD */
