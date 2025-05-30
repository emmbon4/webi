/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE121_Stack_Based_Buffer_Overflow__dest_int_alloca_memmove_66a.c
Label Definition File: CWE121_Stack_Based_Buffer_Overflow__dest.label.xml
Template File: sources-sink-66a.tmpl.c
*/
/*
 * @description
 * CWE: 121 Stack Based Buffer Overflow
 * BadSource:  Set data pointer to the bad buffer
 * GoodSource: Set data pointer to the good buffer
 * Sinks: memmove
 *    BadSink : Copy int array to data using memmove
 * Flow Variant: 66 Data flow: data passed in an array from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

/* bad function declaration */
void CWE121_Stack_Based_Buffer_Overflow__dest_int_alloca_memmove_66b_bad_sink(int * data_array[]);

void CWE121_Stack_Based_Buffer_Overflow__dest_int_alloca_memmove_66_bad()
{
    int * data;
    int * data_array[5];
    int * data_badbuf = (int *)ALLOCA(50*sizeof(int));
    int * data_goodbuf = (int *)ALLOCA(100*sizeof(int));
    /* FLAW: Set a pointer to a "small" buffer. This buffer will be used in the sinks as a destination
     * buffer in various memory copying functions using a "large" source buffer. */
    data = data_badbuf;
    /* put data in array */
    data_array[2] = data;
    CWE121_Stack_Based_Buffer_Overflow__dest_int_alloca_memmove_66b_bad_sink(data_array);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE121_Stack_Based_Buffer_Overflow__dest_int_alloca_memmove_66b_goodG2B_sink(int * data_array[]);

static void goodG2B()
{
    int * data;
    int * data_array[5];
    int * data_badbuf = (int *)ALLOCA(50*sizeof(int));
    int * data_goodbuf = (int *)ALLOCA(100*sizeof(int));
    /* FIX: Set a pointer to a "large" buffer, thus avoiding buffer overflows in the sinks. */
    data = data_goodbuf;
    data_array[2] = data;
    CWE121_Stack_Based_Buffer_Overflow__dest_int_alloca_memmove_66b_goodG2B_sink(data_array);
}

void CWE121_Stack_Based_Buffer_Overflow__dest_int_alloca_memmove_66_good()
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
    CWE121_Stack_Based_Buffer_Overflow__dest_int_alloca_memmove_66_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE121_Stack_Based_Buffer_Overflow__dest_int_alloca_memmove_66_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
