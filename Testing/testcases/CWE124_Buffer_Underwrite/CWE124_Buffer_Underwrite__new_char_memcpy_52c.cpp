/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE124_Buffer_Underwrite__new_char_memcpy_52c.cpp
Label Definition File: CWE124_Buffer_Underwrite__new.label.xml
Template File: sources-sink-52c.tmpl.cpp
*/
/*
 * @description
 * CWE: 124 Buffer Underwrite
 * BadSource:  Set data pointer to before the allocated memory buffer
 * GoodSource: Set data pointer to the allocated memory buffer
 * Sink: memcpy
 *    BadSink : Copy string to data using memcpy
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE124_Buffer_Underwrite__new_char_memcpy_52
{

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

void bad_sink_c(char * data)
{
    {
        char src[100];
        memset(src, 'C', 100-1); /* fill with 'C's */
        src[100-1] = '\0'; /* null terminate */
        /* POTENTIAL FLAW: Possibly copying data to memory before the destination buffer */
        memcpy(data, src, 100*sizeof(char));
        /* Ensure the destination buffer is null terminated */
        data[100-1] = '\0';
        printLine(data);
        /* INCIDENTAL CWE-401: Memory Leak - data may not point to location
           returned by new [] so can't safely call delete [] on it */
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void goodG2B_sink_c(char * data)
{
    {
        char src[100];
        memset(src, 'C', 100-1); /* fill with 'C's */
        src[100-1] = '\0'; /* null terminate */
        /* POTENTIAL FLAW: Possibly copying data to memory before the destination buffer */
        memcpy(data, src, 100*sizeof(char));
        /* Ensure the destination buffer is null terminated */
        data[100-1] = '\0';
        printLine(data);
        /* INCIDENTAL CWE-401: Memory Leak - data may not point to location
           returned by new [] so can't safely call delete [] on it */
    }
}

#endif /* OMITGOOD */

} // close namespace
