/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE560_Use_Of_umask_With_chmod_Style_Argument__basic_02.c
Label Definition File: CWE560_Use_Of_umask_With_chmod_Style_Argument__basic.label.xml
Template File: point-flaw-02.tmpl.c
*/
/*
 * @description
 * CWE: 560 Use Of umask With chmod Style Argument
 * Sinks:
 *    GoodSink: Use umask() correctly
 *    BadSink : Use umask() incorrectly - the bits sent to umask() are bitwise-negated
 * Flow Variant: 02 Control flow: if(1) and if(0)
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
# define UMASK _umask
#else
# define UMASK umask
#endif

#ifndef OMITBAD

void CWE560_Use_Of_umask_With_chmod_Style_Argument__basic_02_bad()
{
    if(1)
    {
        /* FLAW: The umask is a value that is bitwise-negated and then applied
         * to file permissions.  So if you want to allow bits 0644 through,
         * you actually need to negate that, to be 0133 (or 022 in the case that
         * you don't mind execute bits i.e. 0755 through)
         */
        UMASK(0644);
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Use the appropriate umask */
        UMASK(022);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() uses if(0) instead of if(1) */
static void good1()
{
    if(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FLAW: The umask is a value that is bitwise-negated and then applied
         * to file permissions.  So if you want to allow bits 0644 through,
         * you actually need to negate that, to be 0133 (or 022 in the case that
         * you don't mind execute bits i.e. 0755 through)
         */
        UMASK(0644);
    }
    else
    {
        /* FIX: Use the appropriate umask */
        UMASK(022);
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(1)
    {
        /* FIX: Use the appropriate umask */
        UMASK(022);
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FLAW: The umask is a value that is bitwise-negated and then applied
         * to file permissions.  So if you want to allow bits 0644 through,
         * you actually need to negate that, to be 0133 (or 022 in the case that
         * you don't mind execute bits i.e. 0755 through)
         */
        UMASK(0644);
    }
}

void CWE560_Use_Of_umask_With_chmod_Style_Argument__basic_02_good()
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
    CWE560_Use_Of_umask_With_chmod_Style_Argument__basic_02_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE560_Use_Of_umask_With_chmod_Style_Argument__basic_02_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
