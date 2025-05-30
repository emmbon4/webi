/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE187_Partial_Comparison__char_substring_ncmp_correct_pw_61b.c
Label Definition File: CWE187_Partial_Comparison.label.xml
Template File: sources-sinks-61b.tmpl.c
*/
/*
 * @description
 * CWE: 187 Partial Comparison
 * BadSource: substring Provide a password that is a shortened version of the actual password
 * GoodSource: Provide a matching password
 * Sinks: ncmp_correct_pw
 *    GoodSink: Compare the 2 passwords correctly
 *    BadSink : use strncmp() to do password match, but use the length of the correct password
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#define PASSWORD "Password1234"
/* PASSWORD_SZ must equal the length of PASSWORD */
#define PASSWORD_SZ strlen(PASSWORD)

#ifndef OMITBAD

char * CWE187_Partial_Comparison__char_substring_ncmp_correct_pw_61b_bad_source(char * data)
{
    /* FLAW: Provide a shortened version of the actual password
     * NOTE: This must be a substring of PASSWORD starting with the first character in PASSWORD
     * i.e. other examples could be "Pa", "Pas", "Pass", etc. as long as it is shorter than MIN_PASSWORD_SZ
     * and does not match the full PASSWORD string */
    data = "P";
    return data;
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
char * CWE187_Partial_Comparison__char_substring_ncmp_correct_pw_61b_goodG2B_source(char * data)
{
    /* FIX: Use the matching string */
    data = PASSWORD;
    return data;
}

/* goodB2G() uses the BadSource with the GoodSink */
char * CWE187_Partial_Comparison__char_substring_ncmp_correct_pw_61b_goodB2G_source(char * data)
{
    /* FLAW: Provide a shortened version of the actual password
     * NOTE: This must be a substring of PASSWORD starting with the first character in PASSWORD
     * i.e. other examples could be "Pa", "Pas", "Pass", etc. as long as it is shorter than MIN_PASSWORD_SZ
     * and does not match the full PASSWORD string */
    data = "P";
    return data;
}

#endif /* OMITGOOD */
