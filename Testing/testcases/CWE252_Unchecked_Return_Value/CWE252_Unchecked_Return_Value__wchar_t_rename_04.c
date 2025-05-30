/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE252_Unchecked_Return_Value__wchar_t_rename_04.c
Label Definition File: CWE252_Unchecked_Return_Value.string.label.xml
Template File: point-flaw-04.tmpl.c
*/
/*
 * @description
 * CWE: 252 Unchecked Return Value
 * Sinks: rename
 *    GoodSink: Check if wrename() fails
 *    BadSink : Do not check if wrename() fails
 * Flow Variant: 04 Control flow: if(static_const_t) and if(static_const_f)
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

/* The two variables below are declared "const", so a tool should
   be able to identify that reads of these will always return their
   initialized values. */
static const int static_const_t = 1; /* true */
static const int static_const_f = 0; /* false */

#ifndef OMITBAD

void CWE252_Unchecked_Return_Value__wchar_t_rename_04_bad()
{
    if(static_const_t)
    {
        {
            /* FLAW: Do not check the return value */
            RENAME(OLD_BAD_FILE_NAME, L"newbadfilename.txt");
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* FIX: check the return value */
            if (RENAME(OLD_GOOD_FILE_NAME, L"newgoodfilename.txt") != 0)
            {
                printLine("wrename failed!");
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
            /* FLAW: Do not check the return value */
            RENAME(OLD_BAD_FILE_NAME, L"newbadfilename.txt");
        }
    }
    else
    {
        {
            /* FIX: check the return value */
            if (RENAME(OLD_GOOD_FILE_NAME, L"newgoodfilename.txt") != 0)
            {
                printLine("wrename failed!");
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
            /* FIX: check the return value */
            if (RENAME(OLD_GOOD_FILE_NAME, L"newgoodfilename.txt") != 0)
            {
                printLine("wrename failed!");
            }
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* FLAW: Do not check the return value */
            RENAME(OLD_BAD_FILE_NAME, L"newbadfilename.txt");
        }
    }
}

void CWE252_Unchecked_Return_Value__wchar_t_rename_04_good()
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
    CWE252_Unchecked_Return_Value__wchar_t_rename_04_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE252_Unchecked_Return_Value__wchar_t_rename_04_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
