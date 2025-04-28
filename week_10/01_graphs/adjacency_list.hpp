#ifndef ADJACENCY_LIST_HPP
#define ADJACENCY_LIST_HPP

#include "graph.hpp"
#include <vector>

class adjacency_list : graph {
    private:
	std::vector<std::vector<int> > m_edge_list;

    public:
	adjacency_list(int N, bool type);

	void add_edge(int i, int j);

	void is_edge(int i, int j);

	void adjacent_to(int v);

	void display();

	void connected_components();
};

#endif // ADJACENCY_LIST_HPP
