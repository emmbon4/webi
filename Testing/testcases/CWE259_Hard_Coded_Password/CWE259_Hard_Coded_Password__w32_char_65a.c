/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE259_Hard_Coded_Password__w32_char_65a.c
Label Definition File: CWE259_Hard_Coded_Password__w32.label.xml
Template File: sources-sink-65a.tmpl.c
*/
/*
 * @description
 * CWE: 259 Use of Hard-coded Password
 * BadSource:  Use a hardcoded password
 * GoodSource: Read the password from the console
 * Sinks:
 *    BadSink : Authenticate the user using LogonUserA()
 * Flow Variant: 65 Data/control flow: data passed as an argument from one function to a function in a different source file called via a function pointer
 *
 * */

#include "std_testcase.h"

#include <wchar.h>
#define PASSWORD_SZ 100

#define PASSWORD "ABCD1234!"

#ifdef _WIN32
#include <windows.h>
#pragma comment(lib, "advapi32.lib")
#endif

#ifndef OMITBAD

/* bad function declaration */
void CWE259_Hard_Coded_Password__w32_char_65b_bad_sink(char * password);

void CWE259_Hard_Coded_Password__w32_char_65_bad()
{
    char * password;
    /* define a function pointer */
    void (*func_ptr) (char *) = CWE259_Hard_Coded_Password__w32_char_65b_bad_sink;
    char password_buf[100] = "";
    password = password_buf;
    /* FLAW: Use a hardcoded password */
    strcpy(password, PASSWORD);
    /* use the function pointer */
    func_ptr(password);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE259_Hard_Coded_Password__w32_char_65b_goodG2B_sink(char * password);

static void goodG2B()
{
    char * password;
    void (*func_ptr) (char *) = CWE259_Hard_Coded_Password__w32_char_65b_goodG2B_sink;
    char password_buf[100] = "";
    password = password_buf;
    {
        size_t password_len = 0;
        /* FIX: Read the password from the console */
        fgets(password, 100, stdin);
        /* Remove the carriage return from the string that is inserted by fgets() */
        password_len = strlen(password);
        if (password_len > 0)
        {
            password[password_len-1] = '\0';
        }
    }
    func_ptr(password);
}

void CWE259_Hard_Coded_Password__w32_char_65_good()
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
    CWE259_Hard_Coded_Password__w32_char_65_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE259_Hard_Coded_Password__w32_char_65_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
