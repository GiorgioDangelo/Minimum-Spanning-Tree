#ifndef VECTOR_ADIACENZE_H
#define VECTOR_ADIACENZE_H
#include<vector>
#include "Lista_di_adiacenza.h"
#include "heap.h"
#include <climits>
using namespace std;
class Vector_adiacenze
{


private:
int size_heap;
vector<int>key;
vector<bool>scoperto;
vector<int>parent;
vector<Lista_di_adiacenza*>grafo;


public:
    void inserisci_vertice(int vertice1 ,int vertice2,int peso);
    void inserisci_vertice_opposto(int vertice1 ,int vertice2,int peso);
    void stampa_lista(int indice_1);
    void prim(int sorgente);
    void stampa_risultato();
    Vector_adiacenze(int capacita);

};

#endif // VECTOR_ADIACENZE_H
