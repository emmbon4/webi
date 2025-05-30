/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__delete_class_realloc_62b.cpp
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__delete.label.xml
Template File: sources-sinks-62b.tmpl.cpp
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * BadSource: realloc Allocate data using realloc()
 * GoodSource: Allocate data using new
 * Sinks:
 *    GoodSink: Deallocate data using free()
 *    BadSink : Deallocate data using delete
 * Flow Variant: 62 Data flow: data flows using a C++ reference from one function to another in different source files
 *
 * */

#include "std_testcase.h"

namespace CWE762_Mismatched_Memory_Management_Routines__delete_class_realloc_62
{

#ifndef OMITBAD

void bad_source(twointsclass * &data)
{
    data = NULL;
    /* POTENTIAL FLAW: Allocate memory with a function that requires free() to free the memory */
    data = (twointsclass *)realloc(data, 100*sizeof(twointsclass));
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
void goodG2B_source(twointsclass * &data)
{
    /* FIX: Allocate memory from the heap using new */
    data = new twointsclass;
}

/* goodB2G() uses the BadSource with the GoodSink */
void goodB2G_source(twointsclass * &data)
{
    data = NULL;
    /* POTENTIAL FLAW: Allocate memory with a function that requires free() to free the memory */
    data = (twointsclass *)realloc(data, 100*sizeof(twointsclass));
}

#endif /* OMITGOOD */

} // close namespace
