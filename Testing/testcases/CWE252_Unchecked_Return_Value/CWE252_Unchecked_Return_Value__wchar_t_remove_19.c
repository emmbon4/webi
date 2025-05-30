/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE252_Unchecked_Return_Value__wchar_t_remove_19.c
Label Definition File: CWE252_Unchecked_Return_Value.string.label.xml
Template File: point-flaw-19.tmpl.c
*/
/*
 * @description
 * CWE: 252 Unchecked Return Value
 * Sinks: remove
 *    GoodSink: Check if wremove() fails
 *    BadSink : Do not check if wremove() fails
 * Flow Variant: 19 Control flow: Dead code after a return
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
# define REMOVE _wremove
#else
# define REMOVE wremove
#endif

#ifndef OMITBAD

void CWE252_Unchecked_Return_Value__wchar_t_remove_19_bad()
{
    {
        /* FLAW: Do not check the return value */
        REMOVE(L"removemebad.txt");
    }
    return;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        /* FIX: check the return value */
        if (REMOVE(L"removemebad.txt") != 0)
        {
            printLine("wremove failed!");
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() reverses the GoodSinkBody and the BadSinkBody so that the BadSinkBody never runs */
static void good1()
{
    {
        /* FIX: check the return value */
        if (REMOVE(L"removemebad.txt") != 0)
        {
            printLine("wremove failed!");
        }
    }
    return;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        /* FLAW: Do not check the return value */
        REMOVE(L"removemebad.txt");
    }
}

void CWE252_Unchecked_Return_Value__wchar_t_remove_19_good()
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
    CWE252_Unchecked_Return_Value__wchar_t_remove_19_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE252_Unchecked_Return_Value__wchar_t_remove_19_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
