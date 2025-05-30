/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE129_Improper_Validation_Of_Array_Index__rand_int_61a.c
Label Definition File: CWE129_Improper_Validation_Of_Array_Index.label.xml
Template File: sources-sinks-61a.tmpl.c
*/
/*
 * @description
 * CWE: 129 Improper Validation of Array Index
 * BadSource: rand Set data to result of rand(), which may be zero
 * GoodSource: Larger than zero but less than 10
 * Sinks: int
 *    GoodSink: Ensure the array index is valid
 *    BadSink : Improperly check the array index by not checking the upper bound
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

/* bad function declaration */
int CWE129_Improper_Validation_Of_Array_Index__rand_int_61b_bad_source(int data);

void CWE129_Improper_Validation_Of_Array_Index__rand_int_61_bad()
{
    int data;
    data = -1; /* Initialize data */
    data = CWE129_Improper_Validation_Of_Array_Index__rand_int_61b_bad_source(data);
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

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
int CWE129_Improper_Validation_Of_Array_Index__rand_int_61b_goodG2B_source(int data);

static void goodG2B()
{
    int data;
    data = -1; /* Initialize data */
    data = CWE129_Improper_Validation_Of_Array_Index__rand_int_61b_goodG2B_source(data);
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

/* goodB2G uses the BadSource with the GoodSink */
int CWE129_Improper_Validation_Of_Array_Index__rand_int_61b_goodB2G_source(int data);

static void goodB2G()
{
    int data;
    data = -1; /* Initialize data */
    data = CWE129_Improper_Validation_Of_Array_Index__rand_int_61b_goodB2G_source(data);
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

void CWE129_Improper_Validation_Of_Array_Index__rand_int_61_good()
{
    goodG2B();
    goodB2G();
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
    CWE129_Improper_Validation_Of_Array_Index__rand_int_61_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE129_Improper_Validation_Of_Array_Index__rand_int_61_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
