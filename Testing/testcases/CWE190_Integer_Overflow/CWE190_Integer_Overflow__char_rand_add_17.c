/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__char_rand_add_17.c
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-17.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: rand Set data to result of rand()
 * GoodSource: Small, non-zero
 * Sinks: add
 *    GoodSink: Ensure there is no overflow before performing the addition
 *    BadSink : Add 1 to data
 * Flow Variant: 17 Control flow: for loops
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE190_Integer_Overflow__char_rand_add_17_bad()
{
    int h,i,j,k;
    char data;
    data = ' ';
    for(h = 0; h < 0; h++)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Use a small, non-zero value that will not cause an overflow in the sinks */
        data = 5;
    }
    for(i = 0; i < 1; i++)
    {
        /* POTENTIAL FLAW: Use a random value */
        data = (char)rand();
    }
    for(j = 0; j < 1; j++)
    {
        {
            /* POTENTIAL FLAW: Adding 1 to data could cause an overflow */
            char result = data + 1;
            printHexCharLine(result);
        }
    }
    for(k = 0; k < 0; k++)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            char result = -1;
            /* FIX: Add a check to prevent an overflow from occurring */
            if (data < CHAR_MAX)
            {
                result = data + 1;
                printHexCharLine(result);
            }
            else
            {
                printLine("Input value is too large to perform arithmetic safely.");
            }
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G() - use badsource and goodsink by changing the conditions on the third and fourth for statements */
static void goodB2G()
{
    int h,i,j,k;
    char data;
    data = ' ';
    for(h = 0; h < 0; h++)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Use a small, non-zero value that will not cause an overflow in the sinks */
        data = 5;
    }
    for(i = 0; i < 1; i++)
    {
        /* POTENTIAL FLAW: Use a random value */
        data = (char)rand();
    }
    for(j = 0; j < 0; j++)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* POTENTIAL FLAW: Adding 1 to data could cause an overflow */
            char result = data + 1;
            printHexCharLine(result);
        }
    }
    for(k = 0; k < 1; k++)
    {
        {
            char result = -1;
            /* FIX: Add a check to prevent an overflow from occurring */
            if (data < CHAR_MAX)
            {
                result = data + 1;
                printHexCharLine(result);
            }
            else
            {
                printLine("Input value is too large to perform arithmetic safely.");
            }
        }
    }
}

/* goodG2B() - use goodsource and badsink by changing the conditions on the first and second for statements */
static void goodG2B()
{
    int h,i,j,k;
    char data;
    data = ' ';
    for(h = 0; h < 1; h++)
    {
        /* FIX: Use a small, non-zero value that will not cause an overflow in the sinks */
        data = 5;
    }
    for(i = 0; i < 0; i++)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* POTENTIAL FLAW: Use a random value */
        data = (char)rand();
    }
    for(j = 0; j < 1; j++)
    {
        {
            /* POTENTIAL FLAW: Adding 1 to data could cause an overflow */
            char result = data + 1;
            printHexCharLine(result);
        }
    }
    for(k = 0; k < 0; k++)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            char result = -1;
            /* FIX: Add a check to prevent an overflow from occurring */
            if (data < CHAR_MAX)
            {
                result = data + 1;
                printHexCharLine(result);
            }
            else
            {
                printLine("Input value is too large to perform arithmetic safely.");
            }
        }
    }
}

void CWE190_Integer_Overflow__char_rand_add_17_good()
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
    CWE190_Integer_Overflow__char_rand_add_17_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE190_Integer_Overflow__char_rand_add_17_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
