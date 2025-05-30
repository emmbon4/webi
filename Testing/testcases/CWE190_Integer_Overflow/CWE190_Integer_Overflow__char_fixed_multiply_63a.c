/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__char_fixed_multiply_63a.c
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-63a.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: fixed Fixed value
 * GoodSource: Small, non-zero
 * Sinks: multiply
 *    GoodSink: Ensure there is no overflow before performing the multiplication
 *    BadSink : Multiply data by 2
 * Flow Variant: 63 Data flow: pointer to data passed from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

/* bad function declaration */
void CWE190_Integer_Overflow__char_fixed_multiply_63b_bad_sink(char * data_ptr);

void CWE190_Integer_Overflow__char_fixed_multiply_63_bad()
{
    char data;
    data = ' ';
    /* FLAW: Use the maximum size of the data type */
    data = CHAR_MAX;
    CWE190_Integer_Overflow__char_fixed_multiply_63b_bad_sink(&data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE190_Integer_Overflow__char_fixed_multiply_63b_goodG2B_sink(char * data);

static void goodG2B()
{
    char data;
    data = ' ';
    /* FIX: Use a small, non-zero value that will not cause an overflow in the sinks */
    data = 5;
    CWE190_Integer_Overflow__char_fixed_multiply_63b_goodG2B_sink(&data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE190_Integer_Overflow__char_fixed_multiply_63b_goodB2G_sink(char * data);

static void goodB2G()
{
    char data;
    data = ' ';
    /* FLAW: Use the maximum size of the data type */
    data = CHAR_MAX;
    CWE190_Integer_Overflow__char_fixed_multiply_63b_goodB2G_sink(&data);
}

void CWE190_Integer_Overflow__char_fixed_multiply_63_good()
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
    CWE190_Integer_Overflow__char_fixed_multiply_63_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE190_Integer_Overflow__char_fixed_multiply_63_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
