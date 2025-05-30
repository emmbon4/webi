/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_from_Return__char_realloc_68a.c
Label Definition File: CWE690_NULL_Deref_from_Return.free.label.xml
Template File: source-sinks-68a.tmpl.c
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * BadSource: realloc Allocate data using realloc()
 * Sinks:
 *    GoodSink: Check to see if the data allocation failed and if not, use data
 *    BadSink : Don't check for NULL and use data
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

char * CWE690_NULL_Deref_from_Return__char_realloc_68_bad_data_for_bad_sink;

char * CWE690_NULL_Deref_from_Return__char_realloc_68_bad_data_for_good_sink;

#ifndef OMITBAD

/* bad function declaration */
void CWE690_NULL_Deref_from_Return__char_realloc_68b_bad_sink();

void CWE690_NULL_Deref_from_Return__char_realloc_68_bad()
{
    char * data;
    data = NULL; /* Initialize data */
    /* FLAW: Allocate memory without checking if the memeory allocation function failed */
    data = (char *)realloc(data, 100);
    CWE690_NULL_Deref_from_Return__char_realloc_68_bad_data_for_bad_sink = data;
    CWE690_NULL_Deref_from_Return__char_realloc_68b_bad_sink();
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declarations */
void CWE690_NULL_Deref_from_Return__char_realloc_68b_goodB2G_sink();

/* goodB2G uses the BadSource with the GoodSink */
static void goodB2G()
{
    char * data;
    data = NULL; /* Initialize data */
    /* FLAW: Allocate memory without checking if the memeory allocation function failed */
    data = (char *)realloc(data, 100);
    CWE690_NULL_Deref_from_Return__char_realloc_68_bad_data_for_good_sink = data;
    CWE690_NULL_Deref_from_Return__char_realloc_68b_goodB2G_sink();
}

void CWE690_NULL_Deref_from_Return__char_realloc_68_good()
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
    CWE690_NULL_Deref_from_Return__char_realloc_68_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE690_NULL_Deref_from_Return__char_realloc_68_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
