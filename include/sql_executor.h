#pragma once
#include <string>
#include <list>
int exec_sql_list( const std::list<std::string *>& sqllist1,  const std::list<std::string *>& sqllist2, const std::list<int>& arrange);
int sql_random_exec_creator(const std::list<std::string*>& llist, std::list<std::string*>& rlist , std::list<std::list<int>>& result );
int sql_random_exec_itertor_creator(std::list<std::string*>::const_iterator lbegin, std::list<std::string*>::const_iterator lend,
    std::list<std::string*>::const_iterator rbegin,std::list<std::string*>::const_iterator rend, 
    std::list<int>& upresult, std::list<std::list<int>>& result );