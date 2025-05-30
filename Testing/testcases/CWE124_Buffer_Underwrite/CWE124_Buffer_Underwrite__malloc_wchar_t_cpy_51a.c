/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE124_Buffer_Underwrite__malloc_wchar_t_cpy_51a.c
Label Definition File: CWE124_Buffer_Underwrite__malloc.label.xml
Template File: sources-sink-51a.tmpl.c
*/
/*
 * @description
 * CWE: 124 Buffer Underwrite
 * BadSource:  Set data pointer to before the allocated memory buffer
 * GoodSource: Set data pointer to the allocated memory buffer
 * Sink: cpy
 *    BadSink : Copy string to data using wcscpy
 * Flow Variant: 51 Data flow: data passed as an argument from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

/* bad function declaration */
void CWE124_Buffer_Underwrite__malloc_wchar_t_cpy_51b_bad_sink(wchar_t * data);

void CWE124_Buffer_Underwrite__malloc_wchar_t_cpy_51_bad()
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
    CWE124_Buffer_Underwrite__malloc_wchar_t_cpy_51b_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declarations */
void CWE124_Buffer_Underwrite__malloc_wchar_t_cpy_51b_goodG2B_sink(wchar_t * data);

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
    CWE124_Buffer_Underwrite__malloc_wchar_t_cpy_51b_goodG2B_sink(data);
}

void CWE124_Buffer_Underwrite__malloc_wchar_t_cpy_51_good()
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
    CWE124_Buffer_Underwrite__malloc_wchar_t_cpy_51_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE124_Buffer_Underwrite__malloc_wchar_t_cpy_51_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
