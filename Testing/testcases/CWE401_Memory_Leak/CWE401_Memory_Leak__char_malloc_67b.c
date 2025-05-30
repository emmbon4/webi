/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__char_malloc_67b.c
Label Definition File: CWE401_Memory_Leak.c.label.xml
Template File: sources-sinks-67b.tmpl.c
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource: malloc Allocate data using malloc()
 * GoodSource: Allocate data on the stack
 * Sinks:
 *    GoodSink: call free() on data
 *    BadSink : no deallocation of data
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

typedef struct _CWE401_Memory_Leak__char_malloc_67_struct_type
{
    char * a;
} CWE401_Memory_Leak__char_malloc_67_struct_type;

#ifndef OMITBAD

void CWE401_Memory_Leak__char_malloc_67b_bad_sink(CWE401_Memory_Leak__char_malloc_67_struct_type my_struct)
{
    char * data = my_struct.a;
    /* POTENTIAL FLAW: No deallocation */
    ; /* empty statement needed for some flow variants */
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE401_Memory_Leak__char_malloc_67b_goodG2B_sink(CWE401_Memory_Leak__char_malloc_67_struct_type my_struct)
{
    char * data = my_struct.a;
    /* POTENTIAL FLAW: No deallocation */
    ; /* empty statement needed for some flow variants */
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE401_Memory_Leak__char_malloc_67b_goodB2G_sink(CWE401_Memory_Leak__char_malloc_67_struct_type my_struct)
{
    char * data = my_struct.a;
    /* FIX: Deallocate memory */
    free(data);
}

#endif /* OMITGOOD */
