/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__char_fromFile_vfprintf_67b.c
Label Definition File: CWE134_Uncontrolled_Format_String.vasinks.label.xml
Template File: sources-vasinks-67b.tmpl.c
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * BadSource: fromFile Read input from a file
 * GoodSource: Copy a fixed string into data
 * Sinks: vfprintf
 *    GoodSink: vfprintf with a format string
 *    BadSink : vfprintf without a format string
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include <stdarg.h>
#include "std_testcase.h"

#ifdef _WIN32
# define FOPEN fopen
#else
/* fopen is used on unix-based OSs */
# define FOPEN fopen
#endif

typedef struct _CWE134_Uncontrolled_Format_String__char_fromFile_vfprintf_67_struct_type
{
    char * a;
} CWE134_Uncontrolled_Format_String__char_fromFile_vfprintf_67_struct_type;

#ifndef OMITBAD

static void bad_vasink(char * data, ...)
{
    {
        va_list args;
        va_start(args, data);
        /* POTENTIAL FLAW: Do not specify the format allowing a possible format string vulnerability */
        vfprintf(stdout, data, args);
        va_end(args);
    }
}

void CWE134_Uncontrolled_Format_String__char_fromFile_vfprintf_67b_bad_sink(CWE134_Uncontrolled_Format_String__char_fromFile_vfprintf_67_struct_type my_struct)
{
    char * data = my_struct.a;
    bad_vasink(data, data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B_vasink(char * data, ...)
{
    {
        va_list args;
        va_start(args, data);
        /* POTENTIAL FLAW: Do not specify the format allowing a possible format string vulnerability */
        vfprintf(stdout, data, args);
        va_end(args);
    }
}

void CWE134_Uncontrolled_Format_String__char_fromFile_vfprintf_67b_goodG2B_sink(CWE134_Uncontrolled_Format_String__char_fromFile_vfprintf_67_struct_type my_struct)
{
    char * data = my_struct.a;
    goodG2B_vasink(data, data);
}

/* goodB2G uses the BadSource with the GoodSink */
static void goodB2G_vasink(char * data, ...)
{
    {
        va_list args;
        va_start(args, data);
        /* FIX: Specify the format disallowing a format string vulnerability */
        vfprintf(stdout, "%s", args);
        va_end(args);
    }
}

void CWE134_Uncontrolled_Format_String__char_fromFile_vfprintf_67b_goodB2G_sink(CWE134_Uncontrolled_Format_String__char_fromFile_vfprintf_67_struct_type my_struct)
{
    char * data = my_struct.a;
    goodB2G_vasink(data, data);
}

#endif /* OMITGOOD */
