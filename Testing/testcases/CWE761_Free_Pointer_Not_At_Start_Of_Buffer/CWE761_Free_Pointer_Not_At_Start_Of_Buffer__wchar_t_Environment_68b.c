/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE761_Free_Pointer_Not_At_Start_Of_Buffer__wchar_t_Environment_68b.c
Label Definition File: CWE761_Free_Pointer_Not_At_Start_Of_Buffer.label.xml
Template File: source-sinks-68b.tmpl.c
*/
/*
 * @description
 * CWE: 761 Free Pointer Not At Start of Buffer
 * BadSource: Environment Read input from an environment variable
 * Sinks:
 *    GoodSink: free() memory correctly at the start of the buffer
 *    BadSink : free() memory not at the start of the buffer
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#define SEARCH_CHAR L'S'
#define BAD_SRC_FIXED L"Fixed String" /* MAINTENANCE NOTE: This string must contain the SEARCH_CHAR */

#define ENV_VARIABLE L"ADD"

#ifdef _WIN32
# define GETENV _wgetenv
#else
# define GETENV wgetenv
#endif

extern wchar_t * CWE761_Free_Pointer_Not_At_Start_Of_Buffer__wchar_t_Environment_68_bad_data_for_bad_sink;

extern wchar_t * CWE761_Free_Pointer_Not_At_Start_Of_Buffer__wchar_t_Environment_68_bad_data_for_good_sink;

#ifndef OMITBAD

void CWE761_Free_Pointer_Not_At_Start_Of_Buffer__wchar_t_Environment_68b_bad_sink()
{
    wchar_t * data = CWE761_Free_Pointer_Not_At_Start_Of_Buffer__wchar_t_Environment_68_bad_data_for_bad_sink;
    /* FLAW: We are incrementing the pointer in the loop - this will cause us to free the
     * memory block not at the start of the buffer */
    for (; *data != L'\0'; data++)
    {
        if (*data == SEARCH_CHAR)
        {
            printLine("We have a match!");
            break;
        }
    }
    free(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

void CWE761_Free_Pointer_Not_At_Start_Of_Buffer__wchar_t_Environment_68b_goodB2G_sink()
{
    wchar_t * data = CWE761_Free_Pointer_Not_At_Start_Of_Buffer__wchar_t_Environment_68_bad_data_for_good_sink;
    {
        size_t i;
        /* FIX: Use a loop variable to traverse through the string pointed to by data */
        for (i=0; i < wcslen(data); i++)
        {
            if (data[i] == SEARCH_CHAR)
            {
                printLine("We have a match!");
                break;
            }
        }
        free(data);
    }
}

#endif /* OMITGOOD */
