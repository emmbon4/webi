/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE23_Relative_Path_Traversal__char_fromConsole_fopen_07.c
Label Definition File: CWE23_Relative_Path_Traversal.label.xml
Template File: sources-sink-07.tmpl.c
*/
/*
 * @description
 * CWE: 23 Relative Path Traversal
 * BadSource: fromConsole Read input from the console
 * GoodSource: File name without a period or slash
 * Sink: fopen
 *    BadSink :
 * Flow Variant: 07 Control flow: if(static_five==5) and if(static_five!=5)
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
#define BASEPATH "c:\\temp\\"
#else
#define BASEPATH "/tmp/"
#endif

#ifdef _WIN32
# define FOPEN fopen
#else
/* fopen is used on unix-based OSs */
# define FOPEN fopen
#endif

/* The variable below is not declared "const", but is never assigned
   any other value so a tool should be able to identify that reads of
   this will always give its initialized value. */
static int static_five = 5;

#ifndef OMITBAD

void CWE23_Relative_Path_Traversal__char_fromConsole_fopen_07_bad()
{
    char * data;
    char data_buf[FILENAME_MAX] = BASEPATH;
    data = data_buf;
    if(static_five==5)
    {
        {
            /* Read input from the console */
            size_t data_len = strlen(data);
            /* if there is room in data, read into it from the console */
            if(FILENAME_MAX-data_len > 1)
            {
                fgets(data+data_len, (int)(FILENAME_MAX-data_len), stdin);
                /* The next 3 lines remove the carriage return from the string that is
                 * inserted by fgets() */
                data_len = strlen(data);
                if (data_len > 0)
                {
                    data[data_len-1] = '\0';
                }
            }
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: File name does not contain a period or slash */
        strcat(data, "file.txt");
    }
    {
        FILE *file = NULL;
        /* POTENTIAL FLAW: Possibly opening a file without validating the file name or path */
        file = FOPEN(data, "wb+");
        if (file != NULL) fclose(file);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B1() - use goodsource and badsink by changing the static_five==5 to static_five!=5 */
static void goodG2B1()
{
    char * data;
    char data_buf[FILENAME_MAX] = BASEPATH;
    data = data_buf;
    if(static_five!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* Read input from the console */
            size_t data_len = strlen(data);
            /* if there is room in data, read into it from the console */
            if(FILENAME_MAX-data_len > 1)
            {
                fgets(data+data_len, (int)(FILENAME_MAX-data_len), stdin);
                /* The next 3 lines remove the carriage return from the string that is
                 * inserted by fgets() */
                data_len = strlen(data);
                if (data_len > 0)
                {
                    data[data_len-1] = '\0';
                }
            }
        }
    }
    else
    {
        /* FIX: File name does not contain a period or slash */
        strcat(data, "file.txt");
    }
    {
        FILE *file = NULL;
        /* POTENTIAL FLAW: Possibly opening a file without validating the file name or path */
        file = FOPEN(data, "wb+");
        if (file != NULL) fclose(file);
    }
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the if statement */
static void goodG2B2()
{
    char * data;
    char data_buf[FILENAME_MAX] = BASEPATH;
    data = data_buf;
    if(static_five==5)
    {
        /* FIX: File name does not contain a period or slash */
        strcat(data, "file.txt");
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* Read input from the console */
            size_t data_len = strlen(data);
            /* if there is room in data, read into it from the console */
            if(FILENAME_MAX-data_len > 1)
            {
                fgets(data+data_len, (int)(FILENAME_MAX-data_len), stdin);
                /* The next 3 lines remove the carriage return from the string that is
                 * inserted by fgets() */
                data_len = strlen(data);
                if (data_len > 0)
                {
                    data[data_len-1] = '\0';
                }
            }
        }
    }
    {
        FILE *file = NULL;
        /* POTENTIAL FLAW: Possibly opening a file without validating the file name or path */
        file = FOPEN(data, "wb+");
        if (file != NULL) fclose(file);
    }
}

void CWE23_Relative_Path_Traversal__char_fromConsole_fopen_07_good()
{
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
    CWE23_Relative_Path_Traversal__char_fromConsole_fopen_07_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE23_Relative_Path_Traversal__char_fromConsole_fopen_07_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
