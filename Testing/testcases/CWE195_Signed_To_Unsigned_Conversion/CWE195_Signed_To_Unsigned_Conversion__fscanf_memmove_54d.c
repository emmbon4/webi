/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE195_Signed_To_Unsigned_Conversion__fscanf_memmove_54d.c
Label Definition File: CWE195_Signed_To_Unsigned_Conversion.label.xml
Template File: sources-sink-54d.tmpl.c
*/
/*
 * @description
 * CWE: 195 Signed to Unsigned Conversion
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Positive integer
 * Sink: memmove
 *    BadSink : Copy strings using memmove() with the length of data
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

/* bad function declaration */
void CWE195_Signed_To_Unsigned_Conversion__fscanf_memmove_54e_bad_sink(int data);

void CWE195_Signed_To_Unsigned_Conversion__fscanf_memmove_54d_bad_sink(int data)
{
    CWE195_Signed_To_Unsigned_Conversion__fscanf_memmove_54e_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declaration */
void CWE195_Signed_To_Unsigned_Conversion__fscanf_memmove_54e_goodG2B_sink(int data);

/* goodG2B uses the GoodSource with the BadSink */
void CWE195_Signed_To_Unsigned_Conversion__fscanf_memmove_54d_goodG2B_sink(int data)
{
    CWE195_Signed_To_Unsigned_Conversion__fscanf_memmove_54e_goodG2B_sink(data);
}

#endif /* OMITGOOD */
