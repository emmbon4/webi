/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE170_Improper_Null_Termination__wchar_t_memcpy_11.c
Label Definition File: CWE170_Improper_Null_Termination.label.xml
Template File: point-flaw-11.tmpl.c
*/
/*
 * @description
 * CWE: 170 Improper Null Termination
 * Sinks: memcpy
 *    GoodSink: Copy a string using memcpy with explicit null termination
 *    BadSink : Copy a string using memcpy without explicit null termination
 * Flow Variant: 11 Control flow: if(global_returns_t()) and if(global_returns_f())
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE170_Improper_Null_Termination__wchar_t_memcpy_11_bad()
{
    if(global_returns_t())
    {
        {
            wchar_t data[150], dest[100];
            /* Initialize data */
            wmemset(data, L'A', 149);
            data[149] = L'\0';
            memcpy(dest, data, 100*sizeof(wchar_t));
            /* FLAW: do not explicitly null terminate dest after the use of memcpy */
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
            memcpy(dest, data, 100*sizeof(wchar_t));
            dest[99] = L'\0'; /* FIX: null terminate dest */
            printWLine(dest);
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() uses if(global_returns_f()) instead of if(global_returns_t()) */
static void good1()
{
    if(global_returns_f())
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            wchar_t data[150], dest[100];
            /* Initialize data */
            wmemset(data, L'A', 149);
            data[149] = L'\0';
            memcpy(dest, data, 100*sizeof(wchar_t));
            /* FLAW: do not explicitly null terminate dest after the use of memcpy */
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
            memcpy(dest, data, 100*sizeof(wchar_t));
            dest[99] = L'\0'; /* FIX: null terminate dest */
            printWLine(dest);
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(global_returns_t())
    {
        {
            wchar_t data[150], dest[100];
            /* Initialize data */
            wmemset(data, L'A', 149);
            data[149] = L'\0';
            memcpy(dest, data, 100*sizeof(wchar_t));
            dest[99] = L'\0'; /* FIX: null terminate dest */
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
            memcpy(dest, data, 100*sizeof(wchar_t));
            /* FLAW: do not explicitly null terminate dest after the use of memcpy */
            printWLine(dest);
        }
    }
}

void CWE170_Improper_Null_Termination__wchar_t_memcpy_11_good()
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
    CWE170_Improper_Null_Termination__wchar_t_memcpy_11_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE170_Improper_Null_Termination__wchar_t_memcpy_11_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
