/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__wchar_t_fromFile_fprintf_54c.c
Label Definition File: CWE134_Uncontrolled_Format_String.label.xml
Template File: sources-sinks-54c.tmpl.c
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * BadSource: fromFile Read input from a file
 * GoodSource: Copy a fixed string into data
 * Sinks: fprintf
 *    GoodSink: fwprintf with "%s" as the second argument and data as the third
 *    BadSink : fwprintf with data as the second argument
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
# define FOPEN _wfopen
#else
/* fopen is used on unix-based OSs */
# define FOPEN fopen
#endif

#ifndef OMITBAD

/* bad function declaration */
void CWE134_Uncontrolled_Format_String__wchar_t_fromFile_fprintf_54d_bad_sink(wchar_t * data);

void CWE134_Uncontrolled_Format_String__wchar_t_fromFile_fprintf_54c_bad_sink(wchar_t * data)
{
    CWE134_Uncontrolled_Format_String__wchar_t_fromFile_fprintf_54d_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE134_Uncontrolled_Format_String__wchar_t_fromFile_fprintf_54d_goodG2B_sink(wchar_t * data);

void CWE134_Uncontrolled_Format_String__wchar_t_fromFile_fprintf_54c_goodG2B_sink(wchar_t * data)
{
    CWE134_Uncontrolled_Format_String__wchar_t_fromFile_fprintf_54d_goodG2B_sink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE134_Uncontrolled_Format_String__wchar_t_fromFile_fprintf_54d_goodB2G_sink(wchar_t * data);

void CWE134_Uncontrolled_Format_String__wchar_t_fromFile_fprintf_54c_goodB2G_sink(wchar_t * data)
{
    CWE134_Uncontrolled_Format_String__wchar_t_fromFile_fprintf_54d_goodB2G_sink(data);
}

#endif /* OMITGOOD */
