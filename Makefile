CXX=g++
MYSQL_CONCPP_DIR= ...
CPPFLAGS = -I$(MYSQL_CONCPP_DIR)/include -L$(MYSQL_CONCPP_DIR)/lib64 -I./include
LDLIBS = -lmysqlcppconn8
CXXFLAGS = -std=c++11
app : src/main.cpp \
	src/sql_loader.cpp \
	src/sql_executor.cpp