/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE587_Assignment_Of_Fixed_Address_To_Pointer__basic_01.c
Label Definition File: CWE587_Assignment_Of_Fixed_Address_To_Pointer__basic.label.xml
Template File: point-flaw-01.tmpl.c
*/
/*
 * @description
 * CWE: 587 Assignment of Fixed Address to Pointer
 * Sinks:
 *    GoodSink: Assign the pointer to a stack variable
 *    BadSink : Assign fixed address to pointer
 * Flow Variant: 01 Baseline
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE587_Assignment_Of_Fixed_Address_To_Pointer__basic_01_bad()
{
    {
        /* FLAW: Assigning fixed address to pointer */
        char *p = (char*)0x400000;
        printHexCharLine(*p);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

static void good1()
{
    {
        /* FIX: Assign the pointer to a stack variable */
        char c = 'a';
        char *p = &c;
        printHexCharLine(*p);
    }
}

void CWE587_Assignment_Of_Fixed_Address_To_Pointer__basic_01_good()
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
    CWE587_Assignment_Of_Fixed_Address_To_Pointer__basic_01_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE587_Assignment_Of_Fixed_Address_To_Pointer__basic_01_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
