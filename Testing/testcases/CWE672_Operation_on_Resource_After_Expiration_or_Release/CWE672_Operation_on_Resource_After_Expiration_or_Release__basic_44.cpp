/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE672_Operation_on_Resource_After_Expiration_or_Release__basic_44.cpp
Label Definition File: CWE672_Operation_on_Resource_After_Expiration_or_Release__basic.label.xml
Template File: sources-sinks-44.tmpl.cpp
*/
/*
 * @description
 * CWE: 672 Operation on Resource After Expiration or Release
 * BadSource:  Add values to the list, including the number zero
 * GoodSource: Add value to the list that are not zero
 * Sinks:
 *    GoodSink: Iterate through the list without attempting to clear its contents
 *    BadSink : Iterate through the list, but clear the list if it contains a zero
 * Flow Variant: 44 Data/control flow: data passed as an argument from one function to a function in the same source file called via a function pointer
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#include <list>
#include <iostream>
using namespace std;

namespace CWE672_Operation_on_Resource_After_Expiration_or_Release__basic_44
{

#ifndef OMITBAD

static void bad_sink(list<int> data)
{
    {
        list<int>::iterator i;
        cout << "The list contains: ";
        for( i = data.begin(); i != data.end(); i++)
        {
            if (!*i)
            {
                data.clear();
            }
            /* POTENTIAL FLAW: Dereference the iterator, which may be invalid if data is cleared */
            cout << " " << *i;
        }
        cout << endl;
    }
}

void bad()
{
    list<int> data;
    /* define a function pointer */
    void (*func_ptr) (list<int>) = bad_sink;
    /* POTENTIAL FLAW: Insert a zero into the list */
    data.push_back(100);
    data.push_back(0);
    /* use the function pointer */
    func_ptr(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B_sink(list<int> data)
{
    {
        list<int>::iterator i;
        cout << "The list contains: ";
        for( i = data.begin(); i != data.end(); i++)
        {
            if (!*i)
            {
                data.clear();
            }
            /* POTENTIAL FLAW: Dereference the iterator, which may be invalid if data is cleared */
            cout << " " << *i;
        }
        cout << endl;
    }
}

static void goodG2B()
{
    list<int> data;
    void (*func_ptr) (list<int>) = goodG2B_sink;
    /* FIX: Insert non-zero values into the list */
    data.push_back(100);
    data.push_back(200);
    func_ptr(data);
}

/* goodB2G() uses the BadSource with the GoodSink */
static void goodB2G_sink(list<int> data)
{
    {
        list<int>::iterator i;
        cout << "The list contains: ";
        for( i = data.begin(); i != data.end(); i++)
        {
            /* FIX: Do not make any attempt to clear the list */
            cout << " " << *i;
        }
        cout << endl;
    }
}

static void goodB2G()
{
    list<int> data;
    void (*func_ptr) (list<int>) = goodB2G_sink;
    /* POTENTIAL FLAW: Insert a zero into the list */
    data.push_back(100);
    data.push_back(0);
    func_ptr(data);
}

void good()
{
    goodG2B();
    goodB2G();
}

#endif /* OMITGOOD */

} // close namespace

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE672_Operation_on_Resource_After_Expiration_or_Release__basic_44; // so that we can use good and bad easily

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
