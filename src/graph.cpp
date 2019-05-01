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

bool GraphArray::IsConnected (int vertice1, int vertice2) const{
	return array_[vertice1][vertice2] > 0;		
}



GraphList::GraphList(int size): size_(size){
	for (int i=0; i < size; i++) {
		graph_vertice_list_.push_back(new GraphVertice(i));
	}
}

void GraphList::AddEdge(int vertice1, int vertice2, int weight){
	if (vertice1 < size_ && vertice2 < size_) {
		
			
	}
}

bool GraphList::IsConnected(int vertice1, int vertice2) const{
	return true; 
}