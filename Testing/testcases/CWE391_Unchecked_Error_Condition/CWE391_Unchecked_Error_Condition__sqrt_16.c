/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE391_Unchecked_Error_Condition__sqrt_16.c
Label Definition File: CWE391_Unchecked_Error_Condition.label.xml
Template File: point-flaw-16.tmpl.c
*/
/*
 * @description
 * CWE: 391 Unchecked Error Condition
 * Sinks: sqrt
 *    GoodSink: Perform error checks and handling
 *    BadSink : Do not check if sqrt() failed
 * Flow Variant: 16 Control flow: while(1) and while(0)
 *
 * */

#include "std_testcase.h"

#include <errno.h>

#include <math.h>

#ifndef OMITBAD

void CWE391_Unchecked_Error_Condition__sqrt_16_bad()
{
    while(1)
    {
        {
            double d = (double)sqrt((double)-1);
            /* FLAW: Do not check to see if sqrt() failed */
            printDoubleLine(d);
        }
        break;
    }
    while(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            errno_t err_code = -1;
            double d = (double)sqrt((double)-1);
            if (_get_errno(&err_code))
            {
                printLine("_get_errno failed");
                exit(1);
            }
            /* FIX: Check errno to see if sqrt() failed */
            if (err_code == EDOM)
            {
                printLine("sqrt() failed");
                exit(1);
            }
            printDoubleLine(d);
        }
        break;
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() changes the conditions on the while statements */
static void good1()
{
    while(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            double d = (double)sqrt((double)-1);
            /* FLAW: Do not check to see if sqrt() failed */
            printDoubleLine(d);
        }
        break;
    }
    while(1)
    {
        {
            errno_t err_code = -1;
            double d = (double)sqrt((double)-1);
            if (_get_errno(&err_code))
            {
                printLine("_get_errno failed");
                exit(1);
            }
            /* FIX: Check errno to see if sqrt() failed */
            if (err_code == EDOM)
            {
                printLine("sqrt() failed");
                exit(1);
            }
            printDoubleLine(d);
        }
        break;
    }
}

void CWE391_Unchecked_Error_Condition__sqrt_16_good()
{
    good1();
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
    CWE391_Unchecked_Error_Condition__sqrt_16_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE391_Unchecked_Error_Condition__sqrt_16_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
