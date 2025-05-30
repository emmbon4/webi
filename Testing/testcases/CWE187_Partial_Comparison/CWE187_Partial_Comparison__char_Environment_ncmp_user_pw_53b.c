/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE187_Partial_Comparison__char_Environment_ncmp_user_pw_53b.c
Label Definition File: CWE187_Partial_Comparison.label.xml
Template File: sources-sinks-53b.tmpl.c
*/
/*
 * @description
 * CWE: 187 Partial Comparison
 * BadSource: Environment Read input from an environment variable
 * GoodSource: Provide a matching password
 * Sinks: ncmp_user_pw
 *    GoodSink: Compare the 2 passwords correctly
 *    BadSink : use strncmp() to do password match, but use the length of the user password
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#define PASSWORD "Password1234"
/* PASSWORD_SZ must equal the length of PASSWORD */
#define PASSWORD_SZ strlen(PASSWORD)

#define ENV_VARIABLE "ADD"

#ifdef _WIN32
# define GETENV getenv
#else
# define GETENV getenv
#endif

#ifndef OMITBAD

/* bad function declaration */
void CWE187_Partial_Comparison__char_Environment_ncmp_user_pw_53c_bad_sink(char * data);

void CWE187_Partial_Comparison__char_Environment_ncmp_user_pw_53b_bad_sink(char * data)
{
    CWE187_Partial_Comparison__char_Environment_ncmp_user_pw_53c_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE187_Partial_Comparison__char_Environment_ncmp_user_pw_53c_goodG2B_sink(char * data);

void CWE187_Partial_Comparison__char_Environment_ncmp_user_pw_53b_goodG2B_sink(char * data)
{
    CWE187_Partial_Comparison__char_Environment_ncmp_user_pw_53c_goodG2B_sink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE187_Partial_Comparison__char_Environment_ncmp_user_pw_53c_goodB2G_sink(char * data);

void CWE187_Partial_Comparison__char_Environment_ncmp_user_pw_53b_goodB2G_sink(char * data)
{
    CWE187_Partial_Comparison__char_Environment_ncmp_user_pw_53c_goodB2G_sink(data);
}

#endif /* OMITGOOD */
