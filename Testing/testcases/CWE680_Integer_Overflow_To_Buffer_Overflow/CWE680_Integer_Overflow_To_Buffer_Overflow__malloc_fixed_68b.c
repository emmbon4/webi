/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE680_Integer_Overflow_To_Buffer_Overflow__malloc_fixed_68b.c
Label Definition File: CWE680_Integer_Overflow_To_Buffer_Overflow__malloc.label.xml
Template File: sources-sink-68b.tmpl.c
*/
/*
 * @description
 * CWE: 680 Integer Overflow to Buffer Overflow
 * BadSource: fixed Fixed value that will cause an integer overflow in the sink
 * GoodSource: Small number greater than zero that will not cause an integer overflow in the sink
 * Sink:
 *    BadSink : Attempt to allocate array using length value from source
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

extern int CWE680_Integer_Overflow_To_Buffer_Overflow__malloc_fixed_68_bad_data;
extern int CWE680_Integer_Overflow_To_Buffer_Overflow__malloc_fixed_68_goodG2B_data;

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

void CWE680_Integer_Overflow_To_Buffer_Overflow__malloc_fixed_68b_bad_sink()
{
    int data = CWE680_Integer_Overflow_To_Buffer_Overflow__malloc_fixed_68_bad_data;
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

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE680_Integer_Overflow_To_Buffer_Overflow__malloc_fixed_68b_goodG2B_sink()
{
    int data = CWE680_Integer_Overflow_To_Buffer_Overflow__malloc_fixed_68_goodG2B_data;
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

#endif /* OMITGOOD */
