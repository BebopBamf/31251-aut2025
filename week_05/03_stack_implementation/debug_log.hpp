#ifndef DEBUG_LOG_HPP_
#define DEBUG_LOG_HPP_

// Macro for conditional debugging
#ifdef DEBUG
#include <iostream>
#define DEBUG_LOG(msg) (std::cout << (msg) << std::endl)
#define DEBUG_LOG_LIST(lst)                       \
	do {                                      \
		std::cout << #lst << ": ";        \
		for (const auto &item : (lst)) {  \
			std::cout << item << " "; \
		}                                 \
		std::cout << std::endl;           \
	} while (0)
#else
#define DEBUG_LOG(msg) ((void)0) // Expands to nothing in non-debug mode
#define DEBUG_LOG_LIST(lst) ((void)0) // Expands to nothing in non-debug mode
#endif

#endif // DEBUG_LOG_HPP_
