#ifndef RPN_HPP_
#define RPN_HPP_

#include <vector>

struct Token {
	// 'n' for a number, or one of '+', '-', '*', '/' for operators
	char type{};

	// In the case of a number, val holds its integer value.
	// For operators val is not used and can remain 0.
	int val{};
};

int evalRPN(const std::vector<Token> &);

#endif // RPN_HPP_
