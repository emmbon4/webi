/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE121_Stack_Based_Buffer_Overflow__src_char_alloca_snprintf_53c.c
Label Definition File: CWE121_Stack_Based_Buffer_Overflow__src.string.label.xml
Template File: sources-sink-53c.tmpl.c
*/
/*
 * @description
 * CWE: 121 Stack Based Buffer Overflow
 * BadSource:  Initialize data as a large string
 * GoodSource: Initialize data as a small string
 * Sink: snprintf
 *    BadSink : Copy data to string using snprintf
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

/* bad function declaration */
void CWE121_Stack_Based_Buffer_Overflow__src_char_alloca_snprintf_53d_bad_sink(char * data);

void CWE121_Stack_Based_Buffer_Overflow__src_char_alloca_snprintf_53c_bad_sink(char * data)
{
    CWE121_Stack_Based_Buffer_Overflow__src_char_alloca_snprintf_53d_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declaration */
void CWE121_Stack_Based_Buffer_Overflow__src_char_alloca_snprintf_53d_goodG2B_sink(char * data);

/* goodG2B uses the GoodSource with the BadSink */
void CWE121_Stack_Based_Buffer_Overflow__src_char_alloca_snprintf_53c_goodG2B_sink(char * data)
{
    CWE121_Stack_Based_Buffer_Overflow__src_char_alloca_snprintf_53d_goodG2B_sink(data);
}

#endif /* OMITGOOD */
