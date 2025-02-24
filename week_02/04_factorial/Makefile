CFLAGS = -std=c++20 -Wall -Wextra -g

.PHONY: clean

all: factorial tests

tests: tests.cpp factorial.o
	clang++ $(CFLAGS) -isystem /opt/homebrew/include -L/opt/homebrew/lib -lgtest -lgtest_main $^ -o $@

factorial: main.cpp factorial.o
	clang++ $(CFLAGS) -isystem /opt/homebrew/include -L/opt/homebrew/lib -lgtest $^ -o $@

factorial.o: factorial.cpp factorial.hpp
	clang++ $(CFLAGS) -c $^

clean:
	rm *.o *.gch factorial tests
	rm -r *.dSYM
