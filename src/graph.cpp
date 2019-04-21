#include "graph.h"

#include <iostream>

using namespace std;

GraphArray::GraphArray(int size): size_(size){
	array_ = new int* [size];
	for (int i = 0; i < size; i++) {
		array_[i] = new int [size]{0};
	}
}

void GraphArray::AddEdge(int vertice1, int vertice2, int weight){
	array_[vertice1][vertice2] = weight;
	array_[vertice2][vertice1] = weight;
}

void GraphArray::Write() const{
	for (int i = 0; i < size_; i++){
		for (int j = 0; j < size_; j++){
			cout << array_[i][j] << ' ';
		}
		cout << '\n';
	}
}