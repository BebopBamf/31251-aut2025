CXX = clang++
CFLAGS = -std=c++20 -Wall -Wextra -Werror -Wpedantic -g -DDEBUG
#LDFLAGS = -fsanitize=address,undefined
LDFLAGS =

.PHONY: clean

all: tests.out

tests.out: main.cpp grid_graph.o
	$(CXX) $(CFLAGS) $(LDFLAGS) $(shell pkg-config --cflags --libs gtest) -o $@ $^

grid_graph.o: grid_graph.cpp grid_graph.hpp
	$(CXX) $(CFLAGS) $(LDFLAGS) -c $^

clean:
	rm -r *.dSYM *.o *.gch *.pch *.out
