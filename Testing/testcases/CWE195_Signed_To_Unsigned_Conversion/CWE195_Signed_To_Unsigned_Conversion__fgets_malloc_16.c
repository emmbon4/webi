/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE195_Signed_To_Unsigned_Conversion__fgets_malloc_16.c
Label Definition File: CWE195_Signed_To_Unsigned_Conversion.label.xml
Template File: sources-sink-16.tmpl.c
*/
/*
 * @description
 * CWE: 195 Signed to Unsigned Conversion
 * BadSource: fgets Read data from the console using fgets()
 * GoodSource: Positive integer
 * Sink: malloc
 *    BadSink : Allocate memory using malloc() with the size of data
 * Flow Variant: 16 Control flow: while(1) and while(0)
 *
 * */

#include "std_testcase.h"

#define CHAR_ARRAY_SIZE sizeof(data)*sizeof(data)

#ifndef OMITBAD

void CWE195_Signed_To_Unsigned_Conversion__fgets_malloc_16_bad()
{
    int data;
    /* Initialize data */
    data = -1;
    while(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Use a positive integer less than &InitialDataSize&*/
        data = 100-1;
        break;
    }
    while(1)
    {
        {
            char input_buf[CHAR_ARRAY_SIZE] = "";
            fgets(input_buf, CHAR_ARRAY_SIZE, stdin);
            /* Convert to int */
            data = atoi(input_buf);
        }
        break;
    }
    {
        /* Assume we want to allocate a relatively small buffer */
        if (data < 100)
        {
            /* POTENTIAL FLAW: malloc() takes a size_t (unsigned int) as input and therefore if it is negative,
             * the coversion will cause malloc() to allocate a very large amount of data or fail */
            char * data_buf = (char *)malloc(data);
            /* Do something with data_buf */
            memset(data_buf, 'A', data-1);
            data_buf[data-1] = '\0';
            printLine(data_buf);
            free(data_buf);
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() - use goodsource and badsink by changing the conditions on the while statements */
static void goodG2B()
{
    int data;
    /* Initialize data */
    data = -1;
    while(1)
    {
        /* FIX: Use a positive integer less than &InitialDataSize&*/
        data = 100-1;
        break;
    }
    while(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            char input_buf[CHAR_ARRAY_SIZE] = "";
            fgets(input_buf, CHAR_ARRAY_SIZE, stdin);
            /* Convert to int */
            data = atoi(input_buf);
        }
        break;
    }
    {
        /* Assume we want to allocate a relatively small buffer */
        if (data < 100)
        {
            /* POTENTIAL FLAW: malloc() takes a size_t (unsigned int) as input and therefore if it is negative,
             * the coversion will cause malloc() to allocate a very large amount of data or fail */
            char * data_buf = (char *)malloc(data);
            /* Do something with data_buf */
            memset(data_buf, 'A', data-1);
            data_buf[data-1] = '\0';
            printLine(data_buf);
            free(data_buf);
        }
    }
}

void CWE195_Signed_To_Unsigned_Conversion__fgets_malloc_16_good()
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
    CWE195_Signed_To_Unsigned_Conversion__fgets_malloc_16_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE195_Signed_To_Unsigned_Conversion__fgets_malloc_16_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
