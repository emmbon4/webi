/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE464_Insertion_Of_Data_Structure_Sentinel__basic_63a.c
Label Definition File: CWE464_Insertion_Of_Data_Structure_Sentinel__basic.label.xml
Template File: sources-sink-63a.tmpl.c
*/
/*
 * @description
 * CWE: 464 Insertion of Data Structure Sentinel
 * BadSource:  Read in data from the console and convert to an int
 * GoodSource: Set data to a fixed char
 * Sinks:
 *    BadSink : Place data into and print an array
 * Flow Variant: 63 Data flow: pointer to data passed from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

/* bad function declaration */
void CWE464_Insertion_Of_Data_Structure_Sentinel__basic_63b_bad_sink(char * data_ptr);

void CWE464_Insertion_Of_Data_Structure_Sentinel__basic_63_bad()
{
    char data;
    data = ' ';
    {
        char ch;
        ch = (char)getc(stdin);
        /* FLAW: If the character entered on the command line is not an int,
         * a null value will be returned */
        data = (char)atoi(&ch);
    }
    CWE464_Insertion_Of_Data_Structure_Sentinel__basic_63b_bad_sink(&data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE464_Insertion_Of_Data_Structure_Sentinel__basic_63b_goodG2B_sink(char * data);

static void goodG2B()
{
    char data;
    data = ' ';
    /* FIX: Set data to be a char */
    data = 'a';
    CWE464_Insertion_Of_Data_Structure_Sentinel__basic_63b_goodG2B_sink(&data);
}

void CWE464_Insertion_Of_Data_Structure_Sentinel__basic_63_good()
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
    CWE464_Insertion_Of_Data_Structure_Sentinel__basic_63_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE464_Insertion_Of_Data_Structure_Sentinel__basic_63_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
