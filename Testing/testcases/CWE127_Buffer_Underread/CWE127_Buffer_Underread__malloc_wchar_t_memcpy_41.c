/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE127_Buffer_Underread__malloc_wchar_t_memcpy_41.c
Label Definition File: CWE127_Buffer_Underread__malloc.label.xml
Template File: sources-sink-41.tmpl.c
*/
/*
 * @description
 * CWE: 127 Buffer Under-read
 * BadSource:  Set data pointer to before the allocated memory buffer
 * GoodSource: Set data pointer to the allocated memory buffer
 * Sink: memcpy
 *    BadSink : Copy data to string using memcpy
 * Flow Variant: 41 Data flow: data passed as an argument from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE127_Buffer_Underread__malloc_wchar_t_memcpy_41_bad_sink(wchar_t * data)
{
    {
        wchar_t dest[100];
        wmemset(dest, L'C', 100-1); /* fill with 'C's */
        dest[100-1] = L'\0'; /* null terminate */
        /* POTENTIAL FLAW: Possibly copy from a memory location located before the source buffer */
        memcpy(dest, data, 100*sizeof(wchar_t));
        /* Ensure null termination */
        dest[100-1] = L'\0';
        printWLine(dest);
        /* INCIDENTAL CWE-401: Memory Leak - data may not point to location
           returned by malloc() so can't safely call free() on it */
    }
}

void CWE127_Buffer_Underread__malloc_wchar_t_memcpy_41_bad()
{
    wchar_t * data;
    data = NULL;
    {
        wchar_t * data_buf = (wchar_t *)malloc(100*sizeof(wchar_t));
        wmemset(data_buf, L'A', 100-1);
        data_buf[100-1] = L'\0';
        /* FLAW: Set data pointer to before the allocated memory buffer */
        data = data_buf - 8;
    }
    CWE127_Buffer_Underread__malloc_wchar_t_memcpy_41_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

void CWE127_Buffer_Underread__malloc_wchar_t_memcpy_41_goodG2B_sink(wchar_t * data)
{
    {
        wchar_t dest[100];
        wmemset(dest, L'C', 100-1); /* fill with 'C's */
        dest[100-1] = L'\0'; /* null terminate */
        /* POTENTIAL FLAW: Possibly copy from a memory location located before the source buffer */
        memcpy(dest, data, 100*sizeof(wchar_t));
        /* Ensure null termination */
        dest[100-1] = L'\0';
        printWLine(dest);
        /* INCIDENTAL CWE-401: Memory Leak - data may not point to location
           returned by malloc() so can't safely call free() on it */
    }
}

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    wchar_t * data;
    data = NULL;
    {
        wchar_t * data_buf = (wchar_t *)malloc(100*sizeof(wchar_t));
        wmemset(data_buf, L'A', 100-1);
        data_buf[100-1] = L'\0';
        /* FIX: Set data pointer to the allocated memory buffer */
        data = data_buf;
    }
    CWE127_Buffer_Underread__malloc_wchar_t_memcpy_41_goodG2B_sink(data);
}

void CWE127_Buffer_Underread__malloc_wchar_t_memcpy_41_good()
{
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
    CWE127_Buffer_Underread__malloc_wchar_t_memcpy_41_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE127_Buffer_Underread__malloc_wchar_t_memcpy_41_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
