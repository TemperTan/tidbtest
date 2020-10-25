#include <iostream>
#include <mysqlx/xdevapi.h>
using ::std::cout;
using ::std::endl;
using namespace ::mysqlx;
int main(int argc, const char* argv[])
{
    const char   *url = (argc > 1 ? argv[1] : "mysqlx://root@127.0.0.1");
    cout << "Creating session on " << url
        << " ..." << endl;
    Session sess(url);
    try {
        RowResult res = sess.sql("show variables like 'version'").execute();
        std::stringstream version;
        version << res.fetchOne().get(1).get<string>();
        cout <<version.str() <<endl;
    
    } catch( ...)
    {

    }
}