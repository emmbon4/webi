/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE253_Incorrect_Check_of_Return_Value__w32ImpersonateSelf_13.c
Label Definition File: CWE253_Incorrect_Check_of_Return_Value.label.xml
Template File: point-flaw-13.tmpl.c
*/
/*
 * @description
 * CWE: 253 Incorrect Check of Return Value
 * Sinks: w32ImpersonateSelf
 *    GoodSink: Correctly check if ImpersonateSelf() fails
 *    BadSink : Incorrectly check if ImpersonateSelf() fails
 * Flow Variant: 13 Control flow: if(global_const_five==5) and if(global_const_five!=5)
 *
 * */

#include "std_testcase.h"

#include <windows.h>
# pragma comment(lib, "advapi32")

#ifndef OMITBAD

void CWE253_Incorrect_Check_of_Return_Value__w32ImpersonateSelf_13_bad()
{
    if(global_const_five==5)
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

/* good1() uses if(global_const_five!=5) instead of if(global_const_five==5) */
static void good1()
{
    if(global_const_five!=5)
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
    if(global_const_five==5)
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

void CWE253_Incorrect_Check_of_Return_Value__w32ImpersonateSelf_13_good()
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
    CWE253_Incorrect_Check_of_Return_Value__w32ImpersonateSelf_13_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE253_Incorrect_Check_of_Return_Value__w32ImpersonateSelf_13_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
