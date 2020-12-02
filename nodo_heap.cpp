#include "nodo_heap.h"

nodo_heap::nodo_heap()
{
    //ctor
}
void nodo_heap::inserisci_peso(int p)
{
peso=p;
}
void nodo_heap::inserisci_vertice(int v){
vertice=v;
}
int nodo_heap::get_peso()
{
return this->peso;
}
int nodo_heap::get_vertice()
{
return this->vertice;
}
