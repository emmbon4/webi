/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE253_Incorrect_Check_of_Return_Value__wchar_t_snprintf_03.c
Label Definition File: CWE253_Incorrect_Check_of_Return_Value.string.label.xml
Template File: point-flaw-03.tmpl.c
*/
/*
 * @description
 * CWE: 253 Incorrect Check of Return Value
 * Sinks: snprintf
 *    GoodSink: Correctly check if snwprintf() failed
 *    BadSink : Incorrectly check if snwprintf() failed
 * Flow Variant: 03 Control flow: if(5==5) and if(5!=5)
 *
 * */

#include "std_testcase.h"

#define SRC L"string"

#ifndef OMITBAD

void CWE253_Incorrect_Check_of_Return_Value__wchar_t_snprintf_03_bad()
{
    if(5==5)
    {
        {
            /* By initializing data_buf, we ensure this will not be the
             * CWE 690 (Unchecked Return Value To NULL Pointer) flaw for fgetws() and other variants */
            wchar_t data_buf[100] = L"";
            wchar_t * data = data_buf;
            /* FLAW: snwprintf() might fail, in which case the return value will be negative, but
             * we are checking to see if the return value is 0 */
            if (_snwprintf(data,100-wcslen(SRC)-1, L"%s\n", SRC) == 0)
            {
                printLine("snwprintf failed!");
            }
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* By initializing data_buf, we ensure this will not be the
             * CWE 690 (Unchecked Return Value To NULL Pointer) flaw for fgetws() and other variants */
            wchar_t data_buf[100] = L"";
            wchar_t * data = data_buf;
            /* FIX: check for the correct return value */
            if (_snwprintf(data,100-wcslen(SRC)-1, L"%s\n", SRC) < 0)
            {
                printLine("snwprintf failed!");
            }
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() uses if(5!=5) instead of if(5==5) */
static void good1()
{
    if(5!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* By initializing data_buf, we ensure this will not be the
             * CWE 690 (Unchecked Return Value To NULL Pointer) flaw for fgetws() and other variants */
            wchar_t data_buf[100] = L"";
            wchar_t * data = data_buf;
            /* FLAW: snwprintf() might fail, in which case the return value will be negative, but
             * we are checking to see if the return value is 0 */
            if (_snwprintf(data,100-wcslen(SRC)-1, L"%s\n", SRC) == 0)
            {
                printLine("snwprintf failed!");
            }
        }
    }
    else
    {
        {
            /* By initializing data_buf, we ensure this will not be the
             * CWE 690 (Unchecked Return Value To NULL Pointer) flaw for fgetws() and other variants */
            wchar_t data_buf[100] = L"";
            wchar_t * data = data_buf;
            /* FIX: check for the correct return value */
            if (_snwprintf(data,100-wcslen(SRC)-1, L"%s\n", SRC) < 0)
            {
                printLine("snwprintf failed!");
            }
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(5==5)
    {
        {
            /* By initializing data_buf, we ensure this will not be the
             * CWE 690 (Unchecked Return Value To NULL Pointer) flaw for fgetws() and other variants */
            wchar_t data_buf[100] = L"";
            wchar_t * data = data_buf;
            /* FIX: check for the correct return value */
            if (_snwprintf(data,100-wcslen(SRC)-1, L"%s\n", SRC) < 0)
            {
                printLine("snwprintf failed!");
            }
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* By initializing data_buf, we ensure this will not be the
             * CWE 690 (Unchecked Return Value To NULL Pointer) flaw for fgetws() and other variants */
            wchar_t data_buf[100] = L"";
            wchar_t * data = data_buf;
            /* FLAW: snwprintf() might fail, in which case the return value will be negative, but
             * we are checking to see if the return value is 0 */
            if (_snwprintf(data,100-wcslen(SRC)-1, L"%s\n", SRC) == 0)
            {
                printLine("snwprintf failed!");
            }
        }
    }
}

void CWE253_Incorrect_Check_of_Return_Value__wchar_t_snprintf_03_good()
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
    CWE253_Incorrect_Check_of_Return_Value__wchar_t_snprintf_03_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE253_Incorrect_Check_of_Return_Value__wchar_t_snprintf_03_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
