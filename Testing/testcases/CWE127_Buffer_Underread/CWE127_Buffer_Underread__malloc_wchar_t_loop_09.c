/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE127_Buffer_Underread__malloc_wchar_t_loop_09.c
Label Definition File: CWE127_Buffer_Underread__malloc.label.xml
Template File: sources-sink-09.tmpl.c
*/
/*
 * @description
 * CWE: 127 Buffer Under-read
 * BadSource:  Set data pointer to before the allocated memory buffer
 * GoodSource: Set data pointer to the allocated memory buffer
 * Sink: loop
 *    BadSink : Copy data to string using a loop
 * Flow Variant: 09 Control flow: if(global_const_t) and if(global_const_f)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE127_Buffer_Underread__malloc_wchar_t_loop_09_bad()
{
    wchar_t * data;
    data = NULL;
    if(global_const_t)
    {
        {
            wchar_t * data_buf = (wchar_t *)malloc(100*sizeof(wchar_t));
            wmemset(data_buf, L'A', 100-1);
            data_buf[100-1] = L'\0';
            /* FLAW: Set data pointer to before the allocated memory buffer */
            data = data_buf - 8;
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            wchar_t * data_buf = (wchar_t *)malloc(100*sizeof(wchar_t));
            wmemset(data_buf, L'A', 100-1);
            data_buf[100-1] = L'\0';
            /* FIX: Set data pointer to the allocated memory buffer */
            data = data_buf;
        }
    }
    {
        size_t i;
        wchar_t dest[100];
        wmemset(dest, L'C', 100-1); /* fill with 'C's */
        dest[100-1] = L'\0'; /* null terminate */
        /* POTENTIAL FLAW: Possibly copy from a memory location located before the source buffer */
        for (i = 0; i < 100; i++)
        {
            dest[i] = data[i];
        }
        /* Ensure null termination */
        dest[100-1] = L'\0';
        printWLine(dest);
        /* INCIDENTAL CWE-401: Memory Leak - data may not point to location
           returned by malloc() so can't safely call free() on it */
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B1() - use goodsource and badsink by changing the global_const_t to global_const_f */
static void goodG2B1()
{
    wchar_t * data;
    data = NULL;
    if(global_const_f)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            wchar_t * data_buf = (wchar_t *)malloc(100*sizeof(wchar_t));
            wmemset(data_buf, L'A', 100-1);
            data_buf[100-1] = L'\0';
            /* FLAW: Set data pointer to before the allocated memory buffer */
            data = data_buf - 8;
        }
    }
    else
    {
        {
            wchar_t * data_buf = (wchar_t *)malloc(100*sizeof(wchar_t));
            wmemset(data_buf, L'A', 100-1);
            data_buf[100-1] = L'\0';
            /* FIX: Set data pointer to the allocated memory buffer */
            data = data_buf;
        }
    }
    {
        size_t i;
        wchar_t dest[100];
        wmemset(dest, L'C', 100-1); /* fill with 'C's */
        dest[100-1] = L'\0'; /* null terminate */
        /* POTENTIAL FLAW: Possibly copy from a memory location located before the source buffer */
        for (i = 0; i < 100; i++)
        {
            dest[i] = data[i];
        }
        /* Ensure null termination */
        dest[100-1] = L'\0';
        printWLine(dest);
        /* INCIDENTAL CWE-401: Memory Leak - data may not point to location
           returned by malloc() so can't safely call free() on it */
    }
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the if statement */
static void goodG2B2()
{
    wchar_t * data;
    data = NULL;
    if(global_const_t)
    {
        {
            wchar_t * data_buf = (wchar_t *)malloc(100*sizeof(wchar_t));
            wmemset(data_buf, L'A', 100-1);
            data_buf[100-1] = L'\0';
            /* FIX: Set data pointer to the allocated memory buffer */
            data = data_buf;
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            wchar_t * data_buf = (wchar_t *)malloc(100*sizeof(wchar_t));
            wmemset(data_buf, L'A', 100-1);
            data_buf[100-1] = L'\0';
            /* FLAW: Set data pointer to before the allocated memory buffer */
            data = data_buf - 8;
        }
    }
    {
        size_t i;
        wchar_t dest[100];
        wmemset(dest, L'C', 100-1); /* fill with 'C's */
        dest[100-1] = L'\0'; /* null terminate */
        /* POTENTIAL FLAW: Possibly copy from a memory location located before the source buffer */
        for (i = 0; i < 100; i++)
        {
            dest[i] = data[i];
        }
        /* Ensure null termination */
        dest[100-1] = L'\0';
        printWLine(dest);
        /* INCIDENTAL CWE-401: Memory Leak - data may not point to location
           returned by malloc() so can't safely call free() on it */
    }
}

void CWE127_Buffer_Underread__malloc_wchar_t_loop_09_good()
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
    CWE127_Buffer_Underread__malloc_wchar_t_loop_09_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE127_Buffer_Underread__malloc_wchar_t_loop_09_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
