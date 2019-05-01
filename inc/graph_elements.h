#ifndef GRAPH_ELEMENTS_H
#define GRAPH_ELEMENTS_H

#include "list.h"

class GraphVertice;
class GraphEdge;

class GraphEdge{
public:
	GraphEdge(GraphVertice* v1, GraphVertice* v2, int weight);
private:
	int weight_;
	GraphVertice* incident_vertices [2];
};

class GraphVertice{
public:
	GraphVertice(int number): number_(number){};
	void Connect(GraphVertice*, GraphEdge*);
	int GetNumber() const {return number_;}
private:
	int number_;
	List<GraphEdge*> incident_edges;
	List<GraphVertice*> incident_vertices;
};

#endif