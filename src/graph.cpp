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

bool GraphArray::IsConnected (int vertice1, int vertice2) {
	if(array_[vertice1][vertice2] > 0)
		return 1;
	else
		return 0;
}

GraphList::GraphList(int size): size_(size){
	list_ = new List<int>[size];
}

bool GraphList::AddEdge(int vertice1, int vertice2, int weight){
	if (vertice1 < size_ && vertice2 < size_) {
		list_[vertice1].push_back(vertice2);
		list_[vertice2].push_back(vertice1);
		return 1;
	}
	return 0;
}

bool GraphList::IsConnected(int vertice1, int vertice2){
	return list_[vertice1].contains(vertice2);
}