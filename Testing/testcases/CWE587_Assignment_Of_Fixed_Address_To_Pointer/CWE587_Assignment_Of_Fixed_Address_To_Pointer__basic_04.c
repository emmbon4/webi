/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE587_Assignment_Of_Fixed_Address_To_Pointer__basic_04.c
Label Definition File: CWE587_Assignment_Of_Fixed_Address_To_Pointer__basic.label.xml
Template File: point-flaw-04.tmpl.c
*/
/*
 * @description
 * CWE: 587 Assignment of Fixed Address to Pointer
 * Sinks:
 *    GoodSink: Assign the pointer to a stack variable
 *    BadSink : Assign fixed address to pointer
 * Flow Variant: 04 Control flow: if(static_const_t) and if(static_const_f)
 *
 * */

#include "std_testcase.h"

/* The two variables below are declared "const", so a tool should
   be able to identify that reads of these will always return their
   initialized values. */
static const int static_const_t = 1; /* true */
static const int static_const_f = 0; /* false */

#ifndef OMITBAD

void CWE587_Assignment_Of_Fixed_Address_To_Pointer__basic_04_bad()
{
    if(static_const_t)
    {
        {
            /* FLAW: Assigning fixed address to pointer */
            char *p = (char*)0x400000;
            printHexCharLine(*p);
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* FIX: Assign the pointer to a stack variable */
            char c = 'a';
            char *p = &c;
            printHexCharLine(*p);
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
            /* FLAW: Assigning fixed address to pointer */
            char *p = (char*)0x400000;
            printHexCharLine(*p);
        }
    }
    else
    {
        {
            /* FIX: Assign the pointer to a stack variable */
            char c = 'a';
            char *p = &c;
            printHexCharLine(*p);
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(static_const_t)
    {
        {
            /* FIX: Assign the pointer to a stack variable */
            char c = 'a';
            char *p = &c;
            printHexCharLine(*p);
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* FLAW: Assigning fixed address to pointer */
            char *p = (char*)0x400000;
            printHexCharLine(*p);
        }
    }
}

void CWE587_Assignment_Of_Fixed_Address_To_Pointer__basic_04_good()
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
    CWE587_Assignment_Of_Fixed_Address_To_Pointer__basic_04_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE587_Assignment_Of_Fixed_Address_To_Pointer__basic_04_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
