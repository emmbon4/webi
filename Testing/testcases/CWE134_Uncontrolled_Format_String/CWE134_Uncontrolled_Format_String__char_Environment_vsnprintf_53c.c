/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__char_Environment_vsnprintf_53c.c
Label Definition File: CWE134_Uncontrolled_Format_String.vasinks.label.xml
Template File: sources-vasinks-53c.tmpl.c
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * BadSource: Environment Read input from an environment variable
 * GoodSource: Copy a fixed string into data
 * Sinks: vsnprintf
 *    GoodSink: vsnprintf with a format string
 *    BadSink : vsnprintf without a format string
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include <stdarg.h>
#include "std_testcase.h"

#define ENV_VARIABLE "ADD"

#ifdef _WIN32
# define GETENV getenv
#else
# define GETENV getenv
#endif

#ifndef OMITBAD

/* bad function declaration */
void CWE134_Uncontrolled_Format_String__char_Environment_vsnprintf_53d_bad_sink(char * data);

void CWE134_Uncontrolled_Format_String__char_Environment_vsnprintf_53c_bad_sink(char * data)
{
    CWE134_Uncontrolled_Format_String__char_Environment_vsnprintf_53d_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE134_Uncontrolled_Format_String__char_Environment_vsnprintf_53d_goodG2B_sink(char * data);

void CWE134_Uncontrolled_Format_String__char_Environment_vsnprintf_53c_goodG2B_sink(char * data)
{
    CWE134_Uncontrolled_Format_String__char_Environment_vsnprintf_53d_goodG2B_sink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE134_Uncontrolled_Format_String__char_Environment_vsnprintf_53d_goodB2G_sink(char * data);

void CWE134_Uncontrolled_Format_String__char_Environment_vsnprintf_53c_goodB2G_sink(char * data)
{
    CWE134_Uncontrolled_Format_String__char_Environment_vsnprintf_53d_goodB2G_sink(data);
}

#endif /* OMITGOOD */
