/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_from_Return__struct_malloc_54a.c
Label Definition File: CWE690_NULL_Deref_from_Return.free.label.xml
Template File: source-sinks-54a.tmpl.c
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * BadSource: malloc Allocate data using malloc()
 * Sinks:
 *    GoodSink: Check to see if the data allocation failed and if not, use data
 *    BadSink : Don't check for NULL and use data
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

/* bad function declaration */
void CWE690_NULL_Deref_from_Return__struct_malloc_54b_bad_sink(twoints * data);

void CWE690_NULL_Deref_from_Return__struct_malloc_54_bad()
{
    twoints * data;
    data = NULL; /* Initialize data */
    /* FLAW: Allocate memory without checking if the memeory allocation function failed */
    data = (twoints *)malloc(100);
    CWE690_NULL_Deref_from_Return__struct_malloc_54b_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declarations */
void CWE690_NULL_Deref_from_Return__struct_malloc_54b_goodB2G_sink(twoints * data);

/* goodB2G uses the BadSource with the GoodSink */
static void goodB2G()
{
    twoints * data;
    data = NULL; /* Initialize data */
    /* FLAW: Allocate memory without checking if the memeory allocation function failed */
    data = (twoints *)malloc(100);
    CWE690_NULL_Deref_from_Return__struct_malloc_54b_goodB2G_sink(data);
}

void CWE690_NULL_Deref_from_Return__struct_malloc_54_good()
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
    CWE690_NULL_Deref_from_Return__struct_malloc_54_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE690_NULL_Deref_from_Return__struct_malloc_54_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
