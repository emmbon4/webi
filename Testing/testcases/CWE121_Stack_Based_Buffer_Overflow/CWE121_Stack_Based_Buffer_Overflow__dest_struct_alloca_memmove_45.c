/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE121_Stack_Based_Buffer_Overflow__dest_struct_alloca_memmove_45.c
Label Definition File: CWE121_Stack_Based_Buffer_Overflow__dest.label.xml
Template File: sources-sink-45.tmpl.c
*/
/*
 * @description
 * CWE: 121 Stack Based Buffer Overflow
 * BadSource:  Set data pointer to the bad buffer
 * GoodSource: Set data pointer to the good buffer
 * Sinks: memmove
 *    BadSink : Copy twoints array to data using memmove
 * Flow Variant: 45 Data flow: data passed as a static global variable from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

static twoints * CWE121_Stack_Based_Buffer_Overflow__dest_struct_alloca_memmove_45_bad_data;
static twoints * CWE121_Stack_Based_Buffer_Overflow__dest_struct_alloca_memmove_45_goodG2B_data;

#ifndef OMITBAD

static void bad_sink()
{
    twoints * data = CWE121_Stack_Based_Buffer_Overflow__dest_struct_alloca_memmove_45_bad_data;
    {
        twoints src[100];
        {
            size_t i;
            /* Initialize array */
            for (i = 0; i < 100; i++)
            {
                src[i].a = 0;
                src[i].b = 0;
            }
        }
        /* POTENTIAL FLAW: Possible buffer overflow if data < 100 */
        memmove(data, src, 100*sizeof(twoints));
        printStructLine(&data[0]);
    }
}

void CWE121_Stack_Based_Buffer_Overflow__dest_struct_alloca_memmove_45_bad()
{
    twoints * data;
    twoints * data_badbuf = (twoints *)ALLOCA(50*sizeof(twoints));
    twoints * data_goodbuf = (twoints *)ALLOCA(100*sizeof(twoints));
    /* FLAW: Set a pointer to a "small" buffer. This buffer will be used in the sinks as a destination
     * buffer in various memory copying functions using a "large" source buffer. */
    data = data_badbuf;
    CWE121_Stack_Based_Buffer_Overflow__dest_struct_alloca_memmove_45_bad_data = data;
    bad_sink();
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B_sink()
{
    twoints * data = CWE121_Stack_Based_Buffer_Overflow__dest_struct_alloca_memmove_45_goodG2B_data;
    {
        twoints src[100];
        {
            size_t i;
            /* Initialize array */
            for (i = 0; i < 100; i++)
            {
                src[i].a = 0;
                src[i].b = 0;
            }
        }
        /* POTENTIAL FLAW: Possible buffer overflow if data < 100 */
        memmove(data, src, 100*sizeof(twoints));
        printStructLine(&data[0]);
    }
}

static void goodG2B()
{
    twoints * data;
    twoints * data_badbuf = (twoints *)ALLOCA(50*sizeof(twoints));
    twoints * data_goodbuf = (twoints *)ALLOCA(100*sizeof(twoints));
    /* FIX: Set a pointer to a "large" buffer, thus avoiding buffer overflows in the sinks. */
    data = data_goodbuf;
    CWE121_Stack_Based_Buffer_Overflow__dest_struct_alloca_memmove_45_goodG2B_data = data;
    goodG2B_sink();
}

void CWE121_Stack_Based_Buffer_Overflow__dest_struct_alloca_memmove_45_good()
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
    CWE121_Stack_Based_Buffer_Overflow__dest_struct_alloca_memmove_45_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE121_Stack_Based_Buffer_Overflow__dest_struct_alloca_memmove_45_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
