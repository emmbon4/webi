/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE467_Use_of_sizeof_on_Pointer_Type__struct_11.c
Label Definition File: CWE467_Use_of_sizeof_on_Pointer_Type.label.xml
Template File: sources-sink-11.tmpl.c
*/
/*
 * @description
 * CWE: 467 Use of sizeof() on a Pointer Type
 * BadSource:  Initialize the source buffer using the size of a pointer
 * GoodSource: Initialize the source buffer using the size of the DataElementType
 * Sink:
 *    BadSink : Print then free data
 * Flow Variant: 11 Control flow: if(global_returns_t()) and if(global_returns_f())
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE467_Use_of_sizeof_on_Pointer_Type__struct_11_bad()
{
    twoints * data;
    /* Initialize data */
    data = NULL;
    if(global_returns_t())
    {
        /* FLAW: Using sizeof the pointer and not the data type in malloc() */
        data = (twoints *)malloc(sizeof(data));
        data->a = 1;
        data->b = 2;
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Using sizeof the data type in malloc() */
        data = (twoints *)malloc(sizeof(*data));
        data->a = 1;
        data->b = 2;
    }
    /* POTENTIAL FLAW: Attempt to use data, which may not have enough memory allocated */
    printStructLine(data);
    free(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B1() - use goodsource and badsink by changing the global_returns_t() to global_returns_f() */
static void goodG2B1()
{
    twoints * data;
    /* Initialize data */
    data = NULL;
    if(global_returns_f())
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FLAW: Using sizeof the pointer and not the data type in malloc() */
        data = (twoints *)malloc(sizeof(data));
        data->a = 1;
        data->b = 2;
    }
    else
    {
        /* FIX: Using sizeof the data type in malloc() */
        data = (twoints *)malloc(sizeof(*data));
        data->a = 1;
        data->b = 2;
    }
    /* POTENTIAL FLAW: Attempt to use data, which may not have enough memory allocated */
    printStructLine(data);
    free(data);
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the if statement */
static void goodG2B2()
{
    twoints * data;
    /* Initialize data */
    data = NULL;
    if(global_returns_t())
    {
        /* FIX: Using sizeof the data type in malloc() */
        data = (twoints *)malloc(sizeof(*data));
        data->a = 1;
        data->b = 2;
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FLAW: Using sizeof the pointer and not the data type in malloc() */
        data = (twoints *)malloc(sizeof(data));
        data->a = 1;
        data->b = 2;
    }
    /* POTENTIAL FLAW: Attempt to use data, which may not have enough memory allocated */
    printStructLine(data);
    free(data);
}

void CWE467_Use_of_sizeof_on_Pointer_Type__struct_11_good()
{
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
    CWE467_Use_of_sizeof_on_Pointer_Type__struct_11_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE467_Use_of_sizeof_on_Pointer_Type__struct_11_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
