/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE390_Error_Without_Action__wchar_t_fgets_01.c
Label Definition File: CWE390_Error_Without_Action.string.label.xml
Template File: point-flaw-01.tmpl.c
*/
/*
 * @description
 * CWE: 390 Detection of Error Condition Without Action
 * Sinks: fgets
 *    GoodSink: Check if fgetws() failed and handle errors properly
 *    BadSink : Check to see if fgetws() failed, but do nothing about it
 * Flow Variant: 01 Baseline
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE390_Error_Without_Action__wchar_t_fgets_01_bad()
{
    {
        /* By initializing data_buf, we ensure this will not be the
         * CWE 690 (Unchecked Return Value To NULL Pointer) flaw for fgetws() and other variants */
        wchar_t data_buf[100] = L"";
        wchar_t * data = data_buf;
        printLine("Please enter a string: ");
        /* FLAW: check the return value, but do nothing if there is an error */
        if (fgetws(data, 100, stdin) == NULL)
        {
            /* do nothing */
        }
        printWLine(data);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

static void good1()
{
    {
        /* By initializing data_buf, we ensure this will not be the
         * CWE 690 (Unchecked Return Value To NULL Pointer) flaw for fgetws() and other variants */
        wchar_t data_buf[100] = L"";
        wchar_t * data = data_buf;
        printLine("Please enter a string: ");
        /* FIX: check the return value and handle errors properly */
        if (fgetws(data, 100, stdin) == NULL)
        {
            printLine("fgetws failed!");
            exit(1);
        }
        printWLine(data);
    }
}

void CWE390_Error_Without_Action__wchar_t_fgets_01_good()
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
    CWE390_Error_Without_Action__wchar_t_fgets_01_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE390_Error_Without_Action__wchar_t_fgets_01_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
