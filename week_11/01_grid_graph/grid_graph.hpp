#ifndef GRID_GRAPH_HPP_
#define GRID_GRAPH_HPP_

#include <utility>
#include <vector>
#include <unordered_set>
#include <unordered_map>

class GridGraph {
    private:
	// identify {x, y} grid point with integer x * numCols + y
	// this lets us use a vector instead of a map here
	std::vector<std::unordered_set<int> > adjList{};
	int numRows{};
	int numCols{};

    public:
	// create empty grid graph with m rows and n columns
	GridGraph(int m, int n);

	// return unordered_set of neighbours of a vertex
	std::unordered_set<int> neighbours(int) const;

	// add edges via grid points
	void addEdge(std::pair<int, int>, std::pair<int, int>);
	bool isEdge(std::pair<int, int>, std::pair<int, int>) const;

	int numVertices() const;

	// helper functions to convert between grid points and integers
	int pairToInt(const std::pair<int, int> &) const;
	std::pair<int, int> intToPair(int) const;

    private:
	// internally it is easier to work with integers rather than grid points
	void addEdge(int, int);
	bool isEdge(int, int) const;
};

class DirectedCycle {
	// visited[v] is true if dfsVisit(v) has already been called
	std::vector<bool> visited{};
	// onStack[v] true while dfsVisit(v) is running
	std::vector<bool> onStack{};
	// hold names of grid points on cycle if we find one
	std::vector<std::pair<int, int> > cycle{};
	// record which edge we took to arrive at vertex in dfs
	std::unordered_map<int, int> arrivedFrom{};

    public:
	// Default constructor does not need to do anything
	DirectedCycle();
	// containsCycle returns a boolean if there is a cycle or not.
	// if a cycle is found it is stored in cycle private member variable
	bool containsCycle(const GridGraph &G);
	// getter for the cycle private member variable
	std::vector<std::pair<int, int> > getCycle() const;

    private:
	// helper function for dfs
	bool dfsVisit(int, const GridGraph &G);
	// helper function to help reconstruct the cycle
	std::vector<std::pair<int, int> > createCycle(int, int,
						      const GridGraph &G) const;
};

#endif // GRID_GRAPH_HPP_
