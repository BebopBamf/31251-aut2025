#include "rpn.hpp"
#include <vector>

int evalRPN(const std::vector<Token> &tokens)
{
	auto stack = std::vector<int>();
	stack.push_back(0);

	for (const auto &token : tokens) {
		if (token.type == 'n') {
			stack.push_back(token.val);
		} else {
			auto y = stack.back();
			stack.pop_back();
			auto x = stack.back();
			stack.pop_back();

			switch (token.type) {
			case '+':
				stack.push_back(x + y);
				break;
			case '-':
				stack.push_back(x - y);
				break;
			case '*':
				stack.push_back(x * y);
				break;
			case '/':
				stack.push_back(x / y);
				break;
			}
		}
	}

	return stack.back();
}
