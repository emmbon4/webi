/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE195_Signed_To_Unsigned_Conversion__fscanf_memcpy_52b.c
Label Definition File: CWE195_Signed_To_Unsigned_Conversion.label.xml
Template File: sources-sink-52b.tmpl.c
*/
/*
 * @description
 * CWE: 195 Signed to Unsigned Conversion
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Positive integer
 * Sink: memcpy
 *    BadSink : Copy strings using memcpy() with the length of data
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

/* bad function declaration */
void CWE195_Signed_To_Unsigned_Conversion__fscanf_memcpy_52c_bad_sink(int data);

void CWE195_Signed_To_Unsigned_Conversion__fscanf_memcpy_52b_bad_sink(int data)
{
    CWE195_Signed_To_Unsigned_Conversion__fscanf_memcpy_52c_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declaration */
void CWE195_Signed_To_Unsigned_Conversion__fscanf_memcpy_52c_goodG2B_sink(int data);

/* goodG2B uses the GoodSource with the BadSink */
void CWE195_Signed_To_Unsigned_Conversion__fscanf_memcpy_52b_goodG2B_sink(int data)
{
    CWE195_Signed_To_Unsigned_Conversion__fscanf_memcpy_52c_goodG2B_sink(data);
}

#endif /* OMITGOOD */
