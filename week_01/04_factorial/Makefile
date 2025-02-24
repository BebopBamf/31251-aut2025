CXX = clang++
CFLAGS = -std=c++20 -Wall -Wextra -g

.PHONY: clean

all: factorial tests

factorial: main.cpp factorial.o
	$(CXX) $(CFLAGS) $(shell pkg-config --cflags --libs gtest) -o $@ $^

tests: tests.cpp factorial.o
	$(CXX) $(CFLAGS) $(shell pkg-config --cflags --libs gtest) -o $@ $^

factorial.o: factorial.cpp
	$(CXX) $(CFLAGS) -c $^

clean:
	rm -r *.dSYM
	rm *.o factorial tests
