/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__char_Environment_fprintf_52b.c
Label Definition File: CWE134_Uncontrolled_Format_String.label.xml
Template File: sources-sinks-52b.tmpl.c
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * BadSource: Environment Read input from an environment variable
 * GoodSource: Copy a fixed string into data
 * Sinks: fprintf
 *    GoodSink: fprintf with "%s" as the second argument and data as the third
 *    BadSink : fprintf with data as the second argument
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"

#define ENV_VARIABLE "ADD"

#ifdef _WIN32
# define GETENV getenv
#else
# define GETENV getenv
#endif

#ifndef OMITBAD

/* bad function declaration */
void CWE134_Uncontrolled_Format_String__char_Environment_fprintf_52c_bad_sink(char * data);

void CWE134_Uncontrolled_Format_String__char_Environment_fprintf_52b_bad_sink(char * data)
{
    CWE134_Uncontrolled_Format_String__char_Environment_fprintf_52c_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE134_Uncontrolled_Format_String__char_Environment_fprintf_52c_goodG2B_sink(char * data);

void CWE134_Uncontrolled_Format_String__char_Environment_fprintf_52b_goodG2B_sink(char * data)
{
    CWE134_Uncontrolled_Format_String__char_Environment_fprintf_52c_goodG2B_sink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE134_Uncontrolled_Format_String__char_Environment_fprintf_52c_goodB2G_sink(char * data);

void CWE134_Uncontrolled_Format_String__char_Environment_fprintf_52b_goodB2G_sink(char * data)
{
    CWE134_Uncontrolled_Format_String__char_Environment_fprintf_52c_goodB2G_sink(data);
}

#endif /* OMITGOOD */
