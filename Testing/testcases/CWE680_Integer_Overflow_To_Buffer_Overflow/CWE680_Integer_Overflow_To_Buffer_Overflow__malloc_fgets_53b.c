/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE680_Integer_Overflow_To_Buffer_Overflow__malloc_fgets_53b.c
Label Definition File: CWE680_Integer_Overflow_To_Buffer_Overflow__malloc.label.xml
Template File: sources-sink-53b.tmpl.c
*/
/*
 * @description
 * CWE: 680 Integer Overflow to Buffer Overflow
 * BadSource: fgets Read data from the console using fgets()
 * GoodSource: Small number greater than zero that will not cause an integer overflow in the sink
 * Sink:
 *    BadSink : Attempt to allocate array using length value from source
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

#define CHAR_ARRAY_SIZE sizeof(data)*sizeof(data)

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

/* bad function declaration */
void CWE680_Integer_Overflow_To_Buffer_Overflow__malloc_fgets_53c_bad_sink(int data);

void CWE680_Integer_Overflow_To_Buffer_Overflow__malloc_fgets_53b_bad_sink(int data)
{
    CWE680_Integer_Overflow_To_Buffer_Overflow__malloc_fgets_53c_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declaration */
void CWE680_Integer_Overflow_To_Buffer_Overflow__malloc_fgets_53c_goodG2B_sink(int data);

/* goodG2B uses the GoodSource with the BadSink */
void CWE680_Integer_Overflow_To_Buffer_Overflow__malloc_fgets_53b_goodG2B_sink(int data)
{
    CWE680_Integer_Overflow_To_Buffer_Overflow__malloc_fgets_53c_goodG2B_sink(data);
}

#endif /* OMITGOOD */
