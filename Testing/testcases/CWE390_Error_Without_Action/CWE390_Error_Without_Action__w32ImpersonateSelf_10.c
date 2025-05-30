/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE390_Error_Without_Action__w32ImpersonateSelf_10.c
Label Definition File: CWE390_Error_Without_Action.label.xml
Template File: point-flaw-10.tmpl.c
*/
/*
 * @description
 * CWE: 390 Detection of Error Condition Without Action
 * Sinks: w32ImpersonateSelf
 *    GoodSink: Check the return value of ImpersonateSelf() and handle errors properly
 *    BadSink : Check the return value of ImpersonateSelf(), but fail to handle errors
 * Flow Variant: 10 Control flow: if(global_t) and if(global_f)
 *
 * */

#include "std_testcase.h"

#include <windows.h>
# pragma comment(lib, "advapi32")

#ifndef OMITBAD

void CWE390_Error_Without_Action__w32ImpersonateSelf_10_bad()
{
    if(global_t)
    {
        {
            /* FLAW: Check the return value of ImpersonateSelf(), but do not handle errors */
            if (!ImpersonateSelf(SecurityImpersonation))
            {
                /* do nothing */
            }
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* FIX: Check the return value of ImpersonateSelf() and handle errors */
            if (!ImpersonateSelf(SecurityImpersonation))
            {
                exit(1);
            }
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() uses if(global_f) instead of if(global_t) */
static void good1()
{
    if(global_f)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* FLAW: Check the return value of ImpersonateSelf(), but do not handle errors */
            if (!ImpersonateSelf(SecurityImpersonation))
            {
                /* do nothing */
            }
        }
    }
    else
    {
        {
            /* FIX: Check the return value of ImpersonateSelf() and handle errors */
            if (!ImpersonateSelf(SecurityImpersonation))
            {
                exit(1);
            }
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(global_t)
    {
        {
            /* FIX: Check the return value of ImpersonateSelf() and handle errors */
            if (!ImpersonateSelf(SecurityImpersonation))
            {
                exit(1);
            }
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* FLAW: Check the return value of ImpersonateSelf(), but do not handle errors */
            if (!ImpersonateSelf(SecurityImpersonation))
            {
                /* do nothing */
            }
        }
    }
}

void CWE390_Error_Without_Action__w32ImpersonateSelf_10_good()
{
    good1();
    good2();
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
    CWE390_Error_Without_Action__w32ImpersonateSelf_10_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE390_Error_Without_Action__w32ImpersonateSelf_10_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
