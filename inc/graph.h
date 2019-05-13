#ifndef GRAPH_H
#define GRAPH_H

#include "list.h"
#include "graph_elements.h"

class Graph{
public:
	virtual ~Graph(){};	
	virtual bool AddEdge(int vertice1, int vertice2, int weight) = 0;
	virtual int IsConnected(GraphVertice& vertice1, GraphVertice& vertice2) const = 0;
	virtual void Write() const = 0;
	int size() const {return size_;}
	GraphVertice* graph_vertices;

protected:
	int size_;
	List<GraphEdge*> graph_edge_list_;
};

class GraphList: public Graph{
public:
	GraphList (int size);
	virtual bool AddEdge(int vertice1, int vertice2, int weight);
	virtual int IsConnected(GraphVertice& vertice1, GraphVertice& vertice2) const;
	//virtual void Write() const;

private:
	List<GraphEdge*> graph_edge_list_;
};

class GraphArray: public Graph{
public:
	GraphArray(int size);
	virtual bool AddEdge(int vertice1, int vertice2, int weight);
	virtual int IsConnected(GraphVertice& vertice1, GraphVertice& vertice2) const;
	virtual void Write() const;

private:
	int** array_;
};

#define GRAPH_H
#endif