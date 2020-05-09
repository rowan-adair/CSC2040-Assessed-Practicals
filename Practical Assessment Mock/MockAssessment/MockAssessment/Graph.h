#ifndef GRAPH_H
#define GRAPH_H
#include <string>
using std::string;

class Graph
{
public:
	// Constructor - create a graph from a file with the given name
	Graph(string fname);
	// Destructor
	~Graph();

	// Part 2 Graphs
	// (2). The new member function
	void get_max_weight_dest(int source);

private:
	// The graph
	int num_v;			// Number of vertices
	bool directed;	// Direction
	double** edges;	// The 2-D adjaceny matrix
};
#endif
