/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_from_Return__wchar_t_malloc_32.c
Label Definition File: CWE690_NULL_Deref_from_Return.free.label.xml
Template File: source-sinks-32.tmpl.c
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * BadSource: malloc Allocate data using malloc()
 * Sinks:
 *    GoodSink: Check to see if the data allocation failed and if not, use data
 *    BadSink : Don't check for NULL and use data
 * Flow Variant: 32 Data flow: two pointers to the same value within the same function
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE690_NULL_Deref_from_Return__wchar_t_malloc_32_bad()
{
    wchar_t * data;
    wchar_t * *data_ptr1 = &data;
    wchar_t * *data_ptr2 = &data;
    data = NULL; /* Initialize data */
    {
        wchar_t * data = *data_ptr1;
        /* FLAW: Allocate memory without checking if the memeory allocation function failed */
        data = (wchar_t *)malloc(100);
        *data_ptr1 = data;
    }
    {
        wchar_t * data = *data_ptr2;
        /* POTENTIAL FLAW: Initialize memory buffer without checking to see if the memory allocation function failed */
        wcscpy(data, L"Initialize");
        printWLine(data);
        free(data);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G() uses the BadSource with the GoodSink */
static void goodB2G()
{
    wchar_t * data;
    wchar_t * *data_ptr1 = &data;
    wchar_t * *data_ptr2 = &data;
    data = NULL; /* Initialize data */
    {
        wchar_t * data = *data_ptr1;
        /* FLAW: Allocate memory without checking if the memeory allocation function failed */
        data = (wchar_t *)malloc(100);
        *data_ptr1 = data;
    }
    {
        wchar_t * data = *data_ptr2;
        /* FIX: Check to see if the memory allocation function was successful before initializing the memory buffer */
        if (data != NULL)
        {
            wcscpy(data, L"Initialize");
            printWLine(data);
            free(data);
        }
    }
}

void CWE690_NULL_Deref_from_Return__wchar_t_malloc_32_good()
{
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
    CWE690_NULL_Deref_from_Return__wchar_t_malloc_32_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE690_NULL_Deref_from_Return__wchar_t_malloc_32_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
