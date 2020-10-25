#include "sql_loader.h"
#include "sql_executor.h"
#include <iostream>

int print_sql_list( const std::list<std::string *>& sqllist1,  const std::list<std::string *>& sqllist2, const std::list<int>& arrange)
{
    std::list<std::string *>::const_iterator listIt1 = sqllist1.cbegin();
    std::list<std::string *>::const_iterator listendIt1 = sqllist1.cend();
    std::list<std::string *>::const_iterator listIt2 = sqllist2.cbegin();
    std::list<std::string *>::const_iterator listendIt2 = sqllist2.cend();
    for(std::list<int>::const_iterator it = arrange.cbegin(); it != arrange.cend(); ++it)
    {
        if( *it == 1 && listIt1 != listendIt1)
        {
            std::cout << "exec sql:" << *listIt1 << std::endl;
        } else if( *it == 2 && listIt2 != listendIt2)
        {
            std::cout << "exec sql:" << *listIt2 << std::endl;
        } else
        {
            std::cerr << "unsupport type" << std::endl;
        }
        
    }
    return 0;
}

int main(int argc,char *argv[])
{
    std::list<std::string*> sqllist1;
    std::list<std::string*> sqllist2;

    load_sql_from_file( argv[1], sqllist1);
    load_sql_from_file( argv[2], sqllist2);

    std::list<std::list<int>> arranges;
    sql_random_exec_creator(sqllist1, sqllist2, arranges);

    for ( std::list<std::list<int>>::const_iterator it = arranges.cbegin(); it != arranges.cend() ; ++it)
    {
        print_sql_list( sqllist1, sqllist2, *it );
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
    return 0;
}