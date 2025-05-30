/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE129_Improper_Validation_Of_Array_Index__fscanf_int_06.c
Label Definition File: CWE129_Improper_Validation_Of_Array_Index.label.xml
Template File: sources-sinks-06.tmpl.c
*/
/*
 * @description
 * CWE: 129 Improper Validation of Array Index
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Larger than zero but less than 10
 * Sinks: int
 *    GoodSink: Ensure the array index is valid
 *    BadSink : Improperly check the array index by not checking the upper bound
 * Flow Variant: 06 Control flow: if(static_const_five==5) and if(static_const_five!=5)
 *
 * */

#include "std_testcase.h"

/* The variable below is declared "const", so a tool should be able
   to identify that reads of this will always give its initialized
   value. */
static const int static_const_five = 5;

#ifndef OMITBAD

void CWE129_Improper_Validation_Of_Array_Index__fscanf_int_06_bad()
{
    int data;
    data = -1; /* Initialize data */
    if(static_const_five==5)
    {
        fscanf (stdin, "%d", &data);
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Use a value greater than 0, but less than 10 to avoid attempting to
         * access an index of the array in the sink that is out-of-bounds */
        data = 7;
    }
    if(static_const_five==5)
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
    }
    else
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
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G1() - use badsource and goodsink by changing the second static_const_five==5 to static_const_five!=5 */
static void goodB2G1()
{
    int data;
    data = -1; /* Initialize data */
    if(static_const_five==5)
    {
        fscanf (stdin, "%d", &data);
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Use a value greater than 0, but less than 10 to avoid attempting to
         * access an index of the array in the sink that is out-of-bounds */
        data = 7;
    }
    if(static_const_five!=5)
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
    }
    else
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
    }
}

/* goodB2G2() - use badsource and goodsink by reversing the blocks in the second if */
static void goodB2G2()
{
    int data;
    data = -1; /* Initialize data */
    if(static_const_five==5)
    {
        fscanf (stdin, "%d", &data);
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Use a value greater than 0, but less than 10 to avoid attempting to
         * access an index of the array in the sink that is out-of-bounds */
        data = 7;
    }
    if(static_const_five==5)
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
    }
    else
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
    }
}

/* goodG2B1() - use goodsource and badsink by changing the first static_const_five==5 to static_const_five!=5 */
static void goodG2B1()
{
    int data;
    data = -1; /* Initialize data */
    if(static_const_five!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        fscanf (stdin, "%d", &data);
    }
    else
    {
        /* FIX: Use a value greater than 0, but less than 10 to avoid attempting to
         * access an index of the array in the sink that is out-of-bounds */
        data = 7;
    }
    if(static_const_five==5)
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
    }
    else
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
    }
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the first if */
static void goodG2B2()
{
    int data;
    data = -1; /* Initialize data */
    if(static_const_five==5)
    {
        /* FIX: Use a value greater than 0, but less than 10 to avoid attempting to
         * access an index of the array in the sink that is out-of-bounds */
        data = 7;
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        fscanf (stdin, "%d", &data);
    }
    if(static_const_five==5)
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
    }
    else
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
    }
}

void CWE129_Improper_Validation_Of_Array_Index__fscanf_int_06_good()
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
    CWE129_Improper_Validation_Of_Array_Index__fscanf_int_06_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE129_Improper_Validation_Of_Array_Index__fscanf_int_06_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
