/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE789_Uncontrolled_Mem_Alloc__malloc_char_fgets_53b.c
Label Definition File: CWE789_Uncontrolled_Mem_Alloc__malloc.label.xml
Template File: sources-sinks-53b.tmpl.c
*/
/*
 * @description
 * CWE: 789 Uncontrolled Memory Allocation
 * BadSource: fgets Read data from the console using fgets()
 * GoodSource: Small number greater than zero
 * Sinks:
 *    GoodSink: Allocate memory with malloc() and check the size of the memory to be allocated
 *    BadSink : Allocate memory with malloc(), but incorrectly check the size of the memory to be allocated
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

#define CHAR_ARRAY_SIZE sizeof(data)*sizeof(data)

#define HELLO_STRING "hello"

#ifndef OMITBAD

/* bad function declaration */
void CWE789_Uncontrolled_Mem_Alloc__malloc_char_fgets_53c_bad_sink(int data);

void CWE789_Uncontrolled_Mem_Alloc__malloc_char_fgets_53b_bad_sink(int data)
{
    CWE789_Uncontrolled_Mem_Alloc__malloc_char_fgets_53c_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE789_Uncontrolled_Mem_Alloc__malloc_char_fgets_53c_goodG2B_sink(int data);

void CWE789_Uncontrolled_Mem_Alloc__malloc_char_fgets_53b_goodG2B_sink(int data)
{
    CWE789_Uncontrolled_Mem_Alloc__malloc_char_fgets_53c_goodG2B_sink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE789_Uncontrolled_Mem_Alloc__malloc_char_fgets_53c_goodB2G_sink(int data);

void CWE789_Uncontrolled_Mem_Alloc__malloc_char_fgets_53b_goodB2G_sink(int data)
{
    CWE789_Uncontrolled_Mem_Alloc__malloc_char_fgets_53c_goodB2G_sink(data);
}

#endif /* OMITGOOD */
