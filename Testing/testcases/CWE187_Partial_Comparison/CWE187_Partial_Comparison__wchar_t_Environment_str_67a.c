/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE187_Partial_Comparison__wchar_t_Environment_str_67a.c
Label Definition File: CWE187_Partial_Comparison.label.xml
Template File: sources-sinks-67a.tmpl.c
*/
/*
 * @description
 * CWE: 187 Partial Comparison
 * BadSource: Environment Read input from an environment variable
 * GoodSource: Provide a matching password
 * Sinks: str
 *    GoodSink: Compare the 2 passwords correctly
 *    BadSink : use wcsstr() to do password match, which is a partial comparison
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
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

typedef struct _CWE187_Partial_Comparison__wchar_t_Environment_str_67_struct_type
{
    wchar_t * a;
} CWE187_Partial_Comparison__wchar_t_Environment_str_67_struct_type;

#ifndef OMITBAD

/* bad function declaration */
void CWE187_Partial_Comparison__wchar_t_Environment_str_67b_bad_sink(CWE187_Partial_Comparison__wchar_t_Environment_str_67_struct_type my_struct);

void CWE187_Partial_Comparison__wchar_t_Environment_str_67_bad()
{
    wchar_t * data;
    CWE187_Partial_Comparison__wchar_t_Environment_str_67_struct_type my_struct;
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
    my_struct.a = data;
    CWE187_Partial_Comparison__wchar_t_Environment_str_67b_bad_sink(my_struct);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE187_Partial_Comparison__wchar_t_Environment_str_67b_goodG2B_sink(CWE187_Partial_Comparison__wchar_t_Environment_str_67_struct_type my_struct);

static void goodG2B()
{
    wchar_t * data;
    CWE187_Partial_Comparison__wchar_t_Environment_str_67_struct_type my_struct;
    wchar_t data_buf[100] = L"";
    data = data_buf;
    /* FIX: Use the matching string */
    data = PASSWORD;
    my_struct.a = data;
    CWE187_Partial_Comparison__wchar_t_Environment_str_67b_goodG2B_sink(my_struct);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE187_Partial_Comparison__wchar_t_Environment_str_67b_goodB2G_sink(CWE187_Partial_Comparison__wchar_t_Environment_str_67_struct_type my_struct);

static void goodB2G()
{
    wchar_t * data;
    CWE187_Partial_Comparison__wchar_t_Environment_str_67_struct_type my_struct;
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
    my_struct.a = data;
    CWE187_Partial_Comparison__wchar_t_Environment_str_67b_goodB2G_sink(my_struct);
}

void CWE187_Partial_Comparison__wchar_t_Environment_str_67_good()
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
    CWE187_Partial_Comparison__wchar_t_Environment_str_67_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE187_Partial_Comparison__wchar_t_Environment_str_67_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
