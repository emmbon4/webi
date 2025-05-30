/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE680_Integer_Overflow_To_Buffer_Overflow__malloc_fgets_66a.c
Label Definition File: CWE680_Integer_Overflow_To_Buffer_Overflow__malloc.label.xml
Template File: sources-sink-66a.tmpl.c
*/
/*
 * @description
 * CWE: 680 Integer Overflow to Buffer Overflow
 * BadSource: fgets Read data from the console using fgets()
 * GoodSource: Small number greater than zero that will not cause an integer overflow in the sink
 * Sinks:
 *    BadSink : Attempt to allocate array using length value from source
 * Flow Variant: 66 Data flow: data passed in an array from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#define CHAR_ARRAY_SIZE sizeof(data)*sizeof(data)

#ifndef OMITBAD

/* bad function declaration */
void CWE680_Integer_Overflow_To_Buffer_Overflow__malloc_fgets_66b_bad_sink(int data_array[]);

void CWE680_Integer_Overflow_To_Buffer_Overflow__malloc_fgets_66_bad()
{
    int data;
    int data_array[5];
    /* Initialize data */
    data = -1;
    {
        char input_buf[CHAR_ARRAY_SIZE] = "";
        fgets(input_buf, CHAR_ARRAY_SIZE, stdin);
        /* Convert to int */
        data = atoi(input_buf);
    }
    /* put data in array */
    data_array[2] = data;
    CWE680_Integer_Overflow_To_Buffer_Overflow__malloc_fgets_66b_bad_sink(data_array);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE680_Integer_Overflow_To_Buffer_Overflow__malloc_fgets_66b_goodG2B_sink(int data_array[]);

static void goodG2B()
{
    int data;
    int data_array[5];
    /* Initialize data */
    data = -1;
    /* FIX: Set data to a relatively small number greater than zero */
    data = 20;
    data_array[2] = data;
    CWE680_Integer_Overflow_To_Buffer_Overflow__malloc_fgets_66b_goodG2B_sink(data_array);
}

void CWE680_Integer_Overflow_To_Buffer_Overflow__malloc_fgets_66_good()
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
    CWE680_Integer_Overflow_To_Buffer_Overflow__malloc_fgets_66_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE680_Integer_Overflow_To_Buffer_Overflow__malloc_fgets_66_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
