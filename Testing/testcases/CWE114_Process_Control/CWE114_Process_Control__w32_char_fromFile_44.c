/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE114_Process_Control__w32_char_fromFile_44.c
Label Definition File: CWE114_Process_Control__w32.label.xml
Template File: sources-sink-44.tmpl.c
*/
/*
 * @description
 * CWE: 114 Process Control
 * BadSource: fromFile Read input from a file
 * GoodSource: Hard code the full pathname to the library
 * Sinks:
 *    BadSink : Load a dynamic link library
 * Flow Variant: 44 Data/control flow: data passed as an argument from one function to a function in the same source file called via a function pointer
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifdef _WIN32
# define FOPEN fopen
#else
/* fopen is used on unix-based OSs */
# define FOPEN fopen
#endif

#include <windows.h>

#ifndef OMITBAD

static void bad_sink(char * data)
{
#ifdef _WIN32
    {
        HMODULE hModule;

        /* POTENTIAL FLAW: If the path to the library is not specified, an attacker may be able to
         * replace his own file with the intended library */
        hModule = LoadLibraryA(data);

        if (hModule != NULL)
        {
            FreeLibrary(hModule);
            printLine("Library loaded and freed successfully");
        }
        else {
            printLine("Unable to load library");
        }
    }
#endif
}

void CWE114_Process_Control__w32_char_fromFile_44_bad()
{
    char * data;
    /* define a function pointer */
    void (*func_ptr) (char *) = bad_sink;
    char data_buf[100] = "";
    data = data_buf;
    {
        /* Read input from a file */
        size_t data_len = strlen(data);
        FILE * pFile;
        /* if there is room in data, attempt to read the input from a file */
        if(100-data_len > 1)
        {
            pFile = FOPEN("C:\\temp\\file.txt", "r");
            if (pFile != NULL)
            {
                fgets(data+data_len, (int)(100-data_len), pFile);
                fclose(pFile);
            }
        }
    }
    /* use the function pointer */
    func_ptr(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B_sink(char * data)
{
#ifdef _WIN32
    {
        HMODULE hModule;

        /* POTENTIAL FLAW: If the path to the library is not specified, an attacker may be able to
         * replace his own file with the intended library */
        hModule = LoadLibraryA(data);

        if (hModule != NULL)
        {
            FreeLibrary(hModule);
            printLine("Library loaded and freed successfully");
        }
        else {
            printLine("Unable to load library");
        }
    }
#endif
}

static void goodG2B()
{
    char * data;
    void (*func_ptr) (char *) = goodG2B_sink;
    char data_buf[100] = "";
    data = data_buf;
    /* FIX: Specify the full pathname for the library */
    strcpy(data, "C:\\Windows\\System32\\winsrv.dll");
    func_ptr(data);
}

void CWE114_Process_Control__w32_char_fromFile_44_good()
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
    CWE114_Process_Control__w32_char_fromFile_44_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE114_Process_Control__w32_char_fromFile_44_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
