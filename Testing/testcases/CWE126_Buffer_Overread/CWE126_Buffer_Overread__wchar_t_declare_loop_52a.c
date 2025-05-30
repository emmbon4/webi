/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE126_Buffer_Overread__wchar_t_declare_loop_52a.c
Label Definition File: CWE126_Buffer_Overread.stack.label.xml
Template File: sources-sink-52a.tmpl.c
*/
/*
 * @description
 * CWE: 126 Buffer Over-read
 * BadSource:  Set data pointer to a small buffer
 * GoodSource: Set data pointer to a large buffer
 * Sink: loop
 *    BadSink : Copy data to string using a loop
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

/* bad function declaration */
void CWE126_Buffer_Overread__wchar_t_declare_loop_52b_bad_sink(wchar_t * data);

void CWE126_Buffer_Overread__wchar_t_declare_loop_52_bad()
{
    wchar_t * data;
    wchar_t data_badbuf[50];
    wchar_t data_goodbuf[100];
    wmemset(data_badbuf, L'A', 50-1); /* fill with 'A's */
    data_badbuf[50-1] = L'\0'; /* null terminate */
    wmemset(data_goodbuf, L'A', 100-1); /* fill with 'A's */
    data_goodbuf[100-1] = L'\0'; /* null terminate */
    /* FLAW: Set data pointer to a small buffer */
    data = data_badbuf;
    CWE126_Buffer_Overread__wchar_t_declare_loop_52b_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declaration */
void CWE126_Buffer_Overread__wchar_t_declare_loop_52b_goodG2B_sink(wchar_t * data);

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    wchar_t * data;
    wchar_t data_badbuf[50];
    wchar_t data_goodbuf[100];
    wmemset(data_badbuf, L'A', 50-1); /* fill with 'A's */
    data_badbuf[50-1] = L'\0'; /* null terminate */
    wmemset(data_goodbuf, L'A', 100-1); /* fill with 'A's */
    data_goodbuf[100-1] = L'\0'; /* null terminate */
    /* FIX: Set data pointer to a large buffer */
    data = data_goodbuf;
    CWE126_Buffer_Overread__wchar_t_declare_loop_52b_goodG2B_sink(data);
}

void CWE126_Buffer_Overread__wchar_t_declare_loop_52_good()
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
    CWE126_Buffer_Overread__wchar_t_declare_loop_52_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE126_Buffer_Overread__wchar_t_declare_loop_52_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
