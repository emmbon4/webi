/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE547_Hardcoded_Security_Constants__basic_05.c
Label Definition File: CWE547_Hardcoded_Security_Constants__basic.label.xml
Template File: point-flaw-05.tmpl.c
*/
/*
 * @description
 * CWE: 547 Use Of Hardcoded Security Relevant Constants
 * Sinks:
 *    GoodSink: Use a #define for the buffer size
 *    BadSink : Used a hard-coded constant for the buffer size
 * Flow Variant: 05 Control flow: if(static_t) and if(static_f)
 *
 * */

#include "std_testcase.h"

#define SRC_STR "AAAA"
#define DST_SZ 5 /* maintenance note: ensure this is > strlen(SRC_STR) */

/* The two variables below are not defined as "const", but are never
   assigned any other value, so a tool should be able to identify that
   reads of these will always return their initialized values. */
static int static_t = 1; /* true */
static int static_f = 0; /* false */

#ifndef OMITBAD

void CWE547_Hardcoded_Security_Constants__basic_05_bad()
{
    if(static_t)
    {
        {
            char src[] = "AAAA";
            /* FLAW: Used a hard-coded constant for the buffer size */
            char dst[5]; /* maintenance note: ensure this is > strlen(src) */
            memcpy(dst, src, sizeof(src));
            printLine(dst);
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            char src[] = SRC_STR;
            /* FIX: use a #define instead */
            char dst[DST_SZ];
            memcpy(dst, src, sizeof(src));
            printLine(dst);
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() uses if(static_f) instead of if(static_t) */
static void good1()
{
    if(static_f)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            char src[] = "AAAA";
            /* FLAW: Used a hard-coded constant for the buffer size */
            char dst[5]; /* maintenance note: ensure this is > strlen(src) */
            memcpy(dst, src, sizeof(src));
            printLine(dst);
        }
    }
    else
    {
        {
            char src[] = SRC_STR;
            /* FIX: use a #define instead */
            char dst[DST_SZ];
            memcpy(dst, src, sizeof(src));
            printLine(dst);
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(static_t)
    {
        {
            char src[] = SRC_STR;
            /* FIX: use a #define instead */
            char dst[DST_SZ];
            memcpy(dst, src, sizeof(src));
            printLine(dst);
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            char src[] = "AAAA";
            /* FLAW: Used a hard-coded constant for the buffer size */
            char dst[5]; /* maintenance note: ensure this is > strlen(src) */
            memcpy(dst, src, sizeof(src));
            printLine(dst);
        }
    }
}

void CWE547_Hardcoded_Security_Constants__basic_05_good()
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
    CWE547_Hardcoded_Security_Constants__basic_05_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE547_Hardcoded_Security_Constants__basic_05_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
