/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__malloc_free_int_31.c
Label Definition File: CWE415_Double_Free__malloc_free.label.xml
Template File: sources-sinks-31.tmpl.c
*/
/*
 * @description
 * CWE: 415 Double Free
 * BadSource:  Allocate data using malloc() and Deallocate data using free()
 * GoodSource: Allocate data using malloc()
 * Sinks:
 *    GoodSink: do nothing
 *    BadSink : Deallocate data using free()
 * Flow Variant: 31 Data flow using a copy of data within the same function
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE415_Double_Free__malloc_free_int_31_bad()
{
    int * data;
    /* Initialize data */
    data = NULL;
    data = (int *)malloc(100*sizeof(int));
    /* POTENTIAL FLAW: Free data in the source - the bad sink frees data as well */
    free(data);
    {
        int * data_copy = data;
        int * data = data_copy;
        /* POTENTIAL FLAW: Possibly freeing memory twice */
        free(data);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    int * data;
    /* Initialize data */
    data = NULL;
    data = (int *)malloc(100*sizeof(int));
    /* FIX: Do NOT free data in the source - the bad sink frees data */
    {
        int * data_copy = data;
        int * data = data_copy;
        /* POTENTIAL FLAW: Possibly freeing memory twice */
        free(data);
    }
}

/* goodB2G() uses the BadSource with the GoodSink */
static void goodB2G()
{
    int * data;
    /* Initialize data */
    data = NULL;
    data = (int *)malloc(100*sizeof(int));
    /* POTENTIAL FLAW: Free data in the source - the bad sink frees data as well */
    free(data);
    {
        int * data_copy = data;
        int * data = data_copy;
        /* do nothing */
        /* FIX: Don't attempt to free the memory */
        ; /* empty statement needed for some flow variants */
    }
}

void CWE415_Double_Free__malloc_free_int_31_good()
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
    CWE415_Double_Free__malloc_free_int_31_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE415_Double_Free__malloc_free_int_31_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
