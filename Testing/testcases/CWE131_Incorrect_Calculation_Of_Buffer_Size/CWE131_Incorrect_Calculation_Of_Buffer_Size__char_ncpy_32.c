/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE131_Incorrect_Calculation_Of_Buffer_Size__char_ncpy_32.c
Label Definition File: CWE131_Incorrect_Calculation_Of_Buffer_Size.off_by_one.label.xml
Template File: sources-sink-32.tmpl.c
*/
/*
 * @description
 * CWE: 131 Incorrect Calculation of Buffer Size
 * BadSource:  Allocate memory for a string, but do not allocate space for NULL terminator
 * GoodSource: Allocate enough memory for a string and the NULL terminator
 * Sink: ncpy
 *    BadSink : Copy string to data using strncpy()
 * Flow Variant: 32 Data flow using two pointers to the same value within the same function
 *
 * */

#include "std_testcase.h"

/* MAINTENANCE NOTE: The length of this string should equal the 10 */
#define SRC_STRING "AAAAAAAAAA"

#ifndef OMITBAD

void CWE131_Incorrect_Calculation_Of_Buffer_Size__char_ncpy_32_bad()
{
    char * data;
    char * *data_ptr1 = &data;
    char * *data_ptr2 = &data;
    data = NULL;
    {
        char * data = *data_ptr1;
        /* FLAW: Did not leave space for a null terminator */
        data = (char *)malloc(10*sizeof(char));
        *data_ptr1 = data;
    }
    {
        char * data = *data_ptr2;
        {
            char data_src[10+1] = SRC_STRING;
            /* POTENTIAL FLAW: data may not have enough space to hold data_src */
            strncpy(data, data_src, strlen(data_src));
            /* strncpy() does not always NULL terminate */
            data[strlen(data_src)] = '\0'; /* NULL terminate */
            printLine(data);
            free(data);
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    char * data;
    char * *data_ptr1 = &data;
    char * *data_ptr2 = &data;
    data = NULL;
    {
        char * data = *data_ptr1;
        /* FIX: Allocate space for a null terminator */
        data = (char *)malloc((10+1)*sizeof(char));
        *data_ptr1 = data;
    }
    {
        char * data = *data_ptr2;
        {
            char data_src[10+1] = SRC_STRING;
            /* POTENTIAL FLAW: data may not have enough space to hold data_src */
            strncpy(data, data_src, strlen(data_src));
            /* strncpy() does not always NULL terminate */
            data[strlen(data_src)] = '\0'; /* NULL terminate */
            printLine(data);
            free(data);
        }
    }
}

void CWE131_Incorrect_Calculation_Of_Buffer_Size__char_ncpy_32_good()
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
    CWE131_Incorrect_Calculation_Of_Buffer_Size__char_ncpy_32_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE131_Incorrect_Calculation_Of_Buffer_Size__char_ncpy_32_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
