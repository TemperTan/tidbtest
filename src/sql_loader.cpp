#include <list>
#include <string>
#include <fstream>

int load_sql_from_file(const std::string path, std::list<std::string *> sqls)
{
    sqls.clear();

    std::ifstream sqlfile(path);
    if( !sqlfile )
    {
        return -1;
    } else
    {
        std::string sqlstr;
        while( std::getline(sqlfile,sqlstr) )
        {
            if( !sqlstr.empty() )
            {
                sqls.push_back(new std::string(sqlstr));
            }
        }
    }
    return 0;
}


