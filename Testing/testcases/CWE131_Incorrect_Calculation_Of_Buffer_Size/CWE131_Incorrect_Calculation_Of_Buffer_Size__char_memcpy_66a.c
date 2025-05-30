/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE131_Incorrect_Calculation_Of_Buffer_Size__char_memcpy_66a.c
Label Definition File: CWE131_Incorrect_Calculation_Of_Buffer_Size.off_by_one.label.xml
Template File: sources-sink-66a.tmpl.c
*/
/*
 * @description
 * CWE: 131 Incorrect Calculation of Buffer Size
 * BadSource:  Allocate memory for a string, but do not allocate space for NULL terminator
 * GoodSource: Allocate enough memory for a string and the NULL terminator
 * Sinks: memcpy
 *    BadSink : Copy string to data using memcpy()
 * Flow Variant: 66 Data flow: data passed in an array from one function to another in different source files
 *
 * */

#include "std_testcase.h"

/* MAINTENANCE NOTE: The length of this string should equal the 10 */
#define SRC_STRING "AAAAAAAAAA"

#ifndef OMITBAD

/* bad function declaration */
void CWE131_Incorrect_Calculation_Of_Buffer_Size__char_memcpy_66b_bad_sink(char * data_array[]);

void CWE131_Incorrect_Calculation_Of_Buffer_Size__char_memcpy_66_bad()
{
    char * data;
    char * data_array[5];
    data = NULL;
    /* FLAW: Did not leave space for a null terminator */
    data = (char *)malloc(10*sizeof(char));
    /* put data in array */
    data_array[2] = data;
    CWE131_Incorrect_Calculation_Of_Buffer_Size__char_memcpy_66b_bad_sink(data_array);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE131_Incorrect_Calculation_Of_Buffer_Size__char_memcpy_66b_goodG2B_sink(char * data_array[]);

static void goodG2B()
{
    char * data;
    char * data_array[5];
    data = NULL;
    /* FIX: Allocate space for a null terminator */
    data = (char *)malloc((10+1)*sizeof(char));
    data_array[2] = data;
    CWE131_Incorrect_Calculation_Of_Buffer_Size__char_memcpy_66b_goodG2B_sink(data_array);
}

void CWE131_Incorrect_Calculation_Of_Buffer_Size__char_memcpy_66_good()
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
    CWE131_Incorrect_Calculation_Of_Buffer_Size__char_memcpy_66_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE131_Incorrect_Calculation_Of_Buffer_Size__char_memcpy_66_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
