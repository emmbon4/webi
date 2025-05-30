/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE390_Error_Without_Action__sqrt_19.c
Label Definition File: CWE390_Error_Without_Action.label.xml
Template File: point-flaw-19.tmpl.c
*/
/*
 * @description
 * CWE: 390 Detection of Error Condition Without Action
 * Sinks: sqrt
 *    GoodSink: Check to see if sqrt() failed and handle errors properly
 *    BadSink : Check to see if sqrt() failed, but fail to handle errors
 * Flow Variant: 19 Control flow: Dead code after a return
 *
 * */

#include "std_testcase.h"

#include <math.h>
#include <errno.h>

#ifndef OMITBAD

void CWE390_Error_Without_Action__sqrt_19_bad()
{
    {
        errno_t err_code = -1;
        double d = (double)sqrt((double)-1);
        if (_get_errno(&err_code))
        {
            printLine("_get_errno failed");
            exit(1);
        }
        /* FLAW: Check errno to see if sqrt() failed, but do nothing about it */
        if (err_code == EDOM)
        {
            /* do nothing */
        }
        printDoubleLine(d);
    }
    return;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        errno_t err_code = -1;
        double d = (double)sqrt((double)-1);
        if (_get_errno(&err_code))
        {
            printLine("_get_errno failed");
            exit(1);
        }
        /* FIX: Check errno to see if sqrt() failed and handle errors properly */
        if (err_code == EDOM)
        {
            printLine("sqrt() failed");
            exit(1);
        }
        printDoubleLine(d);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() reverses the GoodSinkBody and the BadSinkBody so that the BadSinkBody never runs */
static void good1()
{
    {
        errno_t err_code = -1;
        double d = (double)sqrt((double)-1);
        if (_get_errno(&err_code))
        {
            printLine("_get_errno failed");
            exit(1);
        }
        /* FIX: Check errno to see if sqrt() failed and handle errors properly */
        if (err_code == EDOM)
        {
            printLine("sqrt() failed");
            exit(1);
        }
        printDoubleLine(d);
    }
    return;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        errno_t err_code = -1;
        double d = (double)sqrt((double)-1);
        if (_get_errno(&err_code))
        {
            printLine("_get_errno failed");
            exit(1);
        }
        /* FLAW: Check errno to see if sqrt() failed, but do nothing about it */
        if (err_code == EDOM)
        {
            /* do nothing */
        }
        printDoubleLine(d);
    }
}

void CWE390_Error_Without_Action__sqrt_19_good()
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
    CWE390_Error_Without_Action__sqrt_19_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE390_Error_Without_Action__sqrt_19_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
