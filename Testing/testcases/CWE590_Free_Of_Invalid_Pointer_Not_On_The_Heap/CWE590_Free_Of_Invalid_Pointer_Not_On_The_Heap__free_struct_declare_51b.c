/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__free_struct_declare_51b.c
Label Definition File: CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__free.label.xml
Template File: sources-sink-51b.tmpl.c
*/
/*
 * @description
 * CWE: 590 Free of Invalid Pointer Not on the Heap
 * BadSource: declare Data buffer is declared on the stack
 * GoodSource: Allocate memory on the heap
 * Sink:
 *    BadSink : Print then free data
 * Flow Variant: 51 Data flow: data passed as an argument from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

void CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__free_struct_declare_51b_bad_sink(twoints * data)
{
    printStructLine(&data[0]);
    /* POTENTIAL FLAW: Possibly deallocating memory allocated on the stack */
    free(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__free_struct_declare_51b_goodG2B_sink(twoints * data)
{
    printStructLine(&data[0]);
    /* POTENTIAL FLAW: Possibly deallocating memory allocated on the stack */
    free(data);
}

#endif /* OMITGOOD */
