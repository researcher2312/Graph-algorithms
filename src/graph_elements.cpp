#include "graph_elements.h"
#include <iostream>

GraphEdge::GraphEdge(GraphVertice* v1, GraphVertice* v2, int weight){
	weight_ = weight;
	incident_vertice_numbers[0] = v1->GetNumber();
	incident_vertice_numbers[1] = v2->GetNumber();
}

void GraphVertice::Connect(GraphVertice* new_vertice, GraphEdge* new_edge){
	incident_vertices.push_back(new_vertice);
	incident_edges.push_back(new_edge);
}

bool GraphEdge::Connects(GraphVertice* vertice1, GraphVertice* vertice2) const{
	int v1 = vertice1->GetNumber();
	int v2 = vertice2->GetNumber();

	if (incident_vertice_numbers[0] == v1 && incident_vertice_numbers[1] == v2){
		return 1;
	}
	if (incident_vertice_numbers[0] == v2 && incident_vertice_numbers[1] == v1){
		return 1;
	}
	return 0;
}

int GraphVertice::IsConnected(GraphVertice& other_vertice){
	if (incident_vertices.contains(&other_vertice)){
		for (auto edge = incident_edges.front(); edge != incident_edges.back(); edge++) {
			if (edge.item->Connects(this, &other_vertice)){
				return edge.item->GetWeight();
			}
		}
	}
	return 0;
}

GraphVertice::GraphVertice(){
	number_ = 0;
	distance_ = 10000000;
}

bool operator < (const GraphVertice& v1, const GraphVertice& v2){
	return v1.GetDistance() < v2.GetDistance();

}

bool operator >= (const GraphVertice& v1, const GraphVertice& v2){
	return v1.GetDistance() >= v2.GetDistance();

}
