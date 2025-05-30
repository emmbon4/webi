/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__unsigned_char_fscanf_square_08.c
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-08.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Small, non-zero
 * Sinks: square
 *    GoodSink: Ensure there is no overflow before performing the squaring operation
 *    BadSink : Square data
 * Flow Variant: 08 Control flow: if(static_returns_t()) and if(static_returns_f())
 *
 * */

#include "std_testcase.h"

#include <math.h>

/* The two function below always return the same value, so a tool
   should be able to identify that calls to the functions will always
   return a fixed value. */
static int static_returns_t()
{
    return 1;
}

static int static_returns_f()
{
    return 0;
}

#ifndef OMITBAD

void CWE190_Integer_Overflow__unsigned_char_fscanf_square_08_bad()
{
    unsigned char data;
    data = ' ';
    if(static_returns_t())
    {
        /* POTENTIAL FLAW: Use a value input from the console */
        fscanf (stdin, "%hc", &data);
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Use a small, non-zero value that will not cause an overflow in the sinks */
        data = 5;
    }
    if(static_returns_t())
    {
        {
            /* POTENTIAL FLAW: Squaring data could cause an overflow */
            unsigned char result = data * data;
            printHexUnsignedCharLine(result);
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            unsigned char result = -1;
            /* FIX: Add a check to prevent an overflow from occurring */
            if (data <= (unsigned char)sqrt((unsigned char)UCHAR_MAX))
            {
                result = data * data;
                printHexUnsignedCharLine(result);
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

/* goodB2G1() - use badsource and goodsink by changing the second static_returns_t() to static_returns_f() */
static void goodB2G1()
{
    unsigned char data;
    data = ' ';
    if(static_returns_t())
    {
        /* POTENTIAL FLAW: Use a value input from the console */
        fscanf (stdin, "%hc", &data);
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Use a small, non-zero value that will not cause an overflow in the sinks */
        data = 5;
    }
    if(static_returns_f())
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* POTENTIAL FLAW: Squaring data could cause an overflow */
            unsigned char result = data * data;
            printHexUnsignedCharLine(result);
        }
    }
    else
    {
        {
            unsigned char result = -1;
            /* FIX: Add a check to prevent an overflow from occurring */
            if (data <= (unsigned char)sqrt((unsigned char)UCHAR_MAX))
            {
                result = data * data;
                printHexUnsignedCharLine(result);
            }
            else
            {
                printLine("Input value is too large to perform arithmetic safely.");
            }
        }
    }
}

/* goodB2G2() - use badsource and goodsink by reversing the blocks in the second if */
static void goodB2G2()
{
    unsigned char data;
    data = ' ';
    if(static_returns_t())
    {
        /* POTENTIAL FLAW: Use a value input from the console */
        fscanf (stdin, "%hc", &data);
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Use a small, non-zero value that will not cause an overflow in the sinks */
        data = 5;
    }
    if(static_returns_t())
    {
        {
            unsigned char result = -1;
            /* FIX: Add a check to prevent an overflow from occurring */
            if (data <= (unsigned char)sqrt((unsigned char)UCHAR_MAX))
            {
                result = data * data;
                printHexUnsignedCharLine(result);
            }
            else
            {
                printLine("Input value is too large to perform arithmetic safely.");
            }
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* POTENTIAL FLAW: Squaring data could cause an overflow */
            unsigned char result = data * data;
            printHexUnsignedCharLine(result);
        }
    }
}

/* goodG2B1() - use goodsource and badsink by changing the first static_returns_t() to static_returns_f() */
static void goodG2B1()
{
    unsigned char data;
    data = ' ';
    if(static_returns_f())
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* POTENTIAL FLAW: Use a value input from the console */
        fscanf (stdin, "%hc", &data);
    }
    else
    {
        /* FIX: Use a small, non-zero value that will not cause an overflow in the sinks */
        data = 5;
    }
    if(static_returns_t())
    {
        {
            /* POTENTIAL FLAW: Squaring data could cause an overflow */
            unsigned char result = data * data;
            printHexUnsignedCharLine(result);
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            unsigned char result = -1;
            /* FIX: Add a check to prevent an overflow from occurring */
            if (data <= (unsigned char)sqrt((unsigned char)UCHAR_MAX))
            {
                result = data * data;
                printHexUnsignedCharLine(result);
            }
            else
            {
                printLine("Input value is too large to perform arithmetic safely.");
            }
        }
    }
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the first if */
static void goodG2B2()
{
    unsigned char data;
    data = ' ';
    if(static_returns_t())
    {
        /* FIX: Use a small, non-zero value that will not cause an overflow in the sinks */
        data = 5;
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* POTENTIAL FLAW: Use a value input from the console */
        fscanf (stdin, "%hc", &data);
    }
    if(static_returns_t())
    {
        {
            /* POTENTIAL FLAW: Squaring data could cause an overflow */
            unsigned char result = data * data;
            printHexUnsignedCharLine(result);
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            unsigned char result = -1;
            /* FIX: Add a check to prevent an overflow from occurring */
            if (data <= (unsigned char)sqrt((unsigned char)UCHAR_MAX))
            {
                result = data * data;
                printHexUnsignedCharLine(result);
            }
            else
            {
                printLine("Input value is too large to perform arithmetic safely.");
            }
        }
    }
}

void CWE190_Integer_Overflow__unsigned_char_fscanf_square_08_good()
{
    goodB2G1();
    goodB2G2();
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
    CWE190_Integer_Overflow__unsigned_char_fscanf_square_08_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE190_Integer_Overflow__unsigned_char_fscanf_square_08_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
