/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE416_Use_After_Free__new_delete_array_wchar_t_03.cpp
Label Definition File: CWE416_Use_After_Free__new_delete_array.label.xml
Template File: sources-sinks-03.tmpl.cpp
*/
/*
 * @description
 * CWE: 416 Use After Free
 * BadSource:  Allocate data using new, initialize memory block, and Deallocate data using delete
 * GoodSource: Allocate data using new and initialize memory block
 * Sinks:
 *    GoodSink: Do nothing
 *    BadSink : Use data after free()
 * Flow Variant: 03 Control flow: if(5==5) and if(5!=5)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE416_Use_After_Free__new_delete_array_wchar_t_03
{

#ifndef OMITBAD

void bad()
{
    wchar_t * data;
    /* Initialize data */
    data = NULL;
    if(5==5)
    {
        data = new wchar_t[100];
        wmemset(data, L'A', 100-1);
        data[100-1] = L'\0';
        /* POTENTIAL FLAW: Delete data in the source - the bad sink attempts to use data */
        delete [] data;
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        data = new wchar_t[100];
        wmemset(data, L'A', 100-1);
        data[100-1] = L'\0';
        /* FIX: Do not delete data in the source */
    }
    if(5==5)
    {
        /* POTENTIAL FLAW - Use of data that may have been deleted */
        printWLine(data);
        /* POTENTIAL INCIDENTAL - Possible memory leak here if data was not deleted */
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX - Don't use data that may have been deleted already */
        /* POTENTIAL INCIDENTAL - Possible memory leak here if data was not deleted */
        /* do nothing */
        ; /* empty statement needed for some flow variants */
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G1() - use badsource and goodsink by changing the second 5==5 to 5!=5 */
static void goodB2G1()
{
    wchar_t * data;
    /* Initialize data */
    data = NULL;
    if(5==5)
    {
        data = new wchar_t[100];
        wmemset(data, L'A', 100-1);
        data[100-1] = L'\0';
        /* POTENTIAL FLAW: Delete data in the source - the bad sink attempts to use data */
        delete [] data;
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        data = new wchar_t[100];
        wmemset(data, L'A', 100-1);
        data[100-1] = L'\0';
        /* FIX: Do not delete data in the source */
    }
    if(5!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* POTENTIAL FLAW - Use of data that may have been deleted */
        printWLine(data);
        /* POTENTIAL INCIDENTAL - Possible memory leak here if data was not deleted */
    }
    else
    {
        /* FIX - Don't use data that may have been deleted already */
        /* POTENTIAL INCIDENTAL - Possible memory leak here if data was not deleted */
        /* do nothing */
        ; /* empty statement needed for some flow variants */
    }
}

/* goodB2G2() - use badsource and goodsink by reversing the blocks in the second if */
static void goodB2G2()
{
    wchar_t * data;
    /* Initialize data */
    data = NULL;
    if(5==5)
    {
        data = new wchar_t[100];
        wmemset(data, L'A', 100-1);
        data[100-1] = L'\0';
        /* POTENTIAL FLAW: Delete data in the source - the bad sink attempts to use data */
        delete [] data;
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        data = new wchar_t[100];
        wmemset(data, L'A', 100-1);
        data[100-1] = L'\0';
        /* FIX: Do not delete data in the source */
    }
    if(5==5)
    {
        /* FIX - Don't use data that may have been deleted already */
        /* POTENTIAL INCIDENTAL - Possible memory leak here if data was not deleted */
        /* do nothing */
        ; /* empty statement needed for some flow variants */
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* POTENTIAL FLAW - Use of data that may have been deleted */
        printWLine(data);
        /* POTENTIAL INCIDENTAL - Possible memory leak here if data was not deleted */
    }
}

/* goodG2B1() - use goodsource and badsink by changing the first 5==5 to 5!=5 */
static void goodG2B1()
{
    wchar_t * data;
    /* Initialize data */
    data = NULL;
    if(5!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        data = new wchar_t[100];
        wmemset(data, L'A', 100-1);
        data[100-1] = L'\0';
        /* POTENTIAL FLAW: Delete data in the source - the bad sink attempts to use data */
        delete [] data;
    }
    else
    {
        data = new wchar_t[100];
        wmemset(data, L'A', 100-1);
        data[100-1] = L'\0';
        /* FIX: Do not delete data in the source */
    }
    if(5==5)
    {
        /* POTENTIAL FLAW - Use of data that may have been deleted */
        printWLine(data);
        /* POTENTIAL INCIDENTAL - Possible memory leak here if data was not deleted */
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX - Don't use data that may have been deleted already */
        /* POTENTIAL INCIDENTAL - Possible memory leak here if data was not deleted */
        /* do nothing */
        ; /* empty statement needed for some flow variants */
    }
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the first if */
static void goodG2B2()
{
    wchar_t * data;
    /* Initialize data */
    data = NULL;
    if(5==5)
    {
        data = new wchar_t[100];
        wmemset(data, L'A', 100-1);
        data[100-1] = L'\0';
        /* FIX: Do not delete data in the source */
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        data = new wchar_t[100];
        wmemset(data, L'A', 100-1);
        data[100-1] = L'\0';
        /* POTENTIAL FLAW: Delete data in the source - the bad sink attempts to use data */
        delete [] data;
    }
    if(5==5)
    {
        /* POTENTIAL FLAW - Use of data that may have been deleted */
        printWLine(data);
        /* POTENTIAL INCIDENTAL - Possible memory leak here if data was not deleted */
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX - Don't use data that may have been deleted already */
        /* POTENTIAL INCIDENTAL - Possible memory leak here if data was not deleted */
        /* do nothing */
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

using namespace CWE416_Use_After_Free__new_delete_array_wchar_t_03; // so that we can use good and bad easily

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
