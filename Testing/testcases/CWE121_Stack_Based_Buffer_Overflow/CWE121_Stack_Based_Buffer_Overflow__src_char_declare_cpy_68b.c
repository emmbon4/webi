/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE121_Stack_Based_Buffer_Overflow__src_char_declare_cpy_68b.c
Label Definition File: CWE121_Stack_Based_Buffer_Overflow__src.string.label.xml
Template File: sources-sink-68b.tmpl.c
*/
/*
 * @description
 * CWE: 121 Stack Based Buffer Overflow
 * BadSource:  Initialize data as a large string
 * GoodSource: Initialize data as a small string
 * Sink: cpy
 *    BadSink : Copy data to string using strcpy
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

extern char * CWE121_Stack_Based_Buffer_Overflow__src_char_declare_cpy_68_bad_data;
extern char * CWE121_Stack_Based_Buffer_Overflow__src_char_declare_cpy_68_goodG2B_data;

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

void CWE121_Stack_Based_Buffer_Overflow__src_char_declare_cpy_68b_bad_sink()
{
    char * data = CWE121_Stack_Based_Buffer_Overflow__src_char_declare_cpy_68_bad_data;
    {
        char dest[50] = "";
        /* POTENTIAL FLAW: Possible buffer overflow if data is larger than dest */
        strcpy(dest, data);
        printLine(data);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE121_Stack_Based_Buffer_Overflow__src_char_declare_cpy_68b_goodG2B_sink()
{
    char * data = CWE121_Stack_Based_Buffer_Overflow__src_char_declare_cpy_68_goodG2B_data;
    {
        char dest[50] = "";
        /* POTENTIAL FLAW: Possible buffer overflow if data is larger than dest */
        strcpy(dest, data);
        printLine(data);
    }
}

#endif /* OMITGOOD */
