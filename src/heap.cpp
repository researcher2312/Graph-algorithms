#include "heap.h"

template <typename T>
void heapDown (T *tab, int node, int size){
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
void heapsort(T* tab, int N){
  for(int i=N/2; i>0; i--)
    heapDown(tab, i, N);
  while(N > 1){
    swap(tab, 0, N-1);
    N--;
    heapDown(tab, 1, N);
  }
}
