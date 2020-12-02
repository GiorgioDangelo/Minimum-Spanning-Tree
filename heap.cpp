#include "heap.h"

//*************************************************************************************
/*    ALLOCA VETTORE        */
heap::heap(int cap)
{
    heap_size = 0;
    capacity = cap;


    nodo=vector<nodo_heap*>(cap,0); //Alloco il vettore
}


//*************************************************************************************
/*    STAMPA CON HEAP_SIZE       */
void heap::printArray()
{

for (int i = 0; i <heap_size; ++i)

cout <<"HEAP in questo momento :"<< nodo[i]->get_vertice() <<" con peso :"<<nodo[i]->get_peso()<<endl;

}





//*************************************************************************************
/*    ESTRAI MINIMO       */
int heap::extractMin()
{
    if (heap_size <= 0)
	return 0;

    // Se c'è più di un elemento nell'heap scambio l'elemento estratto con l'ultimo e diminuisco il size di 1 e verifico
    //se il nuovo elemento nella radice verifichi la proprietà dell'heap
    int root = nodo[0]->get_vertice();

    nodo[0]= nodo[heap_size-1];

    heap_size--;

   //Una volta fatto lo scambio deve verificare che il nuovo elemento messo nella radice non violi le proprietà dell'heap
    MinHeapify(0);

    return root;

}


//*************************************************************************************
/*    RIPRISTINA LE PROPRIETA' DEL HEAP      */
void heap::MinHeapify(int i)
{

    int l = 2*i + 1;
    int r = 2*i + 2;
    int smallest=i;
  //Ordino l'heap in base ai pesi degli archi
    if (l < heap_size && nodo[l]->get_peso()< nodo[i]->get_peso())

        smallest = l;

    if (r < heap_size && nodo[r]->get_peso() < nodo[smallest]->get_peso())

        smallest = r;


    if (smallest != i)
    {
        swap(nodo[i], nodo[smallest]);
        MinHeapify(smallest);
    }
}
//*************************************************************************************
/*    Trova posizione      */
int heap::FindPosition(int node){

    int idx = 0;

    for (int i = 0; i <capacity; i++) {

        if ( nodo[i]>0 && nodo[i]->get_vertice() == node ) {

            idx = i;

             return idx;
        }

    }
    return -1;

    }



//*************************************************************************************
/*    INSERISCI VERTICE E PESO        */
void heap::insertKey(int vertice,int peso)
{
    if (heap_size == capacity)
    {
      cout<<"superata capacità"<<endl;
        return;
    }
    int indice_nodo = FindPosition(vertice);

    if(indice_nodo>=0 && peso < nodo[indice_nodo]->get_peso())
   {

      nodo[indice_nodo]->inserisci_peso(peso);

     int j=heap_size-1;

    BuildHeap(heap_size);
    }
    else
    {
    nodo_heap *nuovo=new nodo_heap();
    nuovo->inserisci_vertice(vertice);
    nuovo->inserisci_peso(peso);
         heap_size++;
int i = heap_size- 1;


    // Inserisci la chiave nella prima posizione libera dell'array quindi aumento in size di 1 e l'ho metto nell'ultimo elemento

    nodo[i]=nuovo;    //Inserimento nel vettore heap

    // Verifico se inserendo questo elemento è stata violata la proprietà dell'heap (Decrease Key)


    while (i != 0 && nodo[parent(i)]->get_peso() > nodo[i]->get_peso())
    {
    //cout<<"Scambia :"<<nodo[parent(i)]->get_vertice()<<" "<<nodo[i]->get_vertice()<<endl;
       swap(nodo[i], nodo[parent(i)]);
              i = parent(i);
    }



}
}
//*************************************************************************************
/*    BUILDHEAP        */

void heap::BuildHeap(int i)
{
int N=heap_size/2;
for (int i =N; i >= 0 ; i--) {
        MinHeapify(i);
    }
}
