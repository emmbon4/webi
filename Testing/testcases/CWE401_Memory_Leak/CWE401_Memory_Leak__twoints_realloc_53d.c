/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__twoints_realloc_53d.c
Label Definition File: CWE401_Memory_Leak.c.label.xml
Template File: sources-sinks-53d.tmpl.c
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource: realloc Allocate data using realloc()
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

void CWE401_Memory_Leak__twoints_realloc_53d_bad_sink(twoints * data)
{
    /* POTENTIAL FLAW: No deallocation */
    ; /* empty statement needed for some flow variants */
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE401_Memory_Leak__twoints_realloc_53d_goodG2B_sink(twoints * data)
{
    /* POTENTIAL FLAW: No deallocation */
    ; /* empty statement needed for some flow variants */
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE401_Memory_Leak__twoints_realloc_53d_goodB2G_sink(twoints * data)
{
    /* FIX: Deallocate memory */
    free(data);
}

#endif /* OMITGOOD */
