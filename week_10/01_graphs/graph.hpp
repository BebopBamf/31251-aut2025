#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>

using vertex_t = int;

class graph {
    public:
	void add_edge(vertex_t u, vertex_t v);

	bool is_edge(vertex_t u, vertex_t v);

	void adjacent_to(vertex_t v);

	void display();
};

#endif // GRAPH_HPP
