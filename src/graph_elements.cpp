#include "graph_elements.h"

GraphEdge::GraphEdge(int weight, GraphVertice* v1, GraphVertice* v2){
	weight_ = weight;
	incident_vertices[0] = v1;
	incident_vertices[1] = v2;
}