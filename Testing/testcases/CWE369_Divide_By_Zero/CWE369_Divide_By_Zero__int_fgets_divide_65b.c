/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE369_Divide_By_Zero__int_fgets_divide_65b.c
Label Definition File: CWE369_Divide_By_Zero__int.label.xml
Template File: sources-sink-65b.tmpl.c
*/
/*
 * @description
 * CWE: 369 Divide By Zero
 * BadSource: fgets Read data from the console using fgets()
 * GoodSource: Non-zero
 * Sinks: divide
 *    BadSink : Divide a constant by data
 * Flow Variant: 65 Data/control flow: data passed as an argument from one function to a function in a different source file called via a function pointer
 *
 * */

#include "std_testcase.h"

#define CHAR_ARRAY_SIZE sizeof(data)*sizeof(data)

#ifndef OMITBAD

void CWE369_Divide_By_Zero__int_fgets_divide_65b_bad_sink(int data)
{
    /* POTENTIAL FLAW: Possibly divide by zero */
    printIntLine(100 / data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE369_Divide_By_Zero__int_fgets_divide_65b_goodG2B_sink(int data)
{
    /* POTENTIAL FLAW: Possibly divide by zero */
    printIntLine(100 / data);
}

#endif /* OMITGOOD */
