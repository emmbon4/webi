/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__wchar_t_Environment_vfprintf_11.c
Label Definition File: CWE134_Uncontrolled_Format_String.vasinks.label.xml
Template File: sources-vasinks-11.tmpl.c
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * BadSource: Environment Read input from an environment variable
 * GoodSource: Copy a fixed string into data
 * Sinks: vfprintf
 *    GoodSink: vfwprintf with a format string
 *    BadSink : vfwprintf without a format string
 * Flow Variant: 11 Control flow: if(global_returns_t()) and if(global_returns_f())
 *
 * */

#include <stdarg.h>
#include "std_testcase.h"

#define ENV_VARIABLE L"ADD"

#ifdef _WIN32
# define GETENV _wgetenv
#else
# define GETENV wgetenv
#endif

#ifndef OMITBAD

static void bad_vasinkb(wchar_t * data, ...)
{
    {
        va_list args;
        va_start(args, data);
        /* POTENTIAL FLAW: Do not specify the format allowing a possible format string vulnerability */
        vfwprintf(stdout, data, args);
        va_end(args);
    }
}

/* INCIDENTAL: CWE 561 Dead Code, the function below is never called */
static void bad_vasinkg(wchar_t * data, ...)
{
    {
        va_list args;
        va_start(args, data);
        /* FIX: Specify the format disallowing a format string vulnerability */
        vfwprintf(stdout, L"%s", args);
        va_end(args);
    }
}

void CWE134_Uncontrolled_Format_String__wchar_t_Environment_vfprintf_11_bad()
{
    wchar_t * data;
    wchar_t data_buf[100] = L"";
    data = data_buf;
    if(global_returns_t())
    {
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
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Use a fixed string that does not contain a format specifier */
        wcscpy(data, L"fixedstringtest");
    }
    if(global_returns_t())
    {
        bad_vasinkb(data, data);
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        bad_vasinkg(data, data);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* INCIDENTAL: CWE 561 Dead Code, the function below is never called */
static void goodB2G1_vasinkb(wchar_t * data, ...)
{
    {
        va_list args;
        va_start(args, data);
        /* POTENTIAL FLAW: Do not specify the format allowing a possible format string vulnerability */
        vfwprintf(stdout, data, args);
        va_end(args);
    }
}

static void goodB2G1_vasinkg(wchar_t * data, ...)
{
    {
        va_list args;
        va_start(args, data);
        /* FIX: Specify the format disallowing a format string vulnerability */
        vfwprintf(stdout, L"%s", args);
        va_end(args);
    }
}

/* goodB2G1() - use badsource and goodsink by changing the second global_returns_t() to global_returns_f() */
static void goodB2G1()
{
    wchar_t * data;
    wchar_t data_buf[100] = L"";
    data = data_buf;
    if(global_returns_t())
    {
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
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Use a fixed string that does not contain a format specifier */
        wcscpy(data, L"fixedstringtest");
    }
    if(global_returns_f())
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        goodB2G1_vasinkb(data, data);
    }
    else
    {
        goodB2G1_vasinkg(data, data);
    }
}

/* INCIDENTAL: CWE 561 Dead Code, the function below is never called */
static void goodB2G2_vasinkb(wchar_t * data, ...)
{
    {
        va_list args;
        va_start(args, data);
        /* POTENTIAL FLAW: Do not specify the format allowing a possible format string vulnerability */
        vfwprintf(stdout, data, args);
        va_end(args);
    }
}

static void goodB2G2_vasinkg(wchar_t * data, ...)
{
    {
        va_list args;
        va_start(args, data);
        /* FIX: Specify the format disallowing a format string vulnerability */
        vfwprintf(stdout, L"%s", args);
        va_end(args);
    }
}

/* goodB2G2() - use badsource and goodsink by reversing the blocks in the second if */
static void goodB2G2()
{
    wchar_t * data;
    wchar_t data_buf[100] = L"";
    data = data_buf;
    if(global_returns_t())
    {
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
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Use a fixed string that does not contain a format specifier */
        wcscpy(data, L"fixedstringtest");
    }
    if(global_returns_t())
    {
        goodB2G2_vasinkg(data, data);
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        goodB2G2_vasinkb(data, data);
    }
}

/* INCIDENTAL: CWE 561 Dead Code, the function below is never called */
static void goodG2B1_vasinkg(wchar_t * data, ...)
{
    {
        va_list args;
        va_start(args, data);
        /* FIX: Specify the format disallowing a format string vulnerability */
        vfwprintf(stdout, L"%s", args);
        va_end(args);
    }
}

static void goodG2B1_vasinkb(wchar_t * data, ...)
{
    {
        va_list args;
        va_start(args, data);
        /* POTENTIAL FLAW: Do not specify the format allowing a possible format string vulnerability */
        vfwprintf(stdout, data, args);
        va_end(args);
    }
}

/* goodG2B1() - use goodsource and badsink by changing the first global_returns_t() to global_returns_f() */
static void goodG2B1()
{
    wchar_t * data;
    wchar_t data_buf[100] = L"";
    data = data_buf;
    if(global_returns_f())
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
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
    }
    else
    {
        /* FIX: Use a fixed string that does not contain a format specifier */
        wcscpy(data, L"fixedstringtest");
    }
    if(global_returns_t())
    {
        goodG2B1_vasinkb(data, data);
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        goodG2B1_vasinkg(data, data);
    }
}

/* INCIDENTAL: CWE 561 Dead Code, the function below is never called */
static void goodG2B2_vasinkg(wchar_t * data, ...)
{
    {
        va_list args;
        va_start(args, data);
        /* FIX: Specify the format disallowing a format string vulnerability */
        vfwprintf(stdout, L"%s", args);
        va_end(args);
    }
}

static void goodG2B2_vasinkb(wchar_t * data, ...)
{
    {
        va_list args;
        va_start(args, data);
        /* POTENTIAL FLAW: Do not specify the format allowing a possible format string vulnerability */
        vfwprintf(stdout, data, args);
        va_end(args);
    }
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the first if */
static void goodG2B2()
{
    wchar_t * data;
    wchar_t data_buf[100] = L"";
    data = data_buf;
    if(global_returns_t())
    {
        /* FIX: Use a fixed string that does not contain a format specifier */
        wcscpy(data, L"fixedstringtest");
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
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
    }
    if(global_returns_t())
    {
        goodG2B2_vasinkb(data, data);
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        goodG2B2_vasinkg(data, data);
    }
}

void CWE134_Uncontrolled_Format_String__wchar_t_Environment_vfprintf_11_good()
{
    goodG2B1();
    goodG2B2();
    goodB2G1();
    goodB2G2();
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
    CWE134_Uncontrolled_Format_String__wchar_t_Environment_vfprintf_11_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE134_Uncontrolled_Format_String__wchar_t_Environment_vfprintf_11_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
