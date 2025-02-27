CXX = clang++
CFLAGS = -std=c++20 -Wall -Wextra -Wpedantic -g
LDFLAGS = -fsanitize=address,undefined

.PHONY: clean

tests.out: tests.cpp array_product.o
	$(CXX) $(CFLAGS) $(shell pkg-config --cflags --libs gtest gtest_main) -o $@ $^

array_product.o: array_product.cpp array_product.hpp
	$(CXX) $(CFLAGS) -c $^

clean:
	rm -r *.dSYM *.o *.gch *.out
