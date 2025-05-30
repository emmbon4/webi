/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE675_Duplicate_Operations_on_Resource__fopen_52b.c
Label Definition File: CWE675_Duplicate_Operations_on_Resource.label.xml
Template File: sources-sinks-52b.tmpl.c
*/
/*
 * @description
 * CWE: 675 Duplicate Operations on Resource
 * BadSource: fopen Open and close a file using fopen() and flose()
 * GoodSource: Open a file using fopen()
 * Sinks:
 *    GoodSink: Do nothing
 *    BadSink : Close the file
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

/* bad function declaration */
void CWE675_Duplicate_Operations_on_Resource__fopen_52c_bad_sink(FILE * data);

void CWE675_Duplicate_Operations_on_Resource__fopen_52b_bad_sink(FILE * data)
{
    CWE675_Duplicate_Operations_on_Resource__fopen_52c_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE675_Duplicate_Operations_on_Resource__fopen_52c_goodG2B_sink(FILE * data);

void CWE675_Duplicate_Operations_on_Resource__fopen_52b_goodG2B_sink(FILE * data)
{
    CWE675_Duplicate_Operations_on_Resource__fopen_52c_goodG2B_sink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE675_Duplicate_Operations_on_Resource__fopen_52c_goodB2G_sink(FILE * data);

void CWE675_Duplicate_Operations_on_Resource__fopen_52b_goodB2G_sink(FILE * data)
{
    CWE675_Duplicate_Operations_on_Resource__fopen_52c_goodB2G_sink(data);
}

#endif /* OMITGOOD */
