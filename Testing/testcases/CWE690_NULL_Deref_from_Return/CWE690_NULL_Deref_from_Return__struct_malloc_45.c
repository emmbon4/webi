/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_from_Return__struct_malloc_45.c
Label Definition File: CWE690_NULL_Deref_from_Return.free.label.xml
Template File: source-sinks-45.tmpl.c
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * BadSource: malloc Allocate data using malloc()
 * Sinks:
 *    GoodSink: Check to see if the data allocation failed and if not, use data
 *    BadSink : Don't check for NULL and use data
 * Flow Variant: 45 Data flow: data passed as a static global variable from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

static twoints * CWE690_NULL_Deref_from_Return__struct_malloc_45_bad_data;
static twoints * CWE690_NULL_Deref_from_Return__struct_malloc_45_goodB2G_data;

#ifndef OMITBAD

static void bad_sink()
{
    twoints * data = CWE690_NULL_Deref_from_Return__struct_malloc_45_bad_data;
    /* POTENTIAL FLAW: Initialize memory buffer without checking to see if the memory allocation function failed */
    data[0].a = 1;
    data[0].b = 1;
    printStructLine(&data[0]);
    free(data);
}

void CWE690_NULL_Deref_from_Return__struct_malloc_45_bad()
{
    twoints * data;
    data = NULL; /* Initialize data */
    /* FLAW: Allocate memory without checking if the memeory allocation function failed */
    data = (twoints *)malloc(100);
    CWE690_NULL_Deref_from_Return__struct_malloc_45_bad_data = data;
    bad_sink();
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G() uses the BadSource with the GoodSink */
static void goodB2G_sink()
{
    twoints * data = CWE690_NULL_Deref_from_Return__struct_malloc_45_goodB2G_data;
    /* FIX: Check to see if the memory allocation function was successful before initializing the memory buffer */
    if (data != NULL)
    {
        data[0].a = 1;
        data[0].b = 1;
        printStructLine(&data[0]);
        free(data);
    }
}

static void goodB2G()
{
    twoints * data;
    data = NULL; /* Initialize data */
    /* FLAW: Allocate memory without checking if the memeory allocation function failed */
    data = (twoints *)malloc(100);
    CWE690_NULL_Deref_from_Return__struct_malloc_45_goodB2G_data = data;
    goodB2G_sink();
}

void CWE690_NULL_Deref_from_Return__struct_malloc_45_good()
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
    CWE690_NULL_Deref_from_Return__struct_malloc_45_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE690_NULL_Deref_from_Return__struct_malloc_45_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
