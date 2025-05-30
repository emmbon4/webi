/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE416_Use_After_Free__new_delete_int_66b.cpp
Label Definition File: CWE416_Use_After_Free__new_delete.label.xml
Template File: sources-sinks-66b.tmpl.cpp
*/
/*
 * @description
 * CWE: 416 Use After Free
 * BadSource:  Allocate data using new, initialize memory block, and Deallocate data using delete
 * GoodSource: Allocate data using new and initialize memory block
 * Sinks:
 *    GoodSink: Do nothing
 *    BadSink : Use data after free()
 * Flow Variant: 66 Data flow: data passed in an array from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE416_Use_After_Free__new_delete_int_66
{

#ifndef OMITBAD

void bad_sink(int * data_array[])
{
    /* copy data out of data_array */
    int * data = data_array[2];
    /* POTENTIAL FLAW - Use of data that may have been deleted */
    printIntLine(*data);
    /* POTENTIAL INCIDENTAL - Possible memory leak here if data was not deleted */
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void goodG2B_sink(int * data_array[])
{
    int * data = data_array[2];
    /* POTENTIAL FLAW - Use of data that may have been deleted */
    printIntLine(*data);
    /* POTENTIAL INCIDENTAL - Possible memory leak here if data was not deleted */
}

/* goodB2G uses the BadSource with the GoodSink */
void goodB2G_sink(int * data_array[])
{
    int * data = data_array[2];
    /* FIX - Don't use data that may have been deleted already */
    /* POTENTIAL INCIDENTAL - Possible memory leak here if data was not deleted */
    /* do nothing */
    ; /* empty statement needed for some flow variants */
}

#endif /* OMITGOOD */

} // close namespace
