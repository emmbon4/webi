/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE127_Buffer_Underread__new_char_ncpy_62b.cpp
Label Definition File: CWE127_Buffer_Underread__new.label.xml
Template File: sources-sink-62b.tmpl.cpp
*/
/*
 * @description
 * CWE: 127 Buffer Under-read
 * BadSource:  Set data pointer to before the allocated memory buffer
 * GoodSource: Set data pointer to the allocated memory buffer
 * Sinks: ncpy
 *    BadSink : Copy data to string using strncpy
 * Flow Variant: 62 Data flow: data flows using a C++ reference from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE127_Buffer_Underread__new_char_ncpy_62
{

#ifndef OMITBAD

void bad_source(char * &data)
{
    {
        char * data_buf = new char[100];
        memset(data_buf, 'A', 100-1);
        data_buf[100-1] = '\0';
        /* FLAW: Set data pointer to before the allocated memory buffer */
        data = data_buf - 8;
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
void goodG2B_source(char * &data)
{
    {
        char * data_buf = new char[100];
        memset(data_buf, 'A', 100-1);
        data_buf[100-1] = '\0';
        /* FIX: Set data pointer to the allocated memory buffer */
        data = data_buf;
    }
}

#endif /* OMITGOOD */

} // close namespace
