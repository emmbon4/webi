/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE469_Use_Of_Pointer_Subtraction_To_Determine_Size__char_wrong_order_print_16.c
Label Definition File: CWE469_Use_Of_Pointer_Subtraction_To_Determine_Size.label.xml
Template File: point-flaw-16.tmpl.c
*/
/*
 * @description
 * CWE: 469 Use Of Pointer Subtraction To Determine Size
 * Sinks: wrong_order_print
 *    GoodSink: Subtract pointers correctly and print data
 *    BadSink : Beginning and end pointers are switched leading to an incorrect index when printing
 * Flow Variant: 16 Control flow: while(1) and while(0)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#define SRC_STR "abc/opqrstu"

#ifndef OMITBAD

void CWE469_Use_Of_Pointer_Subtraction_To_Determine_Size__char_wrong_order_print_16_bad()
{
    while(1)
    {
        {
            char * data;
            char string[] = SRC_STR;
            char * slash;
            size_t indexOfSlash;
            slash = strchr(string, '/');
            if (slash == NULL)
            {
                exit(1);
            }
            /* FLAW: switched the beginning and end pointers around, leads to incorrect index when
             * printing
             */
            indexOfSlash = (size_t)(string - slash);
            /* print what comes after the slash */
            data = &(string[indexOfSlash+1]);
            printLine(data);
        }
        break;
    }
    while(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            char * data;
            char string[] = SRC_STR;
            char * slash;
            size_t indexOfSlash;
            slash = strchr(string, '/');
            if (slash == NULL)
            {
                exit(1);
            }
            /* FIX: subtract pointers in the correct order ('slash - string') */
            indexOfSlash = (size_t)(slash - string);
            /* print what comes after the slash */
            data = &(string[indexOfSlash+1]);
            printLine(data);
        }
        break;
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() changes the conditions on the while statements */
static void good1()
{
    while(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            char * data;
            char string[] = SRC_STR;
            char * slash;
            size_t indexOfSlash;
            slash = strchr(string, '/');
            if (slash == NULL)
            {
                exit(1);
            }
            /* FLAW: switched the beginning and end pointers around, leads to incorrect index when
             * printing
             */
            indexOfSlash = (size_t)(string - slash);
            /* print what comes after the slash */
            data = &(string[indexOfSlash+1]);
            printLine(data);
        }
        break;
    }
    while(1)
    {
        {
            char * data;
            char string[] = SRC_STR;
            char * slash;
            size_t indexOfSlash;
            slash = strchr(string, '/');
            if (slash == NULL)
            {
                exit(1);
            }
            /* FIX: subtract pointers in the correct order ('slash - string') */
            indexOfSlash = (size_t)(slash - string);
            /* print what comes after the slash */
            data = &(string[indexOfSlash+1]);
            printLine(data);
        }
        break;
    }
}

void CWE469_Use_Of_Pointer_Subtraction_To_Determine_Size__char_wrong_order_print_16_good()
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
    CWE469_Use_Of_Pointer_Subtraction_To_Determine_Size__char_wrong_order_print_16_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE469_Use_Of_Pointer_Subtraction_To_Determine_Size__char_wrong_order_print_16_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
