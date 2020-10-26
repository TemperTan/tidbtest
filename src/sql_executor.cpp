
#include "sql_executor.h"
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <iostream>

extern sql::Connection *con1;
extern sql::Connection *con2;

int exec_sql_list( const std::list<std::string *>& sqllist1,  const std::list<std::string *>& sqllist2, const std::list<int>& arrange)
{
    std::list<std::string *>::const_iterator listIt1 = sqllist1.cbegin();
    std::list<std::string *>::const_iterator listendIt1 = sqllist1.cend();
    std::list<std::string *>::const_iterator listIt2 = sqllist2.cbegin();
    std::list<std::string *>::const_iterator listendIt2 = sqllist2.cend();
    for(std::list<int>::const_iterator it = arrange.cbegin(); it != arrange.cend(); ++it)
    {
        if( *it == 1 && listIt1 != listendIt1)
        {
            try {
                sql::Statement *stmt = con1->createStatement();
                stmt->execute(**listIt1);
                delete stmt;
                ++listIt1;
            } catch( ...)
            {
                std::cerr << "error catched " << std::endl;
            }
        } else if( *it == 2 && listIt2 != listendIt2)
        {
            try {
                sql::Statement *stmt = con2->createStatement();
                stmt->execute((**listIt2));
                delete stmt;
                ++listIt2;
            } catch( ...)
            {
                std::cerr << "error catched " << std::endl;
            }
        } else
        {
            std::cerr << "unsupport type" << std::endl;
        }
        
    }
    return 0;
}



