/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE374_Passing_Mutable_Objects_to_Untrusted_Method__basic_08.cpp
Label Definition File: CWE374_Passing_Mutable_Objects_to_Untrusted_Method__basic.label.xml
Template File: point-flaw-08.tmpl.cpp
*/
/*
 * @description
 * CWE: 374 Passing Mutable Objects to an Untrusted Method
 * Sinks:
 *    GoodSink: Pass a string by value to a helper function to prevent the string from being modified
 *    BadSink : Pass a string by reference to a helper function that may modify the string
 * Flow Variant: 08 Control flow: if(static_returns_t()) and if(static_returns_f())
 *
 * */

#include "std_testcase.h"

#include <iostream>
#include <string>
using namespace std;

static void helper_bad(string &aString)
{
    /* This will modify the string being passed to the function, as it is passed by reference */
    aString.append(" was modified");
}

static void helper_good(string aString)
{
    /* This will NOT modify the string being passed to the function, as it is passed by value */
    aString.append(" was modified");
}

/* The two function below always return the same value, so a tool
   should be able to identify that calls to the functions will always
   return a fixed value. */
static int static_returns_t()
{
    return 1;
}

static int static_returns_f()
{
    return 0;
}

namespace CWE374_Passing_Mutable_Objects_to_Untrusted_Method__basic_08
{

#ifndef OMITBAD

void bad()
{
    if(static_returns_t())
    {
        {
            string myString("String");
            /* FLAW: Passing myString by reference allows you to modify the string */
            helper_bad(myString);
            cout << "myString after call to helper function: " << myString << endl;
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            string myString("String");
            /* FIX: Passing myString by value does not allow you to modify the string */
            helper_good(myString);
            cout << "myString after call to helper function: " << myString << endl;
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() uses if(static_returns_f()) instead of if(static_returns_t()) */
static void good1()
{
    if(static_returns_f())
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            string myString("String");
            /* FLAW: Passing myString by reference allows you to modify the string */
            helper_bad(myString);
            cout << "myString after call to helper function: " << myString << endl;
        }
    }
    else
    {
        {
            string myString("String");
            /* FIX: Passing myString by value does not allow you to modify the string */
            helper_good(myString);
            cout << "myString after call to helper function: " << myString << endl;
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(static_returns_t())
    {
        {
            string myString("String");
            /* FIX: Passing myString by value does not allow you to modify the string */
            helper_good(myString);
            cout << "myString after call to helper function: " << myString << endl;
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            string myString("String");
            /* FLAW: Passing myString by reference allows you to modify the string */
            helper_bad(myString);
            cout << "myString after call to helper function: " << myString << endl;
        }
    }
}

void good()
{
    good1();
    good2();
}

#endif /* OMITGOOD */

} // close namespace

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE374_Passing_Mutable_Objects_to_Untrusted_Method__basic_08; // so that we can use good and bad easily

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
