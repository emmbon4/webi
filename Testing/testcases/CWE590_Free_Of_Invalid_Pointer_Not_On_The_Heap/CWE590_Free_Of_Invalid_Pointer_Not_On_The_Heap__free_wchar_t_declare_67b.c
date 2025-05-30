/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__free_wchar_t_declare_67b.c
Label Definition File: CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__free.label.xml
Template File: sources-sink-67b.tmpl.c
*/
/*
 * @description
 * CWE: 590 Free of Invalid Pointer Not on the Heap
 * BadSource: declare Data buffer is declared on the stack
 * GoodSource: Allocate memory on the heap
 * Sinks:
 *    BadSink : Print then free data
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

typedef struct _CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__free_wchar_t_declare_67_struct_type
{
    wchar_t * a;
} CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__free_wchar_t_declare_67_struct_type;

#ifndef OMITBAD

void CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__free_wchar_t_declare_67b_bad_sink(CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__free_wchar_t_declare_67_struct_type my_struct)
{
    wchar_t * data = my_struct.a;
    printWLine(data);
    /* POTENTIAL FLAW: Possibly deallocating memory allocated on the stack */
    free(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__free_wchar_t_declare_67b_goodG2B_sink(CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__free_wchar_t_declare_67_struct_type my_struct)
{
    wchar_t * data = my_struct.a;
    printWLine(data);
    /* POTENTIAL FLAW: Possibly deallocating memory allocated on the stack */
    free(data);
}

#endif /* OMITGOOD */
