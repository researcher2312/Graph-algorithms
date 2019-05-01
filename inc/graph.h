#ifndef GRAPH_H
#define GRAPH_H

#include "list.h"
#include "graph_elements.h"

class GraphList{
public:
	GraphList (int size);
	void AddEdge(int vertice1, int vertice2, int weight);
	void Write() const;
	bool IsConnected(int vertice1, int vertice2);

private:
	int size_;
	GraphVertice* graph_vertice_list_;
	List<GraphEdge*> graph_edge_list_;
};

class GraphArray{
public:
	GraphArray(int size);
	bool AddEdge(int vertice1, int vertice2, int weight);
	void Write() const;
	bool IsConnected(int vertice1, int vertice2);

private:
	int size_;
	int** array_;
};

#define GRAPH_H
#endif