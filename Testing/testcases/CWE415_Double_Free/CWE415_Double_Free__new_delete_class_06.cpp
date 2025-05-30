/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__new_delete_class_06.cpp
Label Definition File: CWE415_Double_Free__new_delete.label.xml
Template File: sources-sinks-06.tmpl.cpp
*/
/*
 * @description
 * CWE: 415 Double Free
 * BadSource:  Allocate data using new and Deallocae data using delete
 * GoodSource: Allocate data using new
 * Sinks:
 *    GoodSink: do nothing
 *    BadSink : Deallocate data using delete
 * Flow Variant: 06 Control flow: if(static_const_five==5) and if(static_const_five!=5)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

/* The variable below is declared "const", so a tool should be able
   to identify that reads of this will always give its initialized
   value. */
static const int static_const_five = 5;

namespace CWE415_Double_Free__new_delete_class_06
{

#ifndef OMITBAD

void bad()
{
    twointsclass * data;
    /* Initialize data */
    data = NULL;
    if(static_const_five==5)
    {
        data = new twointsclass;
        /* POTENTIAL FLAW: delete data in the source - the bad sink deletes data as well */
        delete data;
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        data = new twointsclass;
        /* FIX: Do NOT delete data in the source - the bad sink deletes data */
    }
    if(static_const_five==5)
    {
        /* POTENTIAL FLAW: Possibly deleting memory twice */
        delete data;
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

/* goodB2G1() - use badsource and goodsink by changing the second static_const_five==5 to static_const_five!=5 */
static void goodB2G1()
{
    twointsclass * data;
    /* Initialize data */
    data = NULL;
    if(static_const_five==5)
    {
        data = new twointsclass;
        /* POTENTIAL FLAW: delete data in the source - the bad sink deletes data as well */
        delete data;
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        data = new twointsclass;
        /* FIX: Do NOT delete data in the source - the bad sink deletes data */
    }
    if(static_const_five!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* POTENTIAL FLAW: Possibly deleting memory twice */
        delete data;
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
    twointsclass * data;
    /* Initialize data */
    data = NULL;
    if(static_const_five==5)
    {
        data = new twointsclass;
        /* POTENTIAL FLAW: delete data in the source - the bad sink deletes data as well */
        delete data;
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        data = new twointsclass;
        /* FIX: Do NOT delete data in the source - the bad sink deletes data */
    }
    if(static_const_five==5)
    {
        /* do nothing */
        /* FIX: Don't attempt to delete the memory */
        ; /* empty statement needed for some flow variants */
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* POTENTIAL FLAW: Possibly deleting memory twice */
        delete data;
    }
}

/* goodG2B1() - use goodsource and badsink by changing the first static_const_five==5 to static_const_five!=5 */
static void goodG2B1()
{
    twointsclass * data;
    /* Initialize data */
    data = NULL;
    if(static_const_five!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        data = new twointsclass;
        /* POTENTIAL FLAW: delete data in the source - the bad sink deletes data as well */
        delete data;
    }
    else
    {
        data = new twointsclass;
        /* FIX: Do NOT delete data in the source - the bad sink deletes data */
    }
    if(static_const_five==5)
    {
        /* POTENTIAL FLAW: Possibly deleting memory twice */
        delete data;
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
    twointsclass * data;
    /* Initialize data */
    data = NULL;
    if(static_const_five==5)
    {
        data = new twointsclass;
        /* FIX: Do NOT delete data in the source - the bad sink deletes data */
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        data = new twointsclass;
        /* POTENTIAL FLAW: delete data in the source - the bad sink deletes data as well */
        delete data;
    }
    if(static_const_five==5)
    {
        /* POTENTIAL FLAW: Possibly deleting memory twice */
        delete data;
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

using namespace CWE415_Double_Free__new_delete_class_06; // so that we can use good and bad easily

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
