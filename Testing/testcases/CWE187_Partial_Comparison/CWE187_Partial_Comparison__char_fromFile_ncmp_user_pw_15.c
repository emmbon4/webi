/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE187_Partial_Comparison__char_fromFile_ncmp_user_pw_15.c
Label Definition File: CWE187_Partial_Comparison.label.xml
Template File: sources-sinks-15.tmpl.c
*/
/*
 * @description
 * CWE: 187 Partial Comparison
 * BadSource: fromFile Read input from a file
 * GoodSource: Provide a matching password
 * Sinks: ncmp_user_pw
 *    GoodSink: Compare the 2 passwords correctly
 *    BadSink : use strncmp() to do password match, but use the length of the user password
 * Flow Variant: 15 Control flow: switch(6) and switch(7)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#define PASSWORD "Password1234"
/* PASSWORD_SZ must equal the length of PASSWORD */
#define PASSWORD_SZ strlen(PASSWORD)

#ifdef _WIN32
# define FOPEN fopen
#else
/* fopen is used on unix-based OSs */
# define FOPEN fopen
#endif

#ifndef OMITBAD

void CWE187_Partial_Comparison__char_fromFile_ncmp_user_pw_15_bad()
{
    char * data;
    char data_buf[100] = "";
    data = data_buf;
    switch(6)
    {
    case 6:
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
    break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Use the matching string */
        data = PASSWORD;
        break;
    }
    switch(7)
    {
    case 7:
        /* By using the strlen() of the input password, you are able to create a partial comparison
         * For example if PASSWORD=PASSWORD1234, a user supplied password of PASSWORD12 will allow access */
        /* POTENTIAL FLAW: Possibly partially compare the two passwords */
        if (strncmp(PASSWORD, data, strlen(data)) == 0)
            printLine("Access granted");
        else
            printLine("Access denied!");
        break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* Ideally, we would want to do a check to see if the passwords are of equal length */
        /* FIX: Compare the two passwords completely and correctly */
        if (strcmp(PASSWORD, data) == 0)
            printLine("Access granted");
        else
            printLine("Access denied!");
        break;
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G1() - use badsource and goodsink by changing the second switch to switch(8) */
static void goodB2G1()
{
    char * data;
    char data_buf[100] = "";
    data = data_buf;
    switch(6)
    {
    case 6:
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
    break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Use the matching string */
        data = PASSWORD;
        break;
    }
    switch(8)
    {
    case 7:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* By using the strlen() of the input password, you are able to create a partial comparison
         * For example if PASSWORD=PASSWORD1234, a user supplied password of PASSWORD12 will allow access */
        /* POTENTIAL FLAW: Possibly partially compare the two passwords */
        if (strncmp(PASSWORD, data, strlen(data)) == 0)
            printLine("Access granted");
        else
            printLine("Access denied!");
        break;
    default:
        /* Ideally, we would want to do a check to see if the passwords are of equal length */
        /* FIX: Compare the two passwords completely and correctly */
        if (strcmp(PASSWORD, data) == 0)
            printLine("Access granted");
        else
            printLine("Access denied!");
        break;
    }
}

/* goodB2G2() - use badsource and goodsink by reversing the blocks in the second switch */
static void goodB2G2()
{
    char * data;
    char data_buf[100] = "";
    data = data_buf;
    switch(6)
    {
    case 6:
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
    break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Use the matching string */
        data = PASSWORD;
        break;
    }
    switch(7)
    {
    case 7:
        /* Ideally, we would want to do a check to see if the passwords are of equal length */
        /* FIX: Compare the two passwords completely and correctly */
        if (strcmp(PASSWORD, data) == 0)
            printLine("Access granted");
        else
            printLine("Access denied!");
        break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* By using the strlen() of the input password, you are able to create a partial comparison
         * For example if PASSWORD=PASSWORD1234, a user supplied password of PASSWORD12 will allow access */
        /* POTENTIAL FLAW: Possibly partially compare the two passwords */
        if (strncmp(PASSWORD, data, strlen(data)) == 0)
            printLine("Access granted");
        else
            printLine("Access denied!");
        break;
    }
}

/* goodG2B1() - use goodsource and badsink by changing the first switch to switch(5) */
static void goodG2B1()
{
    char * data;
    char data_buf[100] = "";
    data = data_buf;
    switch(5)
    {
    case 6:
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
    break;
    default:
        /* FIX: Use the matching string */
        data = PASSWORD;
        break;
    }
    switch(7)
    {
    case 7:
        /* By using the strlen() of the input password, you are able to create a partial comparison
         * For example if PASSWORD=PASSWORD1234, a user supplied password of PASSWORD12 will allow access */
        /* POTENTIAL FLAW: Possibly partially compare the two passwords */
        if (strncmp(PASSWORD, data, strlen(data)) == 0)
            printLine("Access granted");
        else
            printLine("Access denied!");
        break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* Ideally, we would want to do a check to see if the passwords are of equal length */
        /* FIX: Compare the two passwords completely and correctly */
        if (strcmp(PASSWORD, data) == 0)
            printLine("Access granted");
        else
            printLine("Access denied!");
        break;
    }
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the first switch */
static void goodG2B2()
{
    char * data;
    char data_buf[100] = "";
    data = data_buf;
    switch(6)
    {
    case 6:
        /* FIX: Use the matching string */
        data = PASSWORD;
        break;
    default:
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
    break;
    }
    switch(7)
    {
    case 7:
        /* By using the strlen() of the input password, you are able to create a partial comparison
         * For example if PASSWORD=PASSWORD1234, a user supplied password of PASSWORD12 will allow access */
        /* POTENTIAL FLAW: Possibly partially compare the two passwords */
        if (strncmp(PASSWORD, data, strlen(data)) == 0)
            printLine("Access granted");
        else
            printLine("Access denied!");
        break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* Ideally, we would want to do a check to see if the passwords are of equal length */
        /* FIX: Compare the two passwords completely and correctly */
        if (strcmp(PASSWORD, data) == 0)
            printLine("Access granted");
        else
            printLine("Access denied!");
        break;
    }
}

void CWE187_Partial_Comparison__char_fromFile_ncmp_user_pw_15_good()
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
    CWE187_Partial_Comparison__char_fromFile_ncmp_user_pw_15_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE187_Partial_Comparison__char_fromFile_ncmp_user_pw_15_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
