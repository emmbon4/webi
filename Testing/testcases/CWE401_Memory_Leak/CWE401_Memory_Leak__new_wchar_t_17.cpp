/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__new_wchar_t_17.cpp
Label Definition File: CWE401_Memory_Leak__new.label.xml
Template File: sources-sinks-17.tmpl.cpp
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource:  Allocate data using new
 * GoodSource: Allocate data on the stack
 * Sinks:
 *    GoodSink: call delete on data
 *    BadSink : no deallocation of data
 * Flow Variant: 17 Control flow: for loops
 * */

#include "std_testcase.h"

namespace CWE401_Memory_Leak__new_wchar_t_17
{

#ifndef OMITBAD

void bad()
{
    int h,i,j,k;
    wchar_t * data;
    data = NULL;
    for(h = 0; h < 0; h++)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Use memory allocated on the stack */
        wchar_t data_good;
        data = &data_good;
        /* Initialize and make use of data */
        *data = L'A';
        printHexCharLine((char)*data);
    }
    for(i = 0; i < 1; i++)
    {
        /* POTENTIAL FLAW: Allocate memory on the heap */
        data = new wchar_t;
        /* Initialize and make use of data */
        *data = L'A';
        printHexCharLine((char)*data);
    }
    for(j = 0; j < 1; j++)
    {
        /* POTENTIAL FLAW: No deallocation */
        ; /* empty statement needed for some flow variants */
    }
    for(k = 0; k < 0; k++)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Deallocate memory */
        delete data;
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G() - use badsource and goodsink by changing the conditions on the third and fourth for statements */
static void goodB2G()
{
    int h,i,j,k;
    wchar_t * data;
    data = NULL;
    for(h = 0; h < 0; h++)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Use memory allocated on the stack */
        wchar_t data_good;
        data = &data_good;
        /* Initialize and make use of data */
        *data = L'A';
        printHexCharLine((char)*data);
    }
    for(i = 0; i < 1; i++)
    {
        /* POTENTIAL FLAW: Allocate memory on the heap */
        data = new wchar_t;
        /* Initialize and make use of data */
        *data = L'A';
        printHexCharLine((char)*data);
    }
    for(j = 0; j < 0; j++)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* POTENTIAL FLAW: No deallocation */
        ; /* empty statement needed for some flow variants */
    }
    for(k = 0; k < 1; k++)
    {
        /* FIX: Deallocate memory */
        delete data;
    }
}

/* goodG2B() - use goodsource and badsink by changing the conditions on the first and second for statements */
static void goodG2B()
{
    int h,i,j,k;
    wchar_t * data;
    data = NULL;
    for(h = 0; h < 1; h++)
    {
        /* FIX: Use memory allocated on the stack */
        wchar_t data_good;
        data = &data_good;
        /* Initialize and make use of data */
        *data = L'A';
        printHexCharLine((char)*data);
    }
    for(i = 0; i < 0; i++)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* POTENTIAL FLAW: Allocate memory on the heap */
        data = new wchar_t;
        /* Initialize and make use of data */
        *data = L'A';
        printHexCharLine((char)*data);
    }
    for(j = 0; j < 1; j++)
    {
        /* POTENTIAL FLAW: No deallocation */
        ; /* empty statement needed for some flow variants */
    }
    for(k = 0; k < 0; k++)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Deallocate memory */
        delete data;
    }
}

void good()
{
    goodB2G();
    goodG2B();
}

#endif /* OMITGOOD */

} // close namespace

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE401_Memory_Leak__new_wchar_t_17; // so that we can use good and bad easily

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
