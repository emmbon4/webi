/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__no_close_fopen_54d.c
Label Definition File: CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__no_close.label.xml
Template File: source-sinks-54d.tmpl.c
*/
/*
 * @description
 * CWE: 772 Missing Release of Resource after Effective Lifetime
 * BadSource: fopen Open a file using fopen()
 * Sinks:
 *    GoodSink: Close the file using fclose()
 *    BadSink : Do not close file
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

/* bad function declaration */
void CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__no_close_fopen_54e_bad_sink(FILE * data);

void CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__no_close_fopen_54d_bad_sink(FILE * data)
{
    CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__no_close_fopen_54e_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G uses the BadSource with the GoodSink */
void CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__no_close_fopen_54e_goodB2G_sink(FILE * data);

void CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__no_close_fopen_54d_goodB2G_sink(FILE * data)
{
    CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__no_close_fopen_54e_goodB2G_sink(data);
}

#endif /* OMITGOOD */
