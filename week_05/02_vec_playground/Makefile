CXX = clang++
CFLAGS = -std=c++20 -Wall -Wextra -Wpedantic -g
LDFLAGS = -fsanitize=address,undefined

.PHONY: clean

playground.out: main.cpp
	$(CXX) $(CFLAGS) -o $@ $^

clean:
	rm -r *.dSYM *.o *.out
