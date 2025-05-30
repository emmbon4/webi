/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE129_Improper_Validation_Of_Array_Index__rand_int_16.c
Label Definition File: CWE129_Improper_Validation_Of_Array_Index.label.xml
Template File: sources-sinks-16.tmpl.c
*/
/*
 * @description
 * CWE: 129 Improper Validation of Array Index
 * BadSource: rand Set data to result of rand(), which may be zero
 * GoodSource: Larger than zero but less than 10
 * Sinks: int
 *    GoodSink: Ensure the array index is valid
 *    BadSink : Improperly check the array index by not checking the upper bound
 * Flow Variant: 16 Control flow: while(1) and while(0)
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE129_Improper_Validation_Of_Array_Index__rand_int_16_bad()
{
    int data;
    data = -1; /* Initialize data */
    while(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Use a value greater than 0, but less than 10 to avoid attempting to
         * access an index of the array in the sink that is out-of-bounds */
        data = 7;
        break;
    }
    while(1)
    {
        data = RAND32();
        break;
    }
    while(1)
    {
        {
            int data_buf[10] = {0,1,2,3,4,5,6,7,8,9};
            /* POTENTIAL FLAW: Attempt to access an index of the array that is possibly out-of-bounds
             * This check does not check the upper bounds of the array index */
            if (data >= 0)
            {
                printIntLine(data_buf[data]);
            }
            else
            {
                printLine("ERROR: Array index is negative");
            }
        }
        break;
    }
    while(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            int data_buf[10] = {0,1,2,3,4,5,6,7,8,9};
            /* FIX: Properly validate the array index */
            if (data >= 0 && data < 10)
            {
                printIntLine(data_buf[data]);
            }
            else
            {
                printLine("ERROR: Array index is out-of-bounds");
            }
        }
        break;
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G() - use badsource and goodsink by changing the conditions on the third and fourth while statements */
static void goodB2G()
{
    int data;
    data = -1; /* Initialize data */
    while(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Use a value greater than 0, but less than 10 to avoid attempting to
         * access an index of the array in the sink that is out-of-bounds */
        data = 7;
        break;
    }
    while(1)
    {
        data = RAND32();
        break;
    }
    while(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            int data_buf[10] = {0,1,2,3,4,5,6,7,8,9};
            /* POTENTIAL FLAW: Attempt to access an index of the array that is possibly out-of-bounds
             * This check does not check the upper bounds of the array index */
            if (data >= 0)
            {
                printIntLine(data_buf[data]);
            }
            else
            {
                printLine("ERROR: Array index is negative");
            }
        }
        break;
    }
    while(1)
    {
        {
            int data_buf[10] = {0,1,2,3,4,5,6,7,8,9};
            /* FIX: Properly validate the array index */
            if (data >= 0 && data < 10)
            {
                printIntLine(data_buf[data]);
            }
            else
            {
                printLine("ERROR: Array index is out-of-bounds");
            }
        }
        break;
    }
}

/* goodG2B() - use goodsource and badsink by changing the conditions on the first and second while statements */
static void goodG2B()
{
    int data;
    data = -1; /* Initialize data */
    while(1)
    {
        /* FIX: Use a value greater than 0, but less than 10 to avoid attempting to
         * access an index of the array in the sink that is out-of-bounds */
        data = 7;
        break;
    }
    while(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        data = RAND32();
        break;
    }
    while(1)
    {
        {
            int data_buf[10] = {0,1,2,3,4,5,6,7,8,9};
            /* POTENTIAL FLAW: Attempt to access an index of the array that is possibly out-of-bounds
             * This check does not check the upper bounds of the array index */
            if (data >= 0)
            {
                printIntLine(data_buf[data]);
            }
            else
            {
                printLine("ERROR: Array index is negative");
            }
        }
        break;
    }
    while(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            int data_buf[10] = {0,1,2,3,4,5,6,7,8,9};
            /* FIX: Properly validate the array index */
            if (data >= 0 && data < 10)
            {
                printIntLine(data_buf[data]);
            }
            else
            {
                printLine("ERROR: Array index is out-of-bounds");
            }
        }
        break;
    }
}

void CWE129_Improper_Validation_Of_Array_Index__rand_int_16_good()
{
    goodB2G();
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
    CWE129_Improper_Validation_Of_Array_Index__rand_int_16_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE129_Improper_Validation_Of_Array_Index__rand_int_16_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
