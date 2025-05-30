/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE416_Use_After_Free__malloc_free_struct_45.c
Label Definition File: CWE416_Use_After_Free__malloc_free.label.xml
Template File: sources-sinks-45.tmpl.c
*/
/*
 * @description
 * CWE: 416 Use After Free
 * BadSource:  Allocate data using malloc(), initialize memory block, and Deallocate data using free()
 * GoodSource: Allocate data using malloc() and initialize memory block
 * Sinks:
 *    GoodSink: Do nothing
 *    BadSink : Use data
 * Flow Variant: 45 Data flow: data passed as a static global variable from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

static twoints * CWE416_Use_After_Free__malloc_free_struct_45_bad_data;
static twoints * CWE416_Use_After_Free__malloc_free_struct_45_goodG2B_data;
static twoints * CWE416_Use_After_Free__malloc_free_struct_45_goodB2G_data;

#ifndef OMITBAD

static void bad_sink()
{
    twoints * data = CWE416_Use_After_Free__malloc_free_struct_45_bad_data;
    /* POTENTIAL FLAW - Use of data that may have been deleted */
    printStructLine(&data[0]);
    /* POTENTIAL INCIDENTAL - Possible memory leak here if data was not deleted */
}

void CWE416_Use_After_Free__malloc_free_struct_45_bad()
{
    twoints * data;
    /* Initialize data */
    data = NULL;
    data = (twoints *)malloc(100*sizeof(twoints));
    {
        size_t i;
        for(i = 0; i < 100; i++)
        {
            data[i].a = 1;
            data[i].b = 2;
        }
    }
    /* POTENTIAL FLAW: Free data in the source - the bad sink attempts to use data */
    free(data);
    CWE416_Use_After_Free__malloc_free_struct_45_bad_data = data;
    bad_sink();
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B_sink()
{
    twoints * data = CWE416_Use_After_Free__malloc_free_struct_45_goodG2B_data;
    /* POTENTIAL FLAW - Use of data that may have been deleted */
    printStructLine(&data[0]);
    /* POTENTIAL INCIDENTAL - Possible memory leak here if data was not deleted */
}

static void goodG2B()
{
    twoints * data;
    /* Initialize data */
    data = NULL;
    data = (twoints *)malloc(100*sizeof(twoints));
    {
        size_t i;
        for(i = 0; i < 100; i++)
        {
            data[i].a = 1;
            data[i].b = 2;
        }
    }
    /* FIX: Do not delete data in the source */
    CWE416_Use_After_Free__malloc_free_struct_45_goodG2B_data = data;
    goodG2B_sink();
}

/* goodB2G() uses the BadSource with the GoodSink */
static void goodB2G_sink()
{
    twoints * data = CWE416_Use_After_Free__malloc_free_struct_45_goodB2G_data;
    /* FIX - Don't use data that may have been deleted already */
    /* POTENTIAL INCIDENTAL - Possible memory leak here if data was not deleted */
    /* do nothing */
    ; /* empty statement needed for some flow variants */
}

static void goodB2G()
{
    twoints * data;
    /* Initialize data */
    data = NULL;
    data = (twoints *)malloc(100*sizeof(twoints));
    {
        size_t i;
        for(i = 0; i < 100; i++)
        {
            data[i].a = 1;
            data[i].b = 2;
        }
    }
    /* POTENTIAL FLAW: Free data in the source - the bad sink attempts to use data */
    free(data);
    CWE416_Use_After_Free__malloc_free_struct_45_goodB2G_data = data;
    goodB2G_sink();
}

void CWE416_Use_After_Free__malloc_free_struct_45_good()
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
    CWE416_Use_After_Free__malloc_free_struct_45_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE416_Use_After_Free__malloc_free_struct_45_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
