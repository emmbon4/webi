/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE416_Use_After_Free__new_delete_array_char_62b.cpp
Label Definition File: CWE416_Use_After_Free__new_delete_array.label.xml
Template File: sources-sinks-62b.tmpl.cpp
*/
/*
 * @description
 * CWE: 416 Use After Free
 * BadSource:  Allocate data using new, initialize memory block, and Deallocate data using delete
 * GoodSource: Allocate data using new and initialize memory block
 * Sinks:
 *    GoodSink: Do nothing
 *    BadSink : Use data after free()
 * Flow Variant: 62 Data flow: data flows using a C++ reference from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE416_Use_After_Free__new_delete_array_char_62
{

#ifndef OMITBAD

void bad_source(char * &data)
{
    data = new char[100];
    memset(data, 'A', 100-1);
    data[100-1] = '\0';
    /* POTENTIAL FLAW: Delete data in the source - the bad sink attempts to use data */
    delete [] data;
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
void goodG2B_source(char * &data)
{
    data = new char[100];
    memset(data, 'A', 100-1);
    data[100-1] = '\0';
    /* FIX: Do not delete data in the source */
}

/* goodB2G() uses the BadSource with the GoodSink */
void goodB2G_source(char * &data)
{
    data = new char[100];
    memset(data, 'A', 100-1);
    data[100-1] = '\0';
    /* POTENTIAL FLAW: Delete data in the source - the bad sink attempts to use data */
    delete [] data;
}

#endif /* OMITGOOD */

} // close namespace
