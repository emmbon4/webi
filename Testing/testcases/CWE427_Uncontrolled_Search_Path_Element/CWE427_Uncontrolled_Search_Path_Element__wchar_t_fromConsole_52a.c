/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE427_Uncontrolled_Search_Path_Element__wchar_t_fromConsole_52a.c
Label Definition File: CWE427_Uncontrolled_Search_Path_Element.label.xml
Template File: sources-sink-52a.tmpl.c
*/
/*
 * @description
 * CWE: 427 Uncontrolled Search Path Element
 * BadSource: fromConsole Read input from the console
 * GoodSource: Use a hardcoded path
 * Sink:
 *    BadSink : Set the environment variable
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifdef _WIN32
# define NEW_PATH L"%SystemRoot%\\system32"
# define PUTENV _wputenv
#else
# define NEW_PATH L"/bin"
# define PUTENV wputenv
#endif

#ifndef OMITBAD

/* bad function declaration */
void CWE427_Uncontrolled_Search_Path_Element__wchar_t_fromConsole_52b_bad_sink(wchar_t * data);

void CWE427_Uncontrolled_Search_Path_Element__wchar_t_fromConsole_52_bad()
{
    wchar_t * data;
    wchar_t data_buf[250] = L"PATH=";
    data = data_buf;
    {
        /* Read input from the console */
        size_t data_len = wcslen(data);
        /* if there is room in data, read into it from the console */
        if(250-data_len > 1)
        {
            fgetws(data+data_len, (int)(250-data_len), stdin);
            /* The next 3 lines remove the carriage return from the string that is
             * inserted by fgetws() */
            data_len = wcslen(data);
            if (data_len > 0)
            {
                data[data_len-1] = L'\0';
            }
        }
    }
    CWE427_Uncontrolled_Search_Path_Element__wchar_t_fromConsole_52b_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declaration */
void CWE427_Uncontrolled_Search_Path_Element__wchar_t_fromConsole_52b_goodG2B_sink(wchar_t * data);

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    wchar_t * data;
    wchar_t data_buf[250] = L"PATH=";
    data = data_buf;
    /* FIX: Set the path as the "system" path */
    wcscat(data, NEW_PATH);
    CWE427_Uncontrolled_Search_Path_Element__wchar_t_fromConsole_52b_goodG2B_sink(data);
}

void CWE427_Uncontrolled_Search_Path_Element__wchar_t_fromConsole_52_good()
{
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
    CWE427_Uncontrolled_Search_Path_Element__wchar_t_fromConsole_52_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE427_Uncontrolled_Search_Path_Element__wchar_t_fromConsole_52_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
