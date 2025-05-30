/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE400_Resource_Exhaustion__fgets_for_loop_52b.c
Label Definition File: CWE400_Resource_Exhaustion.label.xml
Template File: sources-sinks-52b.tmpl.c
*/
/*
 * @description
 * CWE: 400 Resource Exhaustion
 * BadSource: fgets Read data from the console using fgets()
 * GoodSource: Assign count to be a relatively small number
 * Sinks: for_loop
 *    GoodSink: Validate count before using it as the loop variant in a for loop
 *    BadSink : Use count as the loop variant in a for loop
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"

#define CHAR_ARRAY_SIZE sizeof(count)*sizeof(count)

#ifndef OMITBAD

/* bad function declaration */
void CWE400_Resource_Exhaustion__fgets_for_loop_52c_bad_sink(int count);

void CWE400_Resource_Exhaustion__fgets_for_loop_52b_bad_sink(int count)
{
    CWE400_Resource_Exhaustion__fgets_for_loop_52c_bad_sink(count);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE400_Resource_Exhaustion__fgets_for_loop_52c_goodG2B_sink(int count);

void CWE400_Resource_Exhaustion__fgets_for_loop_52b_goodG2B_sink(int count)
{
    CWE400_Resource_Exhaustion__fgets_for_loop_52c_goodG2B_sink(count);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE400_Resource_Exhaustion__fgets_for_loop_52c_goodB2G_sink(int count);

void CWE400_Resource_Exhaustion__fgets_for_loop_52b_goodB2G_sink(int count)
{
    CWE400_Resource_Exhaustion__fgets_for_loop_52c_goodB2G_sink(count);
}

#endif /* OMITGOOD */
