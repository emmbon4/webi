/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE114_Process_Control__w32_wchar_t_fromConsole_01.c
Label Definition File: CWE114_Process_Control__w32.label.xml
Template File: sources-sink-01.tmpl.c
*/
/*
 * @description
 * CWE: 114 Process Control
 * BadSource: fromConsole Read input from the console
 * GoodSource: Hard code the full pathname to the library
 * Sink:
 *    BadSink : Load a dynamic link library
 * Flow Variant: 01 Baseline
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#include <windows.h>

#ifndef OMITBAD

void CWE114_Process_Control__w32_wchar_t_fromConsole_01_bad()
{
    wchar_t * data;
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
static void goodG2B()
{
    wchar_t * data;
    wchar_t data_buf[100] = L"";
    data = data_buf;
    /* FIX: Specify the full pathname for the library */
    wcscpy(data, L"C:\\Windows\\System32\\winsrv.dll");
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

void CWE114_Process_Control__w32_wchar_t_fromConsole_01_good()
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
    CWE114_Process_Control__w32_wchar_t_fromConsole_01_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE114_Process_Control__w32_wchar_t_fromConsole_01_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
