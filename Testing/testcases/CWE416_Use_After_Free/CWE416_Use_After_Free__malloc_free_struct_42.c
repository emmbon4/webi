/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE416_Use_After_Free__malloc_free_struct_42.c
Label Definition File: CWE416_Use_After_Free__malloc_free.label.xml
Template File: sources-sinks-42.tmpl.c
*/
/*
 * @description
 * CWE: 416 Use After Free
 * BadSource:  Allocate data using malloc(), initialize memory block, and Deallocate data using free()
 * GoodSource: Allocate data using malloc() and initialize memory block
 * Sinks:
 *    GoodSink: Do nothing
 *    BadSink : Use data
 * Flow Variant: 42 Data flow: data returned from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

static twoints * bad_source(twoints * data)
{
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
    return data;
}

void CWE416_Use_After_Free__malloc_free_struct_42_bad()
{
    twoints * data;
    /* Initialize data */
    data = NULL;
    data = bad_source(data);
    /* POTENTIAL FLAW - Use of data that may have been deleted */
    printStructLine(&data[0]);
    /* POTENTIAL INCIDENTAL - Possible memory leak here if data was not deleted */
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
static twoints * goodG2B_source(twoints * data)
{
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
    return data;
}

static void goodG2B()
{
    twoints * data;
    /* Initialize data */
    data = NULL;
    data = goodG2B_source(data);
    /* POTENTIAL FLAW - Use of data that may have been deleted */
    printStructLine(&data[0]);
    /* POTENTIAL INCIDENTAL - Possible memory leak here if data was not deleted */
}

/* goodB2G uses the BadSource with the GoodSink */
static twoints * goodB2G_source(twoints * data)
{
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
    return data;
}

static void goodB2G()
{
    twoints * data;
    /* Initialize data */
    data = NULL;
    data = goodB2G_source(data);
    /* FIX - Don't use data that may have been deleted already */
    /* POTENTIAL INCIDENTAL - Possible memory leak here if data was not deleted */
    /* do nothing */
    ; /* empty statement needed for some flow variants */
}

void CWE416_Use_After_Free__malloc_free_struct_42_good()
{
    goodB2G();
    goodG2B();
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
    CWE416_Use_After_Free__malloc_free_struct_42_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE416_Use_After_Free__malloc_free_struct_42_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
