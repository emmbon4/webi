/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_from_Return__fopen_52b.c
Label Definition File: CWE690_NULL_Deref_from_Return.fclose.label.xml
Template File: source-sinks-52b.tmpl.c
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * BadSource: fopen Open data with fopen()
 * Sinks: 0
 *    GoodSink: Check data for NULL
 *    BadSink : Do not check data for NULL
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

/* bad function declaration */
void CWE690_NULL_Deref_from_Return__fopen_52c_bad_sink(FILE * data);

void CWE690_NULL_Deref_from_Return__fopen_52b_bad_sink(FILE * data)
{
    CWE690_NULL_Deref_from_Return__fopen_52c_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G uses the BadSource with the GoodSink */
void CWE690_NULL_Deref_from_Return__fopen_52c_goodB2G_sink(FILE * data);

void CWE690_NULL_Deref_from_Return__fopen_52b_goodB2G_sink(FILE * data)
{
    CWE690_NULL_Deref_from_Return__fopen_52c_goodB2G_sink(data);
}

#endif /* OMITGOOD */
