/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__unsigned_int_fscanf_42.c
Label Definition File: CWE191_Integer_Underflow.label.xml
Template File: sources-sinks-42.tmpl.c
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Small, non-zero
 * Sinks:
 *    GoodSink: Ensure there is no underflow before performing the subtraction
 *    BadSink : Subtract 1 from data
 * Flow Variant: 42 Data flow: data returned from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

static unsigned int bad_source(unsigned int data)
{
    /* POTENTIAL FLAW: Use a value input from the console */
    fscanf (stdin, "%u", &data);
    return data;
}

void CWE191_Integer_Underflow__unsigned_int_fscanf_42_bad()
{
    unsigned int data;
    data = 0;
    data = bad_source(data);
    {
        /* POTENTIAL FLAW: Subtracting 1 from data could cause an integer underflow */
        unsigned int result = data - 1;
        printUnsignedLine(result);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
static unsigned int goodG2B_source(unsigned int data)
{
    /* FIX: Use a small value greater than the min value for this data type */
    data = 5;
    return data;
}

static void goodG2B()
{
    unsigned int data;
    data = 0;
    data = goodG2B_source(data);
    {
        /* POTENTIAL FLAW: Subtracting 1 from data could cause an integer underflow */
        unsigned int result = data - 1;
        printUnsignedLine(result);
    }
}

/* goodB2G uses the BadSource with the GoodSink */
static unsigned int goodB2G_source(unsigned int data)
{
    /* POTENTIAL FLAW: Use a value input from the console */
    fscanf (stdin, "%u", &data);
    return data;
}

static void goodB2G()
{
    unsigned int data;
    data = 0;
    data = goodB2G_source(data);
    {
        unsigned int result = 0;
        /* FIX: Add a check to prevent an underflow from occurring */
        if (data > 0)
        {
            result = data - 1;
            printUnsignedLine(result);
        }
        else
        {
            printLine("Input value is too small to perform arithmetic safely.");
        }
    }
}

void CWE191_Integer_Underflow__unsigned_int_fscanf_42_good()
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
    CWE191_Integer_Underflow__unsigned_int_fscanf_42_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE191_Integer_Underflow__unsigned_int_fscanf_42_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
