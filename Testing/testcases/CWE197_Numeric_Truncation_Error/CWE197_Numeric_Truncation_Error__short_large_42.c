/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE197_Numeric_Truncation_Error__short_large_42.c
Label Definition File: CWE197_Numeric_Truncation_Error__short.label.xml
Template File: sources-sink-42.tmpl.c
*/
/*
 * @description
 * CWE: 197 Numeric Truncation Error
 * BadSource: large Set data to a number larger than CHAR_MAX
 * GoodSource: Less than CHAR_MAX
 * Sink:
 *    BadSink : Convert data to a char
 * Flow Variant: 42 Data flow: data returned from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

static short bad_source(short data)
{
    /* FLAW: Use a number larger than CHAR_MAX */
    data = CHAR_MAX + 1;
    return data;
}

void CWE197_Numeric_Truncation_Error__short_large_42_bad()
{
    short data;
    /* Initialize data */
    data = -1;
    data = bad_source(data);
    {
        /* POTENTIAL FLAW: Convert data to a char, possibly causing a truncation error */
        char c = (char)data;
        printHexCharLine(c);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

static short goodG2B_source(short data)
{
    /* FIX: Use a positive integer less than CHAR_MAX*/
    data = CHAR_MAX-5;
    return data;
}

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    short data;
    /* Initialize data */
    data = -1;
    data = goodG2B_source(data);
    {
        /* POTENTIAL FLAW: Convert data to a char, possibly causing a truncation error */
        char c = (char)data;
        printHexCharLine(c);
    }
}

void CWE197_Numeric_Truncation_Error__short_large_42_good()
{
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
    CWE197_Numeric_Truncation_Error__short_large_42_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE197_Numeric_Truncation_Error__short_large_42_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
