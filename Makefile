CXX=g++
MYSQL_CONCPP_DIR= .
CPPFLAGS = -I$(MYSQL_CONCPP_DIR)/include  -I./include -D_GLIBCXX_USE_CXX11_ABI=0
LDLIBS = -L$(MYSQL_CONCPP_DIR)/lib -lmysqlcppconn
CXXFLAGS = -std=c++11

TARGET=bin/maintest
TARGET_SQL=bin/sqltest
TARGET_RAN=bin/rantest

SRC= src/main.cpp \
	src/sql_loader.cpp \
	src/sql_executor.cpp \
	src/sql_arranger.cpp

SQL_SRC= tests/test_mysql.cpp

RAN_SRC= tests/test_sql_rand.cpp \
	src/sql_loader.cpp \
	src/sql_arranger.cpp


OBJS=$(SRC:%.cpp=%.o)

SQL_OBJS=$(SQL_SRC:%.cpp=%.o)

RAN_OBJS=$(RAN_SRC:%.cpp=%.o)

%.o: %.cpp
	@echo --------------- Compiling $< ...
	$(CXX) $(CPPFLAGS) -o $@ -c $<

all: $(TARGET)

tests:$(TARGET_SQL) $(TARGET_RAN)

$(TARGET): $(OBJS)
	$(CXX) -o $(TARGET)  $(CPPFLAGS) $(CXXFLAGS) $(OBJS) $(LDLIBS)

$(TARGET_SQL): $(SQL_OBJS)
	$(CXX) -o $(TARGET_SQL)  $(CPPFLAGS) $(CXXFLAGS) $(SQL_OBJS) $(LDLIBS)

$(TARGET_RAN): $(RAN_OBJS)
	$(CXX) -o $(TARGET_RAN) $(CXXFLAGS) $(RAN_OBJS)

clean:
	rm -rf $(TARGET)
	rm -rf src/*.o
	rm -rf tests/*.o
