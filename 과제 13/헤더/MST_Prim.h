#ifndef MST_PRIM_H
#define MST_PRIM_H

#include "Graph.h"
#include <fstream>

using namespace std;

typedef Graph::Vertex Vertex;					// Ŭ���� Vertex (Node)
typedef Graph::Edge Edge;						// Ŭ���� Edge (����)
typedef std::list<Graph::Vertex> VrtxList;		// Vertex List
typedef std::list<Graph::Edge> EdgeList;		// Edge List (�̾��� ��带 ǥ��)
typedef std::list<Graph::Vertex>::iterator VrtxItor;		// iterator 1
typedef std::list<Graph::Edge>::iterator EdgeItor;			// iterator 2

class MinimumSpanningTree
{

protected:
	Graph& graph;
	bool done;

protected:
	void initialize();		// initialize
	bool isValidID(int vID) { return graph.isValidvID(vID); }
	int getNumVertices() { return graph.NumVertices(); }

public:
	MinimumSpanningTree(Graph& g) : graph(g), done(false) {};

	void PrimJarnikMST();
	Graph& getGraph() { return graph; }
	double** DistMtrx() { return graph.DistMtrx(); }
};

#endif