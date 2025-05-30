/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__wchar_t_fromFile_vsnprintf_67a.c
Label Definition File: CWE134_Uncontrolled_Format_String.vasinks.label.xml
Template File: sources-vasinks-67a.tmpl.c
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * BadSource: fromFile Read input from a file
 * GoodSource: Copy a fixed string into data
 * Sinks: vsnprintf
 *    GoodSink: _vsnwprintf with a format string
 *    BadSink : _vsnwprintf without a format string
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
# define FOPEN _wfopen
#else
/* fopen is used on unix-based OSs */
# define FOPEN fopen
#endif

typedef struct _CWE134_Uncontrolled_Format_String__wchar_t_fromFile_vsnprintf_67_struct_type
{
    wchar_t * a;
} CWE134_Uncontrolled_Format_String__wchar_t_fromFile_vsnprintf_67_struct_type;

#ifndef OMITBAD

/* bad function declaration */
void CWE134_Uncontrolled_Format_String__wchar_t_fromFile_vsnprintf_67b_bad_sink(CWE134_Uncontrolled_Format_String__wchar_t_fromFile_vsnprintf_67_struct_type my_struct);

void CWE134_Uncontrolled_Format_String__wchar_t_fromFile_vsnprintf_67_bad()
{
    wchar_t * data;
    CWE134_Uncontrolled_Format_String__wchar_t_fromFile_vsnprintf_67_struct_type my_struct;
    wchar_t data_buf[100] = L"";
    data = data_buf;
    {
        /* Read input from a file */
        size_t data_len = wcslen(data);
        FILE * pFile;
        /* if there is room in data, attempt to read the input from a file */
        if(100-data_len > 1)
        {
            pFile = FOPEN(L"C:\\temp\\file.txt", L"r");
            if (pFile != NULL)
            {
                fgetws(data+data_len, (int)(100-data_len), pFile);
                fclose(pFile);
            }
        }
    }
    my_struct.a = data;
    CWE134_Uncontrolled_Format_String__wchar_t_fromFile_vsnprintf_67b_bad_sink(my_struct);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE134_Uncontrolled_Format_String__wchar_t_fromFile_vsnprintf_67b_goodG2B_sink(CWE134_Uncontrolled_Format_String__wchar_t_fromFile_vsnprintf_67_struct_type my_struct);

static void goodG2B()
{
    wchar_t * data;
    CWE134_Uncontrolled_Format_String__wchar_t_fromFile_vsnprintf_67_struct_type my_struct;
    wchar_t data_buf[100] = L"";
    data = data_buf;
    /* FIX: Use a fixed string that does not contain a format specifier */
    wcscpy(data, L"fixedstringtest");
    my_struct.a = data;
    CWE134_Uncontrolled_Format_String__wchar_t_fromFile_vsnprintf_67b_goodG2B_sink(my_struct);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE134_Uncontrolled_Format_String__wchar_t_fromFile_vsnprintf_67b_goodB2G_sink(CWE134_Uncontrolled_Format_String__wchar_t_fromFile_vsnprintf_67_struct_type my_struct);

static void goodB2G()
{
    wchar_t * data;
    CWE134_Uncontrolled_Format_String__wchar_t_fromFile_vsnprintf_67_struct_type my_struct;
    wchar_t data_buf[100] = L"";
    data = data_buf;
    {
        /* Read input from a file */
        size_t data_len = wcslen(data);
        FILE * pFile;
        /* if there is room in data, attempt to read the input from a file */
        if(100-data_len > 1)
        {
            pFile = FOPEN(L"C:\\temp\\file.txt", L"r");
            if (pFile != NULL)
            {
                fgetws(data+data_len, (int)(100-data_len), pFile);
                fclose(pFile);
            }
        }
    }
    my_struct.a = data;
    CWE134_Uncontrolled_Format_String__wchar_t_fromFile_vsnprintf_67b_goodB2G_sink(my_struct);
}

void CWE134_Uncontrolled_Format_String__wchar_t_fromFile_vsnprintf_67_good()
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
    CWE134_Uncontrolled_Format_String__wchar_t_fromFile_vsnprintf_67_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE134_Uncontrolled_Format_String__wchar_t_fromFile_vsnprintf_67_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
