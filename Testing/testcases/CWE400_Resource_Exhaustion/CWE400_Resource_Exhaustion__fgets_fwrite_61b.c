/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE400_Resource_Exhaustion__fgets_fwrite_61b.c
Label Definition File: CWE400_Resource_Exhaustion.label.xml
Template File: sources-sinks-61b.tmpl.c
*/
/*
 * @description
 * CWE: 400 Resource Exhaustion
 * BadSource: fgets Read data from the console using fgets()
 * GoodSource: Assign count to be a relatively small number
 * Sinks: fwrite
 *    GoodSink: Write to a file count number of times, but first validate count
 *    BadSink : Write to a file count number of times
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#define CHAR_ARRAY_SIZE sizeof(count)*sizeof(count)

#define SENTENCE "This is the sentence we are printing to the file. "

#ifndef OMITBAD

int CWE400_Resource_Exhaustion__fgets_fwrite_61b_bad_source(int count)
{
    {
        char input_buf[CHAR_ARRAY_SIZE] = "";
        fgets(input_buf, CHAR_ARRAY_SIZE, stdin);
        /* Convert to int */
        count = atoi(input_buf);
    }
    return count;
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
int CWE400_Resource_Exhaustion__fgets_fwrite_61b_goodG2B_source(int count)
{
    /* FIX: Use a relatively small number */
    count = 20;
    return count;
}

/* goodB2G() uses the BadSource with the GoodSink */
int CWE400_Resource_Exhaustion__fgets_fwrite_61b_goodB2G_source(int count)
{
    {
        char input_buf[CHAR_ARRAY_SIZE] = "";
        fgets(input_buf, CHAR_ARRAY_SIZE, stdin);
        /* Convert to int */
        count = atoi(input_buf);
    }
    return count;
}

#endif /* OMITGOOD */
