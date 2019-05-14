#include "list.h"
#include "graph.h"
#include "heap.h"
#include "dijkstra.h"
#include <sys/time.h>

#include <iostream>

using namespace std;

int main(){

	GraphType graph_types [] = {array_graph, list_graph};
	int sizes [] = {100, 200, 500, 1000, 2000};
	int fills [] = {25, 50, 75, 100};

	timeval t1, t2;
	double totalTime;
	double elapsedTime;

	for (GraphType current_graph: graph_types) {
		for (int current_fill: fills) {
			for (int currennt_size: sizes) {
				totalTime = 0;
				for (int i = 0; i < 100; i++){
					Graph* graph = GenerateGraph(currennt_size, current_fill, current_graph);
					gettimeofday(&t1, NULL);
					Dijkstra(graph, 90);
					gettimeofday(&t2, NULL);
					elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
					elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;   //us to ms
					totalTime += elapsedTime;
					delete graph;
				}
				cerr << current_graph << ' ' << current_fill << ' ' << currennt_size << ' ';
				cerr << elapsedTime/100 <<'\n';
			}
		}
	}
	return 0;
}
