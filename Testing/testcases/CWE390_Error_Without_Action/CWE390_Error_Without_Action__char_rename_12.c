/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE390_Error_Without_Action__char_rename_12.c
Label Definition File: CWE390_Error_Without_Action.string.label.xml
Template File: point-flaw-12.tmpl.c
*/
/*
 * @description
 * CWE: 390 Detection of Error Condition Without Action
 * Sinks: rename
 *    GoodSink: Check if rename() failed and handle errors properly
 *    BadSink : Check to see if rename() failed, but do nothing about it
 * Flow Variant: 12 Control flow: if(global_returns_t_or_f())
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
# define RENAME rename
#else
# define RENAME rename
#endif

#define OLD_BAD_FILE_NAME "oldbadfilename.txt"
#define OLD_GOOD_FILE_NAME "oldgoodfilename.txt"

#ifndef OMITBAD

void CWE390_Error_Without_Action__char_rename_12_bad()
{
    if(global_returns_t_or_f())
    {
        {
            /* FLAW: check the return value, but do nothing if there is an error */
            if (RENAME(OLD_BAD_FILE_NAME, "newbadfilename.txt") != 0)
            {
                /* do nothing */
            }
        }
    }
    else
    {
        {
            /* FIX: check the return value and handle errors properly */
            if (RENAME(OLD_GOOD_FILE_NAME, "newgoodfilename.txt") != 0)
            {
                printLine("rename failed!");
                exit(1);
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
            /* FIX: check the return value and handle errors properly */
            if (RENAME(OLD_GOOD_FILE_NAME, "newgoodfilename.txt") != 0)
            {
                printLine("rename failed!");
                exit(1);
            }
        }
    }
    else
    {
        {
            /* FIX: check the return value and handle errors properly */
            if (RENAME(OLD_GOOD_FILE_NAME, "newgoodfilename.txt") != 0)
            {
                printLine("rename failed!");
                exit(1);
            }
        }
    }
}

void CWE390_Error_Without_Action__char_rename_12_good()
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
    CWE390_Error_Without_Action__char_rename_12_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE390_Error_Without_Action__char_rename_12_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
