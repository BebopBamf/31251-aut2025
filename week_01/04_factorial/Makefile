CFLAGS = -std=c++20 -Wall -Wextra -g

.PHONY: clean

all: factorial tests

factorial: main.cpp factorial.o
	clang++ $(CFLAGS) -isystem /opt/homebrew/include -L/opt/homebrew/lib -lgtest $^ -o $@

tests: tests.cpp factorial.o
	clang++ $(CFLAGS) -isystem /opt/homebrew/include -L/opt/homebrew/lib -lgtest -lgtest_main $^ -o $@

factorial.o: factorial.cpp
	clang++ $(CFLAGS) -c $^

clean:
	rm -r *.dSYM
	rm *.o factorial tests
