#pragma once
#include <list>
#include <string>

int load_sql_from_file(const std::string path, std::list<std::string *>& sqls);