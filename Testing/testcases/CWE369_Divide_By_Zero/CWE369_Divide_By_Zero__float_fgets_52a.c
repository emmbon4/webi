/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE369_Divide_By_Zero__float_fgets_52a.c
Label Definition File: CWE369_Divide_By_Zero__float.label.xml
Template File: sources-sink-52a.tmpl.c
*/
/*
 * @description
 * CWE: 369 Divide By Zero
 * BadSource: fgets Read data from the console using fgets()
 * GoodSource: Non-zero
 * Sink:
 *    BadSink : Divide a constant by data
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"

#define CHAR_ARRAY_SIZE sizeof(data)*sizeof(data)

#ifndef OMITBAD

/* bad function declaration */
void CWE369_Divide_By_Zero__float_fgets_52b_bad_sink(float data);

void CWE369_Divide_By_Zero__float_fgets_52_bad()
{
    float data;
    /* Initialize data */
    data = 0.0F;
    {
        char input_buf[CHAR_ARRAY_SIZE];
        /* POTENTIAL FLAW: Use a value input from the console using fgets() */
        fgets(input_buf, CHAR_ARRAY_SIZE, stdin);
        /* Convert to float */
        data = (float)atof(input_buf);
    }
    CWE369_Divide_By_Zero__float_fgets_52b_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declaration */
void CWE369_Divide_By_Zero__float_fgets_52b_goodG2B_sink(float data);

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    float data;
    /* Initialize data */
    data = 0.0F;
    /* FIX: Use a value not equal to zero */
    data = 7.0F;
    CWE369_Divide_By_Zero__float_fgets_52b_goodG2B_sink(data);
}

void CWE369_Divide_By_Zero__float_fgets_52_good()
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
    CWE369_Divide_By_Zero__float_fgets_52_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE369_Divide_By_Zero__float_fgets_52_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
