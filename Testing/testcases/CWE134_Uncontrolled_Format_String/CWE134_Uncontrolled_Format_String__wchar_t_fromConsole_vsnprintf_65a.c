/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__wchar_t_fromConsole_vsnprintf_65a.c
Label Definition File: CWE134_Uncontrolled_Format_String.vasinks.label.xml
Template File: sources-vasinks-65a.tmpl.c
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * BadSource: fromConsole Read input from the console
 * GoodSource: Copy a fixed string into data
 * Sinks: vsnprintf
 *    GoodSink: _vsnwprintf with a format string
 *    BadSink : _vsnwprintf without a format string
 * Flow Variant: 65 Data/control flow: data passed as an argument from one function to a function in a different source file called via a function pointer
 *
 * */

#include <stdarg.h>
#include "std_testcase.h"

#ifndef OMITBAD

/* bad function declaration */
void CWE134_Uncontrolled_Format_String__wchar_t_fromConsole_vsnprintf_65b_bad_vasink(wchar_t * data, ...);

void CWE134_Uncontrolled_Format_String__wchar_t_fromConsole_vsnprintf_65_bad()
{
    wchar_t * data;
    /* define a function pointer */
    void (*func_ptr) (wchar_t *, ...) = CWE134_Uncontrolled_Format_String__wchar_t_fromConsole_vsnprintf_65b_bad_vasink;
    wchar_t data_buf[100] = L"";
    data = data_buf;
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
    /* use the function pointer */
    func_ptr(data, data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE134_Uncontrolled_Format_String__wchar_t_fromConsole_vsnprintf_65b_goodG2B_vasink(wchar_t * data, ...);

static void goodG2B()
{
    wchar_t * data;
    void (*func_ptr) (wchar_t *, ...) = CWE134_Uncontrolled_Format_String__wchar_t_fromConsole_vsnprintf_65b_goodG2B_vasink;
    wchar_t data_buf[100] = L"";
    data = data_buf;
    /* FIX: Use a fixed string that does not contain a format specifier */
    wcscpy(data, L"fixedstringtest");
    func_ptr(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE134_Uncontrolled_Format_String__wchar_t_fromConsole_vsnprintf_65b_goodB2G_vasink(wchar_t * data, ...);

static void goodB2G()
{
    wchar_t * data;
    void (*func_ptr) (wchar_t *, ...) = CWE134_Uncontrolled_Format_String__wchar_t_fromConsole_vsnprintf_65b_goodB2G_vasink;
    wchar_t data_buf[100] = L"";
    data = data_buf;
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
    func_ptr(data);
}

void CWE134_Uncontrolled_Format_String__wchar_t_fromConsole_vsnprintf_65_good()
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
    CWE134_Uncontrolled_Format_String__wchar_t_fromConsole_vsnprintf_65_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE134_Uncontrolled_Format_String__wchar_t_fromConsole_vsnprintf_65_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
