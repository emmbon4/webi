/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE789_Uncontrolled_Mem_Alloc__new_char_fgets_15.cpp
Label Definition File: CWE789_Uncontrolled_Mem_Alloc__new.label.xml
Template File: sources-sinks-15.tmpl.cpp
*/
/*
 * @description
 * CWE: 789 Uncontrolled Memory Allocation
 * BadSource: fgets Read data from the console using fgets()
 * GoodSource: Small number greater than zero
 * Sinks:
 *    GoodSink: Allocate memory with new [] and check the size of the memory to be allocated
 *    BadSink : Allocate memory with new [], but incorrectly check the size of the memory to be allocated
 * Flow Variant: 15 Control flow: switch(6) and switch(7)
 * */

#include "std_testcase.h"

#define CHAR_ARRAY_SIZE sizeof(data)*sizeof(data)

#define HELLO_STRING "hello"

namespace CWE789_Uncontrolled_Mem_Alloc__new_char_fgets_15
{

#ifndef OMITBAD

void bad()
{
    int data;
    /* Initialize data */
    data = -1;
    switch(6)
    {
    case 6:
    {
        char input_buf[CHAR_ARRAY_SIZE] = "";
        fgets(input_buf, CHAR_ARRAY_SIZE, stdin);
        /* Convert to int */
        data = atoi(input_buf);
    }
    break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Use a relatively small number for memory allocation */
        data = 20;
        break;
    }
    switch(7)
    {
    case 7:
    {
        char * char_string;
        /* FLAW: No MAXIMUM limitation for memory allocation and no check to ensure data is large enough
         * for the strcpy() function to not cause a buffer overflow */
        /* INCIDENTAL FLAW: The source could cause a type overrun in data or in the memory allocation */
        if (data > 0)
        {
            char_string = new char[data];
            /* Copy a small string into char_string$ */
            strcpy(char_string, HELLO_STRING);
            printLine(char_string);
            delete [] char_string;
        }
        else
        {
            printLine("Input is less than 0");
        }
    }
    break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        char * char_string;
        /* FIX: Include a MAXIMUM limitation for memory allocation and a check to ensure data is large enough
         * for the strcpy() function to not cause a buffer overflow */
        /* INCIDENTAL FLAW: The source could cause a type overrun in data or in the memory allocation */
        if ((size_t)data > strlen(HELLO_STRING) && data < 100)
        {
            char_string = new char[data];
            /* Copy a small string into char_string$ */
            strcpy(char_string, HELLO_STRING);
            printLine(char_string);
            delete [] char_string;
        }
        else
        {
            printLine("Input is less than the length of the source string or too large");
        }
    }
    break;
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G1() - use badsource and goodsink by changing the second switch to switch(8) */
static void goodB2G1()
{
    int data;
    /* Initialize data */
    data = -1;
    switch(6)
    {
    case 6:
    {
        char input_buf[CHAR_ARRAY_SIZE] = "";
        fgets(input_buf, CHAR_ARRAY_SIZE, stdin);
        /* Convert to int */
        data = atoi(input_buf);
    }
    break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Use a relatively small number for memory allocation */
        data = 20;
        break;
    }
    switch(8)
    {
    case 7:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        char * char_string;
        /* FLAW: No MAXIMUM limitation for memory allocation and no check to ensure data is large enough
         * for the strcpy() function to not cause a buffer overflow */
        /* INCIDENTAL FLAW: The source could cause a type overrun in data or in the memory allocation */
        if (data > 0)
        {
            char_string = new char[data];
            /* Copy a small string into char_string$ */
            strcpy(char_string, HELLO_STRING);
            printLine(char_string);
            delete [] char_string;
        }
        else
        {
            printLine("Input is less than 0");
        }
    }
    break;
    default:
    {
        char * char_string;
        /* FIX: Include a MAXIMUM limitation for memory allocation and a check to ensure data is large enough
         * for the strcpy() function to not cause a buffer overflow */
        /* INCIDENTAL FLAW: The source could cause a type overrun in data or in the memory allocation */
        if ((size_t)data > strlen(HELLO_STRING) && data < 100)
        {
            char_string = new char[data];
            /* Copy a small string into char_string$ */
            strcpy(char_string, HELLO_STRING);
            printLine(char_string);
            delete [] char_string;
        }
        else
        {
            printLine("Input is less than the length of the source string or too large");
        }
    }
    break;
    }
}

/* goodB2G2() - use badsource and goodsink by reversing the blocks in the second switch */
static void goodB2G2()
{
    int data;
    /* Initialize data */
    data = -1;
    switch(6)
    {
    case 6:
    {
        char input_buf[CHAR_ARRAY_SIZE] = "";
        fgets(input_buf, CHAR_ARRAY_SIZE, stdin);
        /* Convert to int */
        data = atoi(input_buf);
    }
    break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Use a relatively small number for memory allocation */
        data = 20;
        break;
    }
    switch(7)
    {
    case 7:
    {
        char * char_string;
        /* FIX: Include a MAXIMUM limitation for memory allocation and a check to ensure data is large enough
         * for the strcpy() function to not cause a buffer overflow */
        /* INCIDENTAL FLAW: The source could cause a type overrun in data or in the memory allocation */
        if ((size_t)data > strlen(HELLO_STRING) && data < 100)
        {
            char_string = new char[data];
            /* Copy a small string into char_string$ */
            strcpy(char_string, HELLO_STRING);
            printLine(char_string);
            delete [] char_string;
        }
        else
        {
            printLine("Input is less than the length of the source string or too large");
        }
    }
    break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        char * char_string;
        /* FLAW: No MAXIMUM limitation for memory allocation and no check to ensure data is large enough
         * for the strcpy() function to not cause a buffer overflow */
        /* INCIDENTAL FLAW: The source could cause a type overrun in data or in the memory allocation */
        if (data > 0)
        {
            char_string = new char[data];
            /* Copy a small string into char_string$ */
            strcpy(char_string, HELLO_STRING);
            printLine(char_string);
            delete [] char_string;
        }
        else
        {
            printLine("Input is less than 0");
        }
    }
    break;
    }
}

/* goodG2B1() - use goodsource and badsink by changing the first switch to switch(5) */
static void goodG2B1()
{
    int data;
    /* Initialize data */
    data = -1;
    switch(5)
    {
    case 6:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        char input_buf[CHAR_ARRAY_SIZE] = "";
        fgets(input_buf, CHAR_ARRAY_SIZE, stdin);
        /* Convert to int */
        data = atoi(input_buf);
    }
    break;
    default:
        /* FIX: Use a relatively small number for memory allocation */
        data = 20;
        break;
    }
    switch(7)
    {
    case 7:
    {
        char * char_string;
        /* FLAW: No MAXIMUM limitation for memory allocation and no check to ensure data is large enough
         * for the strcpy() function to not cause a buffer overflow */
        /* INCIDENTAL FLAW: The source could cause a type overrun in data or in the memory allocation */
        if (data > 0)
        {
            char_string = new char[data];
            /* Copy a small string into char_string$ */
            strcpy(char_string, HELLO_STRING);
            printLine(char_string);
            delete [] char_string;
        }
        else
        {
            printLine("Input is less than 0");
        }
    }
    break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        char * char_string;
        /* FIX: Include a MAXIMUM limitation for memory allocation and a check to ensure data is large enough
         * for the strcpy() function to not cause a buffer overflow */
        /* INCIDENTAL FLAW: The source could cause a type overrun in data or in the memory allocation */
        if ((size_t)data > strlen(HELLO_STRING) && data < 100)
        {
            char_string = new char[data];
            /* Copy a small string into char_string$ */
            strcpy(char_string, HELLO_STRING);
            printLine(char_string);
            delete [] char_string;
        }
        else
        {
            printLine("Input is less than the length of the source string or too large");
        }
    }
    break;
    }
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the first switch */
static void goodG2B2()
{
    int data;
    /* Initialize data */
    data = -1;
    switch(6)
    {
    case 6:
        /* FIX: Use a relatively small number for memory allocation */
        data = 20;
        break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        char input_buf[CHAR_ARRAY_SIZE] = "";
        fgets(input_buf, CHAR_ARRAY_SIZE, stdin);
        /* Convert to int */
        data = atoi(input_buf);
    }
    break;
    }
    switch(7)
    {
    case 7:
    {
        char * char_string;
        /* FLAW: No MAXIMUM limitation for memory allocation and no check to ensure data is large enough
         * for the strcpy() function to not cause a buffer overflow */
        /* INCIDENTAL FLAW: The source could cause a type overrun in data or in the memory allocation */
        if (data > 0)
        {
            char_string = new char[data];
            /* Copy a small string into char_string$ */
            strcpy(char_string, HELLO_STRING);
            printLine(char_string);
            delete [] char_string;
        }
        else
        {
            printLine("Input is less than 0");
        }
    }
    break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        char * char_string;
        /* FIX: Include a MAXIMUM limitation for memory allocation and a check to ensure data is large enough
         * for the strcpy() function to not cause a buffer overflow */
        /* INCIDENTAL FLAW: The source could cause a type overrun in data or in the memory allocation */
        if ((size_t)data > strlen(HELLO_STRING) && data < 100)
        {
            char_string = new char[data];
            /* Copy a small string into char_string$ */
            strcpy(char_string, HELLO_STRING);
            printLine(char_string);
            delete [] char_string;
        }
        else
        {
            printLine("Input is less than the length of the source string or too large");
        }
    }
    break;
    }
}

void good()
{
    goodB2G1();
    goodB2G2();
    goodG2B1();
    goodG2B2();
}

#endif /* OMITGOOD */

} // close namespace

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE789_Uncontrolled_Mem_Alloc__new_char_fgets_15; // so that we can use good and bad easily

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
