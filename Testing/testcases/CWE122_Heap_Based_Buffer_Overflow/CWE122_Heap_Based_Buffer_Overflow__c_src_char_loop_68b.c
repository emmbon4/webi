/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__c_src_char_loop_68b.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__c_src.label.xml
Template File: sources-sink-68b.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Initialize data as a large string
 * GoodSource: Initialize data as a small string
 * Sink: loop
 *    BadSink : Copy data to string using a loop
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

extern char * CWE122_Heap_Based_Buffer_Overflow__c_src_char_loop_68_bad_data;
extern char * CWE122_Heap_Based_Buffer_Overflow__c_src_char_loop_68_goodG2B_data;

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

void CWE122_Heap_Based_Buffer_Overflow__c_src_char_loop_68b_bad_sink()
{
    char * data = CWE122_Heap_Based_Buffer_Overflow__c_src_char_loop_68_bad_data;
    {
        char dest[50] = "";
        size_t i, data_len;
        data_len = strlen(data);
        /* POTENTIAL FLAW: Possible buffer overflow if data is larger than dest */
        for (i = 0; i < data_len; i++)
        {
            dest[i] = data[i];
        }
        dest[50-1] = '\0'; /* Ensure the destination buffer is null terminated */
        printLine(data);
        free(data);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE122_Heap_Based_Buffer_Overflow__c_src_char_loop_68b_goodG2B_sink()
{
    char * data = CWE122_Heap_Based_Buffer_Overflow__c_src_char_loop_68_goodG2B_data;
    {
        char dest[50] = "";
        size_t i, data_len;
        data_len = strlen(data);
        /* POTENTIAL FLAW: Possible buffer overflow if data is larger than dest */
        for (i = 0; i < data_len; i++)
        {
            dest[i] = data[i];
        }
        dest[50-1] = '\0'; /* Ensure the destination buffer is null terminated */
        printLine(data);
        free(data);
    }
}

#endif /* OMITGOOD */
