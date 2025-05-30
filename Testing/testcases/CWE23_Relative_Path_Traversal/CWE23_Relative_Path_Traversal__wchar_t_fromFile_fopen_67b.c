/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE23_Relative_Path_Traversal__wchar_t_fromFile_fopen_67b.c
Label Definition File: CWE23_Relative_Path_Traversal.label.xml
Template File: sources-sink-67b.tmpl.c
*/
/*
 * @description
 * CWE: 23 Relative Path Traversal
 * BadSource: fromFile Read input from a file
 * GoodSource: File name without a period or slash
 * Sinks: fopen
 *    BadSink :
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
#define BASEPATH L"c:\\temp\\"
#else
#define BASEPATH L"/tmp/"
#endif

#ifdef _WIN32
# define FOPEN _wfopen
#else
/* fopen is used on unix-based OSs */
# define FOPEN fopen
#endif

#ifdef _WIN32
# define FOPEN _wfopen
#else
/* fopen is used on unix-based OSs */
# define FOPEN fopen
#endif

typedef struct _CWE23_Relative_Path_Traversal__wchar_t_fromFile_fopen_67_struct_type
{
    wchar_t * a;
} CWE23_Relative_Path_Traversal__wchar_t_fromFile_fopen_67_struct_type;

#ifndef OMITBAD

void CWE23_Relative_Path_Traversal__wchar_t_fromFile_fopen_67b_bad_sink(CWE23_Relative_Path_Traversal__wchar_t_fromFile_fopen_67_struct_type my_struct)
{
    wchar_t * data = my_struct.a;
    {
        FILE *file = NULL;
        /* POTENTIAL FLAW: Possibly opening a file without validating the file name or path */
        file = FOPEN(data, L"wb+");
        if (file != NULL) fclose(file);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE23_Relative_Path_Traversal__wchar_t_fromFile_fopen_67b_goodG2B_sink(CWE23_Relative_Path_Traversal__wchar_t_fromFile_fopen_67_struct_type my_struct)
{
    wchar_t * data = my_struct.a;
    {
        FILE *file = NULL;
        /* POTENTIAL FLAW: Possibly opening a file without validating the file name or path */
        file = FOPEN(data, L"wb+");
        if (file != NULL) fclose(file);
    }
}

#endif /* OMITGOOD */
