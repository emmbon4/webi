/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE588_Attempt_To_Access_Child_Of_A_Non_Structure_Pointer__basic_09.c
Label Definition File: CWE588_Attempt_To_Access_Child_Of_A_Non_Structure_Pointer__basic.label.xml
Template File: sources-sink-09.tmpl.c
*/
/*
 * @description
 * CWE: 588 Attempt to Access Child of a Non Structure Type
 * BadSource:  Void pointer to an int
 * GoodSource: Void pointer to a twoints struct
 * Sink:
 *    BadSink : Print data
 * Flow Variant: 09 Control flow: if(global_const_t) and if(global_const_f)
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE588_Attempt_To_Access_Child_Of_A_Non_Structure_Pointer__basic_09_bad()
{
    void * data;
    twoints data_goodbuf;
    int data_badbuf = 100;
    data_goodbuf.a = 0;
    data_goodbuf.b = 0;
    if(global_const_t)
    {
        /* FLAW: Set data to point to an int */
        data = &data_badbuf;
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Set data to point to a twoints struct */
        data = &data_goodbuf;
    }
    /* POTENTIAL FLAW: Attempt to print a struct when data may be a non-struct data type */
    printStructLine((twoints *)data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B1() - use goodsource and badsink by changing the global_const_t to global_const_f */
static void goodG2B1()
{
    void * data;
    twoints data_goodbuf;
    int data_badbuf = 100;
    data_goodbuf.a = 0;
    data_goodbuf.b = 0;
    if(global_const_f)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FLAW: Set data to point to an int */
        data = &data_badbuf;
    }
    else
    {
        /* FIX: Set data to point to a twoints struct */
        data = &data_goodbuf;
    }
    /* POTENTIAL FLAW: Attempt to print a struct when data may be a non-struct data type */
    printStructLine((twoints *)data);
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the if statement */
static void goodG2B2()
{
    void * data;
    twoints data_goodbuf;
    int data_badbuf = 100;
    data_goodbuf.a = 0;
    data_goodbuf.b = 0;
    if(global_const_t)
    {
        /* FIX: Set data to point to a twoints struct */
        data = &data_goodbuf;
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FLAW: Set data to point to an int */
        data = &data_badbuf;
    }
    /* POTENTIAL FLAW: Attempt to print a struct when data may be a non-struct data type */
    printStructLine((twoints *)data);
}

void CWE588_Attempt_To_Access_Child_Of_A_Non_Structure_Pointer__basic_09_good()
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
    CWE588_Attempt_To_Access_Child_Of_A_Non_Structure_Pointer__basic_09_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE588_Attempt_To_Access_Child_Of_A_Non_Structure_Pointer__basic_09_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
