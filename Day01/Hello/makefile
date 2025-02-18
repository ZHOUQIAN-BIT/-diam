# 编译器
CXX = g++

# 目标可执行文件
TARGET = bin/hello

# 源代码文件：包括 main.cpp 和 phil 目录下的所有 .cpp 文件
SRC = main.cpp $(wildcard phil/*.cpp)

# 目标文件：将 .cpp 文件转为 .o 文件
OBJS = $(patsubst %.cpp, %.o, $(SRC))

# 编译器标志
CXXFLAGS = -Wall -g -Iphil  # -Iphil 用于指定 phil 目录为头文件的搜索路径

# 链接规则：从目标文件生成可执行文件
$(TARGET): $(OBJS)
	$(CXX) -o $(TARGET) $(OBJS)

# 编译 .cpp 文件为 .o 文件
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# 清理规则
clean:
	rm -f $(OBJS) 
