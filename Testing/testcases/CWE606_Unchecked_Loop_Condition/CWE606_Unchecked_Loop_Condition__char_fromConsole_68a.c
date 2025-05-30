/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE606_Unchecked_Loop_Condition__char_fromConsole_68a.c
Label Definition File: CWE606_Unchecked_Loop_Condition.label.xml
Template File: sources-sinks-68a.tmpl.c
*/
/*
 * @description
 * CWE: 606 Unchecked Input For Loop Condition
 * BadSource: fromConsole Read input from the console
 * GoodSource: Input a number less than MAX_LOOP
 * Sinks:
 *    GoodSink: Use data as the for loop variant after checking to see if it is less than MAX_LOOP
 *    BadSink : Use data as the for loop variant without checking its size
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#define MAX_LOOP 10000

char * CWE606_Unchecked_Loop_Condition__char_fromConsole_68_bad_data;
char * CWE606_Unchecked_Loop_Condition__char_fromConsole_68_goodG2B_data;
char * CWE606_Unchecked_Loop_Condition__char_fromConsole_68_goodB2G_data;

#ifndef OMITBAD

/* bad function declaration */
void CWE606_Unchecked_Loop_Condition__char_fromConsole_68b_bad_sink();

void CWE606_Unchecked_Loop_Condition__char_fromConsole_68_bad()
{
    char * data;
    char data_buf[100] = "";
    data = data_buf;
    {
        /* Read input from the console */
        size_t data_len = strlen(data);
        /* if there is room in data, read into it from the console */
        if(100-data_len > 1)
        {
            fgets(data+data_len, (int)(100-data_len), stdin);
            /* The next 3 lines remove the carriage return from the string that is
             * inserted by fgets() */
            data_len = strlen(data);
            if (data_len > 0)
            {
                data[data_len-1] = '\0';
            }
        }
    }
    CWE606_Unchecked_Loop_Condition__char_fromConsole_68_bad_data = data;
    CWE606_Unchecked_Loop_Condition__char_fromConsole_68b_bad_sink();
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declarations */
void CWE606_Unchecked_Loop_Condition__char_fromConsole_68b_goodG2B_sink();
void CWE606_Unchecked_Loop_Condition__char_fromConsole_68b_goodB2G_sink();

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    char * data;
    char data_buf[100] = "";
    data = data_buf;
    /* FIX: Set data to a number less than MAX_LOOP */
    strcpy(data, "15");
    CWE606_Unchecked_Loop_Condition__char_fromConsole_68_goodG2B_data = data;
    CWE606_Unchecked_Loop_Condition__char_fromConsole_68b_goodG2B_sink();
}

/* goodB2G uses the BadSource with the GoodSink */
static void goodB2G()
{
    char * data;
    char data_buf[100] = "";
    data = data_buf;
    {
        /* Read input from the console */
        size_t data_len = strlen(data);
        /* if there is room in data, read into it from the console */
        if(100-data_len > 1)
        {
            fgets(data+data_len, (int)(100-data_len), stdin);
            /* The next 3 lines remove the carriage return from the string that is
             * inserted by fgets() */
            data_len = strlen(data);
            if (data_len > 0)
            {
                data[data_len-1] = '\0';
            }
        }
    }
    CWE606_Unchecked_Loop_Condition__char_fromConsole_68_goodB2G_data = data;
    CWE606_Unchecked_Loop_Condition__char_fromConsole_68b_goodB2G_sink();
}

void CWE606_Unchecked_Loop_Condition__char_fromConsole_68_good()
{
    goodG2B();
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
    CWE606_Unchecked_Loop_Condition__char_fromConsole_68_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE606_Unchecked_Loop_Condition__char_fromConsole_68_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
