/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__delete_wchar_t_realloc_53b.cpp
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__delete.label.xml
Template File: sources-sinks-53b.tmpl.cpp
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * BadSource: realloc Allocate data using realloc()
 * GoodSource: Allocate data using new
 * Sinks:
 *    GoodSink: Deallocate data using free()
 *    BadSink : Deallocate data using delete
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

namespace CWE762_Mismatched_Memory_Management_Routines__delete_wchar_t_realloc_53
{

#ifndef OMITBAD

/* bad function declaration */
void bad_sink_c(wchar_t * data);

void bad_sink_b(wchar_t * data)
{
    bad_sink_c(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void goodG2B_sink_c(wchar_t * data);

void goodG2B_sink_b(wchar_t * data)
{
    goodG2B_sink_c(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void goodB2G_sink_c(wchar_t * data);

void goodB2G_sink_b(wchar_t * data)
{
    goodB2G_sink_c(data);
}

#endif /* OMITGOOD */

} // close namespace
