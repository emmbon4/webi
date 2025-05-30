/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE121_Stack_Based_Buffer_Overflow__dest_wchar_t_alloca_ncat_52a.c
Label Definition File: CWE121_Stack_Based_Buffer_Overflow__dest.string.label.xml
Template File: sources-sink-52a.tmpl.c
*/
/*
 * @description
 * CWE: 121 Stack Based Buffer Overflow
 * BadSource:  Set data pointer to the bad buffer
 * GoodSource: Set data pointer to the good buffer
 * Sink: ncat
 *    BadSink : Copy string to data using wcsncat
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

/* bad function declaration */
void CWE121_Stack_Based_Buffer_Overflow__dest_wchar_t_alloca_ncat_52b_bad_sink(wchar_t * data);

void CWE121_Stack_Based_Buffer_Overflow__dest_wchar_t_alloca_ncat_52_bad()
{
    wchar_t * data;
    wchar_t * data_badbuf = (wchar_t *)ALLOCA(50*sizeof(wchar_t));
    wchar_t * data_goodbuf = (wchar_t *)ALLOCA(100*sizeof(wchar_t));
    /* FLAW: Set a pointer to a "small" buffer. This buffer will be used in the sinks as a destination
     * buffer in various memory copying functions using a "large" source buffer. */
    data = data_badbuf;
    data[0] = L'\0'; /* null terminate */
    CWE121_Stack_Based_Buffer_Overflow__dest_wchar_t_alloca_ncat_52b_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declaration */
void CWE121_Stack_Based_Buffer_Overflow__dest_wchar_t_alloca_ncat_52b_goodG2B_sink(wchar_t * data);

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    wchar_t * data;
    wchar_t * data_badbuf = (wchar_t *)ALLOCA(50*sizeof(wchar_t));
    wchar_t * data_goodbuf = (wchar_t *)ALLOCA(100*sizeof(wchar_t));
    /* FIX: Set a pointer to a "large" buffer, thus avoiding buffer overflows in the sinks. */
    data = data_goodbuf;
    data[0] = L'\0'; /* null terminate */
    CWE121_Stack_Based_Buffer_Overflow__dest_wchar_t_alloca_ncat_52b_goodG2B_sink(data);
}

void CWE121_Stack_Based_Buffer_Overflow__dest_wchar_t_alloca_ncat_52_good()
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
    CWE121_Stack_Based_Buffer_Overflow__dest_wchar_t_alloca_ncat_52_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE121_Stack_Based_Buffer_Overflow__dest_wchar_t_alloca_ncat_52_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
