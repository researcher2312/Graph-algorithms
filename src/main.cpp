#include "list.h"
#include "graph.h"
#include "heap.h"
#include "dijkstra.h"

#include <iostream>

using namespace std;

int main(){
	// GraphVertice v0 (0);
	// v0.SetDistance(17);
	// GraphVertice v1 (1);
	// v1.SetDistance(13);
	// Heap<GraphVertice> heap(5);
	// heap.push(v0);
	// heap.push(v1);
	// heap.MakeOrder();
	// GraphVertice nv = heap.pop();
	// cout << nv.GetDistance();
	// nv = heap.pop();
	// cout << nv.GetDistance();
	GraphArray graph (5);
	graph.AddEdge(0,3,19);
	graph.AddEdge(0,4,6);
	graph.AddEdge(1,3,7);
	graph.AddEdge(1,4,2);
	graph.AddEdge(2,4,6);
	graph.AddEdge(2,3,4);
	graph.AddEdge(3,4,5);
	Dijkstra(&graph, 2);
	graph.Write();
	return 0;
}
