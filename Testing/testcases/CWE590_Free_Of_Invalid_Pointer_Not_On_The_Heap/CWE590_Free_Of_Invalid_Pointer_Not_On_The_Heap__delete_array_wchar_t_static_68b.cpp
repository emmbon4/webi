/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__delete_array_wchar_t_static_68b.cpp
Label Definition File: CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__delete_array.label.xml
Template File: sources-sink-68b.tmpl.cpp
*/
/*
 * @description
 * CWE: 590 Free of Invalid Pointer Not on the Heap
 * BadSource: static Data buffer is declared static on the stack
 * GoodSource: Allocate memory on the heap
 * Sink:
 *    BadSink : Print then free data
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

extern wchar_t * CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__delete_array_wchar_t_static_68_bad_data;
extern wchar_t * CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__delete_array_wchar_t_static_68_goodG2B_data;

namespace CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__delete_array_wchar_t_static_68
{

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

void bad_sink()
{
    wchar_t * data = CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__delete_array_wchar_t_static_68_bad_data;
    printWLine(data);
    /* POTENTIAL FLAW: Possibly deallocating memory allocated on the stack */
    delete [] data;
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void goodG2B_sink()
{
    wchar_t * data = CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__delete_array_wchar_t_static_68_goodG2B_data;
    printWLine(data);
    /* POTENTIAL FLAW: Possibly deallocating memory allocated on the stack */
    delete [] data;
}

#endif /* OMITGOOD */

} // close namespace
