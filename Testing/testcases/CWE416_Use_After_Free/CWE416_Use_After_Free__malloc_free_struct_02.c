/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE416_Use_After_Free__malloc_free_struct_02.c
Label Definition File: CWE416_Use_After_Free__malloc_free.label.xml
Template File: sources-sinks-02.tmpl.c
*/
/*
 * @description
 * CWE: 416 Use After Free
 * BadSource:  Allocate data using malloc(), initialize memory block, and Deallocate data using free()
 * GoodSource: Allocate data using malloc() and initialize memory block
 * Sinks:
 *    GoodSink: Do nothing
 *    BadSink : Use data
 * Flow Variant: 02 Control flow: if(1) and if(0)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE416_Use_After_Free__malloc_free_struct_02_bad()
{
    twoints * data;
    /* Initialize data */
    data = NULL;
    if(1)
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
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
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
    if(1)
    {
        /* POTENTIAL FLAW - Use of data that may have been deleted */
        printStructLine(&data[0]);
        /* POTENTIAL INCIDENTAL - Possible memory leak here if data was not deleted */
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX - Don't use data that may have been deleted already */
        /* POTENTIAL INCIDENTAL - Possible memory leak here if data was not deleted */
        /* do nothing */
        ; /* empty statement needed for some flow variants */
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G1() - use badsource and goodsink by changing the second 1 to 0 */
static void goodB2G1()
{
    twoints * data;
    /* Initialize data */
    data = NULL;
    if(1)
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
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
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
    if(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
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

/* goodB2G2() - use badsource and goodsink by reversing the blocks in the second if */
static void goodB2G2()
{
    twoints * data;
    /* Initialize data */
    data = NULL;
    if(1)
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
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
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
    if(1)
    {
        /* FIX - Don't use data that may have been deleted already */
        /* POTENTIAL INCIDENTAL - Possible memory leak here if data was not deleted */
        /* do nothing */
        ; /* empty statement needed for some flow variants */
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* POTENTIAL FLAW - Use of data that may have been deleted */
        printStructLine(&data[0]);
        /* POTENTIAL INCIDENTAL - Possible memory leak here if data was not deleted */
    }
}

/* goodG2B1() - use goodsource and badsink by changing the first 1 to 0 */
static void goodG2B1()
{
    twoints * data;
    /* Initialize data */
    data = NULL;
    if(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
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
    if(1)
    {
        /* POTENTIAL FLAW - Use of data that may have been deleted */
        printStructLine(&data[0]);
        /* POTENTIAL INCIDENTAL - Possible memory leak here if data was not deleted */
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX - Don't use data that may have been deleted already */
        /* POTENTIAL INCIDENTAL - Possible memory leak here if data was not deleted */
        /* do nothing */
        ; /* empty statement needed for some flow variants */
    }
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the first if */
static void goodG2B2()
{
    twoints * data;
    /* Initialize data */
    data = NULL;
    if(1)
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
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
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
    if(1)
    {
        /* POTENTIAL FLAW - Use of data that may have been deleted */
        printStructLine(&data[0]);
        /* POTENTIAL INCIDENTAL - Possible memory leak here if data was not deleted */
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX - Don't use data that may have been deleted already */
        /* POTENTIAL INCIDENTAL - Possible memory leak here if data was not deleted */
        /* do nothing */
        ; /* empty statement needed for some flow variants */
    }
}

void CWE416_Use_After_Free__malloc_free_struct_02_good()
{
    goodB2G1();
    goodB2G2();
    goodG2B1();
    goodG2B2();
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
    CWE416_Use_After_Free__malloc_free_struct_02_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE416_Use_After_Free__malloc_free_struct_02_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
