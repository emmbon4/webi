/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__new_long_long_66b.cpp
Label Definition File: CWE401_Memory_Leak__new.label.xml
Template File: sources-sinks-66b.tmpl.cpp
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource:  Allocate data using new
 * GoodSource: Allocate data on the stack
 * Sinks:
 *    GoodSink: call delete on data
 *    BadSink : no deallocation of data
 * Flow Variant: 66 Data flow: data passed in an array from one function to another in different source files
 *
 * */

#include "std_testcase.h"

namespace CWE401_Memory_Leak__new_long_long_66
{

#ifndef OMITBAD

void bad_sink(long long * data_array[])
{
    /* copy data out of data_array */
    long long * data = data_array[2];
    /* POTENTIAL FLAW: No deallocation */
    ; /* empty statement needed for some flow variants */
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void goodG2B_sink(long long * data_array[])
{
    long long * data = data_array[2];
    /* POTENTIAL FLAW: No deallocation */
    ; /* empty statement needed for some flow variants */
}

/* goodB2G uses the BadSource with the GoodSink */
void goodB2G_sink(long long * data_array[])
{
    long long * data = data_array[2];
    /* FIX: Deallocate memory */
    delete data;
}

#endif /* OMITGOOD */

} // close namespace
