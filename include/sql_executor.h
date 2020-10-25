#pragma once
#include <string>
#include <list>
int exec_sql_list( const std::list<std::string *>& sqllist );
int sql_random_exec(const std::list<std::string*>& llist, std::list<std::string*>& rlist );
int sql_random_exec_itertor(std::list<std::string*>::const_iterator lbegin, std::list<std::string*>::const_iterator lend,
    std::list<std::string*>::const_iterator rbegin,std::list<std::string*>::const_iterator rend, 
    std::list<std::string*>& upresult );