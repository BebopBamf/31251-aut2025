CXX = clang++
CFLAGS = -std=c++20 -Wall -Wextra -Wpedantic -g -DDEBUG
LDFLAGS = -fsanitize=address,undefined

.PHONY: clean

all: tests.out

tests.out: main.cpp myStack.o
	$(CXX) $(CFLAGS) $(LDFLAGS) $(shell pkg-config --cflags --libs gtest) -o $@ $^

myStack.o: myStack.cpp myStack.hpp debug_log.hpp
	$(CXX) $(CFLAGS) $(LDFLAGS) -c $^

clean:
	rm -r *.dSYM *.o *.gch *.out
