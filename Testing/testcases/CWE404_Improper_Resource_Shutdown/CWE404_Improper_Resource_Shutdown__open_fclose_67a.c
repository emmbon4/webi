/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE404_Improper_Resource_Shutdown__open_fclose_67a.c
Label Definition File: CWE404_Improper_Resource_Shutdown__open.label.xml
Template File: source-sinks-67a.tmpl.c
*/
/*
 * @description
 * CWE: 404 Improper Resource Shutdown or Release
 * BadSource:  Open a file using open()
 * Sinks: fclose
 *    GoodSink: Close the file using close()
 *    BadSink : Close the file using fclose()
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
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

typedef struct _CWE404_Improper_Resource_Shutdown__open_fclose_67_struct_type
{
    int a;
} CWE404_Improper_Resource_Shutdown__open_fclose_67_struct_type;

#ifndef OMITBAD

/* bad function declaration */
void CWE404_Improper_Resource_Shutdown__open_fclose_67b_bad_sink(CWE404_Improper_Resource_Shutdown__open_fclose_67_struct_type my_struct);

void CWE404_Improper_Resource_Shutdown__open_fclose_67_bad()
{
    int data;
    CWE404_Improper_Resource_Shutdown__open_fclose_67_struct_type my_struct;
    /* Initialize data */
    data = -1;
    data = OPEN("BadSource_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE);
    my_struct.a = data;
    CWE404_Improper_Resource_Shutdown__open_fclose_67b_bad_sink(my_struct);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G uses the BadSource with the GoodSink */
void CWE404_Improper_Resource_Shutdown__open_fclose_67b_goodB2G_sink(CWE404_Improper_Resource_Shutdown__open_fclose_67_struct_type my_struct);

static void goodB2G()
{
    int data;
    CWE404_Improper_Resource_Shutdown__open_fclose_67_struct_type my_struct;
    /* Initialize data */
    data = -1;
    data = OPEN("BadSource_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE);
    my_struct.a = data;
    CWE404_Improper_Resource_Shutdown__open_fclose_67b_goodB2G_sink(my_struct);
}

void CWE404_Improper_Resource_Shutdown__open_fclose_67_good()
{
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
    CWE404_Improper_Resource_Shutdown__open_fclose_67_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE404_Improper_Resource_Shutdown__open_fclose_67_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
