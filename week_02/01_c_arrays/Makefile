CXX = clang++
CFLAGS = -std=c++20 -Wall -Wextra -g

.PHONY: clean

all: static_arr.out dynamic_arr.out dynamic_arr_plus.out

static_arr.out: static_arr.cpp
	$(CXX) $(CFLAGS) -o $@ $^

dynamic_arr.out: dynamic_arr.cpp
	$(CXX) $(CFLAGS) -o $@ $^

dynamic_arr_plus.out: dynamic_arr_plus.cpp
	$(CXX) $(CFLAGS) -o $@ $^

clean:
	rm -r *.dSYM *.o *.out
