/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__char_Environment_snprintf_18.c
Label Definition File: CWE134_Uncontrolled_Format_String.label.xml
Template File: sources-sinks-18.tmpl.c
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * BadSource: Environment Read input from an environment variable
 * GoodSource: Copy a fixed string into data
 * Sinks: snprintf
 *    GoodSink: snprintf with "%s" as the third argument and data as the fourth
 *    BadSink : snprintf with data as the third argument
 * Flow Variant: 18 Control flow: goto statements
 *
 * */

#include "std_testcase.h"

#define ENV_VARIABLE "ADD"

#ifdef _WIN32
# define GETENV getenv
#else
# define GETENV getenv
#endif

#ifdef _WIN32
# define SNPRINTF _snprintf
#else /* NOT _WIN32 */
# define SNPRINTF snprintf
#endif

#ifndef OMITBAD

void CWE134_Uncontrolled_Format_String__char_Environment_snprintf_18_bad()
{
    char * data;
    char data_buf[100] = "";
    data = data_buf;
    goto source;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    /* FIX: Use a fixed string that does not contain a format specifier */
    strcpy(data, "fixedstringtest");
source:
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
    goto sink;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        char dest[100] = "";
        /* FIX: Specify the format disallowing a format string vulnerability */
        SNPRINTF(dest, 100-1, "%s", data);
        printLine(dest);
    }
sink:
    {
        char dest[100] = "";
        /* POTENTIAL FLAW: Do not specify the format allowing a possible format string vulnerability */
        SNPRINTF(dest, 100-1, data);
        printLine(dest);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G() - use badsource and goodsink by reversing the blocks on the second goto statement */
static void goodB2G()
{
    char * data;
    char data_buf[100] = "";
    data = data_buf;
    goto source;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    /* FIX: Use a fixed string that does not contain a format specifier */
    strcpy(data, "fixedstringtest");
source:
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
    goto sink;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        char dest[100] = "";
        /* POTENTIAL FLAW: Do not specify the format allowing a possible format string vulnerability */
        SNPRINTF(dest, 100-1, data);
        printLine(dest);
    }
sink:
    {
        char dest[100] = "";
        /* FIX: Specify the format disallowing a format string vulnerability */
        SNPRINTF(dest, 100-1, "%s", data);
        printLine(dest);
    }
}

/* goodG2B() - use goodsource and badsink by reversing the blocks on the first goto statement */
static void goodG2B()
{
    char * data;
    char data_buf[100] = "";
    data = data_buf;
    goto source;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
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
source:
    /* FIX: Use a fixed string that does not contain a format specifier */
    strcpy(data, "fixedstringtest");
    goto sink;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        char dest[100] = "";
        /* FIX: Specify the format disallowing a format string vulnerability */
        SNPRINTF(dest, 100-1, "%s", data);
        printLine(dest);
    }
sink:
    {
        char dest[100] = "";
        /* POTENTIAL FLAW: Do not specify the format allowing a possible format string vulnerability */
        SNPRINTF(dest, 100-1, data);
        printLine(dest);
    }
}

void CWE134_Uncontrolled_Format_String__char_Environment_snprintf_18_good()
{
    goodB2G();
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
    CWE134_Uncontrolled_Format_String__char_Environment_snprintf_18_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE134_Uncontrolled_Format_String__char_Environment_snprintf_18_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
