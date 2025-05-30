/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE253_Incorrect_Check_of_Return_Value__wchar_t_rename_15.c
Label Definition File: CWE253_Incorrect_Check_of_Return_Value.string.label.xml
Template File: point-flaw-15.tmpl.c
*/
/*
 * @description
 * CWE: 253 Incorrect Check of Return Value
 * Sinks: rename
 *    GoodSink: Correctly check if wrename() failed
 *    BadSink : Incorrectlycheck if wrename() failed
 * Flow Variant: 15 Control flow: switch(6)
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

void CWE253_Incorrect_Check_of_Return_Value__wchar_t_rename_15_bad()
{
    switch(6)
    {
    case 6:
    {
        /* FLAW: wrename() might fail, in which case the return value will be non-zero, but
         * we are checking to see if the return value is 0 */
        if (RENAME(OLD_BAD_FILE_NAME, L"newbadfilename.txt") == 0)
        {
            printLine("wrename failed!");
        }
    }
    break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
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

/* good1() changes the switch to switch(5) */
static void good1()
{
    switch(5)
    {
    case 6:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        /* FLAW: wrename() might fail, in which case the return value will be non-zero, but
         * we are checking to see if the return value is 0 */
        if (RENAME(OLD_BAD_FILE_NAME, L"newbadfilename.txt") == 0)
        {
            printLine("wrename failed!");
        }
    }
    break;
    default:
    {
        /* FIX: check for the correct return value */
        if (RENAME(OLD_GOOD_FILE_NAME, L"newgoodfilename.txt") != 0)
        {
            printLine("wrename failed!");
        }
    }
    }
}

/* good2() reverses the blocks in the switch */
static void good2()
{
    switch(6)
    {
    case 6:
    {
        /* FIX: check for the correct return value */
        if (RENAME(OLD_GOOD_FILE_NAME, L"newgoodfilename.txt") != 0)
        {
            printLine("wrename failed!");
        }
    }
    break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        /* FLAW: wrename() might fail, in which case the return value will be non-zero, but
         * we are checking to see if the return value is 0 */
        if (RENAME(OLD_BAD_FILE_NAME, L"newbadfilename.txt") == 0)
        {
            printLine("wrename failed!");
        }
    }
    }
}

void CWE253_Incorrect_Check_of_Return_Value__wchar_t_rename_15_good()
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
    CWE253_Incorrect_Check_of_Return_Value__wchar_t_rename_15_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE253_Incorrect_Check_of_Return_Value__wchar_t_rename_15_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
