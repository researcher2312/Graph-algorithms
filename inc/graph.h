#ifndef GRAPH_H


class GraphArray{
public:
	GraphArray(int size);
	bool AddEdge(int vertice1, int vertice2, int weight);
	void Write() const;
	bool IsConnected(int vertice1, int vertice2);

private:
	int size_;
	int** array_;
};

#define GRAPH_H
#endif