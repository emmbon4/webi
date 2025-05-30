/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE253_Incorrect_Check_of_Return_Value__w32ImpersonateSelf_04.c
Label Definition File: CWE253_Incorrect_Check_of_Return_Value.label.xml
Template File: point-flaw-04.tmpl.c
*/
/*
 * @description
 * CWE: 253 Incorrect Check of Return Value
 * Sinks: w32ImpersonateSelf
 *    GoodSink: Correctly check if ImpersonateSelf() fails
 *    BadSink : Incorrectly check if ImpersonateSelf() fails
 * Flow Variant: 04 Control flow: if(static_const_t) and if(static_const_f)
 *
 * */

#include "std_testcase.h"

#include <windows.h>
# pragma comment(lib, "advapi32")

/* The two variables below are declared "const", so a tool should
   be able to identify that reads of these will always return their
   initialized values. */
static const int static_const_t = 1; /* true */
static const int static_const_f = 0; /* false */

#ifndef OMITBAD

void CWE253_Incorrect_Check_of_Return_Value__w32ImpersonateSelf_04_bad()
{
    if(static_const_t)
    {
        {
            /* FLAW: ImpersonateSelf() could fail and would return 0 (false), but we are checking to see
            if the return value is greater than zero (true) */
            if (ImpersonateSelf(SecurityImpersonation) > 0)
            {
                exit(1);
            }
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* FIX: check for the correct return value */
            if (!ImpersonateSelf(SecurityImpersonation))
            {
                exit(1);
            }
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() uses if(static_const_f) instead of if(static_const_t) */
static void good1()
{
    if(static_const_f)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* FLAW: ImpersonateSelf() could fail and would return 0 (false), but we are checking to see
            if the return value is greater than zero (true) */
            if (ImpersonateSelf(SecurityImpersonation) > 0)
            {
                exit(1);
            }
        }
    }
    else
    {
        {
            /* FIX: check for the correct return value */
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
    if(static_const_t)
    {
        {
            /* FIX: check for the correct return value */
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
            /* FLAW: ImpersonateSelf() could fail and would return 0 (false), but we are checking to see
            if the return value is greater than zero (true) */
            if (ImpersonateSelf(SecurityImpersonation) > 0)
            {
                exit(1);
            }
        }
    }
}

void CWE253_Incorrect_Check_of_Return_Value__w32ImpersonateSelf_04_good()
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
    CWE253_Incorrect_Check_of_Return_Value__w32ImpersonateSelf_04_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE253_Incorrect_Check_of_Return_Value__w32ImpersonateSelf_04_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
