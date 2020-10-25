
#include <string>
#include <list>

int exec_sql_list( const std::list<std::string *>& sqllist )
{
    for( std::list<std::string *>::const_iterator it = sqllist.cbegin(); it != sqllist.cend(); ++it)
    {

    }
}


int sql_random_exec_itertor(std::list<std::string*>::const_iterator lbegin, std::list<std::string*>::const_iterator lend,
    std::list<std::string*>::const_iterator rbegin,std::list<std::string*>::const_iterator rend, 
    std::list<std::string*>& upresult )
{
    if( lbegin == lend )
    {
        upresult.insert(upresult.end(),rbegin,rend);
        exec_sql_list(upresult);
    } else if ( rbegin == rend )
    {
        upresult.insert(upresult.end(),lbegin,lend);
        exec_sql_list(upresult);
    } else
    {
        upresult.push_back( *lbegin);
        sql_random_exec_itertor( ++lbegin, lend , rbegin, rend, upresult );
        upresult.pop_back();
        upresult.push_back( *rbegin);
        sql_random_exec_itertor( --lbegin, lend , ++rbegin, rend, upresult);
        upresult.pop_back();
    }
    return 0;
}

int sql_random_exec(const std::list<std::string*>& llist, std::list<std::string*>& rlist )
{
    std::list<std::string *> tmplist;
    return sql_random_exec_itertor( llist.cbegin(), llist.cend() , rlist.cbegin(), rlist.cend(), tmplist);
}