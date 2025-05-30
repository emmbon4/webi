/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE23_Relative_Path_Traversal__char_fromConsole_open_68a.c
Label Definition File: CWE23_Relative_Path_Traversal.label.xml
Template File: sources-sink-68a.tmpl.c
*/
/*
 * @description
 * CWE: 23 Relative Path Traversal
 * BadSource: fromConsole Read input from the console
 * GoodSource: File name without a period or slash
 * Sink: open
 *    BadSink :
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
#define BASEPATH "c:\\temp\\"
#else
#define BASEPATH "/tmp/"
#endif

#ifdef _WIN32
# define OPEN _open
# define CLOSE _close
#else
# define OPEN open
# define CLOSE close
#endif

char * CWE23_Relative_Path_Traversal__char_fromConsole_open_68_bad_data;
char * CWE23_Relative_Path_Traversal__char_fromConsole_open_68_goodG2B_data;

#ifndef OMITBAD

/* bad function declaration */
void CWE23_Relative_Path_Traversal__char_fromConsole_open_68b_bad_sink();

void CWE23_Relative_Path_Traversal__char_fromConsole_open_68_bad()
{
    char * data;
    char data_buf[FILENAME_MAX] = BASEPATH;
    data = data_buf;
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
    CWE23_Relative_Path_Traversal__char_fromConsole_open_68_bad_data = data;
    CWE23_Relative_Path_Traversal__char_fromConsole_open_68b_bad_sink();
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declarations */
void CWE23_Relative_Path_Traversal__char_fromConsole_open_68b_goodG2B_sink();

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    char * data;
    char data_buf[FILENAME_MAX] = BASEPATH;
    data = data_buf;
    /* FIX: File name does not contain a period or slash */
    strcat(data, "file.txt");
    CWE23_Relative_Path_Traversal__char_fromConsole_open_68_goodG2B_data = data;
    CWE23_Relative_Path_Traversal__char_fromConsole_open_68b_goodG2B_sink();
}

void CWE23_Relative_Path_Traversal__char_fromConsole_open_68_good()
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
    CWE23_Relative_Path_Traversal__char_fromConsole_open_68_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE23_Relative_Path_Traversal__char_fromConsole_open_68_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
