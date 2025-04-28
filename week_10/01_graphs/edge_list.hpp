#ifndef EDGE_LIST_HPP
#define EDGE_LIST_HPP

#include "graph.hpp"
#include <vector>

class edge_list : graph {
    private:
	std::vector<std::pair<int, int> > m_edge_list;

    public:
	edge_list(int N, bool type);

	void add_edge(int i, int j);

	void is_edge(int i, int j);

	void adjacent_to(int v);

	void display();

	void connected_components();
};

#endif // EDGE_LIST_HPP
