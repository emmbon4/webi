/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE121_Stack_Based_Buffer_Overflow__src_wchar_t_alloca_ncpy_66a.c
Label Definition File: CWE121_Stack_Based_Buffer_Overflow__src.string.label.xml
Template File: sources-sink-66a.tmpl.c
*/
/*
 * @description
 * CWE: 121 Stack Based Buffer Overflow
 * BadSource:  Initialize data as a large string
 * GoodSource: Initialize data as a small string
 * Sinks: ncpy
 *    BadSink : Copy data to string using wcsncpy
 * Flow Variant: 66 Data flow: data passed in an array from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

/* bad function declaration */
void CWE121_Stack_Based_Buffer_Overflow__src_wchar_t_alloca_ncpy_66b_bad_sink(wchar_t * data_array[]);

void CWE121_Stack_Based_Buffer_Overflow__src_wchar_t_alloca_ncpy_66_bad()
{
    wchar_t * data;
    wchar_t * data_array[5];
    wchar_t * data_buf = (wchar_t *)ALLOCA(100*sizeof(wchar_t));
    data = data_buf;
    /* FLAW: Initialize data as a large buffer that is larger than the small buffer used in the sink */
    wmemset(data, L'A', 100-1); /* fill with L'A's */
    data[100-1] = L'\0'; /* null terminate */
    /* put data in array */
    data_array[2] = data;
    CWE121_Stack_Based_Buffer_Overflow__src_wchar_t_alloca_ncpy_66b_bad_sink(data_array);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE121_Stack_Based_Buffer_Overflow__src_wchar_t_alloca_ncpy_66b_goodG2B_sink(wchar_t * data_array[]);

static void goodG2B()
{
    wchar_t * data;
    wchar_t * data_array[5];
    wchar_t * data_buf = (wchar_t *)ALLOCA(100*sizeof(wchar_t));
    data = data_buf;
    /* FIX: Initialize data as a small buffer that as small or smaller than the small buffer used in the sink */
    wmemset(data, L'A', 50-1); /* fill with L'A's */
    data[50-1] = L'\0'; /* null terminate */
    data_array[2] = data;
    CWE121_Stack_Based_Buffer_Overflow__src_wchar_t_alloca_ncpy_66b_goodG2B_sink(data_array);
}

void CWE121_Stack_Based_Buffer_Overflow__src_wchar_t_alloca_ncpy_66_good()
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
    CWE121_Stack_Based_Buffer_Overflow__src_wchar_t_alloca_ncpy_66_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE121_Stack_Based_Buffer_Overflow__src_wchar_t_alloca_ncpy_66_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
