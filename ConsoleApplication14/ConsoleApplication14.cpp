
#include <iostream>
#include <Windows.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>

using namespace std; 

void showSQLError(unsigned int handleType, const SQLHANDLE& handle) {
    SQLCHAR SQLState[1024]; 
    SQLCHAR message[1024]; 
    if (SQL_SUCCESS == SQLGetDiagRec(handleType, handle, 1, SQLState, NULL, message, 1024, NULL))
        cout << "SQL driver message : " << message << "\nSQL state:" << SQLState << "." << endl;
}
int main()
{
    SQLHANDLE SQLEnvHandle = NULL;
    SQLHANDLE SQLConnectionHandle = NULL; 
    SQLHANDLE SQLStaementHandle = NULL; 
    SQLRETURN retCode = 0; 
    char SQLQuery[] = "SELECT * FROM people";
    do {
        if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &SQLEnvHandle))
            break;
        if (SQL_SUCCESS != SQLSetEnvAttr(SQLEnvHandle, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0))
            break;
        if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_DBC, SQLEnvHandle, &SQLConnectionHandle))
            break; 
        if (SQL_SUCCESS != SQLSetConnectAttr(SQLConnectionHandle, SQL_LOGIN_TIMEOUT, (SQLPOINTER)5, 0))
            break; 
        SQLCHAR retConString[1024]; 
        SQLDriverConnect(SQLConnectionHandle, NULL, (SQLCHAR*)"DRIVER=(SQL Server); SERVER=localhost, 1433; DATABASE=MyDB;UID=myID; PWD=MyPWD", SQL_NTS, retConString, 1024, NULL, SQL_DRIVER_NOPROMPT)

            ;
    } while (FALSE);
    return 0;
}

