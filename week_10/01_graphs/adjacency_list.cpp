#include "adjacency_list.hpp"

adjacency_list::adjacency_list(std::size_t N, bool type)
	: adj_list(std::vector<std::vector<vertex_t> >(N))
	, is_directed(type)
{
}

void adjacency_list::add_edge(vertex_t u, vertex_t v)
{
	if (0 > u && 0 > v && u >= adj_list.size() && v >= adj_list.size()) {
		std::cout << "ERROR: edges out of bounds\n";
		return;
	} else if (is_edge(u, v)) {
		std::cout << "ERROR: edges already in graph\n";
		return;
	}

	adj_list.at(u).push_back(v);
	if (is_directed) {
		adj_list.at(v).push_back(u);
	}
}

bool adjacency_list::is_edge(vertex_t u, vertex_t v)
{
	for (const auto x : adj_list.at(u)) {
		if (v == x) {
			return true;
		}
	}
	return false;
}
