/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_from_Return__char_calloc_41.c
Label Definition File: CWE690_NULL_Deref_from_Return.free.label.xml
Template File: source-sinks-41.tmpl.c
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * BadSource: calloc Allocate data using calloc()
 * Sinks:
 *    GoodSink: Check to see if the data allocation failed and if not, use data
 *    BadSink : Don't check for NULL and use data
 * Flow Variant: 41 Data flow: data passed as an argument from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

static void bad_sink(char * data)
{
    /* POTENTIAL FLAW: Initialize memory buffer without checking to see if the memory allocation function failed */
    strcpy(data, "Initialize");
    printLine(data);
    free(data);
}

void CWE690_NULL_Deref_from_Return__char_calloc_41_bad()
{
    char * data;
    data = NULL; /* Initialize data */
    /* FLAW: Allocate memory without checking if the memeory allocation function failed */
    data = (char *)calloc(100, sizeof(char));
    bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

static void goodB2G_sink(char * data)
{
    /* FIX: Check to see if the memory allocation function was successful before initializing the memory buffer */
    if (data != NULL)
    {
        strcpy(data, "Initialize");
        printLine(data);
        free(data);
    }
}

/* goodB2G uses the BadSource with the GoodSink */
static void goodB2G()
{
    char * data;
    data = NULL; /* Initialize data */
    /* FLAW: Allocate memory without checking if the memeory allocation function failed */
    data = (char *)calloc(100, sizeof(char));
    goodB2G_sink(data);
}

void CWE690_NULL_Deref_from_Return__char_calloc_41_good()
{
    goodB2G();
}

#endif /* OMITGOOD */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    CWE690_NULL_Deref_from_Return__char_calloc_41_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE690_NULL_Deref_from_Return__char_calloc_41_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
