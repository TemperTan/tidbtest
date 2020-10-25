
#include "sql_executor.h"
#include <mysqlx/xdevapi.h>
#include <iostream>

extern mysqlx::Session *gDbSession1;
extern mysqlx::Session *gDbSession2;

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
                mysqlx::RowResult res = gDbSession1->sql(**listIt1).execute();
                ++listIt1;
            } catch( ...)
            {
                std::cerr << "error catched " << std::endl;
            }
        } else if( *it == 2 && listIt2 != listendIt2)
        {
            try {
                mysqlx::RowResult res = gDbSession2->sql(**listIt2).execute();
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


int sql_random_exec_itertor_creator(std::list<std::string*>::const_iterator lbegin, std::list<std::string*>::const_iterator lend,
    std::list<std::string*>::const_iterator rbegin,std::list<std::string*>::const_iterator rend, 
    std::list<int>& upresult, std::list<std::list<int>>& result )
{
    if( lbegin == lend )
    {
        int cout = 0;
        while( rbegin != rend )
        {
            upresult.push_back(2);
            ++ rbegin ;
            ++ cout;
        }
        result.push_back(upresult);
        while( cout > 0)
        {
            result.pop_back();
            -- cout;
        }
    } else if ( rbegin == rend )
    {
        int cout = 0;
        while( lbegin != lend )
        {
            upresult.push_back(2);
            ++ lbegin ;
            ++ cout;
        }
        result.push_back(upresult);
        while( cout > 0)
        {
            result.pop_back();
            -- cout;
        }
    } else
    {
        upresult.push_back( 1 );
        sql_random_exec_itertor_creator( ++lbegin, lend , rbegin, rend, upresult, result );
        upresult.pop_back();
        upresult.push_back(2);
        sql_random_exec_itertor_creator( --lbegin, lend , ++rbegin, rend, upresult, result);
        upresult.pop_back();
    }
    return 0;
}

int sql_random_exec_creator(const std::list<std::string*>& llist, std::list<std::string*>& rlist , std::list<std::list<int>>& result )
{
    std::list<int> tmplist;
    return sql_random_exec_itertor_creator( llist.cbegin(), llist.cend() , rlist.cbegin(), rlist.cend(), tmplist, result);
}
