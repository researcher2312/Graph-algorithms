#include "graph.h"

GraphArray::GraphArray(int size){
	array_ = new int* [size];
	for (int i = 0; i < size; i++) {
		array_[i] = new int [size]{0};
	}
}