/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE187_Partial_Comparison__char_substring_ncmp_correct_pw_68a.c
Label Definition File: CWE187_Partial_Comparison.label.xml
Template File: sources-sinks-68a.tmpl.c
*/
/*
 * @description
 * CWE: 187 Partial Comparison
 * BadSource: substring Provide a password that is a shortened version of the actual password
 * GoodSource: Provide a matching password
 * Sinks: ncmp_correct_pw
 *    GoodSink: Compare the 2 passwords correctly
 *    BadSink : use strncmp() to do password match, but use the length of the correct password
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#define PASSWORD "Password1234"
/* PASSWORD_SZ must equal the length of PASSWORD */
#define PASSWORD_SZ strlen(PASSWORD)

char * CWE187_Partial_Comparison__char_substring_ncmp_correct_pw_68_bad_data;
char * CWE187_Partial_Comparison__char_substring_ncmp_correct_pw_68_goodG2B_data;
char * CWE187_Partial_Comparison__char_substring_ncmp_correct_pw_68_goodB2G_data;

#ifndef OMITBAD

/* bad function declaration */
void CWE187_Partial_Comparison__char_substring_ncmp_correct_pw_68b_bad_sink();

void CWE187_Partial_Comparison__char_substring_ncmp_correct_pw_68_bad()
{
    char * data;
    char data_buf[100] = "";
    data = data_buf;
    /* FLAW: Provide a shortened version of the actual password
     * NOTE: This must be a substring of PASSWORD starting with the first character in PASSWORD
     * i.e. other examples could be "Pa", "Pas", "Pass", etc. as long as it is shorter than MIN_PASSWORD_SZ
     * and does not match the full PASSWORD string */
    data = "P";
    CWE187_Partial_Comparison__char_substring_ncmp_correct_pw_68_bad_data = data;
    CWE187_Partial_Comparison__char_substring_ncmp_correct_pw_68b_bad_sink();
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declarations */
void CWE187_Partial_Comparison__char_substring_ncmp_correct_pw_68b_goodG2B_sink();
void CWE187_Partial_Comparison__char_substring_ncmp_correct_pw_68b_goodB2G_sink();

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    char * data;
    char data_buf[100] = "";
    data = data_buf;
    /* FIX: Use the matching string */
    data = PASSWORD;
    CWE187_Partial_Comparison__char_substring_ncmp_correct_pw_68_goodG2B_data = data;
    CWE187_Partial_Comparison__char_substring_ncmp_correct_pw_68b_goodG2B_sink();
}

/* goodB2G uses the BadSource with the GoodSink */
static void goodB2G()
{
    char * data;
    char data_buf[100] = "";
    data = data_buf;
    /* FLAW: Provide a shortened version of the actual password
     * NOTE: This must be a substring of PASSWORD starting with the first character in PASSWORD
     * i.e. other examples could be "Pa", "Pas", "Pass", etc. as long as it is shorter than MIN_PASSWORD_SZ
     * and does not match the full PASSWORD string */
    data = "P";
    CWE187_Partial_Comparison__char_substring_ncmp_correct_pw_68_goodB2G_data = data;
    CWE187_Partial_Comparison__char_substring_ncmp_correct_pw_68b_goodB2G_sink();
}

void CWE187_Partial_Comparison__char_substring_ncmp_correct_pw_68_good()
{
    goodG2B();
    goodB2G();
}

#endif /* OMITGOOD */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    CWE187_Partial_Comparison__char_substring_ncmp_correct_pw_68_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE187_Partial_Comparison__char_substring_ncmp_correct_pw_68_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
