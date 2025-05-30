/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__unsigned_int_fixed_multiply_68a.c
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-68a.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: fixed Fixed value
 * GoodSource: Small, non-zero
 * Sinks: multiply
 *    GoodSink: Ensure there is no overflow before performing the multiplication
 *    BadSink : Multiply data by 2
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

unsigned int CWE190_Integer_Overflow__unsigned_int_fixed_multiply_68_bad_data;
unsigned int CWE190_Integer_Overflow__unsigned_int_fixed_multiply_68_goodG2B_data;
unsigned int CWE190_Integer_Overflow__unsigned_int_fixed_multiply_68_goodB2G_data;

#ifndef OMITBAD

/* bad function declaration */
void CWE190_Integer_Overflow__unsigned_int_fixed_multiply_68b_bad_sink();

void CWE190_Integer_Overflow__unsigned_int_fixed_multiply_68_bad()
{
    unsigned int data;
    data = 0;
    /* FLAW: Use the maximum size of the data type */
    data = UINT_MAX;
    CWE190_Integer_Overflow__unsigned_int_fixed_multiply_68_bad_data = data;
    CWE190_Integer_Overflow__unsigned_int_fixed_multiply_68b_bad_sink();
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declarations */
void CWE190_Integer_Overflow__unsigned_int_fixed_multiply_68b_goodG2B_sink();
void CWE190_Integer_Overflow__unsigned_int_fixed_multiply_68b_goodB2G_sink();

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    unsigned int data;
    data = 0;
    /* FIX: Use a small, non-zero value that will not cause an overflow in the sinks */
    data = 5;
    CWE190_Integer_Overflow__unsigned_int_fixed_multiply_68_goodG2B_data = data;
    CWE190_Integer_Overflow__unsigned_int_fixed_multiply_68b_goodG2B_sink();
}

/* goodB2G uses the BadSource with the GoodSink */
static void goodB2G()
{
    unsigned int data;
    data = 0;
    /* FLAW: Use the maximum size of the data type */
    data = UINT_MAX;
    CWE190_Integer_Overflow__unsigned_int_fixed_multiply_68_goodB2G_data = data;
    CWE190_Integer_Overflow__unsigned_int_fixed_multiply_68b_goodB2G_sink();
}

void CWE190_Integer_Overflow__unsigned_int_fixed_multiply_68_good()
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
    CWE190_Integer_Overflow__unsigned_int_fixed_multiply_68_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE190_Integer_Overflow__unsigned_int_fixed_multiply_68_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
