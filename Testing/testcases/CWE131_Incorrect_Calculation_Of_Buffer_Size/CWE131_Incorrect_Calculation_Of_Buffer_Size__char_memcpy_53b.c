/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE131_Incorrect_Calculation_Of_Buffer_Size__char_memcpy_53b.c
Label Definition File: CWE131_Incorrect_Calculation_Of_Buffer_Size.off_by_one.label.xml
Template File: sources-sink-53b.tmpl.c
*/
/*
 * @description
 * CWE: 131 Incorrect Calculation of Buffer Size
 * BadSource:  Allocate memory for a string, but do not allocate space for NULL terminator
 * GoodSource: Allocate enough memory for a string and the NULL terminator
 * Sink: memcpy
 *    BadSink : Copy string to data using memcpy()
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

/* MAINTENANCE NOTE: The length of this string should equal the 10 */
#define SRC_STRING "AAAAAAAAAA"

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

/* bad function declaration */
void CWE131_Incorrect_Calculation_Of_Buffer_Size__char_memcpy_53c_bad_sink(char * data);

void CWE131_Incorrect_Calculation_Of_Buffer_Size__char_memcpy_53b_bad_sink(char * data)
{
    CWE131_Incorrect_Calculation_Of_Buffer_Size__char_memcpy_53c_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declaration */
void CWE131_Incorrect_Calculation_Of_Buffer_Size__char_memcpy_53c_goodG2B_sink(char * data);

/* goodG2B uses the GoodSource with the BadSink */
void CWE131_Incorrect_Calculation_Of_Buffer_Size__char_memcpy_53b_goodG2B_sink(char * data)
{
    CWE131_Incorrect_Calculation_Of_Buffer_Size__char_memcpy_53c_goodG2B_sink(data);
}

#endif /* OMITGOOD */
