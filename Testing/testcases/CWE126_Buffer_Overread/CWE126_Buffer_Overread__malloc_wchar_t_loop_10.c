/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE126_Buffer_Overread__malloc_wchar_t_loop_10.c
Label Definition File: CWE126_Buffer_Overread__malloc.label.xml
Template File: sources-sink-10.tmpl.c
*/
/*
 * @description
 * CWE: 126 Buffer Over-read
 * BadSource:  Use a small buffer
 * GoodSource: Use a large buffer
 * Sink: loop
 *    BadSink : Copy data to string using a loop
 * Flow Variant: 10 Control flow: if(global_t) and if(global_f)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE126_Buffer_Overread__malloc_wchar_t_loop_10_bad()
{
    wchar_t * data;
    data = NULL;
    if(global_t)
    {
        /* FLAW: Use a small buffer */
        data = (wchar_t *)malloc(50*sizeof(wchar_t));
        wmemset(data, L'A', 50-1); /* fill with 'A's */
        data[50-1] = L'\0'; /* null terminate */
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Use a large buffer */
        data = (wchar_t *)malloc(100*sizeof(wchar_t));
        wmemset(data, L'A', 100-1); /* fill with 'A's */
        data[100-1] = L'\0'; /* null terminate */
    }
    {
        size_t i, dest_sz;
        wchar_t dest[100];
        wmemset(dest, L'C', 100-1);
        dest[100-1] = L'\0'; /* null terminate */
        dest_sz = wcslen(dest);
        /* POTENTIAL FLAW: using length of the dest where data
         * could be smaller than dest causing buffer overread */
        for (i = 0; i < dest_sz; i++)
        {
            dest[i] = data[i];
        }
        dest[100-1] = L'\0';
        printWLine(dest);
        free(data);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B1() - use goodsource and badsink by changing the global_t to global_f */
static void goodG2B1()
{
    wchar_t * data;
    data = NULL;
    if(global_f)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FLAW: Use a small buffer */
        data = (wchar_t *)malloc(50*sizeof(wchar_t));
        wmemset(data, L'A', 50-1); /* fill with 'A's */
        data[50-1] = L'\0'; /* null terminate */
    }
    else
    {
        /* FIX: Use a large buffer */
        data = (wchar_t *)malloc(100*sizeof(wchar_t));
        wmemset(data, L'A', 100-1); /* fill with 'A's */
        data[100-1] = L'\0'; /* null terminate */
    }
    {
        size_t i, dest_sz;
        wchar_t dest[100];
        wmemset(dest, L'C', 100-1);
        dest[100-1] = L'\0'; /* null terminate */
        dest_sz = wcslen(dest);
        /* POTENTIAL FLAW: using length of the dest where data
         * could be smaller than dest causing buffer overread */
        for (i = 0; i < dest_sz; i++)
        {
            dest[i] = data[i];
        }
        dest[100-1] = L'\0';
        printWLine(dest);
        free(data);
    }
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the if statement */
static void goodG2B2()
{
    wchar_t * data;
    data = NULL;
    if(global_t)
    {
        /* FIX: Use a large buffer */
        data = (wchar_t *)malloc(100*sizeof(wchar_t));
        wmemset(data, L'A', 100-1); /* fill with 'A's */
        data[100-1] = L'\0'; /* null terminate */
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FLAW: Use a small buffer */
        data = (wchar_t *)malloc(50*sizeof(wchar_t));
        wmemset(data, L'A', 50-1); /* fill with 'A's */
        data[50-1] = L'\0'; /* null terminate */
    }
    {
        size_t i, dest_sz;
        wchar_t dest[100];
        wmemset(dest, L'C', 100-1);
        dest[100-1] = L'\0'; /* null terminate */
        dest_sz = wcslen(dest);
        /* POTENTIAL FLAW: using length of the dest where data
         * could be smaller than dest causing buffer overread */
        for (i = 0; i < dest_sz; i++)
        {
            dest[i] = data[i];
        }
        dest[100-1] = L'\0';
        printWLine(dest);
        free(data);
    }
}

void CWE126_Buffer_Overread__malloc_wchar_t_loop_10_good()
{
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
    CWE126_Buffer_Overread__malloc_wchar_t_loop_10_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE126_Buffer_Overread__malloc_wchar_t_loop_10_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
