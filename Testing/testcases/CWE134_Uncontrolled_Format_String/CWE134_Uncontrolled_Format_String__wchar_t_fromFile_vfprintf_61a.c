/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__wchar_t_fromFile_vfprintf_61a.c
Label Definition File: CWE134_Uncontrolled_Format_String.vasinks.label.xml
Template File: sources-vasinks-61a.tmpl.c
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * BadSource: fromFile Read input from a file
 * GoodSource: Copy a fixed string into data
 * Sinks: vfprintf
 *    GoodSink: vfwprintf with a format string
 *    BadSink : vfwprintf without a format string
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include <stdarg.h>
#include "std_testcase.h"

#ifdef _WIN32
# define FOPEN _wfopen
#else
/* fopen is used on unix-based OSs */
# define FOPEN fopen
#endif

#ifndef OMITBAD

/* bad function declaration */
wchar_t * CWE134_Uncontrolled_Format_String__wchar_t_fromFile_vfprintf_61b_bad_source(wchar_t * data);

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

void CWE134_Uncontrolled_Format_String__wchar_t_fromFile_vfprintf_61_bad()
{
    wchar_t * data;
    wchar_t data_buf[100] = L"";
    data = data_buf;
    data = CWE134_Uncontrolled_Format_String__wchar_t_fromFile_vfprintf_61b_bad_source(data);
    bad_vasink(data, data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
wchar_t * CWE134_Uncontrolled_Format_String__wchar_t_fromFile_vfprintf_61b_goodG2B_source(wchar_t * data);

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
    wchar_t data_buf[100] = L"";
    data = data_buf;
    data = CWE134_Uncontrolled_Format_String__wchar_t_fromFile_vfprintf_61b_goodG2B_source(data);
    goodG2B_vasink(data, data);
}

/* goodB2G uses the BadSource with the GoodSink */
wchar_t * CWE134_Uncontrolled_Format_String__wchar_t_fromFile_vfprintf_61b_goodB2G_source(wchar_t * data);

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
    wchar_t data_buf[100] = L"";
    data = data_buf;
    data = CWE134_Uncontrolled_Format_String__wchar_t_fromFile_vfprintf_61b_goodB2G_source(data);
    goodB2G_vasink(data, data);
}

void CWE134_Uncontrolled_Format_String__wchar_t_fromFile_vfprintf_61_good()
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
    CWE134_Uncontrolled_Format_String__wchar_t_fromFile_vfprintf_61_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE134_Uncontrolled_Format_String__wchar_t_fromFile_vfprintf_61_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
