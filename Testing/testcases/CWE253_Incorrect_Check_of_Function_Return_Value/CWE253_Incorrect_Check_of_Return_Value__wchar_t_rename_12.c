/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE253_Incorrect_Check_of_Return_Value__wchar_t_rename_12.c
Label Definition File: CWE253_Incorrect_Check_of_Return_Value.string.label.xml
Template File: point-flaw-12.tmpl.c
*/
/*
 * @description
 * CWE: 253 Incorrect Check of Return Value
 * Sinks: rename
 *    GoodSink: Correctly check if wrename() failed
 *    BadSink : Incorrectlycheck if wrename() failed
 * Flow Variant: 12 Control flow: if(global_returns_t_or_f())
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
# define RENAME _wrename
#else
# define RENAME wrename
#endif

#define OLD_BAD_FILE_NAME L"oldbadfilename.txt"
#define OLD_GOOD_FILE_NAME L"oldgoodfilename.txt"

#ifndef OMITBAD

void CWE253_Incorrect_Check_of_Return_Value__wchar_t_rename_12_bad()
{
    if(global_returns_t_or_f())
    {
        {
            /* FLAW: wrename() might fail, in which case the return value will be non-zero, but
             * we are checking to see if the return value is 0 */
            if (RENAME(OLD_BAD_FILE_NAME, L"newbadfilename.txt") == 0)
            {
                printLine("wrename failed!");
            }
        }
    }
    else
    {
        {
            /* FIX: check for the correct return value */
            if (RENAME(OLD_GOOD_FILE_NAME, L"newgoodfilename.txt") != 0)
            {
                printLine("wrename failed!");
            }
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() uses the GoodSink on both sides of the "if" statement */
static void good1()
{
    if(global_returns_t_or_f())
    {
        {
            /* FIX: check for the correct return value */
            if (RENAME(OLD_GOOD_FILE_NAME, L"newgoodfilename.txt") != 0)
            {
                printLine("wrename failed!");
            }
        }
    }
    else
    {
        {
            /* FIX: check for the correct return value */
            if (RENAME(OLD_GOOD_FILE_NAME, L"newgoodfilename.txt") != 0)
            {
                printLine("wrename failed!");
            }
        }
    }
}

void CWE253_Incorrect_Check_of_Return_Value__wchar_t_rename_12_good()
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
    CWE253_Incorrect_Check_of_Return_Value__wchar_t_rename_12_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE253_Incorrect_Check_of_Return_Value__wchar_t_rename_12_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
