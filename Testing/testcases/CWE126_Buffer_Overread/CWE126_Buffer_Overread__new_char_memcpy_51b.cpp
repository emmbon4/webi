/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE126_Buffer_Overread__new_char_memcpy_51b.cpp
Label Definition File: CWE126_Buffer_Overread__new.label.xml
Template File: sources-sink-51b.tmpl.cpp
*/
/*
 * @description
 * CWE: 126 Buffer Over-read
 * BadSource:  Use a small buffer
 * GoodSource: Use a large buffer
 * Sink: memcpy
 *    BadSink : Copy data to string using memcpy
 * Flow Variant: 51 Data flow: data passed as an argument from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE126_Buffer_Overread__new_char_memcpy_51
{

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

void bad_sink(char * data)
{
    {
        char dest[100];
        memset(dest, 'C', 100-1);
        dest[100-1] = '\0'; /* null terminate */
        /* POTENTIAL FLAW: using memcpy with the length of the dest where data
         * could be smaller than dest causing buffer overread */
        memcpy(dest, data, strlen(dest)*sizeof(char));
        dest[100-1] = '\0';
        printLine(dest);
        delete [] data;
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void goodG2B_sink(char * data)
{
    {
        char dest[100];
        memset(dest, 'C', 100-1);
        dest[100-1] = '\0'; /* null terminate */
        /* POTENTIAL FLAW: using memcpy with the length of the dest where data
         * could be smaller than dest causing buffer overread */
        memcpy(dest, data, strlen(dest)*sizeof(char));
        dest[100-1] = '\0';
        printLine(dest);
        delete [] data;
    }
}

#endif /* OMITGOOD */

} // close namespace
