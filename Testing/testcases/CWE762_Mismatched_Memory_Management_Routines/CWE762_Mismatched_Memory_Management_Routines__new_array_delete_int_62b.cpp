/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__new_array_delete_int_62b.cpp
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__new_array_delete.label.xml
Template File: sources-sinks-62b.tmpl.cpp
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * BadSource:  Allocate data using new []
 * GoodSource: Allocate data using new
 * Sinks:
 *    GoodSink: Deallocate data using delete []
 *    BadSink : Deallocate data using delete
 * Flow Variant: 62 Data flow: data flows using a C++ reference from one function to another in different source files
 *
 * */

#include "std_testcase.h"

namespace CWE762_Mismatched_Memory_Management_Routines__new_array_delete_int_62
{

#ifndef OMITBAD

void bad_source(int * &data)
{
    /* POTENTIAL FLAW: Allocate memory with a function that requires delete [] to free the memory */
    data = new int[100];
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
void goodG2B_source(int * &data)
{
    /* FIX: Allocate memory from the heap using new */
    data = new int;
}

/* goodB2G() uses the BadSource with the GoodSink */
void goodB2G_source(int * &data)
{
    /* POTENTIAL FLAW: Allocate memory with a function that requires delete [] to free the memory */
    data = new int[100];
}

#endif /* OMITGOOD */

} // close namespace
