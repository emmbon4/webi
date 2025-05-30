/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE121_Stack_Based_Buffer_Overflow__dest_char_declare_snprintf_52b.c
Label Definition File: CWE121_Stack_Based_Buffer_Overflow__dest.string.label.xml
Template File: sources-sink-52b.tmpl.c
*/
/*
 * @description
 * CWE: 121 Stack Based Buffer Overflow
 * BadSource:  Set data pointer to the bad buffer
 * GoodSource: Set data pointer to the good buffer
 * Sink: snprintf
 *    BadSink : Copy string to data using snprintf
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

/* bad function declaration */
void CWE121_Stack_Based_Buffer_Overflow__dest_char_declare_snprintf_52c_bad_sink(char * data);

void CWE121_Stack_Based_Buffer_Overflow__dest_char_declare_snprintf_52b_bad_sink(char * data)
{
    CWE121_Stack_Based_Buffer_Overflow__dest_char_declare_snprintf_52c_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declaration */
void CWE121_Stack_Based_Buffer_Overflow__dest_char_declare_snprintf_52c_goodG2B_sink(char * data);

/* goodG2B uses the GoodSource with the BadSink */
void CWE121_Stack_Based_Buffer_Overflow__dest_char_declare_snprintf_52b_goodG2B_sink(char * data)
{
    CWE121_Stack_Based_Buffer_Overflow__dest_char_declare_snprintf_52c_goodG2B_sink(data);
}

#endif /* OMITGOOD */
