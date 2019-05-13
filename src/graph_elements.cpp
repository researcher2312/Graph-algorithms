#include "graph_elements.h"

GraphEdge::GraphEdge(GraphVertice* v1, GraphVertice* v2, int weight){
	weight_ = weight;
	incident_vertices[0] = v1;
	incident_vertices[1] = v2;
}

void GraphVertice::Connect(GraphVertice* new_vertice, GraphEdge* new_edge){
	incident_vertices.push_back(new_vertice);
	incident_edges.push_back(new_edge);
}

int GraphVertice::IsConnected(GraphVertice& other_vertice){
	if (incident_vertices.contains(&other_vertice)){
		
	}
	return 63;
}

GraphVertice::GraphVertice(){
	number_ = 0;
	distance_ = 10000;
}

bool operator < (const GraphVertice& v1, const GraphVertice& v2){
	return v1.GetDistance() < v2.GetDistance();

}

bool operator >= (const GraphVertice& v1, const GraphVertice& v2){
	return v1.GetDistance() >= v2.GetDistance();

}
