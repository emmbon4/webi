/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE187_Partial_Comparison__char_fromFile_str_52b.c
Label Definition File: CWE187_Partial_Comparison.label.xml
Template File: sources-sinks-52b.tmpl.c
*/
/*
 * @description
 * CWE: 187 Partial Comparison
 * BadSource: fromFile Read input from a file
 * GoodSource: Provide a matching password
 * Sinks: str
 *    GoodSink: Compare the 2 passwords correctly
 *    BadSink : use strstr() to do password match, which is a partial comparison
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#define PASSWORD "Password1234"
/* PASSWORD_SZ must equal the length of PASSWORD */
#define PASSWORD_SZ strlen(PASSWORD)

#ifdef _WIN32
# define FOPEN fopen
#else
/* fopen is used on unix-based OSs */
# define FOPEN fopen
#endif

#ifndef OMITBAD

/* bad function declaration */
void CWE187_Partial_Comparison__char_fromFile_str_52c_bad_sink(char * data);

void CWE187_Partial_Comparison__char_fromFile_str_52b_bad_sink(char * data)
{
    CWE187_Partial_Comparison__char_fromFile_str_52c_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE187_Partial_Comparison__char_fromFile_str_52c_goodG2B_sink(char * data);

void CWE187_Partial_Comparison__char_fromFile_str_52b_goodG2B_sink(char * data)
{
    CWE187_Partial_Comparison__char_fromFile_str_52c_goodG2B_sink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE187_Partial_Comparison__char_fromFile_str_52c_goodB2G_sink(char * data);

void CWE187_Partial_Comparison__char_fromFile_str_52b_goodB2G_sink(char * data)
{
    CWE187_Partial_Comparison__char_fromFile_str_52c_goodB2G_sink(data);
}

#endif /* OMITGOOD */
