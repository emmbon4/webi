/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE416_Use_After_Free__malloc_free_char_61b.c
Label Definition File: CWE416_Use_After_Free__malloc_free.label.xml
Template File: sources-sinks-61b.tmpl.c
*/
/*
 * @description
 * CWE: 416 Use After Free
 * BadSource:  Allocate data using malloc(), initialize memory block, and Deallocate data using free()
 * GoodSource: Allocate data using malloc() and initialize memory block
 * Sinks:
 *    GoodSink: Do nothing
 *    BadSink : Use data
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

char * CWE416_Use_After_Free__malloc_free_char_61b_bad_source(char * data)
{
    data = (char *)malloc(100*sizeof(char));
    memset(data, 'A', 100-1);
    data[100-1] = '\0';
    /* POTENTIAL FLAW: Free data in the source - the bad sink attempts to use data */
    free(data);
    return data;
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
char * CWE416_Use_After_Free__malloc_free_char_61b_goodG2B_source(char * data)
{
    data = (char *)malloc(100*sizeof(char));
    memset(data, 'A', 100-1);
    data[100-1] = '\0';
    /* FIX: Do not delete data in the source */
    return data;
}

/* goodB2G() uses the BadSource with the GoodSink */
char * CWE416_Use_After_Free__malloc_free_char_61b_goodB2G_source(char * data)
{
    data = (char *)malloc(100*sizeof(char));
    memset(data, 'A', 100-1);
    data[100-1] = '\0';
    /* POTENTIAL FLAW: Free data in the source - the bad sink attempts to use data */
    free(data);
    return data;
}

#endif /* OMITGOOD */
