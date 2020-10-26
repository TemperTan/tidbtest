#include "sql_loader.h"
#include "sql_executor.h"
#include "sql_arranger.h"
#include <iostream>
#include <mysql_driver.h>
#include <mysql_connection.h>

sql::Connection *con1;
sql::Connection *con2;


int main(int argc ,char *argv[])
{
    if( argc != 3)
    {
        std::cout << "Usage: " << argv[0] << "  filename1  filename2" << std::endl;
        return 255;
    }
    con1 = sql::mysql::get_mysql_driver_instance()->connect("tcp://127.0.0.1:4000", "root", "");
    con2 = sql::mysql::get_mysql_driver_instance()->connect("tcp://127.0.0.1:4000", "root", "");

    std::list<std::string*> sqllist1;
    std::list<std::string*> sqllist2;

    load_sql_from_file( argv[1], sqllist1);
    load_sql_from_file( argv[2], sqllist2);

    std::list<std::list<int>> arranges;
    sql_random_exec_creator(sqllist1, sqllist2, arranges);

    for ( std::list<std::list<int>>::const_iterator it = arranges.cbegin(); it != arranges.cend() ; ++it)
    {
        exec_sql_list( sqllist1, sqllist2, *it );
    }

    for( std::list<std::string*>::iterator it = sqllist1.begin(); it != sqllist1.end(); ++it )
    {
        delete *it;
    }
    sqllist1.clear();
    for( std::list<std::string*>::iterator it = sqllist2.begin(); it != sqllist2.end(); ++it )
    {
        delete *it;
    }
    sqllist1.clear();
    delete con1;
    delete con2;
    return 0;
}