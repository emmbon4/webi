/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE197_Numeric_Truncation_Error__int_fgets_to_char_65a.c
Label Definition File: CWE197_Numeric_Truncation_Error__int.label.xml
Template File: sources-sink-65a.tmpl.c
*/
/*
 * @description
 * CWE: 197 Numeric Truncation Error
 * BadSource: fgets Read data from the console using fgets()
 * GoodSource: Less than CHAR_MAX
 * Sinks: to_char
 *    BadSink : Convert data to a char
 * Flow Variant: 65 Data/control flow: data passed as an argument from one function to a function in a different source file called via a function pointer
 *
 * */

#include "std_testcase.h"

#define CHAR_ARRAY_SIZE sizeof(data)*sizeof(data)

#ifndef OMITBAD

/* bad function declaration */
void CWE197_Numeric_Truncation_Error__int_fgets_to_char_65b_bad_sink(int data);

void CWE197_Numeric_Truncation_Error__int_fgets_to_char_65_bad()
{
    int data;
    /* define a function pointer */
    void (*func_ptr) (int) = CWE197_Numeric_Truncation_Error__int_fgets_to_char_65b_bad_sink;
    /* Initialize data */
    data = -1;
    {
        char input_buf[CHAR_ARRAY_SIZE] = "";
        fgets(input_buf, CHAR_ARRAY_SIZE, stdin);
        /* Convert to int */
        data = atoi(input_buf);
    }
    /* use the function pointer */
    func_ptr(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE197_Numeric_Truncation_Error__int_fgets_to_char_65b_goodG2B_sink(int data);

static void goodG2B()
{
    int data;
    void (*func_ptr) (int) = CWE197_Numeric_Truncation_Error__int_fgets_to_char_65b_goodG2B_sink;
    /* Initialize data */
    data = -1;
    /* FIX: Use a positive integer less than CHAR_MAX*/
    data = CHAR_MAX-5;
    func_ptr(data);
}

void CWE197_Numeric_Truncation_Error__int_fgets_to_char_65_good()
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
    CWE197_Numeric_Truncation_Error__int_fgets_to_char_65_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE197_Numeric_Truncation_Error__int_fgets_to_char_65_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
