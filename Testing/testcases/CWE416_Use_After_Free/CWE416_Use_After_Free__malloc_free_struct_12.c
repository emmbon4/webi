/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE416_Use_After_Free__malloc_free_struct_12.c
Label Definition File: CWE416_Use_After_Free__malloc_free.label.xml
Template File: sources-sinks-12.tmpl.c
*/
/*
 * @description
 * CWE: 416 Use After Free
 * BadSource:  Allocate data using malloc(), initialize memory block, and Deallocate data using free()
 * GoodSource: Allocate data using malloc() and initialize memory block
 * Sinks:
 *    GoodSink: Do nothing
 *    BadSink : Use data
 * Flow Variant: 12 Control flow: if(global_returns_t_or_f())
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE416_Use_After_Free__malloc_free_struct_12_bad()
{
    twoints * data;
    /* Initialize data */
    data = NULL;
    if(global_returns_t_or_f())
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
    }
    else
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
    }
    if(global_returns_t_or_f())
    {
        /* POTENTIAL FLAW - Use of data that may have been deleted */
        printStructLine(&data[0]);
        /* POTENTIAL INCIDENTAL - Possible memory leak here if data was not deleted */
    }
    else
    {
        /* FIX - Don't use data that may have been deleted already */
        /* POTENTIAL INCIDENTAL - Possible memory leak here if data was not deleted */
        /* do nothing */
        ; /* empty statement needed for some flow variants */
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G() - use badsource and goodsink by changing the first "if" so that
   both branches use the BadSource and the second "if" so that both branches
   use the GoodSink */
static void goodB2G()
{
    twoints * data;
    /* Initialize data */
    data = NULL;
    if(global_returns_t_or_f())
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
    }
    else
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
    }
    if(global_returns_t_or_f())
    {
        /* FIX - Don't use data that may have been deleted already */
        /* POTENTIAL INCIDENTAL - Possible memory leak here if data was not deleted */
        /* do nothing */
        ; /* empty statement needed for some flow variants */
    }
    else
    {
        /* FIX - Don't use data that may have been deleted already */
        /* POTENTIAL INCIDENTAL - Possible memory leak here if data was not deleted */
        /* do nothing */
        ; /* empty statement needed for some flow variants */
    }
}

/* goodG2B() - use goodsource and badsink by changing the first "if" so that
   both branches use the GoodSource and the second "if" so that both branches
   use the BadSink */
static void goodG2B()
{
    twoints * data;
    /* Initialize data */
    data = NULL;
    if(global_returns_t_or_f())
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
    }
    else
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
    }
    if(global_returns_t_or_f())
    {
        /* POTENTIAL FLAW - Use of data that may have been deleted */
        printStructLine(&data[0]);
        /* POTENTIAL INCIDENTAL - Possible memory leak here if data was not deleted */
    }
    else
    {
        /* POTENTIAL FLAW - Use of data that may have been deleted */
        printStructLine(&data[0]);
        /* POTENTIAL INCIDENTAL - Possible memory leak here if data was not deleted */
    }
}

void CWE416_Use_After_Free__malloc_free_struct_12_good()
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
    CWE416_Use_After_Free__malloc_free_struct_12_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE416_Use_After_Free__malloc_free_struct_12_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
