/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__strdup_wchar_t_61b.c
Label Definition File: CWE401_Memory_Leak__strdup.label.xml
Template File: sources-sinks-61b.tmpl.c
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource:  Allocate data using wcsdup()
 * GoodSource: Allocate data on the stack
 * Sinks:
 *    GoodSink: call free() on data
 *    BadSink : no deallocation of data
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

wchar_t * CWE401_Memory_Leak__strdup_wchar_t_61b_bad_source(wchar_t * data)
{
    {
        wchar_t mystring[] = L"mystring";
        /* FLAW: Allocate memory from the heap using a function that requires free() for deallocation */
        data = wcsdup(mystring);
        /* Use data */
        printWLine(data);
    }
    return data;
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
wchar_t * CWE401_Memory_Leak__strdup_wchar_t_61b_goodG2B_source(wchar_t * data)
{
    {
        /* FIX: Allocate memory from the stack */
        wchar_t data_goodbuf[100];
        data = data_goodbuf;
        /* Initialize then use data */
        wcscpy(data, L"a string");
        printWLine(data);
    }
    return data;
}

/* goodB2G() uses the BadSource with the GoodSink */
wchar_t * CWE401_Memory_Leak__strdup_wchar_t_61b_goodB2G_source(wchar_t * data)
{
    {
        wchar_t mystring[] = L"mystring";
        /* FLAW: Allocate memory from the heap using a function that requires free() for deallocation */
        data = wcsdup(mystring);
        /* Use data */
        printWLine(data);
    }
    return data;
}

#endif /* OMITGOOD */
