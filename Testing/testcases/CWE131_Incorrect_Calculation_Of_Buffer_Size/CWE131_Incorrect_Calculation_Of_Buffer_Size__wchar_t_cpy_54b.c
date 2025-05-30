/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE131_Incorrect_Calculation_Of_Buffer_Size__wchar_t_cpy_54b.c
Label Definition File: CWE131_Incorrect_Calculation_Of_Buffer_Size.off_by_one.label.xml
Template File: sources-sink-54b.tmpl.c
*/
/*
 * @description
 * CWE: 131 Incorrect Calculation of Buffer Size
 * BadSource:  Allocate memory for a string, but do not allocate space for NULL terminator
 * GoodSource: Allocate enough memory for a string and the NULL terminator
 * Sink: cpy
 *    BadSink : Copy string to data using wcscpy()
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

/* MAINTENANCE NOTE: The length of this string should equal the 10 */
#define SRC_STRING L"AAAAAAAAAA"

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

/* bad function declaration */
void CWE131_Incorrect_Calculation_Of_Buffer_Size__wchar_t_cpy_54c_bad_sink(wchar_t * data);

void CWE131_Incorrect_Calculation_Of_Buffer_Size__wchar_t_cpy_54b_bad_sink(wchar_t * data)
{
    CWE131_Incorrect_Calculation_Of_Buffer_Size__wchar_t_cpy_54c_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declaration */
void CWE131_Incorrect_Calculation_Of_Buffer_Size__wchar_t_cpy_54c_goodG2B_sink(wchar_t * data);

/* goodG2B uses the GoodSource with the BadSink */
void CWE131_Incorrect_Calculation_Of_Buffer_Size__wchar_t_cpy_54b_goodG2B_sink(wchar_t * data)
{
    CWE131_Incorrect_Calculation_Of_Buffer_Size__wchar_t_cpy_54c_goodG2B_sink(data);
}

#endif /* OMITGOOD */
