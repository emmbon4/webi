/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE400_Resource_Exhaustion__fgets_for_loop_42.c
Label Definition File: CWE400_Resource_Exhaustion.label.xml
Template File: sources-sinks-42.tmpl.c
*/
/*
 * @description
 * CWE: 400 Resource Exhaustion
 * BadSource: fgets Read data from the console using fgets()
 * GoodSource: Assign count to be a relatively small number
 * Sinks: for_loop
 *    GoodSink: Validate count before using it as the loop variant in a for loop
 *    BadSink : Use count as the loop variant in a for loop
 * Flow Variant: 42 Data flow: data returned from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

#define CHAR_ARRAY_SIZE sizeof(count)*sizeof(count)

#ifndef OMITBAD

static int bad_source(int count)
{
    {
        char input_buf[CHAR_ARRAY_SIZE] = "";
        fgets(input_buf, CHAR_ARRAY_SIZE, stdin);
        /* Convert to int */
        count = atoi(input_buf);
    }
    return count;
}

void CWE400_Resource_Exhaustion__fgets_for_loop_42_bad()
{
    int count;
    /* Initialize count */
    count = -1;
    count = bad_source(count);
    {
        size_t i = 0;
        /* FLAW: For loop using count as the loop variant and no validation */
        for (i = 0; i < (size_t)count; i++)
        {
            printLine("Hello");
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
static int goodG2B_source(int count)
{
    /* FIX: Use a relatively small number */
    count = 20;
    return count;
}

static void goodG2B()
{
    int count;
    /* Initialize count */
    count = -1;
    count = goodG2B_source(count);
    {
        size_t i = 0;
        /* FLAW: For loop using count as the loop variant and no validation */
        for (i = 0; i < (size_t)count; i++)
        {
            printLine("Hello");
        }
    }
}

/* goodB2G uses the BadSource with the GoodSink */
static int goodB2G_source(int count)
{
    {
        char input_buf[CHAR_ARRAY_SIZE] = "";
        fgets(input_buf, CHAR_ARRAY_SIZE, stdin);
        /* Convert to int */
        count = atoi(input_buf);
    }
    return count;
}

static void goodB2G()
{
    int count;
    /* Initialize count */
    count = -1;
    count = goodB2G_source(count);
    {
        size_t i = 0;
        /* FIX: Validate $Data% before using it as the for loop variant */
        if (count > 0 && count <= 20)
        {
            for (i = 0; i < (size_t)count; i++)
            {
                printLine("Hello");
            }
        }
    }
}

void CWE400_Resource_Exhaustion__fgets_for_loop_42_good()
{
    goodB2G();
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
    CWE400_Resource_Exhaustion__fgets_for_loop_42_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE400_Resource_Exhaustion__fgets_for_loop_42_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
