/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE469_Use_Of_Pointer_Subtraction_To_Determine_Size__char_wrong_ptr_print_05.c
Label Definition File: CWE469_Use_Of_Pointer_Subtraction_To_Determine_Size.label.xml
Template File: point-flaw-05.tmpl.c
*/
/*
 * @description
 * CWE: 469 Use Of Pointer Subtraction To Determine Size
 * Sinks: wrong_ptr_print
 *    GoodSink: Subtract pointers correctly and print data
 *    BadSink : Subtract pointers to two different strings
 * Flow Variant: 05 Control flow: if(static_t) and if(static_f)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#define SRC_STR "abc/opqrstu"

/* The two variables below are not defined as "const", but are never
   assigned any other value, so a tool should be able to identify that
   reads of these will always return their initialized values. */
static int static_t = 1; /* true */
static int static_f = 0; /* false */

#ifndef OMITBAD

void CWE469_Use_Of_Pointer_Subtraction_To_Determine_Size__char_wrong_ptr_print_05_bad()
{
    if(static_t)
    {
        {
            char * data;
            char string1[] = SRC_STR;
            char string2[] = SRC_STR;
            char * slashInString1;
            size_t indexOfSlashInString1;
            slashInString1 = strchr(string1, '/');
            if (slashInString1 == NULL)
            {
                exit(1);
            }
            /* FLAW: subtracting the slash pointer from a completely different string, should be slashInString1 - string1 */
            indexOfSlashInString1 = (size_t)(slashInString1 - string2);
            /* print what comes after the slash */
            data = &(string1[indexOfSlashInString1+1]);
            printLine(data);
            printLine(string2); /* suppress warning about unused string2 */
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            char * data;
            char string1[] = SRC_STR;
            char string2[] = SRC_STR;
            char * slashInString1;
            size_t indexOfSlashInString1;
            slashInString1 = strchr(string1, '/');
            if (slashInString1 == NULL)
            {
                exit(1);
            }
            /* FIX: subtract the ending pointer from the actual string it originated from (string1) */
            indexOfSlashInString1 = (size_t)(slashInString1 - string1);
            /* print what comes after the slash */
            data = &(string1[indexOfSlashInString1+1]);
            printLine(data);
            printLine(string2); /* suppress warning about unused string2 */
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() uses if(static_f) instead of if(static_t) */
static void good1()
{
    if(static_f)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            char * data;
            char string1[] = SRC_STR;
            char string2[] = SRC_STR;
            char * slashInString1;
            size_t indexOfSlashInString1;
            slashInString1 = strchr(string1, '/');
            if (slashInString1 == NULL)
            {
                exit(1);
            }
            /* FLAW: subtracting the slash pointer from a completely different string, should be slashInString1 - string1 */
            indexOfSlashInString1 = (size_t)(slashInString1 - string2);
            /* print what comes after the slash */
            data = &(string1[indexOfSlashInString1+1]);
            printLine(data);
            printLine(string2); /* suppress warning about unused string2 */
        }
    }
    else
    {
        {
            char * data;
            char string1[] = SRC_STR;
            char string2[] = SRC_STR;
            char * slashInString1;
            size_t indexOfSlashInString1;
            slashInString1 = strchr(string1, '/');
            if (slashInString1 == NULL)
            {
                exit(1);
            }
            /* FIX: subtract the ending pointer from the actual string it originated from (string1) */
            indexOfSlashInString1 = (size_t)(slashInString1 - string1);
            /* print what comes after the slash */
            data = &(string1[indexOfSlashInString1+1]);
            printLine(data);
            printLine(string2); /* suppress warning about unused string2 */
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(static_t)
    {
        {
            char * data;
            char string1[] = SRC_STR;
            char string2[] = SRC_STR;
            char * slashInString1;
            size_t indexOfSlashInString1;
            slashInString1 = strchr(string1, '/');
            if (slashInString1 == NULL)
            {
                exit(1);
            }
            /* FIX: subtract the ending pointer from the actual string it originated from (string1) */
            indexOfSlashInString1 = (size_t)(slashInString1 - string1);
            /* print what comes after the slash */
            data = &(string1[indexOfSlashInString1+1]);
            printLine(data);
            printLine(string2); /* suppress warning about unused string2 */
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            char * data;
            char string1[] = SRC_STR;
            char string2[] = SRC_STR;
            char * slashInString1;
            size_t indexOfSlashInString1;
            slashInString1 = strchr(string1, '/');
            if (slashInString1 == NULL)
            {
                exit(1);
            }
            /* FLAW: subtracting the slash pointer from a completely different string, should be slashInString1 - string1 */
            indexOfSlashInString1 = (size_t)(slashInString1 - string2);
            /* print what comes after the slash */
            data = &(string1[indexOfSlashInString1+1]);
            printLine(data);
            printLine(string2); /* suppress warning about unused string2 */
        }
    }
}

void CWE469_Use_Of_Pointer_Subtraction_To_Determine_Size__char_wrong_ptr_print_05_good()
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
    CWE469_Use_Of_Pointer_Subtraction_To_Determine_Size__char_wrong_ptr_print_05_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE469_Use_Of_Pointer_Subtraction_To_Determine_Size__char_wrong_ptr_print_05_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
