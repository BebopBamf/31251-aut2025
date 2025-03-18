#include "two_sum.hpp"

std::pair<int, int> twoSum(const std::vector<int>& vec, int target) {
	std::unordered_map<int, std::size_t> vals{};

	for (std::size_t i = 0; i < vec.size(); i++) {
		if (vals.contains(target - vec.at(i))) {
			return {vals.at(target - vec.at(i)), i};
		}
		vals.insert({vec.at(i), i});
	}

	return {0, 0};
}
