/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__new_long_long_52c.cpp
Label Definition File: CWE401_Memory_Leak__new.label.xml
Template File: sources-sinks-52c.tmpl.cpp
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource:  Allocate data using new
 * GoodSource: Allocate data on the stack
 * Sinks:
 *    GoodSink: call delete on data
 *    BadSink : no deallocation of data
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"

namespace CWE401_Memory_Leak__new_long_long_52
{

#ifndef OMITBAD

void bad_sink_c(long long * data)
{
    /* POTENTIAL FLAW: No deallocation */
    ; /* empty statement needed for some flow variants */
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void goodG2B_sink_c(long long * data)
{
    /* POTENTIAL FLAW: No deallocation */
    ; /* empty statement needed for some flow variants */
}

/* goodB2G uses the BadSource with the GoodSink */
void goodB2G_sink_c(long long * data)
{
    /* FIX: Deallocate memory */
    delete data;
}

#endif /* OMITGOOD */

} // close namespace
