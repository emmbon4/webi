/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE390_Error_Without_Action__wchar_t_rename_10.c
Label Definition File: CWE390_Error_Without_Action.string.label.xml
Template File: point-flaw-10.tmpl.c
*/
/*
 * @description
 * CWE: 390 Detection of Error Condition Without Action
 * Sinks: rename
 *    GoodSink: Check if wrename() failed and handle errors properly
 *    BadSink : Check to see if wrename() failed, but do nothing about it
 * Flow Variant: 10 Control flow: if(global_t) and if(global_f)
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

void CWE390_Error_Without_Action__wchar_t_rename_10_bad()
{
    if(global_t)
    {
        {
            /* FLAW: check the return value, but do nothing if there is an error */
            if (RENAME(OLD_BAD_FILE_NAME, L"newbadfilename.txt") != 0)
            {
                /* do nothing */
            }
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* FIX: check the return value and handle errors properly */
            if (RENAME(OLD_GOOD_FILE_NAME, L"newgoodfilename.txt") != 0)
            {
                printLine("wrename failed!");
                exit(1);
            }
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() uses if(global_f) instead of if(global_t) */
static void good1()
{
    if(global_f)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* FLAW: check the return value, but do nothing if there is an error */
            if (RENAME(OLD_BAD_FILE_NAME, L"newbadfilename.txt") != 0)
            {
                /* do nothing */
            }
        }
    }
    else
    {
        {
            /* FIX: check the return value and handle errors properly */
            if (RENAME(OLD_GOOD_FILE_NAME, L"newgoodfilename.txt") != 0)
            {
                printLine("wrename failed!");
                exit(1);
            }
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(global_t)
    {
        {
            /* FIX: check the return value and handle errors properly */
            if (RENAME(OLD_GOOD_FILE_NAME, L"newgoodfilename.txt") != 0)
            {
                printLine("wrename failed!");
                exit(1);
            }
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* FLAW: check the return value, but do nothing if there is an error */
            if (RENAME(OLD_BAD_FILE_NAME, L"newbadfilename.txt") != 0)
            {
                /* do nothing */
            }
        }
    }
}

void CWE390_Error_Without_Action__wchar_t_rename_10_good()
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
    CWE390_Error_Without_Action__wchar_t_rename_10_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE390_Error_Without_Action__wchar_t_rename_10_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
