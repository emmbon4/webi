/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE457_Use_of_Uninitialized_Variable__double_pointer_63b.c
Label Definition File: CWE457_Use_of_Uninitialized_Variable.c.label.xml
Template File: sources-sinks-63b.tmpl.c
*/
/*
 * @description
 * CWE: 457 Use of Uninitialized Variable
 * BadSource: no_init Don't initialize data
 * GoodSource: Initialize data
 * Sinks: use
 *    GoodSink: Initialize then use data
 *    BadSink : Use data
 * Flow Variant: 63 Data flow: pointer to data passed from one function to another in different source files
 *
 * */

#include "std_testcase.h"

# include <wchar.h>

#ifndef OMITBAD

void CWE457_Use_of_Uninitialized_Variable__double_pointer_63b_bad_sink(double * * data_ptr)
{
    double * data = *data_ptr;
    printDoubleLine(*data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE457_Use_of_Uninitialized_Variable__double_pointer_63b_goodG2B_sink(double * * data_ptr)
{
    double * data = *data_ptr;
    printDoubleLine(*data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE457_Use_of_Uninitialized_Variable__double_pointer_63b_goodB2G_sink(double * * data_ptr)
{
    double * data = *data_ptr;
    /* initialize both the pointer and the data pointed to */
    data = (double *)malloc(sizeof(double));
    *data = 5.0;
    printDoubleLine(*data);
}

#endif /* OMITGOOD */
