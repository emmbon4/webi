/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE467_Use_of_sizeof_on_Pointer_Type__struct_13.c
Label Definition File: CWE467_Use_of_sizeof_on_Pointer_Type.label.xml
Template File: sources-sink-13.tmpl.c
*/
/*
 * @description
 * CWE: 467 Use of sizeof() on a Pointer Type
 * BadSource:  Initialize the source buffer using the size of a pointer
 * GoodSource: Initialize the source buffer using the size of the DataElementType
 * Sink:
 *    BadSink : Print then free data
 * Flow Variant: 13 Control flow: if(global_const_five==5) and if(global_const_five!=5)
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE467_Use_of_sizeof_on_Pointer_Type__struct_13_bad()
{
    twoints * data;
    /* Initialize data */
    data = NULL;
    if(global_const_five==5)
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

/* goodG2B1() - use goodsource and badsink by changing the global_const_five==5 to global_const_five!=5 */
static void goodG2B1()
{
    twoints * data;
    /* Initialize data */
    data = NULL;
    if(global_const_five!=5)
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
    if(global_const_five==5)
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

void CWE467_Use_of_sizeof_on_Pointer_Type__struct_13_good()
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
    CWE467_Use_of_sizeof_on_Pointer_Type__struct_13_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE467_Use_of_sizeof_on_Pointer_Type__struct_13_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
