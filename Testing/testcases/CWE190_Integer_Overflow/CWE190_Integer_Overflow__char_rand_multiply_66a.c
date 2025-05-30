/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__char_rand_multiply_66a.c
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-66a.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: rand Set data to result of rand()
 * GoodSource: Small, non-zero
 * Sinks: multiply
 *    GoodSink: Ensure there is no overflow before performing the multiplication
 *    BadSink : Multiply data by 2
 * Flow Variant: 66 Data flow: data passed in an array from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

/* bad function declaration */
void CWE190_Integer_Overflow__char_rand_multiply_66b_bad_sink(char data_array[]);

void CWE190_Integer_Overflow__char_rand_multiply_66_bad()
{
    char data;
    char data_array[5];
    data = ' ';
    /* POTENTIAL FLAW: Use a random value */
    data = (char)rand();
    /* put data in array */
    data_array[2] = data;
    CWE190_Integer_Overflow__char_rand_multiply_66b_bad_sink(data_array);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE190_Integer_Overflow__char_rand_multiply_66b_goodG2B_sink(char data_array[]);

static void goodG2B()
{
    char data;
    char data_array[5];
    data = ' ';
    /* FIX: Use a small, non-zero value that will not cause an overflow in the sinks */
    data = 5;
    data_array[2] = data;
    CWE190_Integer_Overflow__char_rand_multiply_66b_goodG2B_sink(data_array);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE190_Integer_Overflow__char_rand_multiply_66b_goodB2G_sink(char data_array[]);

static void goodB2G()
{
    char data;
    char data_array[5];
    data = ' ';
    /* POTENTIAL FLAW: Use a random value */
    data = (char)rand();
    data_array[2] = data;
    CWE190_Integer_Overflow__char_rand_multiply_66b_goodB2G_sink(data_array);
}

void CWE190_Integer_Overflow__char_rand_multiply_66_good()
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
    CWE190_Integer_Overflow__char_rand_multiply_66_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE190_Integer_Overflow__char_rand_multiply_66_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
