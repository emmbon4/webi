/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__malloc_free_long_long_66a.c
Label Definition File: CWE415_Double_Free__malloc_free.label.xml
Template File: sources-sinks-66a.tmpl.c
*/
/*
 * @description
 * CWE: 415 Double Free
 * BadSource:  Allocate data using malloc() and Deallocate data using free()
 * GoodSource: Allocate data using malloc()
 * Sinks:
 *    GoodSink: do nothing
 *    BadSink : Deallocate data using free()
 * Flow Variant: 66 Data flow: data passed in an array from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

/* bad function declaration */
void CWE415_Double_Free__malloc_free_long_long_66b_bad_sink(long long * data_array[]);

void CWE415_Double_Free__malloc_free_long_long_66_bad()
{
    long long * data;
    long long * data_array[5];
    /* Initialize data */
    data = NULL;
    data = (long long *)malloc(100*sizeof(long long));
    /* POTENTIAL FLAW: Free data in the source - the bad sink frees data as well */
    free(data);
    /* put data in array */
    data_array[2] = data;
    CWE415_Double_Free__malloc_free_long_long_66b_bad_sink(data_array);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE415_Double_Free__malloc_free_long_long_66b_goodG2B_sink(long long * data_array[]);

static void goodG2B()
{
    long long * data;
    long long * data_array[5];
    /* Initialize data */
    data = NULL;
    data = (long long *)malloc(100*sizeof(long long));
    /* FIX: Do NOT free data in the source - the bad sink frees data */
    data_array[2] = data;
    CWE415_Double_Free__malloc_free_long_long_66b_goodG2B_sink(data_array);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE415_Double_Free__malloc_free_long_long_66b_goodB2G_sink(long long * data_array[]);

static void goodB2G()
{
    long long * data;
    long long * data_array[5];
    /* Initialize data */
    data = NULL;
    data = (long long *)malloc(100*sizeof(long long));
    /* POTENTIAL FLAW: Free data in the source - the bad sink frees data as well */
    free(data);
    data_array[2] = data;
    CWE415_Double_Free__malloc_free_long_long_66b_goodB2G_sink(data_array);
}

void CWE415_Double_Free__malloc_free_long_long_66_good()
{
    goodG2B();
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
    CWE415_Double_Free__malloc_free_long_long_66_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE415_Double_Free__malloc_free_long_long_66_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
