/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE36_Absolute_Path_Traversal__char_fromConsole_open_65a.c
Label Definition File: CWE36_Absolute_Path_Traversal.label.xml
Template File: sources-sink-65a.tmpl.c
*/
/*
 * @description
 * CWE: 36 Absolute Path Traversal
 * BadSource: fromConsole Read input from the console
 * GoodSource: Full path and file name
 * Sinks: open
 *    BadSink :
 * Flow Variant: 65 Data/control flow: data passed as an argument from one function to a function in a different source file called via a function pointer
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
# define OPEN _open
# define CLOSE _close
#else
# define OPEN open
# define CLOSE close
#endif

#ifndef OMITBAD

/* bad function declaration */
void CWE36_Absolute_Path_Traversal__char_fromConsole_open_65b_bad_sink(char * data);

void CWE36_Absolute_Path_Traversal__char_fromConsole_open_65_bad()
{
    char * data;
    /* define a function pointer */
    void (*func_ptr) (char *) = CWE36_Absolute_Path_Traversal__char_fromConsole_open_65b_bad_sink;
    char data_buf[FILENAME_MAX] = "";
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
    /* use the function pointer */
    func_ptr(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE36_Absolute_Path_Traversal__char_fromConsole_open_65b_goodG2B_sink(char * data);

static void goodG2B()
{
    char * data;
    void (*func_ptr) (char *) = CWE36_Absolute_Path_Traversal__char_fromConsole_open_65b_goodG2B_sink;
    char data_buf[FILENAME_MAX] = "";
    data = data_buf;
#ifdef _WIN32
    /* FIX: Full path and file name */
    strcpy(data, "c:\\temp\\file.txt");
#else
    /* FIX: Full path and file name */
    strcpy(data, "/tmp/file.txt");
#endif
    func_ptr(data);
}

void CWE36_Absolute_Path_Traversal__char_fromConsole_open_65_good()
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
    CWE36_Absolute_Path_Traversal__char_fromConsole_open_65_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE36_Absolute_Path_Traversal__char_fromConsole_open_65_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
