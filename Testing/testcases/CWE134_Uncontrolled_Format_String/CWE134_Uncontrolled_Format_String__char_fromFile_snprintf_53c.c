/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__char_fromFile_snprintf_53c.c
Label Definition File: CWE134_Uncontrolled_Format_String.label.xml
Template File: sources-sinks-53c.tmpl.c
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * BadSource: fromFile Read input from a file
 * GoodSource: Copy a fixed string into data
 * Sinks: snprintf
 *    GoodSink: snprintf with "%s" as the third argument and data as the fourth
 *    BadSink : snprintf with data as the third argument
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
# define FOPEN fopen
#else
/* fopen is used on unix-based OSs */
# define FOPEN fopen
#endif

#ifdef _WIN32
# define SNPRINTF _snprintf
#else /* NOT _WIN32 */
# define SNPRINTF snprintf
#endif

#ifndef OMITBAD

/* bad function declaration */
void CWE134_Uncontrolled_Format_String__char_fromFile_snprintf_53d_bad_sink(char * data);

void CWE134_Uncontrolled_Format_String__char_fromFile_snprintf_53c_bad_sink(char * data)
{
    CWE134_Uncontrolled_Format_String__char_fromFile_snprintf_53d_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE134_Uncontrolled_Format_String__char_fromFile_snprintf_53d_goodG2B_sink(char * data);

void CWE134_Uncontrolled_Format_String__char_fromFile_snprintf_53c_goodG2B_sink(char * data)
{
    CWE134_Uncontrolled_Format_String__char_fromFile_snprintf_53d_goodG2B_sink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE134_Uncontrolled_Format_String__char_fromFile_snprintf_53d_goodB2G_sink(char * data);

void CWE134_Uncontrolled_Format_String__char_fromFile_snprintf_53c_goodB2G_sink(char * data)
{
    CWE134_Uncontrolled_Format_String__char_fromFile_snprintf_53d_goodB2G_sink(data);
}

#endif /* OMITGOOD */
