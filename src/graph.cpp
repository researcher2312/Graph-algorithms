#include "graph.h"

#include <iostream>

using namespace std;

GraphArray::GraphArray(int size): size_(size){
	array_ = new int* [size];
	for (int i = 0; i < size; i++) {
		array_[i] = new int [size]{0};
	}
}

bool GraphArray::AddEdge(int vertice1, int vertice2, int weight){
	if (vertice1 < size_ && vertice2 < size_) {
		array_[vertice1][vertice2] = weight;
		array_[vertice2][vertice1] = weight;
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

int GraphArray::IsConnected (int vertice1, int vertice2) const{
	return array_[vertice1][vertice2] > 0;		
}



GraphList::GraphList(int size): size_(size){
	for (int i=0; i < size; i++) {
		graph_vertice_list_.push_back(new GraphVertice(i));
	}
}

void GraphList::AddEdge(GraphVertice* vertice1, GraphVertice* vertice2, int weight){
	if (vertice1->GetNumber() < size_ && vertice2->GetNumber() < size_) {
		GraphEdge* new_edge = new GraphEdge(vertice1, vertice2, weight);
		graph_edge_list_.push_back(new_edge);
		vertice1->Connect(vertice2, new_edge);
		vertice2->Connect(vertice1, new_edge);			
	}
}

int GraphList::IsConnected(GraphVertice* vertice1, GraphVertice* vertice2) const{
	if(vertice1->IsConnected(vertice2)){

	}
	return 32;
}