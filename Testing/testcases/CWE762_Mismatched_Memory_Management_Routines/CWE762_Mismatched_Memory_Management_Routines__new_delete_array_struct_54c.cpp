/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__new_delete_array_struct_54c.cpp
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__new_delete_array.label.xml
Template File: sources-sinks-54c.tmpl.cpp
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * BadSource:  Allocate data using new
 * GoodSource: Allocate data using new []
 * Sinks:
 *    GoodSink: Deallocate data using delete
 *    BadSink : Deallocate data using delete []
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

namespace CWE762_Mismatched_Memory_Management_Routines__new_delete_array_struct_54
{

#ifndef OMITBAD

/* bad function declaration */
void bad_sink_d(twoints * data);

void bad_sink_c(twoints * data)
{
    bad_sink_d(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void goodG2B_sink_d(twoints * data);

void goodG2B_sink_c(twoints * data)
{
    goodG2B_sink_d(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void goodB2G_sink_d(twoints * data);

void goodB2G_sink_c(twoints * data)
{
    goodB2G_sink_d(data);
}

#endif /* OMITGOOD */

} // close namespace
