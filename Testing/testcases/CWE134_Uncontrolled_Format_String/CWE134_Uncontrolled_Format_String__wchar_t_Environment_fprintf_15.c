/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__wchar_t_Environment_fprintf_15.c
Label Definition File: CWE134_Uncontrolled_Format_String.label.xml
Template File: sources-sinks-15.tmpl.c
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * BadSource: Environment Read input from an environment variable
 * GoodSource: Copy a fixed string into data
 * Sinks: fprintf
 *    GoodSink: fwprintf with "%s" as the second argument and data as the third
 *    BadSink : fwprintf with data as the second argument
 * Flow Variant: 15 Control flow: switch(6) and switch(7)
 *
 * */

#include "std_testcase.h"

#define ENV_VARIABLE L"ADD"

#ifdef _WIN32
# define GETENV _wgetenv
#else
# define GETENV wgetenv
#endif

#ifndef OMITBAD

void CWE134_Uncontrolled_Format_String__wchar_t_Environment_fprintf_15_bad()
{
    wchar_t * data;
    wchar_t data_buf[100] = L"";
    data = data_buf;
    switch(6)
    {
    case 6:
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
    break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Use a fixed string that does not contain a format specifier */
        wcscpy(data, L"fixedstringtest");
        break;
    }
    switch(7)
    {
    case 7:
        /* POTENTIAL FLAW: Do not specify the format allowing a possible format string vulnerability */
        fwprintf(stdout, data);
        break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Specify the format disallowing a format string vulnerability */
        fwprintf(stdout, L"%s\n", data);
        break;
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G1() - use badsource and goodsink by changing the second switch to switch(8) */
static void goodB2G1()
{
    wchar_t * data;
    wchar_t data_buf[100] = L"";
    data = data_buf;
    switch(6)
    {
    case 6:
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
    break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Use a fixed string that does not contain a format specifier */
        wcscpy(data, L"fixedstringtest");
        break;
    }
    switch(8)
    {
    case 7:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* POTENTIAL FLAW: Do not specify the format allowing a possible format string vulnerability */
        fwprintf(stdout, data);
        break;
    default:
        /* FIX: Specify the format disallowing a format string vulnerability */
        fwprintf(stdout, L"%s\n", data);
        break;
    }
}

/* goodB2G2() - use badsource and goodsink by reversing the blocks in the second switch */
static void goodB2G2()
{
    wchar_t * data;
    wchar_t data_buf[100] = L"";
    data = data_buf;
    switch(6)
    {
    case 6:
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
    break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Use a fixed string that does not contain a format specifier */
        wcscpy(data, L"fixedstringtest");
        break;
    }
    switch(7)
    {
    case 7:
        /* FIX: Specify the format disallowing a format string vulnerability */
        fwprintf(stdout, L"%s\n", data);
        break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* POTENTIAL FLAW: Do not specify the format allowing a possible format string vulnerability */
        fwprintf(stdout, data);
        break;
    }
}

/* goodG2B1() - use goodsource and badsink by changing the first switch to switch(5) */
static void goodG2B1()
{
    wchar_t * data;
    wchar_t data_buf[100] = L"";
    data = data_buf;
    switch(5)
    {
    case 6:
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
    break;
    default:
        /* FIX: Use a fixed string that does not contain a format specifier */
        wcscpy(data, L"fixedstringtest");
        break;
    }
    switch(7)
    {
    case 7:
        /* POTENTIAL FLAW: Do not specify the format allowing a possible format string vulnerability */
        fwprintf(stdout, data);
        break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Specify the format disallowing a format string vulnerability */
        fwprintf(stdout, L"%s\n", data);
        break;
    }
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the first switch */
static void goodG2B2()
{
    wchar_t * data;
    wchar_t data_buf[100] = L"";
    data = data_buf;
    switch(6)
    {
    case 6:
        /* FIX: Use a fixed string that does not contain a format specifier */
        wcscpy(data, L"fixedstringtest");
        break;
    default:
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
    break;
    }
    switch(7)
    {
    case 7:
        /* POTENTIAL FLAW: Do not specify the format allowing a possible format string vulnerability */
        fwprintf(stdout, data);
        break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Specify the format disallowing a format string vulnerability */
        fwprintf(stdout, L"%s\n", data);
        break;
    }
}

void CWE134_Uncontrolled_Format_String__wchar_t_Environment_fprintf_15_good()
{
    goodB2G1();
    goodB2G2();
    goodG2B1();
    goodG2B2();
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
    CWE134_Uncontrolled_Format_String__wchar_t_Environment_fprintf_15_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE134_Uncontrolled_Format_String__wchar_t_Environment_fprintf_15_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
