#include "dijkstra.h"

#include "graph_elements.h"
#include "list.h"
#include "heap.h"

#include <iostream>

void UpdateDistance(Graph* graph, GraphVertice& start_vertice){
	for (int i = 0; i < graph->size(); i++){
		int new_distance = graph->IsConnected(start_vertice, graph->graph_vertices[i]);
		if(new_distance > 0) {
			graph->graph_vertices[i].SetDistance(new_distance);
		}
	}
}

void Dijkstra(Graph* graph, int start_vertice_number){
	GraphVertice& start_vertice = graph->graph_vertices[start_vertice_number];
	Heap<GraphVertice> graph_vertice_heap(graph->size());
	start_vertice.SetDistance(0);
	int* before = new int [graph->size()];
	UpdateDistance(graph, start_vertice);
	for (int i = 0; i < graph->size(); i++) {
		graph_vertice_heap.push(&graph->graph_vertices[i]);
		before[i] = start_vertice_number;
	}
	graph_vertice_heap.MakeOrder();
	graph_vertice_heap.pop();
	while(!graph_vertice_heap.Empty()){
		GraphVertice* tested_vertice = graph_vertice_heap.pop();
		for (auto& vertice = tested_vertice->incident_vertices.front(); vertice != tested_vertice->incident_vertices.back(); vertice++) {
			if(vertice.item->GetDistance() > tested_vertice->GetDistance() + graph->IsConnected(*tested_vertice, *vertice.item)){
				vertice.item->SetDistance(tested_vertice->GetDistance() + graph->IsConnected(*tested_vertice, *vertice.item));
				before[vertice.item->GetNumber()] = tested_vertice->GetNumber();
			}
		}
		graph_vertice_heap.MakeOrder();
	}
	// for (int i = 0; i < graph->size(); i++){
	// 	std::cout << before[i] << ' ';
	// }
	// std::cout << '\n';
}
