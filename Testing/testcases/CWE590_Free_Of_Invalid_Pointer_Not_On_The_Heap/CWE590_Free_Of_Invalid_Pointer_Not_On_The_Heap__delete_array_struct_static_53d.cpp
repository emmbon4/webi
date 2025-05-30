/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__delete_array_struct_static_53d.cpp
Label Definition File: CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__delete_array.label.xml
Template File: sources-sink-53d.tmpl.cpp
*/
/*
 * @description
 * CWE: 590 Free of Invalid Pointer Not on the Heap
 * BadSource: static Data buffer is declared static on the stack
 * GoodSource: Allocate memory on the heap
 * Sink:
 *    BadSink : Print then free data
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__delete_array_struct_static_53
{

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

void bad_sink_d(twoints * data)
{
    printStructLine(&data[0]);
    /* POTENTIAL FLAW: Possibly deallocating memory allocated on the stack */
    delete [] data;
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void goodG2B_sink_d(twoints * data)
{
    printStructLine(&data[0]);
    /* POTENTIAL FLAW: Possibly deallocating memory allocated on the stack */
    delete [] data;
}

#endif /* OMITGOOD */

} // close namespace
