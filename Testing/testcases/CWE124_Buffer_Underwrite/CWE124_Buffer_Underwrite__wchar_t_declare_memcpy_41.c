/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE124_Buffer_Underwrite__wchar_t_declare_memcpy_41.c
Label Definition File: CWE124_Buffer_Underwrite.stack.label.xml
Template File: sources-sink-41.tmpl.c
*/
/*
 * @description
 * CWE: 124 Buffer Underwrite
 * BadSource:  Set data pointer to before the allocated memory buffer
 * GoodSource: Set data pointer to the allocated memory buffer
 * Sink: memcpy
 *    BadSink : Copy string to data using memcpy
 * Flow Variant: 41 Data flow: data passed as an argument from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE124_Buffer_Underwrite__wchar_t_declare_memcpy_41_bad_sink(wchar_t * data)
{
    {
        wchar_t src[100];
        wmemset(src, L'C', 100-1); /* fill with 'C's */
        src[100-1] = L'\0'; /* null terminate */
        /* POTENTIAL FLAW: Possibly copying data to memory before the destination buffer */
        memcpy(data, src, 100*sizeof(wchar_t));
        /* Ensure the destination buffer is null terminated */
        data[100-1] = L'\0';
        printWLine(data);
    }
}

void CWE124_Buffer_Underwrite__wchar_t_declare_memcpy_41_bad()
{
    wchar_t * data;
    wchar_t data_buf[100];
    wmemset(data_buf, L'A', 100-1);
    data_buf[100-1] = L'\0';
    /* FLAW: Set data pointer to before the allocated memory buffer */
    data = data_buf - 8;
    CWE124_Buffer_Underwrite__wchar_t_declare_memcpy_41_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

void CWE124_Buffer_Underwrite__wchar_t_declare_memcpy_41_goodG2B_sink(wchar_t * data)
{
    {
        wchar_t src[100];
        wmemset(src, L'C', 100-1); /* fill with 'C's */
        src[100-1] = L'\0'; /* null terminate */
        /* POTENTIAL FLAW: Possibly copying data to memory before the destination buffer */
        memcpy(data, src, 100*sizeof(wchar_t));
        /* Ensure the destination buffer is null terminated */
        data[100-1] = L'\0';
        printWLine(data);
    }
}

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    wchar_t * data;
    wchar_t data_buf[100];
    wmemset(data_buf, L'A', 100-1);
    data_buf[100-1] = L'\0';
    /* FIX: Set data pointer to the allocated memory buffer */
    data = data_buf;
    CWE124_Buffer_Underwrite__wchar_t_declare_memcpy_41_goodG2B_sink(data);
}

void CWE124_Buffer_Underwrite__wchar_t_declare_memcpy_41_good()
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
    CWE124_Buffer_Underwrite__wchar_t_declare_memcpy_41_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE124_Buffer_Underwrite__wchar_t_declare_memcpy_41_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
