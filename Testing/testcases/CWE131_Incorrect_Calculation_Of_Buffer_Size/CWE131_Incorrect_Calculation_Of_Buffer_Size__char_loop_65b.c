/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE131_Incorrect_Calculation_Of_Buffer_Size__char_loop_65b.c
Label Definition File: CWE131_Incorrect_Calculation_Of_Buffer_Size.off_by_one.label.xml
Template File: sources-sink-65b.tmpl.c
*/
/*
 * @description
 * CWE: 131 Incorrect Calculation of Buffer Size
 * BadSource:  Allocate memory for a string, but do not allocate space for NULL terminator
 * GoodSource: Allocate enough memory for a string and the NULL terminator
 * Sinks: loop
 *    BadSink : Copy array to data using a loop
 * Flow Variant: 65 Data/control flow: data passed as an argument from one function to a function in a different source file called via a function pointer
 *
 * */

#include "std_testcase.h"

/* MAINTENANCE NOTE: The length of this string should equal the 10 */
#define SRC_STRING "AAAAAAAAAA"

#ifndef OMITBAD

void CWE131_Incorrect_Calculation_Of_Buffer_Size__char_loop_65b_bad_sink(char * data)
{
    {
        char data_src[10+1] = SRC_STRING;
        size_t i, src_len;
        src_len = strlen(data_src);
        /* POTENTIAL FLAW: data may not have enough space to hold data_src */
        for (i = 0; i < src_len; i++)
        {
            data[i] = data_src[i];
        }
        data[strlen(data_src)] = '\0'; /* NULL terminate */
        printLine(data);
        free(data);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE131_Incorrect_Calculation_Of_Buffer_Size__char_loop_65b_goodG2B_sink(char * data)
{
    {
        char data_src[10+1] = SRC_STRING;
        size_t i, src_len;
        src_len = strlen(data_src);
        /* POTENTIAL FLAW: data may not have enough space to hold data_src */
        for (i = 0; i < src_len; i++)
        {
            data[i] = data_src[i];
        }
        data[strlen(data_src)] = '\0'; /* NULL terminate */
        printLine(data);
        free(data);
    }
}

#endif /* OMITGOOD */
