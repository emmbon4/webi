/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE416_Use_After_Free__new_delete_char_34.cpp
Label Definition File: CWE416_Use_After_Free__new_delete.label.xml
Template File: sources-sinks-34.tmpl.cpp
*/
/*
 * @description
 * CWE: 416 Use After Free
 * BadSource:  Allocate data using new, initialize memory block, and Deallocate data using delete
 * GoodSource: Allocate data using new and initialize memory block
 * Sinks:
 *    GoodSink: Do nothing
 *    BadSink : Use data after free()
 * Flow Variant: 34 Data flow: use of a union containing two methods of accessing the same data (within the same function)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE416_Use_After_Free__new_delete_char_34
{

typedef union
{
    char * a;
    char * b;
} union_type;

#ifndef OMITBAD

void bad()
{
    char * data;
    union_type my_union;
    /* Initialize data */
    data = NULL;
    data = new char;
    *data = 'A';
    /* POTENTIAL FLAW: Delete data in the source - the bad sink attempts to use data */
    delete data;
    my_union.a = data;
    {
        char * data = my_union.b;
        /* POTENTIAL FLAW - Use of data that may have been deleted */
        printf("%c\n", *data);
        /* POTENTIAL INCIDENTAL - Possible memory leak here if data was not deleted */
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    char * data;
    union_type my_union;
    /* Initialize data */
    data = NULL;
    data = new char;
    *data = 'A';
    /* FIX: Do not delete data in the source */
    my_union.a = data;
    {
        char * data = my_union.b;
        /* POTENTIAL FLAW - Use of data that may have been deleted */
        printf("%c\n", *data);
        /* POTENTIAL INCIDENTAL - Possible memory leak here if data was not deleted */
    }
}

/* goodB2G() uses the BadSource with the GoodSink */
static void goodB2G()
{
    char * data;
    union_type my_union;
    /* Initialize data */
    data = NULL;
    data = new char;
    *data = 'A';
    /* POTENTIAL FLAW: Delete data in the source - the bad sink attempts to use data */
    delete data;
    my_union.a = data;
    {
        char * data = my_union.b;
        /* FIX - Don't use data that may have been deleted already */
        /* POTENTIAL INCIDENTAL - Possible memory leak here if data was not deleted */
        /* do nothing */
        ; /* empty statement needed for some flow variants */
    }
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

using namespace CWE416_Use_After_Free__new_delete_char_34; // so that we can use good and bad easily

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
