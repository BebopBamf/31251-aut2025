#ifndef ADJACENCY_LIST_HPP
#define ADJACENCY_LIST_HPP

#include "graph.hpp"
#include <vector>

class adjacency_list : graph {
    private:
	std::vector<std::vector<vertex_t> > adj_list;
	bool is_directed;

    public:
	adjacency_list(std::size_t N, bool directed);

	void add_edge(vertex_t u, vertex_t v);

	bool is_edge(vertex_t u, vertex_t v);

	void adjacent_to(vertex_t v);

	void display();

	void connected_components();
};

#endif // ADJACENCY_LIST_HPP
