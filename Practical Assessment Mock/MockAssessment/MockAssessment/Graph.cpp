#include "Graph.h"
#include <fstream>
#include <iostream>
using namespace std;

Graph::Graph(string fname)
{
	ifstream fin(fname);
	if (!fin) {
		cout << "Cannot open: " << fname << endl;
		exit(1);
	}

	fin >> num_v;
	char c;
	fin >> c;
	if (c == 'd') directed = true;
	else if (c == 'u') directed = false;

	edges = new double*[num_v];
	if (directed) {
		for (int i = 0; i < num_v; i++) {
			edges[i] = new double[num_v];
			for (int j = 0; j < num_v; j++) edges[i][j] = 0.;
		}
	}
	else {
		for (int i = 0; i < num_v; i++) {
			edges[i] = new double[i + 1];
			for (int j = 0; j < i + 1; j++) edges[i][j] = 0.;
		}
	}

	int source, dest; double weight;
	while (fin >> source >> dest >> weight) {
		if (!directed && dest > source) edges[dest][source] = weight;
		else edges[source][dest] = weight;
	}
	fin.close();
}

Graph::~Graph()
{
	for (int i = 0; i < num_v; i++) delete [] edges[i];
	delete [] edges;
}

void Graph::get_max_weight_dest(int source)
{
	if (source < 0) exit(-1);
	int max_weight_dest = -1;
	double max_weight = 0.;
	for (int dest = 0; dest < num_v; dest++) {
		double weight = 0.;
		// In the case the graph is directed, the source will always 
		if(directed) weight = edges[source][dest];
		// 
		else weight = (source >= dest)?edges[source][dest]:edges[dest][source];
		// If the weight is greater than the current max weight,
		// set the new max_weight and the new max destination.
		if (weight > max_weight) {
			max_weight = weight;
			max_weight_dest = dest;
		}
	}
	cout << max_weight_dest << " is the max-weight destination from source " << source << endl;
	cout << "The weight is " << max_weight << endl;
}

