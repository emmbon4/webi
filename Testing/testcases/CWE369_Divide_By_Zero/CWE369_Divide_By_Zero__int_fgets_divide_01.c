/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE369_Divide_By_Zero__int_fgets_divide_01.c
Label Definition File: CWE369_Divide_By_Zero__int.label.xml
Template File: sources-sink-01.tmpl.c
*/
/*
 * @description
 * CWE: 369 Divide By Zero
 * BadSource: fgets Read data from the console using fgets()
 * GoodSource: Non-zero
 * Sink: divide
 *    BadSink : Divide a constant by data
 * Flow Variant: 01 Baseline
 *
 * */

#include "std_testcase.h"

#define CHAR_ARRAY_SIZE sizeof(data)*sizeof(data)

#ifndef OMITBAD

void CWE369_Divide_By_Zero__int_fgets_divide_01_bad()
{
    int data;
    /* Initialize data */
    data = -1;
    {
        char input_buf[CHAR_ARRAY_SIZE] = "";
        fgets(input_buf, CHAR_ARRAY_SIZE, stdin);
        /* Convert to int */
        data = atoi(input_buf);
    }
    /* POTENTIAL FLAW: Possibly divide by zero */
    printIntLine(100 / data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    int data;
    /* Initialize data */
    data = -1;
    /* FIX: Use a value not equal to zero */
    data = 7;
    /* POTENTIAL FLAW: Possibly divide by zero */
    printIntLine(100 / data);
}

void CWE369_Divide_By_Zero__int_fgets_divide_01_good()
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
    CWE369_Divide_By_Zero__int_fgets_divide_01_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE369_Divide_By_Zero__int_fgets_divide_01_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
