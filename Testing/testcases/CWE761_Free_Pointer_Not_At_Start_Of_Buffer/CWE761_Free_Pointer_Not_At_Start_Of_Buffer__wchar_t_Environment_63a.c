/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE761_Free_Pointer_Not_At_Start_Of_Buffer__wchar_t_Environment_63a.c
Label Definition File: CWE761_Free_Pointer_Not_At_Start_Of_Buffer.label.xml
Template File: source-sinks-63a.tmpl.c
*/
/*
 * @description
 * CWE: 761 Free Pointer Not At Start of Buffer
 * BadSource: Environment Read input from an environment variable
 * Sinks:
 *    GoodSink: free() memory correctly at the start of the buffer
 *    BadSink : free() memory not at the start of the buffer
 * Flow Variant: 63 Data flow: pointer to data passed from one function to another in different source files
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

#ifndef OMITBAD

/* bad function declaration */
void CWE761_Free_Pointer_Not_At_Start_Of_Buffer__wchar_t_Environment_63b_bad_sink(wchar_t * * data_ptr);

void CWE761_Free_Pointer_Not_At_Start_Of_Buffer__wchar_t_Environment_63_bad()
{
    wchar_t * data;
    data = (wchar_t *)malloc(100*sizeof(wchar_t));
    data[0] = L'\0';
    {
        /* Read input from an environment variable */
        size_t data_len = wcslen(data);
        wchar_t * environment = GETENV(ENV_VARIABLE);
        /* If there is data in the environment variable */
        if (environment != NULL)
        {
            wcsncat(data+data_len, environment, 100-data_len-1);
        }
    }
    CWE761_Free_Pointer_Not_At_Start_Of_Buffer__wchar_t_Environment_63b_bad_sink(&data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G uses the BadSource with the GoodSink */
void CWE761_Free_Pointer_Not_At_Start_Of_Buffer__wchar_t_Environment_63b_goodB2G_sink(wchar_t * * data);

static void goodB2G()
{
    wchar_t * data;
    data = (wchar_t *)malloc(100*sizeof(wchar_t));
    data[0] = L'\0';
    {
        /* Read input from an environment variable */
        size_t data_len = wcslen(data);
        wchar_t * environment = GETENV(ENV_VARIABLE);
        /* If there is data in the environment variable */
        if (environment != NULL)
        {
            wcsncat(data+data_len, environment, 100-data_len-1);
        }
    }
    CWE761_Free_Pointer_Not_At_Start_Of_Buffer__wchar_t_Environment_63b_goodB2G_sink(&data);
}

void CWE761_Free_Pointer_Not_At_Start_Of_Buffer__wchar_t_Environment_63_good()
{
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
    CWE761_Free_Pointer_Not_At_Start_Of_Buffer__wchar_t_Environment_63_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE761_Free_Pointer_Not_At_Start_Of_Buffer__wchar_t_Environment_63_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
