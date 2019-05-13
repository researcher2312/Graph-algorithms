#ifndef HEAP_H
#define HEAP_H

template <typename T>
class Heap {
public:
	Heap(int maxsize);
	T pop();
	void push(const T&);
	void MakeOrder();
	bool Empty()const{return size_ == 0;}
	int Size()const{return size_;}

private:
	T* heap_;
	int maxsize_;
	int offset_=0;
	int size_ = 0;
	void HeapDown(T* tab, int node, int size);
	void Heapsort(T* tab, int size);
	void Swap(T* tab, int a, int b);
};

#endif