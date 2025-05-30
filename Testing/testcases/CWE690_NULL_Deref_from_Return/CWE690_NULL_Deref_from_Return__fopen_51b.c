/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_from_Return__fopen_51b.c
Label Definition File: CWE690_NULL_Deref_from_Return.fclose.label.xml
Template File: source-sinks-51b.tmpl.c
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * BadSource: fopen Open data with fopen()
 * Sinks: 0
 *    GoodSink: Check data for NULL
 *    BadSink : Do not check data for NULL
 * Flow Variant: 51 Data flow: data passed as an argument from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE690_NULL_Deref_from_Return__fopen_51b_bad_sink(FILE * data)
{
    /* FLAW: if the fopen failed, data could be NULL here */
    fclose(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

void CWE690_NULL_Deref_from_Return__fopen_51b_goodB2G_sink(FILE * data)
{
    /* FIX: check the return value */
    if (data != NULL)
    {
        fclose(data);
    }
}

#endif /* OMITGOOD */
