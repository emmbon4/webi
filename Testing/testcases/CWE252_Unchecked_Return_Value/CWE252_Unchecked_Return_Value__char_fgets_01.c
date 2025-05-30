/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE252_Unchecked_Return_Value__char_fgets_01.c
Label Definition File: CWE252_Unchecked_Return_Value.string.label.xml
Template File: point-flaw-01.tmpl.c
*/
/*
 * @description
 * CWE: 252 Unchecked Return Value
 * Sinks: fgets
 *    GoodSink: Check if fgets() fails before trying to use the destination buffer
 *    BadSink : Do not check if fgets() fails
 * Flow Variant: 01 Baseline
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE252_Unchecked_Return_Value__char_fgets_01_bad()
{
    {
        /* By initializing data_buf, we ensure this will not be the
         * CWE 690 (Unchecked Return Value To NULL Pointer) flaw for fgets() and other variants */
        char data_buf[100] = "";
        char * data = data_buf;
        printLine("Please enter a string: ");
        /* FLAW: Do not check the return value */
        fgets(data, 100, stdin);
        printLine(data);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

static void good1()
{
    {
        /* By initializing data_buf, we ensure this will not be the
         * CWE 690 (Unchecked Return Value To NULL Pointer) flaw for fgets() and other variants */
        char data_buf[100] = "";
        char * data = data_buf;
        printLine("Please enter a string: ");
        /* FIX: check the return value */
        if (fgets(data, 100, stdin) == NULL)
        {
            printLine("fgets failed!");
            exit(1);
        }
        printLine(data);
    }
}

void CWE252_Unchecked_Return_Value__char_fgets_01_good()
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
    CWE252_Unchecked_Return_Value__char_fgets_01_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE252_Unchecked_Return_Value__char_fgets_01_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
