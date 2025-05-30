/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE427_Uncontrolled_Search_Path_Element__char_Environment_34.c
Label Definition File: CWE427_Uncontrolled_Search_Path_Element.label.xml
Template File: sources-sink-34.tmpl.c
*/
/*
 * @description
 * CWE: 427 Uncontrolled Search Path Element
 * BadSource: Environment Read input from an environment variable
 * GoodSource: Use a hardcoded path
 * Sinks:
 *    BadSink : Set the environment variable
 * Flow Variant: 34 Data flow: use of a union containing two methods of accessing the same data (within the same function)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifdef _WIN32
# define NEW_PATH "%SystemRoot%\\system32"
# define PUTENV _putenv
#else
# define NEW_PATH "/bin"
# define PUTENV putenv
#endif

#define ENV_VARIABLE "ADD"

#ifdef _WIN32
# define GETENV getenv
#else
# define GETENV getenv
#endif

typedef union
{
    char * a;
    char * b;
} CWE427_Uncontrolled_Search_Path_Element__char_Environment_34_union_type;

#ifndef OMITBAD

void CWE427_Uncontrolled_Search_Path_Element__char_Environment_34_bad()
{
    char * data;
    CWE427_Uncontrolled_Search_Path_Element__char_Environment_34_union_type my_union;
    char data_buf[250] = "PATH=";
    data = data_buf;
    {
        /* Read input from an environment variable */
        size_t data_len = strlen(data);
        char * environment = GETENV(ENV_VARIABLE);
        /* If there is data in the environment variable */
        if (environment != NULL)
        {
            strncat(data+data_len, environment, 100-data_len-1);
        }
    }
    my_union.a = data;
    {
        char * data = my_union.b;
        /* POTENTIAL FLAW: Set a new environment variable with a path that is possibly insecure */
        PUTENV(data);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    char * data;
    CWE427_Uncontrolled_Search_Path_Element__char_Environment_34_union_type my_union;
    char data_buf[250] = "PATH=";
    data = data_buf;
    /* FIX: Set the path as the "system" path */
    strcat(data, NEW_PATH);
    my_union.a = data;
    {
        char * data = my_union.b;
        /* POTENTIAL FLAW: Set a new environment variable with a path that is possibly insecure */
        PUTENV(data);
    }
}

void CWE427_Uncontrolled_Search_Path_Element__char_Environment_34_good()
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
    CWE427_Uncontrolled_Search_Path_Element__char_Environment_34_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE427_Uncontrolled_Search_Path_Element__char_Environment_34_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
