/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE457_Use_of_Uninitialized_Variable__long_long_64b.c
Label Definition File: CWE457_Use_of_Uninitialized_Variable.c.label.xml
Template File: sources-sinks-64b.tmpl.c
*/
/*
 * @description
 * CWE: 457 Use of Uninitialized Variable
 * BadSource: no_init Don't initialize data
 * GoodSource: Initialize data
 * Sinks: use
 *    GoodSink: Initialize then use data
 *    BadSink : Use data
 * Flow Variant: 64 Data flow: void pointer to data passed from one function to another in different source files
 *
 * */

#include "std_testcase.h"

# include <wchar.h>

#ifndef OMITBAD

void CWE457_Use_of_Uninitialized_Variable__long_long_64b_bad_sink(void * void_data_ptr)
{
    /* cast void pointer to a pointer of the appropriate type */
    long long * data_ptr = (long long *)void_data_ptr;
    /* dereference data_ptr into data */
    long long data = (*data_ptr);
    printLongLongLine(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE457_Use_of_Uninitialized_Variable__long_long_64b_goodG2B_sink(void * void_data_ptr)
{
    /* cast void pointer to a pointer of the appropriate type */
    long long * data_ptr = (long long *)void_data_ptr;
    /* dereference data_ptr into data */
    long long data = (*data_ptr);
    printLongLongLine(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE457_Use_of_Uninitialized_Variable__long_long_64b_goodB2G_sink(void * void_data_ptr)
{
    /* cast void pointer to a pointer of the appropriate type */
    long long * data_ptr = (long long *)void_data_ptr;
    /* dereference data_ptr into data */
    long long data = (*data_ptr);
    data = 5L;
    printLongLongLine(data);
}

#endif /* OMITGOOD */
