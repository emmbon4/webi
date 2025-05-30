/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__delete_int_calloc_52b.cpp
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__delete.label.xml
Template File: sources-sinks-52b.tmpl.cpp
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * BadSource: calloc Allocate data using calloc()
 * GoodSource: Allocate data using new
 * Sinks:
 *    GoodSink: Deallocate data using free()
 *    BadSink : Deallocate data using delete
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"

namespace CWE762_Mismatched_Memory_Management_Routines__delete_int_calloc_52
{

#ifndef OMITBAD

/* bad function declaration */
void bad_sink_c(int * data);

void bad_sink_b(int * data)
{
    bad_sink_c(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void goodG2B_sink_c(int * data);

void goodG2B_sink_b(int * data)
{
    goodG2B_sink_c(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void goodB2G_sink_c(int * data);

void goodB2G_sink_b(int * data)
{
    goodB2G_sink_c(data);
}

#endif /* OMITGOOD */

} // close namespace
