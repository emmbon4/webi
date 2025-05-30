/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE124_Buffer_Underwrite__wchar_t_declare_memmove_32.c
Label Definition File: CWE124_Buffer_Underwrite.stack.label.xml
Template File: sources-sink-32.tmpl.c
*/
/*
 * @description
 * CWE: 124 Buffer Underwrite
 * BadSource:  Set data pointer to before the allocated memory buffer
 * GoodSource: Set data pointer to the allocated memory buffer
 * Sink: memmove
 *    BadSink : Copy string to data using memmove
 * Flow Variant: 32 Data flow using two pointers to the same value within the same function
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE124_Buffer_Underwrite__wchar_t_declare_memmove_32_bad()
{
    wchar_t * data;
    wchar_t * *data_ptr1 = &data;
    wchar_t * *data_ptr2 = &data;
    wchar_t data_buf[100];
    wmemset(data_buf, L'A', 100-1);
    data_buf[100-1] = L'\0';
    {
        wchar_t * data = *data_ptr1;
        /* FLAW: Set data pointer to before the allocated memory buffer */
        data = data_buf - 8;
        *data_ptr1 = data;
    }
    {
        wchar_t * data = *data_ptr2;
        {
            wchar_t src[100];
            wmemset(src, L'C', 100-1); /* fill with 'C's */
            src[100-1] = L'\0'; /* null terminate */
            /* POTENTIAL FLAW: Possibly copying data to memory before the destination buffer */
            memmove(data, src, 100*sizeof(wchar_t));
            /* Ensure the destination buffer is null terminated */
            data[100-1] = L'\0';
            printWLine(data);
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    wchar_t * data;
    wchar_t * *data_ptr1 = &data;
    wchar_t * *data_ptr2 = &data;
    wchar_t data_buf[100];
    wmemset(data_buf, L'A', 100-1);
    data_buf[100-1] = L'\0';
    {
        wchar_t * data = *data_ptr1;
        /* FIX: Set data pointer to the allocated memory buffer */
        data = data_buf;
        *data_ptr1 = data;
    }
    {
        wchar_t * data = *data_ptr2;
        {
            wchar_t src[100];
            wmemset(src, L'C', 100-1); /* fill with 'C's */
            src[100-1] = L'\0'; /* null terminate */
            /* POTENTIAL FLAW: Possibly copying data to memory before the destination buffer */
            memmove(data, src, 100*sizeof(wchar_t));
            /* Ensure the destination buffer is null terminated */
            data[100-1] = L'\0';
            printWLine(data);
        }
    }
}

void CWE124_Buffer_Underwrite__wchar_t_declare_memmove_32_good()
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
    CWE124_Buffer_Underwrite__wchar_t_declare_memmove_32_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE124_Buffer_Underwrite__wchar_t_declare_memmove_32_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
