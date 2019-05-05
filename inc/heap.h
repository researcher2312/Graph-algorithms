#ifndef HEAP_H
#define HEAP_H

template <typename T>
class Heap {
public:
	Heap(T* heap):heap_(heap);
	T pop();

private:
	T* heap_;
}







#endif