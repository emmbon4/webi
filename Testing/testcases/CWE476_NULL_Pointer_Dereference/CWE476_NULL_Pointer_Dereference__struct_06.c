/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE476_NULL_Pointer_Dereference__struct_06.c
Label Definition File: CWE476_NULL_Pointer_Dereference.label.xml
Template File: sources-sink-06.tmpl.c
*/
/*
 * @description
 * CWE: 476 NULL Pointer Dereference
 * BadSource:  Set data to NULL
 * GoodSource: Initialize data
 * Sink:
 *    BadSink : Print data
 * Flow Variant: 06 Control flow: if(static_const_five==5) and if(static_const_five!=5)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

/* The variable below is declared "const", so a tool should be able
   to identify that reads of this will always give its initialized
   value. */
static const int static_const_five = 5;

#ifndef OMITBAD

void CWE476_NULL_Pointer_Dereference__struct_06_bad()
{
    twoints * data;
    /* Initialize data */
    data = NULL;
    if(static_const_five==5)
    {
        /* FLAW: Set data to NULL - it will be used in the sink */
        data = NULL;
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Initialize data - it will be used in the sink */
        {
            twoints tmp;
            tmp.a = 0;
            tmp.b = 0;
            data = &tmp;
        }
    }
    /* POTENTIAL FLAW: Attempt to use data, which may be NULL */
    printStructLine(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B1() - use goodsource and badsink by changing the static_const_five==5 to static_const_five!=5 */
static void goodG2B1()
{
    twoints * data;
    /* Initialize data */
    data = NULL;
    if(static_const_five!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FLAW: Set data to NULL - it will be used in the sink */
        data = NULL;
    }
    else
    {
        /* FIX: Initialize data - it will be used in the sink */
        {
            twoints tmp;
            tmp.a = 0;
            tmp.b = 0;
            data = &tmp;
        }
    }
    /* POTENTIAL FLAW: Attempt to use data, which may be NULL */
    printStructLine(data);
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the if statement */
static void goodG2B2()
{
    twoints * data;
    /* Initialize data */
    data = NULL;
    if(static_const_five==5)
    {
        /* FIX: Initialize data - it will be used in the sink */
        {
            twoints tmp;
            tmp.a = 0;
            tmp.b = 0;
            data = &tmp;
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FLAW: Set data to NULL - it will be used in the sink */
        data = NULL;
    }
    /* POTENTIAL FLAW: Attempt to use data, which may be NULL */
    printStructLine(data);
}

void CWE476_NULL_Pointer_Dereference__struct_06_good()
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
    CWE476_NULL_Pointer_Dereference__struct_06_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE476_NULL_Pointer_Dereference__struct_06_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
