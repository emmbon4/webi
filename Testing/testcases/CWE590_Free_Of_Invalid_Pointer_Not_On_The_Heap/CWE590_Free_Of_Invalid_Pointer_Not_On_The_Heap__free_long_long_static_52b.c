/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__free_long_long_static_52b.c
Label Definition File: CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__free.label.xml
Template File: sources-sink-52b.tmpl.c
*/
/*
 * @description
 * CWE: 590 Free of Invalid Pointer Not on the Heap
 * BadSource: static Data buffer is declared static on the stack
 * GoodSource: Allocate memory on the heap
 * Sink:
 *    BadSink : Print then free data
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

/* bad function declaration */
void CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__free_long_long_static_52c_bad_sink(long long * data);

void CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__free_long_long_static_52b_bad_sink(long long * data)
{
    CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__free_long_long_static_52c_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declaration */
void CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__free_long_long_static_52c_goodG2B_sink(long long * data);

/* goodG2B uses the GoodSource with the BadSink */
void CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__free_long_long_static_52b_goodG2B_sink(long long * data)
{
    CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__free_long_long_static_52c_goodG2B_sink(data);
}

#endif /* OMITGOOD */
