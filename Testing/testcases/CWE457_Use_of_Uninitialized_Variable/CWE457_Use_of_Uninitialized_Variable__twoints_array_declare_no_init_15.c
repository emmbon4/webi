/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE457_Use_of_Uninitialized_Variable__twoints_array_declare_no_init_15.c
Label Definition File: CWE457_Use_of_Uninitialized_Variable.c_array.label.xml
Template File: sources-sinks-15.tmpl.c
*/
/*
 * @description
 * CWE: 457 Use of Uninitialized Variable
 * BadSource: no_init Don't initialize data
 * GoodSource: Initialize data
 * Sinks: use
 *    GoodSink: Initialize then use data
 *    BadSink : Use data
 * Flow Variant: 15 Control flow: switch(6) and switch(7)
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE457_Use_of_Uninitialized_Variable__twoints_array_declare_no_init_15_bad()
{
    twoints * data;
    twoints data_uninit_array[10];
    data = data_uninit_array;
    switch(6)
    {
    case 6:
        /* Don't initialize data */
        ; /* empty statement needed for some flow variants */
        break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        int i;
        for(i=0; i<10; i++)
        {
            data[i].a = i;
            data[i].b = i;
        }
    }
    break;
    }
    switch(7)
    {
    case 7:
    {
        int i;
        for(i=0; i<10; i++)
        {
            printIntLine(data[i].a);
            printIntLine(data[i].b);
        }
    }
    break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        int i;
        for(i=0; i<10; i++)
        {
            data[i].a = i;
            data[i].b = i;
        }
    }
    {
        int i;
        for(i=0; i<10; i++)
        {
            printIntLine(data[i].a);
            printIntLine(data[i].b);
        }
    }
    break;
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G1() - use badsource and goodsink by changing the second switch to switch(8) */
static void goodB2G1()
{
    twoints * data;
    twoints data_uninit_array[10];
    data = data_uninit_array;
    switch(6)
    {
    case 6:
        /* Don't initialize data */
        ; /* empty statement needed for some flow variants */
        break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        int i;
        for(i=0; i<10; i++)
        {
            data[i].a = i;
            data[i].b = i;
        }
    }
    break;
    }
    switch(8)
    {
    case 7:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        int i;
        for(i=0; i<10; i++)
        {
            printIntLine(data[i].a);
            printIntLine(data[i].b);
        }
    }
    break;
    default:
    {
        int i;
        for(i=0; i<10; i++)
        {
            data[i].a = i;
            data[i].b = i;
        }
    }
    {
        int i;
        for(i=0; i<10; i++)
        {
            printIntLine(data[i].a);
            printIntLine(data[i].b);
        }
    }
    break;
    }
}

/* goodB2G2() - use badsource and goodsink by reversing the blocks in the second switch */
static void goodB2G2()
{
    twoints * data;
    twoints data_uninit_array[10];
    data = data_uninit_array;
    switch(6)
    {
    case 6:
        /* Don't initialize data */
        ; /* empty statement needed for some flow variants */
        break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        int i;
        for(i=0; i<10; i++)
        {
            data[i].a = i;
            data[i].b = i;
        }
    }
    break;
    }
    switch(7)
    {
    case 7:
    {
        int i;
        for(i=0; i<10; i++)
        {
            data[i].a = i;
            data[i].b = i;
        }
    }
    {
        int i;
        for(i=0; i<10; i++)
        {
            printIntLine(data[i].a);
            printIntLine(data[i].b);
        }
    }
    break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        int i;
        for(i=0; i<10; i++)
        {
            printIntLine(data[i].a);
            printIntLine(data[i].b);
        }
    }
    break;
    }
}

/* goodG2B1() - use goodsource and badsink by changing the first switch to switch(5) */
static void goodG2B1()
{
    twoints * data;
    twoints data_uninit_array[10];
    data = data_uninit_array;
    switch(5)
    {
    case 6:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* Don't initialize data */
        ; /* empty statement needed for some flow variants */
        break;
    default:
    {
        int i;
        for(i=0; i<10; i++)
        {
            data[i].a = i;
            data[i].b = i;
        }
    }
    break;
    }
    switch(7)
    {
    case 7:
    {
        int i;
        for(i=0; i<10; i++)
        {
            printIntLine(data[i].a);
            printIntLine(data[i].b);
        }
    }
    break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        int i;
        for(i=0; i<10; i++)
        {
            data[i].a = i;
            data[i].b = i;
        }
    }
    {
        int i;
        for(i=0; i<10; i++)
        {
            printIntLine(data[i].a);
            printIntLine(data[i].b);
        }
    }
    break;
    }
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the first switch */
static void goodG2B2()
{
    twoints * data;
    twoints data_uninit_array[10];
    data = data_uninit_array;
    switch(6)
    {
    case 6:
    {
        int i;
        for(i=0; i<10; i++)
        {
            data[i].a = i;
            data[i].b = i;
        }
    }
    break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* Don't initialize data */
        ; /* empty statement needed for some flow variants */
        break;
    }
    switch(7)
    {
    case 7:
    {
        int i;
        for(i=0; i<10; i++)
        {
            printIntLine(data[i].a);
            printIntLine(data[i].b);
        }
    }
    break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        int i;
        for(i=0; i<10; i++)
        {
            data[i].a = i;
            data[i].b = i;
        }
    }
    {
        int i;
        for(i=0; i<10; i++)
        {
            printIntLine(data[i].a);
            printIntLine(data[i].b);
        }
    }
    break;
    }
}

void CWE457_Use_of_Uninitialized_Variable__twoints_array_declare_no_init_15_good()
{
    goodB2G1();
    goodB2G2();
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
    CWE457_Use_of_Uninitialized_Variable__twoints_array_declare_no_init_15_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE457_Use_of_Uninitialized_Variable__twoints_array_declare_no_init_15_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
