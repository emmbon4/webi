/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE170_Improper_Null_Termination__char_strncpy_15.c
Label Definition File: CWE170_Improper_Null_Termination.label.xml
Template File: point-flaw-15.tmpl.c
*/
/*
 * @description
 * CWE: 170 Improper Null Termination
 * Sinks: strncpy
 *    GoodSink: Copy a string using strncpy() with explicit null termination
 *    BadSink : Copy a string using strncpy() without explicit null termination
 * Flow Variant: 15 Control flow: switch(6)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE170_Improper_Null_Termination__char_strncpy_15_bad()
{
    switch(6)
    {
    case 6:
    {
        char data[150], dest[100];
        /* Initialize data */
        memset(data, 'A', 149);
        data[149] = '\0';
        /* strncpy() does not null terminate if the string in the src buffer is larger than
         * the number of characters being copied to the dest buffer */
        strncpy(dest, data, 100);
        /* FLAW: do not explicitly null terminate dest after the use of strncpy() */
        printLine(dest);
    }
    break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        char data[150], dest[100];
        /* Initialize data */
        memset(data, 'A', 149);
        data[149] = '\0';
        /* strncpy() does not null terminate if the string in the src buffer is larger than
         * the number of characters being copied to the dest buffer */
        strncpy(dest, data, 100);
        dest[99] = '\0'; /* FIX: Explicitly null terminate dest after the use of strncpy() */
        printLine(dest);
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
        char data[150], dest[100];
        /* Initialize data */
        memset(data, 'A', 149);
        data[149] = '\0';
        /* strncpy() does not null terminate if the string in the src buffer is larger than
         * the number of characters being copied to the dest buffer */
        strncpy(dest, data, 100);
        /* FLAW: do not explicitly null terminate dest after the use of strncpy() */
        printLine(dest);
    }
    break;
    default:
    {
        char data[150], dest[100];
        /* Initialize data */
        memset(data, 'A', 149);
        data[149] = '\0';
        /* strncpy() does not null terminate if the string in the src buffer is larger than
         * the number of characters being copied to the dest buffer */
        strncpy(dest, data, 100);
        dest[99] = '\0'; /* FIX: Explicitly null terminate dest after the use of strncpy() */
        printLine(dest);
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
        char data[150], dest[100];
        /* Initialize data */
        memset(data, 'A', 149);
        data[149] = '\0';
        /* strncpy() does not null terminate if the string in the src buffer is larger than
         * the number of characters being copied to the dest buffer */
        strncpy(dest, data, 100);
        dest[99] = '\0'; /* FIX: Explicitly null terminate dest after the use of strncpy() */
        printLine(dest);
    }
    break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        char data[150], dest[100];
        /* Initialize data */
        memset(data, 'A', 149);
        data[149] = '\0';
        /* strncpy() does not null terminate if the string in the src buffer is larger than
         * the number of characters being copied to the dest buffer */
        strncpy(dest, data, 100);
        /* FLAW: do not explicitly null terminate dest after the use of strncpy() */
        printLine(dest);
    }
    }
}

void CWE170_Improper_Null_Termination__char_strncpy_15_good()
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
    CWE170_Improper_Null_Termination__char_strncpy_15_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE170_Improper_Null_Termination__char_strncpy_15_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
