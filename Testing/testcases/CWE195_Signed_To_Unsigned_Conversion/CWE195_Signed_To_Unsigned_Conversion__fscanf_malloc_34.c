/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE195_Signed_To_Unsigned_Conversion__fscanf_malloc_34.c
Label Definition File: CWE195_Signed_To_Unsigned_Conversion.label.xml
Template File: sources-sink-34.tmpl.c
*/
/*
 * @description
 * CWE: 195 Signed to Unsigned Conversion
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Positive integer
 * Sinks: malloc
 *    BadSink : Allocate memory using malloc() with the size of data
 * Flow Variant: 34 Data flow: use of a union containing two methods of accessing the same data (within the same function)
 *
 * */

#include "std_testcase.h"

typedef union
{
    int a;
    int b;
} CWE195_Signed_To_Unsigned_Conversion__fscanf_malloc_34_union_type;

#ifndef OMITBAD

void CWE195_Signed_To_Unsigned_Conversion__fscanf_malloc_34_bad()
{
    int data;
    CWE195_Signed_To_Unsigned_Conversion__fscanf_malloc_34_union_type my_union;
    /* Initialize data */
    data = -1;
    fscanf (stdin, "%d", &data);
    my_union.a = data;
    {
        int data = my_union.b;
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
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    int data;
    CWE195_Signed_To_Unsigned_Conversion__fscanf_malloc_34_union_type my_union;
    /* Initialize data */
    data = -1;
    /* FIX: Use a positive integer less than &InitialDataSize&*/
    data = 100-1;
    my_union.a = data;
    {
        int data = my_union.b;
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
}

void CWE195_Signed_To_Unsigned_Conversion__fscanf_malloc_34_good()
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
    CWE195_Signed_To_Unsigned_Conversion__fscanf_malloc_34_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE195_Signed_To_Unsigned_Conversion__fscanf_malloc_34_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
