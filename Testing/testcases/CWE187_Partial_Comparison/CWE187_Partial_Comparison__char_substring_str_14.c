/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE187_Partial_Comparison__char_substring_str_14.c
Label Definition File: CWE187_Partial_Comparison.label.xml
Template File: sources-sinks-14.tmpl.c
*/
/*
 * @description
 * CWE: 187 Partial Comparison
 * BadSource: substring Provide a password that is a shortened version of the actual password
 * GoodSource: Provide a matching password
 * Sinks: str
 *    GoodSink: Compare the 2 passwords correctly
 *    BadSink : use strstr() to do password match, which is a partial comparison
 * Flow Variant: 14 Control flow: if(global_five==5) and if(global_five!=5)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#define PASSWORD "Password1234"
/* PASSWORD_SZ must equal the length of PASSWORD */
#define PASSWORD_SZ strlen(PASSWORD)

#ifndef OMITBAD

void CWE187_Partial_Comparison__char_substring_str_14_bad()
{
    char * data;
    char data_buf[100] = "";
    data = data_buf;
    if(global_five==5)
    {
        /* FLAW: Provide a shortened version of the actual password
         * NOTE: This must be a substring of PASSWORD starting with the first character in PASSWORD
         * i.e. other examples could be "Pa", "Pas", "Pass", etc. as long as it is shorter than MIN_PASSWORD_SZ
         * and does not match the full PASSWORD string */
        data = "P";
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Use the matching string */
        data = PASSWORD;
    }
    if(global_five==5)
    {
        /* POTENTIAL FLAW: Partially compare the two passwords */
        if (strstr(PASSWORD, data) != NULL)
            printLine("Access granted");
        else
            printLine("Access denied!");
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* Ideally, we would want to do a check to see if the passwords are of equal length */
        /* FIX: Compare the two passwords completely and correctly */
        if (strcmp(PASSWORD, data) == 0)
            printLine("Access granted");
        else
            printLine("Access denied!");
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G1() - use badsource and goodsink by changing the second global_five==5 to global_five!=5 */
static void goodB2G1()
{
    char * data;
    char data_buf[100] = "";
    data = data_buf;
    if(global_five==5)
    {
        /* FLAW: Provide a shortened version of the actual password
         * NOTE: This must be a substring of PASSWORD starting with the first character in PASSWORD
         * i.e. other examples could be "Pa", "Pas", "Pass", etc. as long as it is shorter than MIN_PASSWORD_SZ
         * and does not match the full PASSWORD string */
        data = "P";
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Use the matching string */
        data = PASSWORD;
    }
    if(global_five!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* POTENTIAL FLAW: Partially compare the two passwords */
        if (strstr(PASSWORD, data) != NULL)
            printLine("Access granted");
        else
            printLine("Access denied!");
    }
    else
    {
        /* Ideally, we would want to do a check to see if the passwords are of equal length */
        /* FIX: Compare the two passwords completely and correctly */
        if (strcmp(PASSWORD, data) == 0)
            printLine("Access granted");
        else
            printLine("Access denied!");
    }
}

/* goodB2G2() - use badsource and goodsink by reversing the blocks in the second if */
static void goodB2G2()
{
    char * data;
    char data_buf[100] = "";
    data = data_buf;
    if(global_five==5)
    {
        /* FLAW: Provide a shortened version of the actual password
         * NOTE: This must be a substring of PASSWORD starting with the first character in PASSWORD
         * i.e. other examples could be "Pa", "Pas", "Pass", etc. as long as it is shorter than MIN_PASSWORD_SZ
         * and does not match the full PASSWORD string */
        data = "P";
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Use the matching string */
        data = PASSWORD;
    }
    if(global_five==5)
    {
        /* Ideally, we would want to do a check to see if the passwords are of equal length */
        /* FIX: Compare the two passwords completely and correctly */
        if (strcmp(PASSWORD, data) == 0)
            printLine("Access granted");
        else
            printLine("Access denied!");
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* POTENTIAL FLAW: Partially compare the two passwords */
        if (strstr(PASSWORD, data) != NULL)
            printLine("Access granted");
        else
            printLine("Access denied!");
    }
}

/* goodG2B1() - use goodsource and badsink by changing the first global_five==5 to global_five!=5 */
static void goodG2B1()
{
    char * data;
    char data_buf[100] = "";
    data = data_buf;
    if(global_five!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FLAW: Provide a shortened version of the actual password
         * NOTE: This must be a substring of PASSWORD starting with the first character in PASSWORD
         * i.e. other examples could be "Pa", "Pas", "Pass", etc. as long as it is shorter than MIN_PASSWORD_SZ
         * and does not match the full PASSWORD string */
        data = "P";
    }
    else
    {
        /* FIX: Use the matching string */
        data = PASSWORD;
    }
    if(global_five==5)
    {
        /* POTENTIAL FLAW: Partially compare the two passwords */
        if (strstr(PASSWORD, data) != NULL)
            printLine("Access granted");
        else
            printLine("Access denied!");
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* Ideally, we would want to do a check to see if the passwords are of equal length */
        /* FIX: Compare the two passwords completely and correctly */
        if (strcmp(PASSWORD, data) == 0)
            printLine("Access granted");
        else
            printLine("Access denied!");
    }
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the first if */
static void goodG2B2()
{
    char * data;
    char data_buf[100] = "";
    data = data_buf;
    if(global_five==5)
    {
        /* FIX: Use the matching string */
        data = PASSWORD;
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FLAW: Provide a shortened version of the actual password
         * NOTE: This must be a substring of PASSWORD starting with the first character in PASSWORD
         * i.e. other examples could be "Pa", "Pas", "Pass", etc. as long as it is shorter than MIN_PASSWORD_SZ
         * and does not match the full PASSWORD string */
        data = "P";
    }
    if(global_five==5)
    {
        /* POTENTIAL FLAW: Partially compare the two passwords */
        if (strstr(PASSWORD, data) != NULL)
            printLine("Access granted");
        else
            printLine("Access denied!");
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* Ideally, we would want to do a check to see if the passwords are of equal length */
        /* FIX: Compare the two passwords completely and correctly */
        if (strcmp(PASSWORD, data) == 0)
            printLine("Access granted");
        else
            printLine("Access denied!");
    }
}

void CWE187_Partial_Comparison__char_substring_str_14_good()
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
    CWE187_Partial_Comparison__char_substring_str_14_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE187_Partial_Comparison__char_substring_str_14_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
