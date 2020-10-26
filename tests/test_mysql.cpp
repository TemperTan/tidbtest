#include <iostream>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

int main(int argc, const char* argv[])
{
    sql::mysql::MySQL_Driver *driver;
    sql::Connection *con;

    driver = sql::mysql::get_mysql_driver_instance();
    con = driver->connect("tcp://127.0.0.1:4000", "root", "");
    sql::Statement *stmt = con->createStatement();
    sql::ResultSet *res  = stmt->executeQuery("show variables like 'version';");
    while (res->next()) 
    {
        std::cout << res->getString("Value") << std::endl;
    }
    delete con;
    
}