/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE187_Partial_Comparison__wchar_t_Environment_ncmp_user_pw_41.c
Label Definition File: CWE187_Partial_Comparison.label.xml
Template File: sources-sinks-41.tmpl.c
*/
/*
 * @description
 * CWE: 187 Partial Comparison
 * BadSource: Environment Read input from an environment variable
 * GoodSource: Provide a matching password
 * Sinks: ncmp_user_pw
 *    GoodSink: Compare the 2 passwords correctly
 *    BadSink : use wcsncmp() to do password match, but use the length of the user password
 * Flow Variant: 41 Data flow: data passed as an argument from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#define PASSWORD L"Password1234"
/* PASSWORD_SZ must equal the length of PASSWORD */
#define PASSWORD_SZ wcslen(PASSWORD)

#define ENV_VARIABLE L"ADD"

#ifdef _WIN32
# define GETENV _wgetenv
#else
# define GETENV wgetenv
#endif

#ifndef OMITBAD

static void bad_sink(wchar_t * data)
{
    /* By using the strlen() of the input password, you are able to create a partial comparison
     * For example if PASSWORD=PASSWORD1234, a user supplied password of PASSWORD12 will allow access */
    /* POTENTIAL FLAW: Possibly partially compare the two passwords */
    if (wcsncmp(PASSWORD, data, wcslen(data)) == 0)
        printLine("Access granted");
    else
        printLine("Access denied!");
}

void CWE187_Partial_Comparison__wchar_t_Environment_ncmp_user_pw_41_bad()
{
    wchar_t * data;
    wchar_t data_buf[100] = L"";
    data = data_buf;
    {
        /* Read input from an environment variable */
        size_t data_len = wcslen(data);
        wchar_t * environment = GETENV(ENV_VARIABLE);
        /* If there is data in the environment variable */
        if (environment != NULL)
        {
            wcsncat(data+data_len, environment, 100-data_len-1);
        }
    }
    bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B_sink(wchar_t * data)
{
    /* By using the strlen() of the input password, you are able to create a partial comparison
     * For example if PASSWORD=PASSWORD1234, a user supplied password of PASSWORD12 will allow access */
    /* POTENTIAL FLAW: Possibly partially compare the two passwords */
    if (wcsncmp(PASSWORD, data, wcslen(data)) == 0)
        printLine("Access granted");
    else
        printLine("Access denied!");
}

static void goodG2B()
{
    wchar_t * data;
    wchar_t data_buf[100] = L"";
    data = data_buf;
    /* FIX: Use the matching string */
    data = PASSWORD;
    goodG2B_sink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
static void goodB2G_sink(wchar_t * data)
{
    /* Ideally, we would want to do a check to see if the passwords are of equal length */
    /* FIX: Compare the two passwords completely and correctly */
    if (wcscmp(PASSWORD, data) == 0)
        printLine("Access granted");
    else
        printLine("Access denied!");
}

static void goodB2G()
{
    wchar_t * data;
    wchar_t data_buf[100] = L"";
    data = data_buf;
    {
        /* Read input from an environment variable */
        size_t data_len = wcslen(data);
        wchar_t * environment = GETENV(ENV_VARIABLE);
        /* If there is data in the environment variable */
        if (environment != NULL)
        {
            wcsncat(data+data_len, environment, 100-data_len-1);
        }
    }
    goodB2G_sink(data);
}

void CWE187_Partial_Comparison__wchar_t_Environment_ncmp_user_pw_41_good()
{
    goodB2G();
    goodG2B();
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
    CWE187_Partial_Comparison__wchar_t_Environment_ncmp_user_pw_41_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE187_Partial_Comparison__wchar_t_Environment_ncmp_user_pw_41_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
