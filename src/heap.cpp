#include "heap.h"

#include "graph_elements.h"

template <typename T>
Heap<T>::Heap(int maxsize): maxsize_(maxsize) {
  heap_ = new T[maxsize_];
}

template <typename T>
void Heap<T>::push(const T& new_item){
  if (size_ < maxsize_);
  heap_[size_] = new_item;
  ++size_;
}

template <typename T>
void Heap<T>::MakeOrder(){
  Heapsort(heap_ + offset_, size_);
}


template <typename T>
T Heap<T>::pop(){
  if(size_ > 0){
    T temp = heap_[offset_];
    offset_++;
    size_ --;
    Heapsort(heap_ + offset_, size_);
    return temp;   
  }
  else
    return 0;
}

template <typename T>
void Heap<T>::HeapDown (T *tab, int node, int size){
  T nodeValue = tab[node-1];
  while(node <= size/2){
    int nextNode = 2*node;
    if(nextNode < size && tab[nextNode-1] < tab[nextNode])
      nextNode++;
    if(nodeValue >= tab[nextNode-1])
      break;
    tab[node-1]=tab[nextNode-1];
    node=nextNode;
  }
  tab[node-1]=nodeValue;
}

/*Heap sort used in Introspective sort*/
template <typename T>
void Heap<T>::Heapsort(T* tab, int size){
  for(int i=size/2; i>0; i--)
    HeapDown(tab, i, size);
  while(size > 1){
    Swap(tab, 0, size-1);
    size--;
    HeapDown(tab, 1, size);
  }
}

template <typename T>
void Heap<T>::Swap(T* tab, int a, int b){
  T temp = tab[a];
  tab[a] = tab[b];
  tab[b] = temp;
}
template class Heap<int>;
template class Heap<GraphVertice>;
