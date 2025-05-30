/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__new_free_struct_61b.cpp
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__new_free.label.xml
Template File: sources-sinks-61b.tmpl.cpp
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * BadSource:  Allocate data using new
 * GoodSource: Allocate data using malloc()
 * Sinks:
 *    GoodSink: Deallocate data using delete
 *    BadSink : Deallocate data using free()
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

namespace CWE762_Mismatched_Memory_Management_Routines__new_free_struct_61
{

#ifndef OMITBAD

twoints * bad_source(twoints * data)
{
    /* POTENTIAL FLAW: Allocate memory with a function that requires delete to free the memory */
    data = new twoints;
    return data;
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
twoints * goodG2B_source(twoints * data)
{
    /* FIX: Allocate memory from the heap using malloc() */
    data = (twoints *)malloc(100*sizeof(twoints));
    return data;
}

/* goodB2G() uses the BadSource with the GoodSink */
twoints * goodB2G_source(twoints * data)
{
    /* POTENTIAL FLAW: Allocate memory with a function that requires delete to free the memory */
    data = new twoints;
    return data;
}

#endif /* OMITGOOD */

} // close namespace
