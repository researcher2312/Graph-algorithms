#ifndef GRAPH_ELEMENTS_H
#define GRAPH_ELEMENTS_H

#include "list.h"


class GraphVertice;
class GraphEdge;

class GraphEdge{
public:
	GraphEdge(GraphVertice* v1, GraphVertice* v2, int weight);
	bool Connects(GraphVertice* v1, GraphVertice* v2) const;
	int GetWeight() const {return weight_;}

private:
	int weight_;
	int incident_vertice_numbers [2];
};

class GraphVertice{
public:
	GraphVertice(int number): number_(number){};
	GraphVertice();
	void Connect(GraphVertice*, GraphEdge*);
	int GetNumber() const {return number_;}
	void SetNumber(int number){number_=number;}
	void SetDistance(int distance){distance_ = distance;}
	int GetDistance() const {return distance_;}
	int IsConnected(GraphVertice& other_vertice);
	List<GraphEdge*> incident_edges;
	List<GraphVertice*> incident_vertices;

private:
	int number_;
	int distance_;
};

bool operator < (const GraphVertice& v1, const GraphVertice& v2);
bool operator >= (const GraphVertice& v1, const GraphVertice& v2);

#endif