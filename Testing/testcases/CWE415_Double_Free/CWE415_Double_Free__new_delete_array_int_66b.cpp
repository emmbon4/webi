/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__new_delete_array_int_66b.cpp
Label Definition File: CWE415_Double_Free__new_delete_array.label.xml
Template File: sources-sinks-66b.tmpl.cpp
*/
/*
 * @description
 * CWE: 415 Double Free
 * BadSource:  Allocate data using new and Deallocae data using delete
 * GoodSource: Allocate data using new
 * Sinks:
 *    GoodSink: do nothing
 *    BadSink : Deallocate data using delete
 * Flow Variant: 66 Data flow: data passed in an array from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE415_Double_Free__new_delete_array_int_66
{

#ifndef OMITBAD

void bad_sink(int * data_array[])
{
    /* copy data out of data_array */
    int * data = data_array[2];
    /* POTENTIAL FLAW: Possibly deleting memory twice */
    delete [] data;
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void goodG2B_sink(int * data_array[])
{
    int * data = data_array[2];
    /* POTENTIAL FLAW: Possibly deleting memory twice */
    delete [] data;
}

/* goodB2G uses the BadSource with the GoodSink */
void goodB2G_sink(int * data_array[])
{
    int * data = data_array[2];
    /* do nothing */
    /* FIX: Don't attempt to delete the memory */
    ; /* empty statement needed for some flow variants */
}

#endif /* OMITGOOD */

} // close namespace
