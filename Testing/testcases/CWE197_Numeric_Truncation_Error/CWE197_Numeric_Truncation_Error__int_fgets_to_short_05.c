/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE197_Numeric_Truncation_Error__int_fgets_to_short_05.c
Label Definition File: CWE197_Numeric_Truncation_Error__int.label.xml
Template File: sources-sink-05.tmpl.c
*/
/*
 * @description
 * CWE: 197 Numeric Truncation Error
 * BadSource: fgets Read data from the console using fgets()
 * GoodSource: Less than CHAR_MAX
 * Sink: to_short
 *    BadSink : Convert data to a short
 * Flow Variant: 05 Control flow: if(static_t) and if(static_f)
 *
 * */

#include "std_testcase.h"

#define CHAR_ARRAY_SIZE sizeof(data)*sizeof(data)

/* The two variables below are not defined as "const", but are never
   assigned any other value, so a tool should be able to identify that
   reads of these will always return their initialized values. */
static int static_t = 1; /* true */
static int static_f = 0; /* false */

#ifndef OMITBAD

void CWE197_Numeric_Truncation_Error__int_fgets_to_short_05_bad()
{
    int data;
    /* Initialize data */
    data = -1;
    if(static_t)
    {
        {
            char input_buf[CHAR_ARRAY_SIZE] = "";
            fgets(input_buf, CHAR_ARRAY_SIZE, stdin);
            /* Convert to int */
            data = atoi(input_buf);
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Use a positive integer less than CHAR_MAX*/
        data = CHAR_MAX-5;
    }
    {
        /* POTENTIAL FLAW: Convert data to a short, possibly causing a truncation error */
        short s = (short)data;
        printf("%hd\n", s);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B1() - use goodsource and badsink by changing the static_t to static_f */
static void goodG2B1()
{
    int data;
    /* Initialize data */
    data = -1;
    if(static_f)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            char input_buf[CHAR_ARRAY_SIZE] = "";
            fgets(input_buf, CHAR_ARRAY_SIZE, stdin);
            /* Convert to int */
            data = atoi(input_buf);
        }
    }
    else
    {
        /* FIX: Use a positive integer less than CHAR_MAX*/
        data = CHAR_MAX-5;
    }
    {
        /* POTENTIAL FLAW: Convert data to a short, possibly causing a truncation error */
        short s = (short)data;
        printf("%hd\n", s);
    }
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the if statement */
static void goodG2B2()
{
    int data;
    /* Initialize data */
    data = -1;
    if(static_t)
    {
        /* FIX: Use a positive integer less than CHAR_MAX*/
        data = CHAR_MAX-5;
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            char input_buf[CHAR_ARRAY_SIZE] = "";
            fgets(input_buf, CHAR_ARRAY_SIZE, stdin);
            /* Convert to int */
            data = atoi(input_buf);
        }
    }
    {
        /* POTENTIAL FLAW: Convert data to a short, possibly causing a truncation error */
        short s = (short)data;
        printf("%hd\n", s);
    }
}

void CWE197_Numeric_Truncation_Error__int_fgets_to_short_05_good()
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
    CWE197_Numeric_Truncation_Error__int_fgets_to_short_05_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE197_Numeric_Truncation_Error__int_fgets_to_short_05_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
