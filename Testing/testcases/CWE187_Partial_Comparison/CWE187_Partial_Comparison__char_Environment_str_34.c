/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE187_Partial_Comparison__char_Environment_str_34.c
Label Definition File: CWE187_Partial_Comparison.label.xml
Template File: sources-sinks-34.tmpl.c
*/
/*
 * @description
 * CWE: 187 Partial Comparison
 * BadSource: Environment Read input from an environment variable
 * GoodSource: Provide a matching password
 * Sinks: str
 *    GoodSink: Compare the 2 passwords correctly
 *    BadSink : use strstr() to do password match, which is a partial comparison
 * Flow Variant: 34 Data flow: use of a union containing two methods of accessing the same data (within the same function)
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

typedef union
{
    char * a;
    char * b;
} CWE187_Partial_Comparison__char_Environment_str_34_union_type;

#ifndef OMITBAD

void CWE187_Partial_Comparison__char_Environment_str_34_bad()
{
    char * data;
    CWE187_Partial_Comparison__char_Environment_str_34_union_type my_union;
    char data_buf[100] = "";
    data = data_buf;
    {
        /* Read input from an environment variable */
        size_t data_len = strlen(data);
        char * environment = GETENV(ENV_VARIABLE);
        /* If there is data in the environment variable */
        if (environment != NULL)
        {
            strncat(data+data_len, environment, 100-data_len-1);
        }
    }
    my_union.a = data;
    {
        char * data = my_union.b;
        /* POTENTIAL FLAW: Partially compare the two passwords */
        if (strstr(PASSWORD, data) != NULL)
            printLine("Access granted");
        else
            printLine("Access denied!");
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    char * data;
    CWE187_Partial_Comparison__char_Environment_str_34_union_type my_union;
    char data_buf[100] = "";
    data = data_buf;
    /* FIX: Use the matching string */
    data = PASSWORD;
    my_union.a = data;
    {
        char * data = my_union.b;
        /* POTENTIAL FLAW: Partially compare the two passwords */
        if (strstr(PASSWORD, data) != NULL)
            printLine("Access granted");
        else
            printLine("Access denied!");
    }
}

/* goodB2G() uses the BadSource with the GoodSink */
static void goodB2G()
{
    char * data;
    CWE187_Partial_Comparison__char_Environment_str_34_union_type my_union;
    char data_buf[100] = "";
    data = data_buf;
    {
        /* Read input from an environment variable */
        size_t data_len = strlen(data);
        char * environment = GETENV(ENV_VARIABLE);
        /* If there is data in the environment variable */
        if (environment != NULL)
        {
            strncat(data+data_len, environment, 100-data_len-1);
        }
    }
    my_union.a = data;
    {
        char * data = my_union.b;
        /* Ideally, we would want to do a check to see if the passwords are of equal length */
        /* FIX: Compare the two passwords completely and correctly */
        if (strcmp(PASSWORD, data) == 0)
            printLine("Access granted");
        else
            printLine("Access denied!");
    }
}

void CWE187_Partial_Comparison__char_Environment_str_34_good()
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
    CWE187_Partial_Comparison__char_Environment_str_34_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE187_Partial_Comparison__char_Environment_str_34_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
