/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE194_Unexpected_Sign_Extension__fgets_malloc_14.c
Label Definition File: CWE194_Unexpected_Sign_Extension.label.xml
Template File: sources-sink-14.tmpl.c
*/
/*
 * @description
 * CWE: 194 Unexpected Sign Extension
 * BadSource: fgets Read data from the console using fgets()
 * GoodSource: Positive integer
 * Sink: malloc
 *    BadSink : Allocate memory using malloc() with the size of data
 * Flow Variant: 14 Control flow: if(global_five==5) and if(global_five!=5)
 *
 * */

#include "std_testcase.h"

/* Must be at least 8 for atoi() to work properly */
#define CHAR_ARRAY_SIZE 8

#ifndef OMITBAD

void CWE194_Unexpected_Sign_Extension__fgets_malloc_14_bad()
{
    short data;
    /* Initialize data */
    data = 0;
    if(global_five==5)
    {
        {
            char input_buf[CHAR_ARRAY_SIZE] = "";
            /* POTENTIAL FLAW: Use a value input from the console using fgets() */
            fgets(input_buf, CHAR_ARRAY_SIZE, stdin);
            /* Convert to short */
            data = (short)atoi(input_buf);
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Use a positive integer less than &InitialDataSize&*/
        data = 100-1;
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

/* goodG2B1() - use goodsource and badsink by changing the global_five==5 to global_five!=5 */
static void goodG2B1()
{
    short data;
    /* Initialize data */
    data = 0;
    if(global_five!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            char input_buf[CHAR_ARRAY_SIZE] = "";
            /* POTENTIAL FLAW: Use a value input from the console using fgets() */
            fgets(input_buf, CHAR_ARRAY_SIZE, stdin);
            /* Convert to short */
            data = (short)atoi(input_buf);
        }
    }
    else
    {
        /* FIX: Use a positive integer less than &InitialDataSize&*/
        data = 100-1;
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

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the if statement */
static void goodG2B2()
{
    short data;
    /* Initialize data */
    data = 0;
    if(global_five==5)
    {
        /* FIX: Use a positive integer less than &InitialDataSize&*/
        data = 100-1;
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            char input_buf[CHAR_ARRAY_SIZE] = "";
            /* POTENTIAL FLAW: Use a value input from the console using fgets() */
            fgets(input_buf, CHAR_ARRAY_SIZE, stdin);
            /* Convert to short */
            data = (short)atoi(input_buf);
        }
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

void CWE194_Unexpected_Sign_Extension__fgets_malloc_14_good()
{
    goodG2B1();
    goodG2B2();
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
    CWE194_Unexpected_Sign_Extension__fgets_malloc_14_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE194_Unexpected_Sign_Extension__fgets_malloc_14_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
