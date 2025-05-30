/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE476_NULL_Pointer_Dereference__int_34.c
Label Definition File: CWE476_NULL_Pointer_Dereference.label.xml
Template File: sources-sink-34.tmpl.c
*/
/*
 * @description
 * CWE: 476 NULL Pointer Dereference
 * BadSource:  Set data to NULL
 * GoodSource: Initialize data
 * Sinks:
 *    BadSink : Print data
 * Flow Variant: 34 Data flow: use of a union containing two methods of accessing the same data (within the same function)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

typedef union
{
    int * a;
    int * b;
} CWE476_NULL_Pointer_Dereference__int_34_union_type;

#ifndef OMITBAD

void CWE476_NULL_Pointer_Dereference__int_34_bad()
{
    int * data;
    CWE476_NULL_Pointer_Dereference__int_34_union_type my_union;
    /* Initialize data */
    data = NULL;
    /* FLAW: Set data to NULL - it will be used in the sink */
    data = NULL;
    my_union.a = data;
    {
        int * data = my_union.b;
        /* POTENTIAL FLAW: Attempt to use data, which may be NULL */
        printIntLine(*data);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    int * data;
    CWE476_NULL_Pointer_Dereference__int_34_union_type my_union;
    /* Initialize data */
    data = NULL;
    /* FIX: Initialize data - it will be used in the sink */
    {
        int tmp = 5;
        data = &tmp;
    }
    my_union.a = data;
    {
        int * data = my_union.b;
        /* POTENTIAL FLAW: Attempt to use data, which may be NULL */
        printIntLine(*data);
    }
}

void CWE476_NULL_Pointer_Dereference__int_34_good()
{
    goodG2B();
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
    CWE476_NULL_Pointer_Dereference__int_34_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE476_NULL_Pointer_Dereference__int_34_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
