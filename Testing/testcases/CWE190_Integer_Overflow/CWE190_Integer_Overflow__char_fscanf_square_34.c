/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__char_fscanf_square_34.c
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-34.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Small, non-zero
 * Sinks: square
 *    GoodSink: Ensure there is no overflow before performing the squaring operation
 *    BadSink : Square data
 * Flow Variant: 34 Data flow: use of a union containing two methods of accessing the same data (within the same function)
 *
 * */

#include "std_testcase.h"

#include <math.h>

typedef union
{
    char a;
    char b;
} CWE190_Integer_Overflow__char_fscanf_square_34_union_type;

#ifndef OMITBAD

void CWE190_Integer_Overflow__char_fscanf_square_34_bad()
{
    char data;
    CWE190_Integer_Overflow__char_fscanf_square_34_union_type my_union;
    data = ' ';
    /* POTENTIAL FLAW: Use a value input from the console */
    fscanf (stdin, "%c", &data);
    my_union.a = data;
    {
        char data = my_union.b;
        {
            /* POTENTIAL FLAW: Squaring data could cause an overflow */
            char result = data * data;
            printHexCharLine(result);
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    char data;
    CWE190_Integer_Overflow__char_fscanf_square_34_union_type my_union;
    data = ' ';
    /* FIX: Use a small, non-zero value that will not cause an overflow in the sinks */
    data = 5;
    my_union.a = data;
    {
        char data = my_union.b;
        {
            /* POTENTIAL FLAW: Squaring data could cause an overflow */
            char result = data * data;
            printHexCharLine(result);
        }
    }
}

/* goodB2G() uses the BadSource with the GoodSink */
static void goodB2G()
{
    char data;
    CWE190_Integer_Overflow__char_fscanf_square_34_union_type my_union;
    data = ' ';
    /* POTENTIAL FLAW: Use a value input from the console */
    fscanf (stdin, "%c", &data);
    my_union.a = data;
    {
        char data = my_union.b;
        {
            char result = -1;
            /* FIX: Add a check to prevent an overflow from occurring */
            if (data <= (char)sqrt((char)CHAR_MAX))
            {
                result = data * data;
                printHexCharLine(result);
            }
            else
            {
                printLine("Input value is too large to perform arithmetic safely.");
            }
        }
    }
}

void CWE190_Integer_Overflow__char_fscanf_square_34_good()
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
    CWE190_Integer_Overflow__char_fscanf_square_34_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE190_Integer_Overflow__char_fscanf_square_34_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
