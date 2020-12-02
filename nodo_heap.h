#ifndef NODO_HEAP_H
#define NODO_HEAP_H


class nodo_heap
{



    private:
    int peso;
    int vertice;

    public:
    nodo_heap();
    void inserisci_peso(int p);
    void inserisci_vertice(int v);
    int get_peso();
    int get_vertice();



};

#endif // NODO_HEAP_H
