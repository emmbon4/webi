/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE114_Process_Control__w32_wchar_t_fromConsole_67b.c
Label Definition File: CWE114_Process_Control__w32.label.xml
Template File: sources-sink-67b.tmpl.c
*/
/*
 * @description
 * CWE: 114 Process Control
 * BadSource: fromConsole Read input from the console
 * GoodSource: Hard code the full pathname to the library
 * Sinks:
 *    BadSink : Load a dynamic link library
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#include <windows.h>

typedef struct _CWE114_Process_Control__w32_wchar_t_fromConsole_67_struct_type
{
    wchar_t * a;
} CWE114_Process_Control__w32_wchar_t_fromConsole_67_struct_type;

#ifndef OMITBAD

void CWE114_Process_Control__w32_wchar_t_fromConsole_67b_bad_sink(CWE114_Process_Control__w32_wchar_t_fromConsole_67_struct_type my_struct)
{
    wchar_t * data = my_struct.a;
#ifdef _WIN32
    {
        HMODULE hModule;
        /* POTENTIAL FLAW: If the path to the library is not specified, an attacker may be able to
         * replace his own file with the intended library */
        hModule = LoadLibraryW(data);
        if (hModule != NULL)
        {
            FreeLibrary(hModule);
            printLine("Library loaded and freed successfully");
        }
        else
        {
            printLine("Unable to load library");
        }
    }
#endif
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE114_Process_Control__w32_wchar_t_fromConsole_67b_goodG2B_sink(CWE114_Process_Control__w32_wchar_t_fromConsole_67_struct_type my_struct)
{
    wchar_t * data = my_struct.a;
#ifdef _WIN32
    {
        HMODULE hModule;
        /* POTENTIAL FLAW: If the path to the library is not specified, an attacker may be able to
         * replace his own file with the intended library */
        hModule = LoadLibraryW(data);
        if (hModule != NULL)
        {
            FreeLibrary(hModule);
            printLine("Library loaded and freed successfully");
        }
        else
        {
            printLine("Unable to load library");
        }
    }
#endif
}

#endif /* OMITGOOD */
