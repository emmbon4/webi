/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__strdup_wchar_t_63b.c
Label Definition File: CWE401_Memory_Leak__strdup.label.xml
Template File: sources-sinks-63b.tmpl.c
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource:  Allocate data using wcsdup()
 * GoodSource: Allocate data on the stack
 * Sinks:
 *    GoodSink: call free() on data
 *    BadSink : no deallocation of data
 * Flow Variant: 63 Data flow: pointer to data passed from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE401_Memory_Leak__strdup_wchar_t_63b_bad_sink(wchar_t * * data_ptr)
{
    wchar_t * data = *data_ptr;
    /* POTENTIAL FLAW: No deallocation of memory */
    /* no deallocation */
    ; /* empty statement needed for some flow variants */
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE401_Memory_Leak__strdup_wchar_t_63b_goodG2B_sink(wchar_t * * data_ptr)
{
    wchar_t * data = *data_ptr;
    /* POTENTIAL FLAW: No deallocation of memory */
    /* no deallocation */
    ; /* empty statement needed for some flow variants */
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE401_Memory_Leak__strdup_wchar_t_63b_goodB2G_sink(wchar_t * * data_ptr)
{
    wchar_t * data = *data_ptr;
    /* FIX: Deallocate memory initialized in the source */
    free(data);
}

#endif /* OMITGOOD */
