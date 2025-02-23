CXX = clang++
CFLAGS = -std=c++20 -Wall -Wextra -g

.PHONY: clean

all: factorial tests

factorial: main.cpp factorial.o
	$(CXX) $(CFLAGS) $(shell pkg-config --cflags gtest) $(shell pkg-config --libs gtest) -o $@ $^

tests: tests.cpp factorial.o
	$(CXX) $(CFLAGS) $(shell pkg-config --cflags gtest) $(shell pkg-config --libs gtest gtest_main) -o $@ $^

factorial.o: factorial.cpp
	$(CXX) $(CFLAGS) -c $^

clean:
	rm -r *.dSYM
	rm *.o factorial tests
