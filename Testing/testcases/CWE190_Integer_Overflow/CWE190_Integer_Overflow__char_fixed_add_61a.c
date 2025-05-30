/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__char_fixed_add_61a.c
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-61a.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: fixed Fixed value
 * GoodSource: Small, non-zero
 * Sinks: add
 *    GoodSink: Ensure there is no overflow before performing the addition
 *    BadSink : Add 1 to data
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

/* bad function declaration */
char CWE190_Integer_Overflow__char_fixed_add_61b_bad_source(char data);

void CWE190_Integer_Overflow__char_fixed_add_61_bad()
{
    char data;
    data = ' ';
    data = CWE190_Integer_Overflow__char_fixed_add_61b_bad_source(data);
    {
        /* POTENTIAL FLAW: Adding 1 to data could cause an overflow */
        char result = data + 1;
        printHexCharLine(result);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
char CWE190_Integer_Overflow__char_fixed_add_61b_goodG2B_source(char data);

static void goodG2B()
{
    char data;
    data = ' ';
    data = CWE190_Integer_Overflow__char_fixed_add_61b_goodG2B_source(data);
    {
        /* POTENTIAL FLAW: Adding 1 to data could cause an overflow */
        char result = data + 1;
        printHexCharLine(result);
    }
}

/* goodB2G uses the BadSource with the GoodSink */
char CWE190_Integer_Overflow__char_fixed_add_61b_goodB2G_source(char data);

static void goodB2G()
{
    char data;
    data = ' ';
    data = CWE190_Integer_Overflow__char_fixed_add_61b_goodB2G_source(data);
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

void CWE190_Integer_Overflow__char_fixed_add_61_good()
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
    CWE190_Integer_Overflow__char_fixed_add_61_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE190_Integer_Overflow__char_fixed_add_61_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
