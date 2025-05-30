/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE170_Improper_Null_Termination__wchar_t_loop_04.c
Label Definition File: CWE170_Improper_Null_Termination.label.xml
Template File: point-flaw-04.tmpl.c
*/
/*
 * @description
 * CWE: 170 Improper Null Termination
 * Sinks: loop
 *    GoodSink: Copy a string using a loop with explicit null termination
 *    BadSink : Copy a string using a loop without explicit null termination
 * Flow Variant: 04 Control flow: if(static_const_t) and if(static_const_f)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

/* The two variables below are declared "const", so a tool should
   be able to identify that reads of these will always return their
   initialized values. */
static const int static_const_t = 1; /* true */
static const int static_const_f = 0; /* false */

#ifndef OMITBAD

void CWE170_Improper_Null_Termination__wchar_t_loop_04_bad()
{
    if(static_const_t)
    {
        {
            wchar_t src[150], dest[100];
            int i;
            /* Initialize src */
            wmemset(src, L'A', 149);
            src[149] = L'\0';
            for(i=0; i < 100; i++)
            {
                dest[i] = src[i];
            }
            /* FLAW: do not explicitly null terminate dest after the loop */
            printWLine(dest);
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            wchar_t src[150], dest[100];
            int i;
            /* Initialize src */
            wmemset(src, L'A', 149);
            src[149] = L'\0';
            for(i=0; i < 100; i++)
            {
                dest[i] = src[i];
            }
            dest[99] = L'\0'; /* FIX: null terminate dest */
            printWLine(dest);
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
            wchar_t src[150], dest[100];
            int i;
            /* Initialize src */
            wmemset(src, L'A', 149);
            src[149] = L'\0';
            for(i=0; i < 100; i++)
            {
                dest[i] = src[i];
            }
            /* FLAW: do not explicitly null terminate dest after the loop */
            printWLine(dest);
        }
    }
    else
    {
        {
            wchar_t src[150], dest[100];
            int i;
            /* Initialize src */
            wmemset(src, L'A', 149);
            src[149] = L'\0';
            for(i=0; i < 100; i++)
            {
                dest[i] = src[i];
            }
            dest[99] = L'\0'; /* FIX: null terminate dest */
            printWLine(dest);
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(static_const_t)
    {
        {
            wchar_t src[150], dest[100];
            int i;
            /* Initialize src */
            wmemset(src, L'A', 149);
            src[149] = L'\0';
            for(i=0; i < 100; i++)
            {
                dest[i] = src[i];
            }
            dest[99] = L'\0'; /* FIX: null terminate dest */
            printWLine(dest);
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            wchar_t src[150], dest[100];
            int i;
            /* Initialize src */
            wmemset(src, L'A', 149);
            src[149] = L'\0';
            for(i=0; i < 100; i++)
            {
                dest[i] = src[i];
            }
            /* FLAW: do not explicitly null terminate dest after the loop */
            printWLine(dest);
        }
    }
}

void CWE170_Improper_Null_Termination__wchar_t_loop_04_good()
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
    CWE170_Improper_Null_Termination__wchar_t_loop_04_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE170_Improper_Null_Termination__wchar_t_loop_04_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
