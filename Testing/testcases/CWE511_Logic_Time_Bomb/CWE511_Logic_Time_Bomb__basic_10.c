/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE511_Logic_Time_Bomb__basic_10.c
Label Definition File: CWE511_Logic_Time_Bomb__basic.label.xml
Template File: point-flaw-10.tmpl.c
*/
/*
 * @description
 * CWE: 511 Logic Time Bomb
 * Sinks:
 *    GoodSink: After a certain date, do something harmless
 *    BadSink : After a certain date, do something bad
 * Flow Variant: 10 Control flow: if(global_t) and if(global_f)
 *
 * */

#include "std_testcase.h"

#include <time.h>

#define TIME_CHECK ((time_t)1199163600) /* Jan 1, 2008 12:00:00 AM */

#ifdef _WIN32
# define UNLINK _unlink
#else
# define UNLINK unlink
#endif

#ifndef OMITBAD

void CWE511_Logic_Time_Bomb__basic_10_bad()
{
    if(global_t)
    {
        {
            time_t time_val;
            /* FLAW: After a certain date, delete a file */
            time(&time_val);
            if (time_val > TIME_CHECK)
            {
                UNLINK("important_file.txt");
            }
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            time_t time_val;
            /* FLAW: After a certain date, print to the console */
            time(&time_val);
            if (time_val > TIME_CHECK)
            {
                printLine("Happy New Year!");
            }
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() uses if(global_f) instead of if(global_t) */
static void good1()
{
    if(global_f)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            time_t time_val;
            /* FLAW: After a certain date, delete a file */
            time(&time_val);
            if (time_val > TIME_CHECK)
            {
                UNLINK("important_file.txt");
            }
        }
    }
    else
    {
        {
            time_t time_val;
            /* FLAW: After a certain date, print to the console */
            time(&time_val);
            if (time_val > TIME_CHECK)
            {
                printLine("Happy New Year!");
            }
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(global_t)
    {
        {
            time_t time_val;
            /* FLAW: After a certain date, print to the console */
            time(&time_val);
            if (time_val > TIME_CHECK)
            {
                printLine("Happy New Year!");
            }
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            time_t time_val;
            /* FLAW: After a certain date, delete a file */
            time(&time_val);
            if (time_val > TIME_CHECK)
            {
                UNLINK("important_file.txt");
            }
        }
    }
}

void CWE511_Logic_Time_Bomb__basic_10_good()
{
    good1();
    good2();
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
    CWE511_Logic_Time_Bomb__basic_10_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE511_Logic_Time_Bomb__basic_10_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
