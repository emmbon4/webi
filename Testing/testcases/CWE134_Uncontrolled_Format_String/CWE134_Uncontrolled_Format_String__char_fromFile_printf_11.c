/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__char_fromFile_printf_11.c
Label Definition File: CWE134_Uncontrolled_Format_String.label.xml
Template File: sources-sinks-11.tmpl.c
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * BadSource: fromFile Read input from a file
 * GoodSource: Copy a fixed string into data
 * Sinks: printf
 *    GoodSink: printf with "%s" as the first argument and data as the second
 *    BadSink : printf with only data as an argument
 * Flow Variant: 11 Control flow: if(global_returns_t()) and if(global_returns_f())
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
# define FOPEN fopen
#else
/* fopen is used on unix-based OSs */
# define FOPEN fopen
#endif

#ifndef OMITBAD

void CWE134_Uncontrolled_Format_String__char_fromFile_printf_11_bad()
{
    char * data;
    char data_buf[100] = "";
    data = data_buf;
    if(global_returns_t())
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
    if(global_returns_t())
    {
        /* POTENTIAL FLAW: Do not specify the format allowing a possible format string vulnerability */
        printf(data);
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Specify the format disallowing a format string vulnerability */
        printf("%s\n", data);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G1() - use badsource and goodsink by changing the second global_returns_t() to global_returns_f() */
static void goodB2G1()
{
    char * data;
    char data_buf[100] = "";
    data = data_buf;
    if(global_returns_t())
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
    if(global_returns_f())
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* POTENTIAL FLAW: Do not specify the format allowing a possible format string vulnerability */
        printf(data);
    }
    else
    {
        /* FIX: Specify the format disallowing a format string vulnerability */
        printf("%s\n", data);
    }
}

/* goodB2G2() - use badsource and goodsink by reversing the blocks in the second if */
static void goodB2G2()
{
    char * data;
    char data_buf[100] = "";
    data = data_buf;
    if(global_returns_t())
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
    if(global_returns_t())
    {
        /* FIX: Specify the format disallowing a format string vulnerability */
        printf("%s\n", data);
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* POTENTIAL FLAW: Do not specify the format allowing a possible format string vulnerability */
        printf(data);
    }
}

/* goodG2B1() - use goodsource and badsink by changing the first global_returns_t() to global_returns_f() */
static void goodG2B1()
{
    char * data;
    char data_buf[100] = "";
    data = data_buf;
    if(global_returns_f())
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
    if(global_returns_t())
    {
        /* POTENTIAL FLAW: Do not specify the format allowing a possible format string vulnerability */
        printf(data);
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Specify the format disallowing a format string vulnerability */
        printf("%s\n", data);
    }
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the first if */
static void goodG2B2()
{
    char * data;
    char data_buf[100] = "";
    data = data_buf;
    if(global_returns_t())
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
    if(global_returns_t())
    {
        /* POTENTIAL FLAW: Do not specify the format allowing a possible format string vulnerability */
        printf(data);
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Specify the format disallowing a format string vulnerability */
        printf("%s\n", data);
    }
}

void CWE134_Uncontrolled_Format_String__char_fromFile_printf_11_good()
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
    CWE134_Uncontrolled_Format_String__char_fromFile_printf_11_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE134_Uncontrolled_Format_String__char_fromFile_printf_11_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
