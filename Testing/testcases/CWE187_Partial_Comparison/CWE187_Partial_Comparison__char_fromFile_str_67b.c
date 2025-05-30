/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE187_Partial_Comparison__char_fromFile_str_67b.c
Label Definition File: CWE187_Partial_Comparison.label.xml
Template File: sources-sinks-67b.tmpl.c
*/
/*
 * @description
 * CWE: 187 Partial Comparison
 * BadSource: fromFile Read input from a file
 * GoodSource: Provide a matching password
 * Sinks: str
 *    GoodSink: Compare the 2 passwords correctly
 *    BadSink : use strstr() to do password match, which is a partial comparison
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#define PASSWORD "Password1234"
/* PASSWORD_SZ must equal the length of PASSWORD */
#define PASSWORD_SZ strlen(PASSWORD)

#ifdef _WIN32
# define FOPEN fopen
#else
/* fopen is used on unix-based OSs */
# define FOPEN fopen
#endif

typedef struct _CWE187_Partial_Comparison__char_fromFile_str_67_struct_type
{
    char * a;
} CWE187_Partial_Comparison__char_fromFile_str_67_struct_type;

#ifndef OMITBAD

void CWE187_Partial_Comparison__char_fromFile_str_67b_bad_sink(CWE187_Partial_Comparison__char_fromFile_str_67_struct_type my_struct)
{
    char * data = my_struct.a;
    /* POTENTIAL FLAW: Partially compare the two passwords */
    if (strstr(PASSWORD, data) != NULL)
        printLine("Access granted");
    else
        printLine("Access denied!");
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE187_Partial_Comparison__char_fromFile_str_67b_goodG2B_sink(CWE187_Partial_Comparison__char_fromFile_str_67_struct_type my_struct)
{
    char * data = my_struct.a;
    /* POTENTIAL FLAW: Partially compare the two passwords */
    if (strstr(PASSWORD, data) != NULL)
        printLine("Access granted");
    else
        printLine("Access denied!");
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE187_Partial_Comparison__char_fromFile_str_67b_goodB2G_sink(CWE187_Partial_Comparison__char_fromFile_str_67_struct_type my_struct)
{
    char * data = my_struct.a;
    /* Ideally, we would want to do a check to see if the passwords are of equal length */
    /* FIX: Compare the two passwords completely and correctly */
    if (strcmp(PASSWORD, data) == 0)
        printLine("Access granted");
    else
        printLine("Access denied!");
}

#endif /* OMITGOOD */
