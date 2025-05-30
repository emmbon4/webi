/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE170_Improper_Null_Termination__wchar_t_strncpy_14.c
Label Definition File: CWE170_Improper_Null_Termination.label.xml
Template File: point-flaw-14.tmpl.c
*/
/*
 * @description
 * CWE: 170 Improper Null Termination
 * Sinks: strncpy
 *    GoodSink: Copy a string using wcsncpy() with explicit null termination
 *    BadSink : Copy a string using wcsncpy() without explicit null termination
 * Flow Variant: 14 Control flow: if(global_five==5) and if(global_five!=5)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE170_Improper_Null_Termination__wchar_t_strncpy_14_bad()
{
    if(global_five==5)
    {
        {
            wchar_t data[150], dest[100];
            /* Initialize data */
            wmemset(data, L'A', 149);
            data[149] = L'\0';
            /* wcsncpy() does not null terminate if the string in the src buffer is larger than
             * the number of characters being copied to the dest buffer */
            wcsncpy(dest, data, 100);
            /* FLAW: do not explicitly null terminate dest after the use of wcsncpy() */
            printWLine(dest);
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            wchar_t data[150], dest[100];
            /* Initialize data */
            wmemset(data, L'A', 149);
            data[149] = L'\0';
            /* wcsncpy() does not null terminate if the string in the src buffer is larger than
             * the number of characters being copied to the dest buffer */
            wcsncpy(dest, data, 100);
            dest[99] = L'\0'; /* FIX: Explicitly null terminate dest after the use of wcsncpy() */
            printWLine(dest);
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() uses if(global_five!=5) instead of if(global_five==5) */
static void good1()
{
    if(global_five!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            wchar_t data[150], dest[100];
            /* Initialize data */
            wmemset(data, L'A', 149);
            data[149] = L'\0';
            /* wcsncpy() does not null terminate if the string in the src buffer is larger than
             * the number of characters being copied to the dest buffer */
            wcsncpy(dest, data, 100);
            /* FLAW: do not explicitly null terminate dest after the use of wcsncpy() */
            printWLine(dest);
        }
    }
    else
    {
        {
            wchar_t data[150], dest[100];
            /* Initialize data */
            wmemset(data, L'A', 149);
            data[149] = L'\0';
            /* wcsncpy() does not null terminate if the string in the src buffer is larger than
             * the number of characters being copied to the dest buffer */
            wcsncpy(dest, data, 100);
            dest[99] = L'\0'; /* FIX: Explicitly null terminate dest after the use of wcsncpy() */
            printWLine(dest);
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(global_five==5)
    {
        {
            wchar_t data[150], dest[100];
            /* Initialize data */
            wmemset(data, L'A', 149);
            data[149] = L'\0';
            /* wcsncpy() does not null terminate if the string in the src buffer is larger than
             * the number of characters being copied to the dest buffer */
            wcsncpy(dest, data, 100);
            dest[99] = L'\0'; /* FIX: Explicitly null terminate dest after the use of wcsncpy() */
            printWLine(dest);
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            wchar_t data[150], dest[100];
            /* Initialize data */
            wmemset(data, L'A', 149);
            data[149] = L'\0';
            /* wcsncpy() does not null terminate if the string in the src buffer is larger than
             * the number of characters being copied to the dest buffer */
            wcsncpy(dest, data, 100);
            /* FLAW: do not explicitly null terminate dest after the use of wcsncpy() */
            printWLine(dest);
        }
    }
}

void CWE170_Improper_Null_Termination__wchar_t_strncpy_14_good()
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
    CWE170_Improper_Null_Termination__wchar_t_strncpy_14_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE170_Improper_Null_Termination__wchar_t_strncpy_14_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
