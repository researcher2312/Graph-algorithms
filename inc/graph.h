#ifndef GRAPH_H

class GraphArray{
public:
	GraphArray(int size);
	void AddEdge(int vertice1, int vertice2, int weight);

private:
	int** array_;
};

#define GRAPH_H
#endif