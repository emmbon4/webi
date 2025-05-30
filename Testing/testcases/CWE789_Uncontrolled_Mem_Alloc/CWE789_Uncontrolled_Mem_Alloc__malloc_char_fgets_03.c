/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE789_Uncontrolled_Mem_Alloc__malloc_char_fgets_03.c
Label Definition File: CWE789_Uncontrolled_Mem_Alloc__malloc.label.xml
Template File: sources-sinks-03.tmpl.c
*/
/*
 * @description
 * CWE: 789 Uncontrolled Memory Allocation
 * BadSource: fgets Read data from the console using fgets()
 * GoodSource: Small number greater than zero
 * Sinks:
 *    GoodSink: Allocate memory with malloc() and check the size of the memory to be allocated
 *    BadSink : Allocate memory with malloc(), but incorrectly check the size of the memory to be allocated
 * Flow Variant: 03 Control flow: if(5==5) and if(5!=5)
 *
 * */

#include "std_testcase.h"

#define CHAR_ARRAY_SIZE sizeof(data)*sizeof(data)

#define HELLO_STRING "hello"

#ifndef OMITBAD

void CWE789_Uncontrolled_Mem_Alloc__malloc_char_fgets_03_bad()
{
    int data;
    /* Initialize data */
    data = -1;
    if(5==5)
    {
        {
            char input_buf[CHAR_ARRAY_SIZE] = "";
            fgets(input_buf, CHAR_ARRAY_SIZE, stdin);
            /* Convert to int */
            data = atoi(input_buf);
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Use a relatively small number for memory allocation */
        data = 20;
    }
    if(5==5)
    {
        {
            char * char_string;
            /* FLAW: No MAXIMUM limitation for memory allocation and no check to ensure data is large enough
             * for the strcpy() function to not cause a buffer overflow */
            /* INCIDENTAL FLAW: The source could cause a type overrun in data or in the memory allocation */
            if (data > 0)
            {
                char_string = (char *)malloc(data*sizeof(char));
                /* Copy a small string into char_string$ */
                strcpy(char_string, HELLO_STRING);
                printLine(char_string);
                free(char_string);
            }
            else
            {
                printLine("Input is less than 0");
            }
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            char * char_string;
            /* FIX: Include a MAXIMUM limitation for memory allocation and a check to ensure data is large enough
             * for the strcpy() function to not cause a buffer overflow */
            /* INCIDENTAL FLAW: The source could cause a type overrun in data or in the memory allocation */
            if ((size_t)data > strlen(HELLO_STRING) && data < 100)
            {
                char_string = (char *)malloc(data*sizeof(char));
                /* Copy a small string into char_string$ */
                strcpy(char_string, HELLO_STRING);
                printLine(char_string);
                free(char_string);
            }
            else
            {
                printLine("Input is less than the length of the source string or too large");
            }
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G1() - use badsource and goodsink by changing the second 5==5 to 5!=5 */
static void goodB2G1()
{
    int data;
    /* Initialize data */
    data = -1;
    if(5==5)
    {
        {
            char input_buf[CHAR_ARRAY_SIZE] = "";
            fgets(input_buf, CHAR_ARRAY_SIZE, stdin);
            /* Convert to int */
            data = atoi(input_buf);
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Use a relatively small number for memory allocation */
        data = 20;
    }
    if(5!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            char * char_string;
            /* FLAW: No MAXIMUM limitation for memory allocation and no check to ensure data is large enough
             * for the strcpy() function to not cause a buffer overflow */
            /* INCIDENTAL FLAW: The source could cause a type overrun in data or in the memory allocation */
            if (data > 0)
            {
                char_string = (char *)malloc(data*sizeof(char));
                /* Copy a small string into char_string$ */
                strcpy(char_string, HELLO_STRING);
                printLine(char_string);
                free(char_string);
            }
            else
            {
                printLine("Input is less than 0");
            }
        }
    }
    else
    {
        {
            char * char_string;
            /* FIX: Include a MAXIMUM limitation for memory allocation and a check to ensure data is large enough
             * for the strcpy() function to not cause a buffer overflow */
            /* INCIDENTAL FLAW: The source could cause a type overrun in data or in the memory allocation */
            if ((size_t)data > strlen(HELLO_STRING) && data < 100)
            {
                char_string = (char *)malloc(data*sizeof(char));
                /* Copy a small string into char_string$ */
                strcpy(char_string, HELLO_STRING);
                printLine(char_string);
                free(char_string);
            }
            else
            {
                printLine("Input is less than the length of the source string or too large");
            }
        }
    }
}

/* goodB2G2() - use badsource and goodsink by reversing the blocks in the second if */
static void goodB2G2()
{
    int data;
    /* Initialize data */
    data = -1;
    if(5==5)
    {
        {
            char input_buf[CHAR_ARRAY_SIZE] = "";
            fgets(input_buf, CHAR_ARRAY_SIZE, stdin);
            /* Convert to int */
            data = atoi(input_buf);
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Use a relatively small number for memory allocation */
        data = 20;
    }
    if(5==5)
    {
        {
            char * char_string;
            /* FIX: Include a MAXIMUM limitation for memory allocation and a check to ensure data is large enough
             * for the strcpy() function to not cause a buffer overflow */
            /* INCIDENTAL FLAW: The source could cause a type overrun in data or in the memory allocation */
            if ((size_t)data > strlen(HELLO_STRING) && data < 100)
            {
                char_string = (char *)malloc(data*sizeof(char));
                /* Copy a small string into char_string$ */
                strcpy(char_string, HELLO_STRING);
                printLine(char_string);
                free(char_string);
            }
            else
            {
                printLine("Input is less than the length of the source string or too large");
            }
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            char * char_string;
            /* FLAW: No MAXIMUM limitation for memory allocation and no check to ensure data is large enough
             * for the strcpy() function to not cause a buffer overflow */
            /* INCIDENTAL FLAW: The source could cause a type overrun in data or in the memory allocation */
            if (data > 0)
            {
                char_string = (char *)malloc(data*sizeof(char));
                /* Copy a small string into char_string$ */
                strcpy(char_string, HELLO_STRING);
                printLine(char_string);
                free(char_string);
            }
            else
            {
                printLine("Input is less than 0");
            }
        }
    }
}

/* goodG2B1() - use goodsource and badsink by changing the first 5==5 to 5!=5 */
static void goodG2B1()
{
    int data;
    /* Initialize data */
    data = -1;
    if(5!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            char input_buf[CHAR_ARRAY_SIZE] = "";
            fgets(input_buf, CHAR_ARRAY_SIZE, stdin);
            /* Convert to int */
            data = atoi(input_buf);
        }
    }
    else
    {
        /* FIX: Use a relatively small number for memory allocation */
        data = 20;
    }
    if(5==5)
    {
        {
            char * char_string;
            /* FLAW: No MAXIMUM limitation for memory allocation and no check to ensure data is large enough
             * for the strcpy() function to not cause a buffer overflow */
            /* INCIDENTAL FLAW: The source could cause a type overrun in data or in the memory allocation */
            if (data > 0)
            {
                char_string = (char *)malloc(data*sizeof(char));
                /* Copy a small string into char_string$ */
                strcpy(char_string, HELLO_STRING);
                printLine(char_string);
                free(char_string);
            }
            else
            {
                printLine("Input is less than 0");
            }
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            char * char_string;
            /* FIX: Include a MAXIMUM limitation for memory allocation and a check to ensure data is large enough
             * for the strcpy() function to not cause a buffer overflow */
            /* INCIDENTAL FLAW: The source could cause a type overrun in data or in the memory allocation */
            if ((size_t)data > strlen(HELLO_STRING) && data < 100)
            {
                char_string = (char *)malloc(data*sizeof(char));
                /* Copy a small string into char_string$ */
                strcpy(char_string, HELLO_STRING);
                printLine(char_string);
                free(char_string);
            }
            else
            {
                printLine("Input is less than the length of the source string or too large");
            }
        }
    }
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the first if */
static void goodG2B2()
{
    int data;
    /* Initialize data */
    data = -1;
    if(5==5)
    {
        /* FIX: Use a relatively small number for memory allocation */
        data = 20;
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            char input_buf[CHAR_ARRAY_SIZE] = "";
            fgets(input_buf, CHAR_ARRAY_SIZE, stdin);
            /* Convert to int */
            data = atoi(input_buf);
        }
    }
    if(5==5)
    {
        {
            char * char_string;
            /* FLAW: No MAXIMUM limitation for memory allocation and no check to ensure data is large enough
             * for the strcpy() function to not cause a buffer overflow */
            /* INCIDENTAL FLAW: The source could cause a type overrun in data or in the memory allocation */
            if (data > 0)
            {
                char_string = (char *)malloc(data*sizeof(char));
                /* Copy a small string into char_string$ */
                strcpy(char_string, HELLO_STRING);
                printLine(char_string);
                free(char_string);
            }
            else
            {
                printLine("Input is less than 0");
            }
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            char * char_string;
            /* FIX: Include a MAXIMUM limitation for memory allocation and a check to ensure data is large enough
             * for the strcpy() function to not cause a buffer overflow */
            /* INCIDENTAL FLAW: The source could cause a type overrun in data or in the memory allocation */
            if ((size_t)data > strlen(HELLO_STRING) && data < 100)
            {
                char_string = (char *)malloc(data*sizeof(char));
                /* Copy a small string into char_string$ */
                strcpy(char_string, HELLO_STRING);
                printLine(char_string);
                free(char_string);
            }
            else
            {
                printLine("Input is less than the length of the source string or too large");
            }
        }
    }
}

void CWE789_Uncontrolled_Mem_Alloc__malloc_char_fgets_03_good()
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
    CWE789_Uncontrolled_Mem_Alloc__malloc_char_fgets_03_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE789_Uncontrolled_Mem_Alloc__malloc_char_fgets_03_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
