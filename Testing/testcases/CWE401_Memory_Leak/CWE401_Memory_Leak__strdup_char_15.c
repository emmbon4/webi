/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__strdup_char_15.c
Label Definition File: CWE401_Memory_Leak__strdup.label.xml
Template File: sources-sinks-15.tmpl.c
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource:  Allocate data using strdup()
 * GoodSource: Allocate data on the stack
 * Sinks:
 *    GoodSink: call free() on data
 *    BadSink : no deallocation of data
 * Flow Variant: 15 Control flow: switch(6) and switch(7)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE401_Memory_Leak__strdup_char_15_bad()
{
    char * data;
    data = NULL;
    switch(6)
    {
    case 6:
    {
        char mystring[] = "mystring";
        /* FLAW: Allocate memory from the heap using a function that requires free() for deallocation */
        data = strdup(mystring);
        /* Use data */
        printLine(data);
    }
    break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        /* FIX: Allocate memory from the stack */
        char data_goodbuf[100];
        data = data_goodbuf;
        /* Initialize then use data */
        strcpy(data, "a string");
        printLine(data);
    }
    break;
    }
    switch(7)
    {
    case 7:
        /* POTENTIAL FLAW: No deallocation of memory */
        /* no deallocation */
        ; /* empty statement needed for some flow variants */
        break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Deallocate memory initialized in the source */
        free(data);
        break;
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G1() - use badsource and goodsink by changing the second switch to switch(8) */
static void goodB2G1()
{
    char * data;
    data = NULL;
    switch(6)
    {
    case 6:
    {
        char mystring[] = "mystring";
        /* FLAW: Allocate memory from the heap using a function that requires free() for deallocation */
        data = strdup(mystring);
        /* Use data */
        printLine(data);
    }
    break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        /* FIX: Allocate memory from the stack */
        char data_goodbuf[100];
        data = data_goodbuf;
        /* Initialize then use data */
        strcpy(data, "a string");
        printLine(data);
    }
    break;
    }
    switch(8)
    {
    case 7:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* POTENTIAL FLAW: No deallocation of memory */
        /* no deallocation */
        ; /* empty statement needed for some flow variants */
        break;
    default:
        /* FIX: Deallocate memory initialized in the source */
        free(data);
        break;
    }
}

/* goodB2G2() - use badsource and goodsink by reversing the blocks in the second switch */
static void goodB2G2()
{
    char * data;
    data = NULL;
    switch(6)
    {
    case 6:
    {
        char mystring[] = "mystring";
        /* FLAW: Allocate memory from the heap using a function that requires free() for deallocation */
        data = strdup(mystring);
        /* Use data */
        printLine(data);
    }
    break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        /* FIX: Allocate memory from the stack */
        char data_goodbuf[100];
        data = data_goodbuf;
        /* Initialize then use data */
        strcpy(data, "a string");
        printLine(data);
    }
    break;
    }
    switch(7)
    {
    case 7:
        /* FIX: Deallocate memory initialized in the source */
        free(data);
        break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* POTENTIAL FLAW: No deallocation of memory */
        /* no deallocation */
        ; /* empty statement needed for some flow variants */
        break;
    }
}

/* goodG2B1() - use goodsource and badsink by changing the first switch to switch(5) */
static void goodG2B1()
{
    char * data;
    data = NULL;
    switch(5)
    {
    case 6:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        char mystring[] = "mystring";
        /* FLAW: Allocate memory from the heap using a function that requires free() for deallocation */
        data = strdup(mystring);
        /* Use data */
        printLine(data);
    }
    break;
    default:
    {
        /* FIX: Allocate memory from the stack */
        char data_goodbuf[100];
        data = data_goodbuf;
        /* Initialize then use data */
        strcpy(data, "a string");
        printLine(data);
    }
    break;
    }
    switch(7)
    {
    case 7:
        /* POTENTIAL FLAW: No deallocation of memory */
        /* no deallocation */
        ; /* empty statement needed for some flow variants */
        break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Deallocate memory initialized in the source */
        free(data);
        break;
    }
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the first switch */
static void goodG2B2()
{
    char * data;
    data = NULL;
    switch(6)
    {
    case 6:
    {
        /* FIX: Allocate memory from the stack */
        char data_goodbuf[100];
        data = data_goodbuf;
        /* Initialize then use data */
        strcpy(data, "a string");
        printLine(data);
    }
    break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        char mystring[] = "mystring";
        /* FLAW: Allocate memory from the heap using a function that requires free() for deallocation */
        data = strdup(mystring);
        /* Use data */
        printLine(data);
    }
    break;
    }
    switch(7)
    {
    case 7:
        /* POTENTIAL FLAW: No deallocation of memory */
        /* no deallocation */
        ; /* empty statement needed for some flow variants */
        break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Deallocate memory initialized in the source */
        free(data);
        break;
    }
}

void CWE401_Memory_Leak__strdup_char_15_good()
{
    goodB2G1();
    goodB2G2();
    goodG2B1();
    goodG2B2();
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
    CWE401_Memory_Leak__strdup_char_15_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE401_Memory_Leak__strdup_char_15_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
