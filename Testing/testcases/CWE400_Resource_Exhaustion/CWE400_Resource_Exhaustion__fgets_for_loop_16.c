/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE400_Resource_Exhaustion__fgets_for_loop_16.c
Label Definition File: CWE400_Resource_Exhaustion.label.xml
Template File: sources-sinks-16.tmpl.c
*/
/*
 * @description
 * CWE: 400 Resource Exhaustion
 * BadSource: fgets Read data from the console using fgets()
 * GoodSource: Assign count to be a relatively small number
 * Sinks: for_loop
 *    GoodSink: Validate count before using it as the loop variant in a for loop
 *    BadSink : Use count as the loop variant in a for loop
 * Flow Variant: 16 Control flow: while(1) and while(0)
 *
 * */

#include "std_testcase.h"

#define CHAR_ARRAY_SIZE sizeof(count)*sizeof(count)

#ifndef OMITBAD

void CWE400_Resource_Exhaustion__fgets_for_loop_16_bad()
{
    int count;
    /* Initialize count */
    count = -1;
    while(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Use a relatively small number */
        count = 20;
        break;
    }
    while(1)
    {
        {
            char input_buf[CHAR_ARRAY_SIZE] = "";
            fgets(input_buf, CHAR_ARRAY_SIZE, stdin);
            /* Convert to int */
            count = atoi(input_buf);
        }
        break;
    }
    while(1)
    {
        {
            size_t i = 0;
            /* FLAW: For loop using count as the loop variant and no validation */
            for (i = 0; i < (size_t)count; i++)
            {
                printLine("Hello");
            }
        }
        break;
    }
    while(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
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
        break;
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G() - use badsource and goodsink by changing the conditions on the third and fourth while statements */
static void goodB2G()
{
    int count;
    /* Initialize count */
    count = -1;
    while(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Use a relatively small number */
        count = 20;
        break;
    }
    while(1)
    {
        {
            char input_buf[CHAR_ARRAY_SIZE] = "";
            fgets(input_buf, CHAR_ARRAY_SIZE, stdin);
            /* Convert to int */
            count = atoi(input_buf);
        }
        break;
    }
    while(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            size_t i = 0;
            /* FLAW: For loop using count as the loop variant and no validation */
            for (i = 0; i < (size_t)count; i++)
            {
                printLine("Hello");
            }
        }
        break;
    }
    while(1)
    {
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
        break;
    }
}

/* goodG2B() - use goodsource and badsink by changing the conditions on the first and second while statements */
static void goodG2B()
{
    int count;
    /* Initialize count */
    count = -1;
    while(1)
    {
        /* FIX: Use a relatively small number */
        count = 20;
        break;
    }
    while(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            char input_buf[CHAR_ARRAY_SIZE] = "";
            fgets(input_buf, CHAR_ARRAY_SIZE, stdin);
            /* Convert to int */
            count = atoi(input_buf);
        }
        break;
    }
    while(1)
    {
        {
            size_t i = 0;
            /* FLAW: For loop using count as the loop variant and no validation */
            for (i = 0; i < (size_t)count; i++)
            {
                printLine("Hello");
            }
        }
        break;
    }
    while(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
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
        break;
    }
}

void CWE400_Resource_Exhaustion__fgets_for_loop_16_good()
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
    CWE400_Resource_Exhaustion__fgets_for_loop_16_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE400_Resource_Exhaustion__fgets_for_loop_16_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
