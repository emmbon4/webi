/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE606_Unchecked_Loop_Condition__wchar_t_fromConsole_52b.c
Label Definition File: CWE606_Unchecked_Loop_Condition.label.xml
Template File: sources-sinks-52b.tmpl.c
*/
/*
 * @description
 * CWE: 606 Unchecked Input For Loop Condition
 * BadSource: fromConsole Read input from the console
 * GoodSource: Input a number less than MAX_LOOP
 * Sinks:
 *    GoodSink: Use data as the for loop variant after checking to see if it is less than MAX_LOOP
 *    BadSink : Use data as the for loop variant without checking its size
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"

#define MAX_LOOP 10000

#ifndef OMITBAD

/* bad function declaration */
void CWE606_Unchecked_Loop_Condition__wchar_t_fromConsole_52c_bad_sink(wchar_t * data);

void CWE606_Unchecked_Loop_Condition__wchar_t_fromConsole_52b_bad_sink(wchar_t * data)
{
    CWE606_Unchecked_Loop_Condition__wchar_t_fromConsole_52c_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE606_Unchecked_Loop_Condition__wchar_t_fromConsole_52c_goodG2B_sink(wchar_t * data);

void CWE606_Unchecked_Loop_Condition__wchar_t_fromConsole_52b_goodG2B_sink(wchar_t * data)
{
    CWE606_Unchecked_Loop_Condition__wchar_t_fromConsole_52c_goodG2B_sink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE606_Unchecked_Loop_Condition__wchar_t_fromConsole_52c_goodB2G_sink(wchar_t * data);

void CWE606_Unchecked_Loop_Condition__wchar_t_fromConsole_52b_goodB2G_sink(wchar_t * data)
{
    CWE606_Unchecked_Loop_Condition__wchar_t_fromConsole_52c_goodB2G_sink(data);
}

#endif /* OMITGOOD */
