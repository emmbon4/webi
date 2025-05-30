/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE416_Use_After_Free__malloc_free_wchar_t_07.c
Label Definition File: CWE416_Use_After_Free__malloc_free.label.xml
Template File: sources-sinks-07.tmpl.c
*/
/*
 * @description
 * CWE: 416 Use After Free
 * BadSource:  Allocate data using malloc(), initialize memory block, and Deallocate data using free()
 * GoodSource: Allocate data using malloc() and initialize memory block
 * Sinks:
 *    GoodSink: Do nothing
 *    BadSink : Use data
 * Flow Variant: 07 Control flow: if(static_five==5) and if(static_five!=5)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

/* The variable below is not declared "const", but is never assigned
   any other value so a tool should be able to identify that reads of
   this will always give its initialized value. */
static int static_five = 5;

#ifndef OMITBAD

void CWE416_Use_After_Free__malloc_free_wchar_t_07_bad()
{
    wchar_t * data;
    /* Initialize data */
    data = NULL;
    if(static_five==5)
    {
        data = (wchar_t *)malloc(100*sizeof(wchar_t));
        wmemset(data, L'A', 100-1);
        data[100-1] = L'\0';
        /* POTENTIAL FLAW: Free data in the source - the bad sink attempts to use data */
        free(data);
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        data = (wchar_t *)malloc(100*sizeof(wchar_t));
        wmemset(data, L'A', 100-1);
        data[100-1] = L'\0';
        /* FIX: Do not delete data in the source */
    }
    if(static_five==5)
    {
        /* POTENTIAL FLAW - Use of data that may have been deleted */
        printWLine(data);
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

/* goodB2G1() - use badsource and goodsink by changing the second static_five==5 to static_five!=5 */
static void goodB2G1()
{
    wchar_t * data;
    /* Initialize data */
    data = NULL;
    if(static_five==5)
    {
        data = (wchar_t *)malloc(100*sizeof(wchar_t));
        wmemset(data, L'A', 100-1);
        data[100-1] = L'\0';
        /* POTENTIAL FLAW: Free data in the source - the bad sink attempts to use data */
        free(data);
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        data = (wchar_t *)malloc(100*sizeof(wchar_t));
        wmemset(data, L'A', 100-1);
        data[100-1] = L'\0';
        /* FIX: Do not delete data in the source */
    }
    if(static_five!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* POTENTIAL FLAW - Use of data that may have been deleted */
        printWLine(data);
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
    wchar_t * data;
    /* Initialize data */
    data = NULL;
    if(static_five==5)
    {
        data = (wchar_t *)malloc(100*sizeof(wchar_t));
        wmemset(data, L'A', 100-1);
        data[100-1] = L'\0';
        /* POTENTIAL FLAW: Free data in the source - the bad sink attempts to use data */
        free(data);
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        data = (wchar_t *)malloc(100*sizeof(wchar_t));
        wmemset(data, L'A', 100-1);
        data[100-1] = L'\0';
        /* FIX: Do not delete data in the source */
    }
    if(static_five==5)
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
        printWLine(data);
        /* POTENTIAL INCIDENTAL - Possible memory leak here if data was not deleted */
    }
}

/* goodG2B1() - use goodsource and badsink by changing the first static_five==5 to static_five!=5 */
static void goodG2B1()
{
    wchar_t * data;
    /* Initialize data */
    data = NULL;
    if(static_five!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        data = (wchar_t *)malloc(100*sizeof(wchar_t));
        wmemset(data, L'A', 100-1);
        data[100-1] = L'\0';
        /* POTENTIAL FLAW: Free data in the source - the bad sink attempts to use data */
        free(data);
    }
    else
    {
        data = (wchar_t *)malloc(100*sizeof(wchar_t));
        wmemset(data, L'A', 100-1);
        data[100-1] = L'\0';
        /* FIX: Do not delete data in the source */
    }
    if(static_five==5)
    {
        /* POTENTIAL FLAW - Use of data that may have been deleted */
        printWLine(data);
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
    wchar_t * data;
    /* Initialize data */
    data = NULL;
    if(static_five==5)
    {
        data = (wchar_t *)malloc(100*sizeof(wchar_t));
        wmemset(data, L'A', 100-1);
        data[100-1] = L'\0';
        /* FIX: Do not delete data in the source */
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        data = (wchar_t *)malloc(100*sizeof(wchar_t));
        wmemset(data, L'A', 100-1);
        data[100-1] = L'\0';
        /* POTENTIAL FLAW: Free data in the source - the bad sink attempts to use data */
        free(data);
    }
    if(static_five==5)
    {
        /* POTENTIAL FLAW - Use of data that may have been deleted */
        printWLine(data);
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

void CWE416_Use_After_Free__malloc_free_wchar_t_07_good()
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
    CWE416_Use_After_Free__malloc_free_wchar_t_07_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE416_Use_After_Free__malloc_free_wchar_t_07_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
