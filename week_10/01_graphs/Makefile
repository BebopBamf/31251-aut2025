CXX = clang++
CFLAGS = -std=c++20 -Wall -Wextra -Werror -Wpedantic -g -DDEBUG
#LDFLAGS = -fsanitize=address,undefined
LDFLAGS = -fsanitize=address,undefined

.PHONY: clean

all: tests.out

tests.out: tests.cpp rpn.o
	$(CXX) $(CFLAGS) $(LDFLAGS) $(shell pkg-config --cflags --libs gtest) -o $@ $^

rpn.o: rpn.cpp rpn.hpp
	$(CXX) $(CFLAGS) $(LDFLAGS) -c $^

clean:
	rm -r *.dSYM *.o *.gch *.pch *.out
