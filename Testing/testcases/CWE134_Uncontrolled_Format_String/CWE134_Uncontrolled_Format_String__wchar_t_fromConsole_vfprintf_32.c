/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__wchar_t_fromConsole_vfprintf_32.c
Label Definition File: CWE134_Uncontrolled_Format_String.vasinks.label.xml
Template File: sources-vasinks-32.tmpl.c
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * BadSource: fromConsole Read input from the console
 * GoodSource: Copy a fixed string into data
 * Sinks: vfprintf
 *    GoodSink: vfwprintf with a format string
 *    BadSink : vfwprintf without a format string
 * Flow Variant: 32 Data flow using two pointers to the same value within the same function
 *
 * */

#include <stdarg.h>
#include "std_testcase.h"

#ifndef OMITBAD

static void bad_vasink(wchar_t * data, ...)
{
    {
        va_list args;
        va_start(args, data);
        /* POTENTIAL FLAW: Do not specify the format allowing a possible format string vulnerability */
        vfwprintf(stdout, data, args);
        va_end(args);
    }
}

void CWE134_Uncontrolled_Format_String__wchar_t_fromConsole_vfprintf_32_bad()
{
    wchar_t * data;
    wchar_t * *data_ptr1 = &data;
    wchar_t * *data_ptr2 = &data;
    wchar_t data_buf[100] = L"";
    data = data_buf;
    {
        wchar_t * data = *data_ptr1;
        {
            /* Read input from the console */
            size_t data_len = wcslen(data);
            /* if there is room in data, read into it from the console */
            if(100-data_len > 1)
            {
                fgetws(data+data_len, (int)(100-data_len), stdin);
                /* The next 3 lines remove the carriage return from the string that is
                 * inserted by fgetws() */
                data_len = wcslen(data);
                if (data_len > 0)
                {
                    data[data_len-1] = L'\0';
                }
            }
        }
        *data_ptr1 = data;
    }
    {
        wchar_t * data = *data_ptr2;
        bad_vasink(data, data);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B_vasink(wchar_t * data, ...)
{
    {
        va_list args;
        va_start(args, data);
        /* POTENTIAL FLAW: Do not specify the format allowing a possible format string vulnerability */
        vfwprintf(stdout, data, args);
        va_end(args);
    }
}

static void goodG2B()
{
    wchar_t * data;
    wchar_t * *data_ptr1 = &data;
    wchar_t * *data_ptr2 = &data;
    wchar_t data_buf[100] = L"";
    data = data_buf;
    {
        wchar_t * data = *data_ptr1;
        /* FIX: Use a fixed string that does not contain a format specifier */
        wcscpy(data, L"fixedstringtest");
        *data_ptr1 = data;
    }
    {
        wchar_t * data = *data_ptr2;
        goodG2B_vasink(data, data);
    }
}

/* goodB2G uses the BadSource with the GoodSink */
static void goodB2G_vasink(wchar_t * data, ...)
{
    {
        va_list args;
        va_start(args, data);
        /* FIX: Specify the format disallowing a format string vulnerability */
        vfwprintf(stdout, L"%s", args);
        va_end(args);
    }
}

static void goodB2G()
{
    wchar_t * data;
    wchar_t * *data_ptr1 = &data;
    wchar_t * *data_ptr2 = &data;
    wchar_t data_buf[100] = L"";
    data = data_buf;
    {
        wchar_t * data = *data_ptr1;
        {
            /* Read input from the console */
            size_t data_len = wcslen(data);
            /* if there is room in data, read into it from the console */
            if(100-data_len > 1)
            {
                fgetws(data+data_len, (int)(100-data_len), stdin);
                /* The next 3 lines remove the carriage return from the string that is
                 * inserted by fgetws() */
                data_len = wcslen(data);
                if (data_len > 0)
                {
                    data[data_len-1] = L'\0';
                }
            }
        }
        *data_ptr1 = data;
    }
    {
        wchar_t * data = *data_ptr2;
        goodB2G_vasink(data, data);
    }
}

void CWE134_Uncontrolled_Format_String__wchar_t_fromConsole_vfprintf_32_good()
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
    CWE134_Uncontrolled_Format_String__wchar_t_fromConsole_vfprintf_32_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE134_Uncontrolled_Format_String__wchar_t_fromConsole_vfprintf_32_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
