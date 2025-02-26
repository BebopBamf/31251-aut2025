CXX = clang++
CFLAGS = -std=c++20 -Wall -Wextra -g

.PHONY: clean

tests.out: tests.cpp my_int.o
	$(CXX) $(CFLAGS) $(shell pkg-config --cflags --libs gtest gtest_main) -o $@ $^

my_int.o: my_int.cpp my_int.hpp
	$(CXX) $(CFLAGS) -c $^

clean:
	rm -r *.dSYM *.o *.gch *.out
