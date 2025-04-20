# Компилятор
CXX := g++
# Флаги компиляции
CXXFLAGS := -std=c++11 -Wall -Wextra -pedantic

# Имя исполняемого файла
TARGET := product_app

# Исходные файлы
SRCS := main.cpp menu.cpp rwFunc.cpp
# Объектные файлы
OBJS := $(SRCS:.cpp=.o)
# Заголовочные файлы
HEADERS := menu.hpp rwFunc.hpp

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

run: $(TARGET)
	./$(TARGET)