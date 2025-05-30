/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE680_Integer_Overflow_To_Buffer_Overflow__malloc_fscanf_45.c
Label Definition File: CWE680_Integer_Overflow_To_Buffer_Overflow__malloc.label.xml
Template File: sources-sink-45.tmpl.c
*/
/*
 * @description
 * CWE: 680 Integer Overflow to Buffer Overflow
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Small number greater than zero that will not cause an integer overflow in the sink
 * Sinks:
 *    BadSink : Attempt to allocate array using length value from source
 * Flow Variant: 45 Data flow: data passed as a static global variable from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

static int CWE680_Integer_Overflow_To_Buffer_Overflow__malloc_fscanf_45_bad_data;
static int CWE680_Integer_Overflow_To_Buffer_Overflow__malloc_fscanf_45_goodG2B_data;

#ifndef OMITBAD

static void bad_sink()
{
    int data = CWE680_Integer_Overflow_To_Buffer_Overflow__malloc_fscanf_45_bad_data;
    {
        size_t i;
        int *b;
        /* POTENTIAL FLAW: if data * sizeof(int) > SIZE_MAX, overflows to a small value
             so that the for loop doing the initialization causes a buffer overflow */
        b = (int*)malloc(data * sizeof(int));
        for (i = 0; i < (size_t)data; i++)
        {
            b[i] = 0; /* Potentially writes beyond the boundary of b */
        }
        printIntLine(b[0]);
        free(b);
    }
}

void CWE680_Integer_Overflow_To_Buffer_Overflow__malloc_fscanf_45_bad()
{
    int data;
    /* Initialize data */
    data = -1;
    fscanf (stdin, "%d", &data);
    CWE680_Integer_Overflow_To_Buffer_Overflow__malloc_fscanf_45_bad_data = data;
    bad_sink();
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B_sink()
{
    int data = CWE680_Integer_Overflow_To_Buffer_Overflow__malloc_fscanf_45_goodG2B_data;
    {
        size_t i;
        int *b;
        /* POTENTIAL FLAW: if data * sizeof(int) > SIZE_MAX, overflows to a small value
             so that the for loop doing the initialization causes a buffer overflow */
        b = (int*)malloc(data * sizeof(int));
        for (i = 0; i < (size_t)data; i++)
        {
            b[i] = 0; /* Potentially writes beyond the boundary of b */
        }
        printIntLine(b[0]);
        free(b);
    }
}

static void goodG2B()
{
    int data;
    /* Initialize data */
    data = -1;
    /* FIX: Set data to a relatively small number greater than zero */
    data = 20;
    CWE680_Integer_Overflow_To_Buffer_Overflow__malloc_fscanf_45_goodG2B_data = data;
    goodG2B_sink();
}

void CWE680_Integer_Overflow_To_Buffer_Overflow__malloc_fscanf_45_good()
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
    CWE680_Integer_Overflow_To_Buffer_Overflow__malloc_fscanf_45_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE680_Integer_Overflow_To_Buffer_Overflow__malloc_fscanf_45_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
