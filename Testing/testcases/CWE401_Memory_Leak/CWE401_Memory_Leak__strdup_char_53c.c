/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__strdup_char_53c.c
Label Definition File: CWE401_Memory_Leak__strdup.label.xml
Template File: sources-sinks-53c.tmpl.c
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource:  Allocate data using strdup()
 * GoodSource: Allocate data on the stack
 * Sinks:
 *    GoodSink: call free() on data
 *    BadSink : no deallocation of data
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

/* bad function declaration */
void CWE401_Memory_Leak__strdup_char_53d_bad_sink(char * data);

void CWE401_Memory_Leak__strdup_char_53c_bad_sink(char * data)
{
    CWE401_Memory_Leak__strdup_char_53d_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE401_Memory_Leak__strdup_char_53d_goodG2B_sink(char * data);

void CWE401_Memory_Leak__strdup_char_53c_goodG2B_sink(char * data)
{
    CWE401_Memory_Leak__strdup_char_53d_goodG2B_sink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE401_Memory_Leak__strdup_char_53d_goodB2G_sink(char * data);

void CWE401_Memory_Leak__strdup_char_53c_goodB2G_sink(char * data)
{
    CWE401_Memory_Leak__strdup_char_53d_goodB2G_sink(data);
}

#endif /* OMITGOOD */
