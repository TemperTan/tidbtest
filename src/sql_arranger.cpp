
#include <sql_arranger.h>
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
            upresult.pop_back();
            -- cout;
        }
    } else if ( rbegin == rend )
    {
        int cout = 0;
        while( lbegin != lend )
        {
            upresult.push_back(1);
            ++ lbegin ;
            ++ cout;
        }
        result.push_back(upresult);
        while( cout > 0)
        {
            upresult.pop_back();
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