/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE606_Unchecked_Loop_Condition__wchar_t_Environment_68b.c
Label Definition File: CWE606_Unchecked_Loop_Condition.label.xml
Template File: sources-sinks-68b.tmpl.c
*/
/*
 * @description
 * CWE: 606 Unchecked Input For Loop Condition
 * BadSource: Environment Read input from an environment variable
 * GoodSource: Input a number less than MAX_LOOP
 * Sinks:
 *    GoodSink: Use data as the for loop variant after checking to see if it is less than MAX_LOOP
 *    BadSink : Use data as the for loop variant without checking its size
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#define MAX_LOOP 10000

#define ENV_VARIABLE L"ADD"

#ifdef _WIN32
# define GETENV _wgetenv
#else
# define GETENV wgetenv
#endif

extern wchar_t * CWE606_Unchecked_Loop_Condition__wchar_t_Environment_68_bad_data;
extern wchar_t * CWE606_Unchecked_Loop_Condition__wchar_t_Environment_68_goodG2B_data;
extern wchar_t * CWE606_Unchecked_Loop_Condition__wchar_t_Environment_68_goodB2G_data;

#ifndef OMITBAD

void CWE606_Unchecked_Loop_Condition__wchar_t_Environment_68b_bad_sink()
{
    wchar_t * data = CWE606_Unchecked_Loop_Condition__wchar_t_Environment_68_bad_data;
    {
        int i, n, v;
        if (swscanf(data, L"%d", &n) == 1)
        {
            /* POTENTIAL FLAW: user-supplied value 'n' could lead to very large loop iteration */
            v = 0;
            for (i = 0; i < n; i++)
            {
                /* INCIDENTAL: CWE 561: Dead Code - non-avoidable if n <= 0 */
                v++; /* avoid a dead/empty code block issue */
            }
            printIntLine(v);
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE606_Unchecked_Loop_Condition__wchar_t_Environment_68b_goodG2B_sink()
{
    wchar_t * data = CWE606_Unchecked_Loop_Condition__wchar_t_Environment_68_goodG2B_data;
    {
        int i, n, v;
        if (swscanf(data, L"%d", &n) == 1)
        {
            /* POTENTIAL FLAW: user-supplied value 'n' could lead to very large loop iteration */
            v = 0;
            for (i = 0; i < n; i++)
            {
                /* INCIDENTAL: CWE 561: Dead Code - non-avoidable if n <= 0 */
                v++; /* avoid a dead/empty code block issue */
            }
            printIntLine(v);
        }
    }
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE606_Unchecked_Loop_Condition__wchar_t_Environment_68b_goodB2G_sink()
{
    wchar_t * data = CWE606_Unchecked_Loop_Condition__wchar_t_Environment_68_goodB2G_data;
    {
        int i, n, v;
        if (swscanf(data, L"%d", &n) == 1)
        {
            /* FIX: limit loop iteration counts */
            if (n < MAX_LOOP)
            {
                v = 0;
                for (i = 0; i < n; i++)
                {
                    /* INCIDENTAL: CWE 561: Dead Code - non-avoidable if n <= 0 */
                    v++; /* avoid a dead/empty code block issue */
                }
                printIntLine(v);
            }
        }
    }
}

#endif /* OMITGOOD */
