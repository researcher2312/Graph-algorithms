#ifndef GRAPH_H


class GraphArray{
public:
	GraphArray(int size);
	void AddEdge(int vertice1, int vertice2, int weight);
	void Write() const;

private:
	int size_;
	int** array_;
};

#define GRAPH_H
#endif