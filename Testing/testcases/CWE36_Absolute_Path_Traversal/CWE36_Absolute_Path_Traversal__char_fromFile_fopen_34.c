/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE36_Absolute_Path_Traversal__char_fromFile_fopen_34.c
Label Definition File: CWE36_Absolute_Path_Traversal.label.xml
Template File: sources-sink-34.tmpl.c
*/
/*
 * @description
 * CWE: 36 Absolute Path Traversal
 * BadSource: fromFile Read input from a file
 * GoodSource: Full path and file name
 * Sinks: fopen
 *    BadSink :
 * Flow Variant: 34 Data flow: use of a union containing two methods of accessing the same data (within the same function)
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
# define FOPEN fopen
#else
/* fopen is used on unix-based OSs */
# define FOPEN fopen
#endif

typedef union
{
    char * a;
    char * b;
} CWE36_Absolute_Path_Traversal__char_fromFile_fopen_34_union_type;

#ifndef OMITBAD

void CWE36_Absolute_Path_Traversal__char_fromFile_fopen_34_bad()
{
    char * data;
    CWE36_Absolute_Path_Traversal__char_fromFile_fopen_34_union_type my_union;
    char data_buf[FILENAME_MAX] = "";
    data = data_buf;
    {
        /* Read input from a file */
        size_t data_len = strlen(data);
        FILE * pFile;
        /* if there is room in data, attempt to read the input from a file */
        if(FILENAME_MAX-data_len > 1)
        {
            pFile = FOPEN("C:\\temp\\file.txt", "r");
            if (pFile != NULL)
            {
                fgets(data+data_len, (int)(FILENAME_MAX-data_len), pFile);
                fclose(pFile);
            }
        }
    }
    my_union.a = data;
    {
        char * data = my_union.b;
        {
            FILE *file = NULL;
            /* POTENTIAL FLAW: Possibly opening a file without validating the file name or path */
            file = FOPEN(data, "wb+");
            if (file != NULL) fclose(file);
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    char * data;
    CWE36_Absolute_Path_Traversal__char_fromFile_fopen_34_union_type my_union;
    char data_buf[FILENAME_MAX] = "";
    data = data_buf;
#ifdef _WIN32
    /* FIX: Full path and file name */
    strcpy(data, "c:\\temp\\file.txt");
#else
    /* FIX: Full path and file name */
    strcpy(data, "/tmp/file.txt");
#endif
    my_union.a = data;
    {
        char * data = my_union.b;
        {
            FILE *file = NULL;
            /* POTENTIAL FLAW: Possibly opening a file without validating the file name or path */
            file = FOPEN(data, "wb+");
            if (file != NULL) fclose(file);
        }
    }
}

void CWE36_Absolute_Path_Traversal__char_fromFile_fopen_34_good()
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
    CWE36_Absolute_Path_Traversal__char_fromFile_fopen_34_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE36_Absolute_Path_Traversal__char_fromFile_fopen_34_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
