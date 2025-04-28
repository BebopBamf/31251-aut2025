#ifndef GRAPH_HPP
#define GRAPH_HPP

class graph {
    public:
	void add_edge(int i, int j);

	void is_edge(int i, int j);

	void adjacent_to(int v);

	void display();
};

#endif // GRAPH_HPP
