#include "graph.h"

#include <iostream>

using namespace std;

GraphArray::GraphArray(int size){
	size_ = size;
	array_ = new int* [size];
	for (int i = 0; i < size; i++) {
		array_[i] = new int [size]{0};
	}
	graph_vertices = new GraphVertice[size_];
	for (int i = 0; i < size_; i++) {
		graph_vertices[i].SetNumber(i);
	}
}

bool GraphArray::AddEdge(int vertice1, int vertice2, int weight){
	if (vertice1 < size_ && vertice2 < size_) {
		array_[vertice1][vertice2] = weight;
		array_[vertice2][vertice1] = weight;
		graph_vertices[vertice1].incident_vertices.push_back(&graph_vertices[vertice2]);
		graph_vertices[vertice2].incident_vertices.push_back(&graph_vertices[vertice1]);
		return 1;
	}
	return 0;
}

void GraphArray::Write() const{
	for (int i = 0; i < size_; i++){
		for (int j = 0; j < size_; j++){
			cout << array_[i][j] << ' ';
		}
		cout << '\n';
	}
}

int GraphArray::IsConnected (GraphVertice& vertice1, GraphVertice& vertice2) const{
	return array_[vertice1.GetNumber()][vertice2.GetNumber()];		
}



GraphList::GraphList(int size){
	size_ = size;
	graph_vertices = new GraphVertice[size_];
	for (int i = 0; i < size_; i++) {
		graph_vertices[i].SetNumber(i);
	}
}

bool GraphList::AddEdge(int vertice1, int vertice2, int weight){
	if (vertice1 < size_ && vertice2 < size_) {
		GraphEdge* new_edge = new GraphEdge(&graph_vertices[vertice1], &graph_vertices[vertice2], weight);
		graph_edge_list_.push_back(new_edge);
		graph_vertices[vertice1].Connect(&graph_vertices[vertice2], new_edge);
		graph_vertices[vertice2].Connect(&graph_vertices[vertice1], new_edge);
		return 1;		
	}
	return 0;
}

int GraphList::IsConnected(GraphVertice& vertice1, GraphVertice& vertice2) const{
	if(vertice1.IsConnected(vertice2)){

	}
	return 32;
}