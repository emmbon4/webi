/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE121_Stack_Based_Buffer_Overflow__dest_long_long_alloca_memmove_53c.c
Label Definition File: CWE121_Stack_Based_Buffer_Overflow__dest.label.xml
Template File: sources-sink-53c.tmpl.c
*/
/*
 * @description
 * CWE: 121 Stack Based Buffer Overflow
 * BadSource:  Set data pointer to the bad buffer
 * GoodSource: Set data pointer to the good buffer
 * Sink: memmove
 *    BadSink : Copy long long array to data using memmove
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

/* bad function declaration */
void CWE121_Stack_Based_Buffer_Overflow__dest_long_long_alloca_memmove_53d_bad_sink(long long * data);

void CWE121_Stack_Based_Buffer_Overflow__dest_long_long_alloca_memmove_53c_bad_sink(long long * data)
{
    CWE121_Stack_Based_Buffer_Overflow__dest_long_long_alloca_memmove_53d_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declaration */
void CWE121_Stack_Based_Buffer_Overflow__dest_long_long_alloca_memmove_53d_goodG2B_sink(long long * data);

/* goodG2B uses the GoodSource with the BadSink */
void CWE121_Stack_Based_Buffer_Overflow__dest_long_long_alloca_memmove_53c_goodG2B_sink(long long * data)
{
    CWE121_Stack_Based_Buffer_Overflow__dest_long_long_alloca_memmove_53d_goodG2B_sink(data);
}

#endif /* OMITGOOD */
