/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE187_Partial_Comparison__char_connect_socket_ncmp_correct_pw_53c.c
Label Definition File: CWE187_Partial_Comparison.label.xml
Template File: sources-sinks-53c.tmpl.c
*/
/*
 * @description
 * CWE: 187 Partial Comparison
 * BadSource: connect_socket Read data using a connect socket (client side)
 * GoodSource: Provide a matching password
 * Sinks: ncmp_correct_pw
 *    GoodSink: Compare the 2 passwords correctly
 *    BadSink : use strncmp() to do password match, but use the length of the correct password
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#define PASSWORD "Password1234"
/* PASSWORD_SZ must equal the length of PASSWORD */
#define PASSWORD_SZ strlen(PASSWORD)

#ifdef _WIN32
# include <winsock2.h>
# include <windows.h>
# include <direct.h>
# pragma comment(lib, "ws2_32") /* include ws2_32.lib when linking */
# define CLOSE_SOCKET closesocket
# define PATH_SZ 100
#else /* NOT _WIN32 */
# define INVALID_SOCKET -1
# define SOCKET_ERROR -1
# define CLOSE_SOCKET close
# define SOCKET int
# define PATH_SZ PATH_MAX
#endif

#define TCP_PORT 27015

#ifndef OMITBAD

/* bad function declaration */
void CWE187_Partial_Comparison__char_connect_socket_ncmp_correct_pw_53d_bad_sink(char * data);

void CWE187_Partial_Comparison__char_connect_socket_ncmp_correct_pw_53c_bad_sink(char * data)
{
    CWE187_Partial_Comparison__char_connect_socket_ncmp_correct_pw_53d_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE187_Partial_Comparison__char_connect_socket_ncmp_correct_pw_53d_goodG2B_sink(char * data);

void CWE187_Partial_Comparison__char_connect_socket_ncmp_correct_pw_53c_goodG2B_sink(char * data)
{
    CWE187_Partial_Comparison__char_connect_socket_ncmp_correct_pw_53d_goodG2B_sink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE187_Partial_Comparison__char_connect_socket_ncmp_correct_pw_53d_goodB2G_sink(char * data);

void CWE187_Partial_Comparison__char_connect_socket_ncmp_correct_pw_53c_goodB2G_sink(char * data)
{
    CWE187_Partial_Comparison__char_connect_socket_ncmp_correct_pw_53d_goodB2G_sink(data);
}

#endif /* OMITGOOD */
