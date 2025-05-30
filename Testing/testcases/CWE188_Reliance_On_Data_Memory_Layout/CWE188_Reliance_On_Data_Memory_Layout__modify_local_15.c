/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE188_Reliance_On_Data_Memory_Layout__modify_local_15.c
Label Definition File: CWE188_Reliance_On_Data_Memory_Layout.label.xml
Template File: point-flaw-15.tmpl.c
*/
/*
 * @description
 * CWE: 188 Reliance on Data Memory Layout
 * Sinks: modify_local
 *    GoodSink: Modify the second field of the struct using the field name
 *    BadSink : Attempt to modify second field in struct, assuming the first field is an int
 * Flow Variant: 15 Control flow: switch(6)
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE188_Reliance_On_Data_Memory_Layout__modify_local_15_bad()
{
    switch(6)
    {
    case 6:
    {
        struct
        {
            char first;
            int second;
        } s;
        char *c;
        s.first = 1;
        c = &s.first;
        /* FLAW: Attempt to modify 'second' assuming second comes after first and
         * is aligned on an int-boundary after first
         */
        *(int*)(c + sizeof(int)) = 5;
        printIntLine(s.first);
        printIntLine(s.second);
    }
    break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        struct
        {
            char first;
            int second;
        } s;
        s.first = 1;
        /* FIX: Do not make unwarranted assumptions about underlying data model
         * Modify and access data appropriately */
        s.second = 5;
        printIntLine(s.first);
        printIntLine(s.second);
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
        struct
        {
            char first;
            int second;
        } s;
        char *c;
        s.first = 1;
        c = &s.first;
        /* FLAW: Attempt to modify 'second' assuming second comes after first and
         * is aligned on an int-boundary after first
         */
        *(int*)(c + sizeof(int)) = 5;
        printIntLine(s.first);
        printIntLine(s.second);
    }
    break;
    default:
    {
        struct
        {
            char first;
            int second;
        } s;
        s.first = 1;
        /* FIX: Do not make unwarranted assumptions about underlying data model
         * Modify and access data appropriately */
        s.second = 5;
        printIntLine(s.first);
        printIntLine(s.second);
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
        struct
        {
            char first;
            int second;
        } s;
        s.first = 1;
        /* FIX: Do not make unwarranted assumptions about underlying data model
         * Modify and access data appropriately */
        s.second = 5;
        printIntLine(s.first);
        printIntLine(s.second);
    }
    break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        struct
        {
            char first;
            int second;
        } s;
        char *c;
        s.first = 1;
        c = &s.first;
        /* FLAW: Attempt to modify 'second' assuming second comes after first and
         * is aligned on an int-boundary after first
         */
        *(int*)(c + sizeof(int)) = 5;
        printIntLine(s.first);
        printIntLine(s.second);
    }
    }
}

void CWE188_Reliance_On_Data_Memory_Layout__modify_local_15_good()
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
    CWE188_Reliance_On_Data_Memory_Layout__modify_local_15_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE188_Reliance_On_Data_Memory_Layout__modify_local_15_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
