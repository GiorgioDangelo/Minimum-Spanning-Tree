#ifndef HEAP_H
#define HEAP_H
#include <vector>
#include <iostream>
#include<climits>
#include "nodo_heap.h"
using namespace std;

class heap
{


private:
    int capacity; // capacità massima del mini heap
    int heap_size; // Numero correnti di nodi all'interno del vector



public:
        vector<nodo_heap*>nodo;  //nodi Heap
    heap(int capacity); //Inserisco il size dell'heap
    void MinHeapify(int i);  //Ripristina l'heapify se violata la proprietà
    int parent(int i) { return ((i-1)/2); }
   int FindPosition(int node);
    int extractMin(); //estraggo il minimo
    void insertKey(int vertice,int peso);
    void printArray(); //Stampo l'heap in quel momento
   void BuildHeap(int i);

};

#endif // HEAP_H
