/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE672_Operation_on_Resource_After_Expiration_or_Release__basic_02.cpp
Label Definition File: CWE672_Operation_on_Resource_After_Expiration_or_Release__basic.label.xml
Template File: sources-sinks-02.tmpl.cpp
*/
/*
 * @description
 * CWE: 672 Operation on Resource After Expiration or Release
 * BadSource:  Add values to the list, including the number zero
 * GoodSource: Add value to the list that are not zero
 * Sinks:
 *    GoodSink: Iterate through the list without attempting to clear its contents
 *    BadSink : Iterate through the list, but clear the list if it contains a zero
 * Flow Variant: 02 Control flow: if(1) and if(0)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#include <list>
#include <iostream>
using namespace std;

namespace CWE672_Operation_on_Resource_After_Expiration_or_Release__basic_02
{

#ifndef OMITBAD

void bad()
{
    list<int> data;
    if(1)
    {
        /* POTENTIAL FLAW: Insert a zero into the list */
        data.push_back(100);
        data.push_back(0);
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Insert non-zero values into the list */
        data.push_back(100);
        data.push_back(200);
    }
    if(1)
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
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
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
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G1() - use badsource and goodsink by changing the second 1 to 0 */
static void goodB2G1()
{
    list<int> data;
    if(1)
    {
        /* POTENTIAL FLAW: Insert a zero into the list */
        data.push_back(100);
        data.push_back(0);
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Insert non-zero values into the list */
        data.push_back(100);
        data.push_back(200);
    }
    if(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
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
    else
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
}

/* goodB2G2() - use badsource and goodsink by reversing the blocks in the second if */
static void goodB2G2()
{
    list<int> data;
    if(1)
    {
        /* POTENTIAL FLAW: Insert a zero into the list */
        data.push_back(100);
        data.push_back(0);
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Insert non-zero values into the list */
        data.push_back(100);
        data.push_back(200);
    }
    if(1)
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
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
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
}

/* goodG2B1() - use goodsource and badsink by changing the first 1 to 0 */
static void goodG2B1()
{
    list<int> data;
    if(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* POTENTIAL FLAW: Insert a zero into the list */
        data.push_back(100);
        data.push_back(0);
    }
    else
    {
        /* FIX: Insert non-zero values into the list */
        data.push_back(100);
        data.push_back(200);
    }
    if(1)
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
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
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
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the first if */
static void goodG2B2()
{
    list<int> data;
    if(1)
    {
        /* FIX: Insert non-zero values into the list */
        data.push_back(100);
        data.push_back(200);
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* POTENTIAL FLAW: Insert a zero into the list */
        data.push_back(100);
        data.push_back(0);
    }
    if(1)
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
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
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

using namespace CWE672_Operation_on_Resource_After_Expiration_or_Release__basic_02; // so that we can use good and bad easily

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
