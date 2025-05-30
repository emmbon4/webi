/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__new_delete_array_char_11.cpp
Label Definition File: CWE415_Double_Free__new_delete_array.label.xml
Template File: sources-sinks-11.tmpl.cpp
*/
/*
 * @description
 * CWE: 415 Double Free
 * BadSource:  Allocate data using new and Deallocae data using delete
 * GoodSource: Allocate data using new
 * Sinks:
 *    GoodSink: do nothing
 *    BadSink : Deallocate data using delete
 * Flow Variant: 11 Control flow: if(global_returns_t()) and if(global_returns_f())
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE415_Double_Free__new_delete_array_char_11
{

#ifndef OMITBAD

void bad()
{
    char * data;
    /* Initialize data */
    data = NULL;
    if(global_returns_t())
    {
        data = new char[100];
        /* POTENTIAL FLAW: delete the array data in the source - the bad sink deletes the array data as well */
        delete [] data;
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        data = new char[100];
        /* FIX: Do NOT delete the array data in the source - the bad sink deletes the array data */
    }
    if(global_returns_t())
    {
        /* POTENTIAL FLAW: Possibly deleting memory twice */
        delete [] data;
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* do nothing */
        /* FIX: Don't attempt to delete the memory */
        ; /* empty statement needed for some flow variants */
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G1() - use badsource and goodsink by changing the second global_returns_t() to global_returns_f() */
static void goodB2G1()
{
    char * data;
    /* Initialize data */
    data = NULL;
    if(global_returns_t())
    {
        data = new char[100];
        /* POTENTIAL FLAW: delete the array data in the source - the bad sink deletes the array data as well */
        delete [] data;
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        data = new char[100];
        /* FIX: Do NOT delete the array data in the source - the bad sink deletes the array data */
    }
    if(global_returns_f())
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* POTENTIAL FLAW: Possibly deleting memory twice */
        delete [] data;
    }
    else
    {
        /* do nothing */
        /* FIX: Don't attempt to delete the memory */
        ; /* empty statement needed for some flow variants */
    }
}

/* goodB2G2() - use badsource and goodsink by reversing the blocks in the second if */
static void goodB2G2()
{
    char * data;
    /* Initialize data */
    data = NULL;
    if(global_returns_t())
    {
        data = new char[100];
        /* POTENTIAL FLAW: delete the array data in the source - the bad sink deletes the array data as well */
        delete [] data;
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        data = new char[100];
        /* FIX: Do NOT delete the array data in the source - the bad sink deletes the array data */
    }
    if(global_returns_t())
    {
        /* do nothing */
        /* FIX: Don't attempt to delete the memory */
        ; /* empty statement needed for some flow variants */
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* POTENTIAL FLAW: Possibly deleting memory twice */
        delete [] data;
    }
}

/* goodG2B1() - use goodsource and badsink by changing the first global_returns_t() to global_returns_f() */
static void goodG2B1()
{
    char * data;
    /* Initialize data */
    data = NULL;
    if(global_returns_f())
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        data = new char[100];
        /* POTENTIAL FLAW: delete the array data in the source - the bad sink deletes the array data as well */
        delete [] data;
    }
    else
    {
        data = new char[100];
        /* FIX: Do NOT delete the array data in the source - the bad sink deletes the array data */
    }
    if(global_returns_t())
    {
        /* POTENTIAL FLAW: Possibly deleting memory twice */
        delete [] data;
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* do nothing */
        /* FIX: Don't attempt to delete the memory */
        ; /* empty statement needed for some flow variants */
    }
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the first if */
static void goodG2B2()
{
    char * data;
    /* Initialize data */
    data = NULL;
    if(global_returns_t())
    {
        data = new char[100];
        /* FIX: Do NOT delete the array data in the source - the bad sink deletes the array data */
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        data = new char[100];
        /* POTENTIAL FLAW: delete the array data in the source - the bad sink deletes the array data as well */
        delete [] data;
    }
    if(global_returns_t())
    {
        /* POTENTIAL FLAW: Possibly deleting memory twice */
        delete [] data;
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* do nothing */
        /* FIX: Don't attempt to delete the memory */
        ; /* empty statement needed for some flow variants */
    }
}

void good()
{
    goodB2G1();
    goodB2G2();
    goodG2B1();
    goodG2B2();
}

#endif /* OMITGOOD */

} // close namespace

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE415_Double_Free__new_delete_array_char_11; // so that we can use good and bad easily

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
