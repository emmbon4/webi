/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__char_fromFile_snprintf_08.c
Label Definition File: CWE134_Uncontrolled_Format_String.label.xml
Template File: sources-sinks-08.tmpl.c
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * BadSource: fromFile Read input from a file
 * GoodSource: Copy a fixed string into data
 * Sinks: snprintf
 *    GoodSink: snprintf with "%s" as the third argument and data as the fourth
 *    BadSink : snprintf with data as the third argument
 * Flow Variant: 08 Control flow: if(static_returns_t()) and if(static_returns_f())
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
# define FOPEN fopen
#else
/* fopen is used on unix-based OSs */
# define FOPEN fopen
#endif

#ifdef _WIN32
# define SNPRINTF _snprintf
#else /* NOT _WIN32 */
# define SNPRINTF snprintf
#endif

/* The two function below always return the same value, so a tool
   should be able to identify that calls to the functions will always
   return a fixed value. */
static int static_returns_t()
{
    return 1;
}

static int static_returns_f()
{
    return 0;
}

#ifndef OMITBAD

void CWE134_Uncontrolled_Format_String__char_fromFile_snprintf_08_bad()
{
    char * data;
    char data_buf[100] = "";
    data = data_buf;
    if(static_returns_t())
    {
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
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Use a fixed string that does not contain a format specifier */
        strcpy(data, "fixedstringtest");
    }
    if(static_returns_t())
    {
        {
            char dest[100] = "";
            /* POTENTIAL FLAW: Do not specify the format allowing a possible format string vulnerability */
            SNPRINTF(dest, 100-1, data);
            printLine(dest);
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            char dest[100] = "";
            /* FIX: Specify the format disallowing a format string vulnerability */
            SNPRINTF(dest, 100-1, "%s", data);
            printLine(dest);
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G1() - use badsource and goodsink by changing the second static_returns_t() to static_returns_f() */
static void goodB2G1()
{
    char * data;
    char data_buf[100] = "";
    data = data_buf;
    if(static_returns_t())
    {
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
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Use a fixed string that does not contain a format specifier */
        strcpy(data, "fixedstringtest");
    }
    if(static_returns_f())
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            char dest[100] = "";
            /* POTENTIAL FLAW: Do not specify the format allowing a possible format string vulnerability */
            SNPRINTF(dest, 100-1, data);
            printLine(dest);
        }
    }
    else
    {
        {
            char dest[100] = "";
            /* FIX: Specify the format disallowing a format string vulnerability */
            SNPRINTF(dest, 100-1, "%s", data);
            printLine(dest);
        }
    }
}

/* goodB2G2() - use badsource and goodsink by reversing the blocks in the second if */
static void goodB2G2()
{
    char * data;
    char data_buf[100] = "";
    data = data_buf;
    if(static_returns_t())
    {
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
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Use a fixed string that does not contain a format specifier */
        strcpy(data, "fixedstringtest");
    }
    if(static_returns_t())
    {
        {
            char dest[100] = "";
            /* FIX: Specify the format disallowing a format string vulnerability */
            SNPRINTF(dest, 100-1, "%s", data);
            printLine(dest);
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            char dest[100] = "";
            /* POTENTIAL FLAW: Do not specify the format allowing a possible format string vulnerability */
            SNPRINTF(dest, 100-1, data);
            printLine(dest);
        }
    }
}

/* goodG2B1() - use goodsource and badsink by changing the first static_returns_t() to static_returns_f() */
static void goodG2B1()
{
    char * data;
    char data_buf[100] = "";
    data = data_buf;
    if(static_returns_f())
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
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
    }
    else
    {
        /* FIX: Use a fixed string that does not contain a format specifier */
        strcpy(data, "fixedstringtest");
    }
    if(static_returns_t())
    {
        {
            char dest[100] = "";
            /* POTENTIAL FLAW: Do not specify the format allowing a possible format string vulnerability */
            SNPRINTF(dest, 100-1, data);
            printLine(dest);
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            char dest[100] = "";
            /* FIX: Specify the format disallowing a format string vulnerability */
            SNPRINTF(dest, 100-1, "%s", data);
            printLine(dest);
        }
    }
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the first if */
static void goodG2B2()
{
    char * data;
    char data_buf[100] = "";
    data = data_buf;
    if(static_returns_t())
    {
        /* FIX: Use a fixed string that does not contain a format specifier */
        strcpy(data, "fixedstringtest");
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
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
    }
    if(static_returns_t())
    {
        {
            char dest[100] = "";
            /* POTENTIAL FLAW: Do not specify the format allowing a possible format string vulnerability */
            SNPRINTF(dest, 100-1, data);
            printLine(dest);
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            char dest[100] = "";
            /* FIX: Specify the format disallowing a format string vulnerability */
            SNPRINTF(dest, 100-1, "%s", data);
            printLine(dest);
        }
    }
}

void CWE134_Uncontrolled_Format_String__char_fromFile_snprintf_08_good()
{
    goodB2G1();
    goodB2G2();
    goodG2B1();
    goodG2B2();
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
    CWE134_Uncontrolled_Format_String__char_fromFile_snprintf_08_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE134_Uncontrolled_Format_String__char_fromFile_snprintf_08_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
