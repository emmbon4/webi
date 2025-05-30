/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__wchar_t_fromConsole_fprintf_67b.c
Label Definition File: CWE134_Uncontrolled_Format_String.label.xml
Template File: sources-sinks-67b.tmpl.c
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * BadSource: fromConsole Read input from the console
 * GoodSource: Copy a fixed string into data
 * Sinks: fprintf
 *    GoodSink: fwprintf with "%s" as the second argument and data as the third
 *    BadSink : fwprintf with data as the second argument
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

typedef struct _CWE134_Uncontrolled_Format_String__wchar_t_fromConsole_fprintf_67_struct_type
{
    wchar_t * a;
} CWE134_Uncontrolled_Format_String__wchar_t_fromConsole_fprintf_67_struct_type;

#ifndef OMITBAD

void CWE134_Uncontrolled_Format_String__wchar_t_fromConsole_fprintf_67b_bad_sink(CWE134_Uncontrolled_Format_String__wchar_t_fromConsole_fprintf_67_struct_type my_struct)
{
    wchar_t * data = my_struct.a;
    /* POTENTIAL FLAW: Do not specify the format allowing a possible format string vulnerability */
    fwprintf(stdout, data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE134_Uncontrolled_Format_String__wchar_t_fromConsole_fprintf_67b_goodG2B_sink(CWE134_Uncontrolled_Format_String__wchar_t_fromConsole_fprintf_67_struct_type my_struct)
{
    wchar_t * data = my_struct.a;
    /* POTENTIAL FLAW: Do not specify the format allowing a possible format string vulnerability */
    fwprintf(stdout, data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE134_Uncontrolled_Format_String__wchar_t_fromConsole_fprintf_67b_goodB2G_sink(CWE134_Uncontrolled_Format_String__wchar_t_fromConsole_fprintf_67_struct_type my_struct)
{
    wchar_t * data = my_struct.a;
    /* FIX: Specify the format disallowing a format string vulnerability */
    fwprintf(stdout, L"%s\n", data);
}

#endif /* OMITGOOD */
