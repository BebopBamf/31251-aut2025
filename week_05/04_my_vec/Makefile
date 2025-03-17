CXX = clang++
CFLAGS = -std=c++20 -Wall -Wextra -Wpedantic -g
LDFLAGS = -fsanitize=address,undefined

.PHONY: clean

tests.out: tests.cpp my_vector.o
	$(CXX) $(CFLAGS) $(LDFLAGS) $(shell pkg-config --cflags --libs gtest gtest_main) -o $@ $^

my_vector.o: my_vector.cpp my_vector.hpp
	$(CXX) $(CFLAGS) $(LDFLAGS) -c $^

clean:
	rm -r *.dSYM *.o *.gch *.out
