/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__new_delete_array_char_65b.cpp
Label Definition File: CWE415_Double_Free__new_delete_array.label.xml
Template File: sources-sinks-65b.tmpl.cpp
*/
/*
 * @description
 * CWE: 415 Double Free
 * BadSource:  Allocate data using new and Deallocae data using delete
 * GoodSource: Allocate data using new
 * Sinks:
 *    GoodSink: do nothing
 *    BadSink : Deallocate data using delete
 * Flow Variant: 65 Data/control flow: data passed as an argument from one function to a function in a different source file called via a function pointer
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE415_Double_Free__new_delete_array_char_65
{

#ifndef OMITBAD

void bad_sink(char * data)
{
    /* POTENTIAL FLAW: Possibly deleting memory twice */
    delete [] data;
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void goodG2B_sink(char * data)
{
    /* POTENTIAL FLAW: Possibly deleting memory twice */
    delete [] data;
}

/* goodB2G uses the BadSource with the GoodSink */
void goodB2G_sink(char * data)
{
    /* do nothing */
    /* FIX: Don't attempt to delete the memory */
    ; /* empty statement needed for some flow variants */
}

#endif /* OMITGOOD */

} // close namespace
