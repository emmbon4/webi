/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE761_Free_Pointer_Not_At_Start_Of_Buffer__char_fixed_string_61b.c
Label Definition File: CWE761_Free_Pointer_Not_At_Start_Of_Buffer.label.xml
Template File: source-sinks-61b.tmpl.c
*/
/*
 * @description
 * CWE: 761 Free Pointer Not At Start of Buffer
 * BadSource: fixed_string Initialize data to be a fixed string
 * Sinks:
 *    GoodSink: free() memory correctly at the start of the buffer
 *    BadSink : free() memory not at the start of the buffer
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#define SEARCH_CHAR 'S'
#define BAD_SRC_FIXED "Fixed String" /* MAINTENANCE NOTE: This string must contain the SEARCH_CHAR */

#ifndef OMITBAD

char * CWE761_Free_Pointer_Not_At_Start_Of_Buffer__char_fixed_string_61b_bad_source(char * data)
{
    /* Initialize data to be a fixed string that contains the search character in the sinks */
    strcpy(data, BAD_SRC_FIXED);
    return data;
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G() uses the BadSource with the GoodSink */
char * CWE761_Free_Pointer_Not_At_Start_Of_Buffer__char_fixed_string_61b_goodB2G_source(char * data)
{
    /* Initialize data to be a fixed string that contains the search character in the sinks */
    strcpy(data, BAD_SRC_FIXED);
    return data;
}

#endif /* OMITGOOD */
