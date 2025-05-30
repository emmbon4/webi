/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE252_Unchecked_Return_Value__w32RpcImpersonateClient_12.c
Label Definition File: CWE252_Unchecked_Return_Value.label.xml
Template File: point-flaw-12.tmpl.c
*/
/*
 * @description
 * CWE: 252 Unchecked Return Value
 * Sinks: w32RpcImpersonateClient
 *    GoodSink: Check the return value of RpcImpersonateClient() and handle it properly
 *    BadSink : Do not check if RpcImpersonateClient() fails
 * Flow Variant: 12 Control flow: if(global_returns_t_or_f())
 *
 * */

#include "std_testcase.h"

#include <windows.h>
#include <rpcdce.h>
# pragma comment(lib, "rpcrt4")

#ifndef OMITBAD

void CWE252_Unchecked_Return_Value__w32RpcImpersonateClient_12_bad()
{
    if(global_returns_t_or_f())
    {
        {
            RpcImpersonateClient(0);
            /* FLAW: Do not check if RpcImpersonateClient() fails */
            /* We'll leave out most of the implementation since it has nothing to do with the CWE
             * and since the checkers are looking for certain function calls anyway */
        }
    }
    else
    {
        {
            /* FIX: Check the return value of RpcImpersonateClient() for RPC_S_OK */
            if (RpcImpersonateClient(0) != RPC_S_OK)
            {
                exit(1);
            }
            /* We'll leave out most of the implementation since it has nothing to do with the CWE
             * and since the checkers are looking for certain function calls anyway */
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() uses the GoodSink on both sides of the "if" statement */
static void good1()
{
    if(global_returns_t_or_f())
    {
        {
            /* FIX: Check the return value of RpcImpersonateClient() for RPC_S_OK */
            if (RpcImpersonateClient(0) != RPC_S_OK)
            {
                exit(1);
            }
            /* We'll leave out most of the implementation since it has nothing to do with the CWE
             * and since the checkers are looking for certain function calls anyway */
        }
    }
    else
    {
        {
            /* FIX: Check the return value of RpcImpersonateClient() for RPC_S_OK */
            if (RpcImpersonateClient(0) != RPC_S_OK)
            {
                exit(1);
            }
            /* We'll leave out most of the implementation since it has nothing to do with the CWE
             * and since the checkers are looking for certain function calls anyway */
        }
    }
}

void CWE252_Unchecked_Return_Value__w32RpcImpersonateClient_12_good()
{
    good1();
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
    CWE252_Unchecked_Return_Value__w32RpcImpersonateClient_12_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE252_Unchecked_Return_Value__w32RpcImpersonateClient_12_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
