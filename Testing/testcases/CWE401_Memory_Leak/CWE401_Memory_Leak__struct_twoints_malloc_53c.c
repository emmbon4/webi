/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__struct_twoints_malloc_53c.c
Label Definition File: CWE401_Memory_Leak.c.label.xml
Template File: sources-sinks-53c.tmpl.c
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource: malloc Allocate data using malloc()
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
void CWE401_Memory_Leak__struct_twoints_malloc_53d_bad_sink(struct _twoints * data);

void CWE401_Memory_Leak__struct_twoints_malloc_53c_bad_sink(struct _twoints * data)
{
    CWE401_Memory_Leak__struct_twoints_malloc_53d_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE401_Memory_Leak__struct_twoints_malloc_53d_goodG2B_sink(struct _twoints * data);

void CWE401_Memory_Leak__struct_twoints_malloc_53c_goodG2B_sink(struct _twoints * data)
{
    CWE401_Memory_Leak__struct_twoints_malloc_53d_goodG2B_sink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE401_Memory_Leak__struct_twoints_malloc_53d_goodB2G_sink(struct _twoints * data);

void CWE401_Memory_Leak__struct_twoints_malloc_53c_goodB2G_sink(struct _twoints * data)
{
    CWE401_Memory_Leak__struct_twoints_malloc_53d_goodB2G_sink(data);
}

#endif /* OMITGOOD */
