/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE680_Integer_Overflow_To_Buffer_Overflow__malloc_fscanf_52b.c
Label Definition File: CWE680_Integer_Overflow_To_Buffer_Overflow__malloc.label.xml
Template File: sources-sink-52b.tmpl.c
*/
/*
 * @description
 * CWE: 680 Integer Overflow to Buffer Overflow
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Small number greater than zero that will not cause an integer overflow in the sink
 * Sink:
 *    BadSink : Attempt to allocate array using length value from source
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

/* bad function declaration */
void CWE680_Integer_Overflow_To_Buffer_Overflow__malloc_fscanf_52c_bad_sink(int data);

void CWE680_Integer_Overflow_To_Buffer_Overflow__malloc_fscanf_52b_bad_sink(int data)
{
    CWE680_Integer_Overflow_To_Buffer_Overflow__malloc_fscanf_52c_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declaration */
void CWE680_Integer_Overflow_To_Buffer_Overflow__malloc_fscanf_52c_goodG2B_sink(int data);

/* goodG2B uses the GoodSource with the BadSink */
void CWE680_Integer_Overflow_To_Buffer_Overflow__malloc_fscanf_52b_goodG2B_sink(int data)
{
    CWE680_Integer_Overflow_To_Buffer_Overflow__malloc_fscanf_52c_goodG2B_sink(data);
}

#endif /* OMITGOOD */
