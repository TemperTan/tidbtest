#pragma once
#include <string>
#include <list>

int sql_random_exec_creator(const std::list<std::string*>& llist, std::list<std::string*>& rlist , std::list<std::list<int>>& result );
int sql_random_exec_itertor_creator(std::list<std::string*>::const_iterator lbegin, std::list<std::string*>::const_iterator lend,
    std::list<std::string*>::const_iterator rbegin,std::list<std::string*>::const_iterator rend, 
    std::list<int>& upresult, std::list<std::list<int>>& result );