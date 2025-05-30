/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE785_Path_Manipulation_Function_Without_Max_Sized_Buffer__w32_14.c
Label Definition File: CWE785_Path_Manipulation_Function_Without_Max_Sized_Buffer__w32.label.xml
Template File: point-flaw-14.tmpl.c
*/
/*
 * @description
 * CWE: 785 Path Manipulation Function Without Max Sized Buffer
 * Sinks:
 *    GoodSink: Ensure the path parameter is MAX_PATH
 *    BadSink : Use PathAppend() with a buffer that is less than MAX_PATH
 * Flow Variant: 14 Control flow: if(global_five==5) and if(global_five!=5)
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32 /* this is WIN32 specific */
#include <windows.h>
#include <shlwapi.h>

#pragma comment(lib, "shlwapi")

#define BAD_SZ (MAX_PATH / 2) /* maintenance note: must be < MAX_PATH in order for 'bad' to be 'bad' */
#endif

#ifndef OMITBAD

void CWE785_Path_Manipulation_Function_Without_Max_Sized_Buffer__w32_14_bad()
{
    if(global_five==5)
    {
        {
#ifdef _WIN32 /* this is WIN32 specific */
            char path[BAD_SZ];
            DWORD length;
            length = GetCurrentDirectoryA(BAD_SZ, path);
            if (length == 0 || length >= BAD_SZ) exit(1); /* failure conditions for this API call */
            /* FLAW: PathAppend assumes the 'path' parameter is MAX_PATH */
            /* INCIDENTAL: CWE 121 stack based buffer overflow, which is intrinsic to
             * this example identified on the CWE webpage */
            if (!PathAppendA(path, "AAAAAAAAAAAA")) exit(1);
            printSizeTLine(strlen(path));
            printIntLine(BAD_SZ);
            printLine(path);
#endif /* _WIN32 */
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
#ifdef _WIN32 /* this is WIN32 specific */
            /* FIX: ensure MAX_PATH allocated in 'path' */
            char path[MAX_PATH];
            DWORD length;
            length = GetCurrentDirectoryA(MAX_PATH, path);
            if (length == 0 || length >= MAX_PATH) exit(1); /* failure conditions for this API call */
            if (!PathAppendA(path, "AAAAAAAAAAAA")) exit(1);
            printLine(path);
#endif /* _WIN32 */
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() uses if(global_five!=5) instead of if(global_five==5) */
static void good1()
{
    if(global_five!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
#ifdef _WIN32 /* this is WIN32 specific */
            char path[BAD_SZ];
            DWORD length;
            length = GetCurrentDirectoryA(BAD_SZ, path);
            if (length == 0 || length >= BAD_SZ) exit(1); /* failure conditions for this API call */
            /* FLAW: PathAppend assumes the 'path' parameter is MAX_PATH */
            /* INCIDENTAL: CWE 121 stack based buffer overflow, which is intrinsic to
             * this example identified on the CWE webpage */
            if (!PathAppendA(path, "AAAAAAAAAAAA")) exit(1);
            printSizeTLine(strlen(path));
            printIntLine(BAD_SZ);
            printLine(path);
#endif /* _WIN32 */
        }
    }
    else
    {
        {
#ifdef _WIN32 /* this is WIN32 specific */
            /* FIX: ensure MAX_PATH allocated in 'path' */
            char path[MAX_PATH];
            DWORD length;
            length = GetCurrentDirectoryA(MAX_PATH, path);
            if (length == 0 || length >= MAX_PATH) exit(1); /* failure conditions for this API call */
            if (!PathAppendA(path, "AAAAAAAAAAAA")) exit(1);
            printLine(path);
#endif /* _WIN32 */
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(global_five==5)
    {
        {
#ifdef _WIN32 /* this is WIN32 specific */
            /* FIX: ensure MAX_PATH allocated in 'path' */
            char path[MAX_PATH];
            DWORD length;
            length = GetCurrentDirectoryA(MAX_PATH, path);
            if (length == 0 || length >= MAX_PATH) exit(1); /* failure conditions for this API call */
            if (!PathAppendA(path, "AAAAAAAAAAAA")) exit(1);
            printLine(path);
#endif /* _WIN32 */
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
#ifdef _WIN32 /* this is WIN32 specific */
            char path[BAD_SZ];
            DWORD length;
            length = GetCurrentDirectoryA(BAD_SZ, path);
            if (length == 0 || length >= BAD_SZ) exit(1); /* failure conditions for this API call */
            /* FLAW: PathAppend assumes the 'path' parameter is MAX_PATH */
            /* INCIDENTAL: CWE 121 stack based buffer overflow, which is intrinsic to
             * this example identified on the CWE webpage */
            if (!PathAppendA(path, "AAAAAAAAAAAA")) exit(1);
            printSizeTLine(strlen(path));
            printIntLine(BAD_SZ);
            printLine(path);
#endif /* _WIN32 */
        }
    }
}

void CWE785_Path_Manipulation_Function_Without_Max_Sized_Buffer__w32_14_good()
{
    good1();
    good2();
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
    CWE785_Path_Manipulation_Function_Without_Max_Sized_Buffer__w32_14_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE785_Path_Manipulation_Function_Without_Max_Sized_Buffer__w32_14_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
