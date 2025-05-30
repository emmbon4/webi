/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE400_Resource_Exhaustion__fgets_fwrite_66a.c
Label Definition File: CWE400_Resource_Exhaustion.label.xml
Template File: sources-sinks-66a.tmpl.c
*/
/*
 * @description
 * CWE: 400 Resource Exhaustion
 * BadSource: fgets Read data from the console using fgets()
 * GoodSource: Assign count to be a relatively small number
 * Sinks: fwrite
 *    GoodSink: Write to a file count number of times, but first validate count
 *    BadSink : Write to a file count number of times
 * Flow Variant: 66 Data flow: data passed in an array from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#define CHAR_ARRAY_SIZE sizeof(count)*sizeof(count)

#define SENTENCE "This is the sentence we are printing to the file. "

#ifndef OMITBAD

/* bad function declaration */
void CWE400_Resource_Exhaustion__fgets_fwrite_66b_bad_sink(int count_array[]);

void CWE400_Resource_Exhaustion__fgets_fwrite_66_bad()
{
    int count;
    int count_array[5];
    /* Initialize count */
    count = -1;
    {
        char input_buf[CHAR_ARRAY_SIZE] = "";
        fgets(input_buf, CHAR_ARRAY_SIZE, stdin);
        /* Convert to int */
        count = atoi(input_buf);
    }
    /* put count in array */
    count_array[2] = count;
    CWE400_Resource_Exhaustion__fgets_fwrite_66b_bad_sink(count_array);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE400_Resource_Exhaustion__fgets_fwrite_66b_goodG2B_sink(int count_array[]);

static void goodG2B()
{
    int count;
    int count_array[5];
    /* Initialize count */
    count = -1;
    /* FIX: Use a relatively small number */
    count = 20;
    count_array[2] = count;
    CWE400_Resource_Exhaustion__fgets_fwrite_66b_goodG2B_sink(count_array);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE400_Resource_Exhaustion__fgets_fwrite_66b_goodB2G_sink(int count_array[]);

static void goodB2G()
{
    int count;
    int count_array[5];
    /* Initialize count */
    count = -1;
    {
        char input_buf[CHAR_ARRAY_SIZE] = "";
        fgets(input_buf, CHAR_ARRAY_SIZE, stdin);
        /* Convert to int */
        count = atoi(input_buf);
    }
    count_array[2] = count;
    CWE400_Resource_Exhaustion__fgets_fwrite_66b_goodB2G_sink(count_array);
}

void CWE400_Resource_Exhaustion__fgets_fwrite_66_good()
{
    goodG2B();
    goodB2G();
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
    CWE400_Resource_Exhaustion__fgets_fwrite_66_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE400_Resource_Exhaustion__fgets_fwrite_66_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
