#include "Vector_adiacenze.h"
#include "Lista_di_adiacenza.h"
#include <iostream>


using namespace std;
//*************************************************************************************
/*  Costruttore        */
Vector_adiacenze::Vector_adiacenze(int cap)
{
size_heap=cap;
key=vector<int>(cap,0);
scoperto=vector<bool>(cap,false);
parent=vector<int>(cap,-1);
grafo=vector<Lista_di_adiacenza*>(cap+1,nullptr);

}
//*************************************************************************************
/*   stampa risultato        */
void Vector_adiacenze::stampa_risultato()
{
     int tot=0;

    cout<<""<<endl;
    cout<<"PONTI RICOSTRUITI"<<endl;
    for(int i=1;i<size_heap;i++)   //Poichè il vertice 0 nn lo voglio parto da 1
    {
    if(key[i]==INT_MAX)
    {
    cout<<i<<" non ricostruito"<<endl;
  // cout<<""<<endl;
    }
    //Stampo solo i ponti con peso maggiore di 0
    else if(key[i]>=0 &&parent[i]>-1)
    {
     tot+=key[i];
       cout<<"Strada "<<i<< "-" <<parent[i]<< " peso "<<key[i]<<endl;
    }
    }

     cout<<" "<<endl;
    cout<<"="<<endl;
    cout<<"Costo totale "<<tot<<endl;


}

//*************************************************************************************
/*    INSERISCI VERTICE         */
void Vector_adiacenze::inserisci_vertice(int vertice1 ,int vertice2,int peso)
{
//cout<<vertice1<<"-"<< vertice2<< " peso :"<< peso<<endl;
//Creo un nuovo nodo ogni volta che sto inserendo l'elemento
Lista_di_adiacenza *nuovo_link=new Lista_di_adiacenza();

nuovo_link->inserisci_next(nullptr);
//Controllo,se il grafo è vuoto allora inserisco l'indirizzo dell'oggetto di vertice ad esempio 1 nella posizione 1 del grafo
if(grafo[vertice1]==nullptr){
nuovo_link->inserisci_isola1(vertice1);//Isola 1
nuovo_link->inserisci_isola2(vertice2);//Isola 2

nuovo_link->inserisci_arco(peso); //Arco tra le due isole
grafo[vertice1]=nuovo_link; //Assegno nell'indice di quel vertice ,l'oggetto

 }

 //Se invece quella posizione del grafo già è occupata,allora mi scorro la lista fino alla fine e inserisco l'elemento nella coda
 else

   {

    Lista_di_adiacenza *temp;

    temp=grafo[vertice1];

    while(temp->ritorna_next()!=nullptr)
    {

    temp=temp->ritorna_next();   //scorri la lista finchè non trovi il null

    }

   nuovo_link->inserisci_isola1(vertice1); //isola1
   nuovo_link->inserisci_isola2(vertice2);  //isola2
   nuovo_link->inserisci_arco(peso); //arco tra le due isole

   temp->inserisci_next(nuovo_link); //inserisci il nuovo elemento nell'ultima posizione
}


}




//*************************************************************************************
/*     ALTRO VERSO DEL GRAFO           */



void Vector_adiacenze::inserisci_vertice_opposto(int vertice1 ,int vertice2,int peso)
{

//Poichè il grafo è non orientato significa che la lista di adiacenza è in entrambi i sensi dei vertici
//Quindi in questo caso mi creo la lista di adiacenza dal secondo vertice al primo
Lista_di_adiacenza *nuovo_link=new Lista_di_adiacenza();

nuovo_link->inserisci_next(nullptr);

//Controllo se non c'è nulla in quell'indice e inserisco
if(grafo[vertice2]==nullptr){
nuovo_link->inserisci_isola1(vertice2);  //isola2
nuovo_link->inserisci_isola2(vertice1);//isola1

nuovo_link->inserisci_arco(peso);//arco tra le due isole
grafo[vertice2]=nuovo_link;

 }
 //se c'è qualcosa,sempre lo stesso procedimento inserirò il nuovo elemento alla fine della lista
 else

   {

    Lista_di_adiacenza *temp;

    temp=grafo[vertice2];

    while(temp->ritorna_next()!=nullptr)
    {

    temp=temp->ritorna_next();   //scorri la lista finchè non trovi il null

    }


   nuovo_link->inserisci_isola1(vertice2);
    nuovo_link->inserisci_isola2(vertice1);
   nuovo_link->inserisci_arco(peso);
temp->inserisci_next(nuovo_link); //inserisci il nuovo elemento nell'ultima posizione
}


}



//*************************************************************************************
/*     STAMPA LISTA             */
void Vector_adiacenze::stampa_lista(int indice_1)
{

    if (grafo[indice_1]==nullptr)
    {
    cout<<"La lista e' vuota "<<endl;
    }
 else{
   Lista_di_adiacenza *temp;
   temp=grafo[indice_1];
    while(temp!=nullptr)
{
    //Stampo i vertici adiacenti di un nodo
   cout<<"Vertice "<<temp->get_vertice1()<<"-"<<temp->get_vertice2()<< " arco :" <<temp->get_peso()<<endl;

   temp=temp->ritorna_next();

}

 }
}


//*************************************************************************************
/*   PRIM          */

//Vuole in input un vertice sorgente da cui iniziare la procedura
void Vector_adiacenze::prim(int sorgente)
{

heap *nuovo_heap=new heap(size_heap);


//Metto come infinito tutti gli elementi che esistono nell'indice del grafo
for(int j=0;j<size_heap;j++)
{
if (grafo[j]!=NULL){
    key[j]=INT_MAX;
}
}
//Se il vertice sorgente che ho inserito non esiste esco
if(grafo[sorgente]==nullptr)
{
cout<<"Questo vertice non esiste"<<endl;
exit(0);
}

//Inizializzo
parent[sorgente]=sorgente; //Parto dal vertice sorgente
key[sorgente]=0; //Inizializzo il peso a 0

nuovo_heap->insertKey(parent[sorgente],key[sorgente]); //Insert(vertice,peso) inserisc quindi il vertice sorgente con peso 0 poichè in realtà non è un arco


while(!nuovo_heap->nodo.empty())
{
     /* LEGGI ELEMENTI PRESENTI NELL'HEAP*/
  //nuovo_heap->printArray();  // elementi contenuti nell'heap

//Estraggo il minimo e setto il suo valore nel vector booleano a true in quanto è stato scoperto

    int u=nuovo_heap->extractMin();

    if(u==0)
    {
       return;
    }
else{
scoperto[u]=true;
}
     /* LEGGI MINIMO*/
  // cout<<"minimo estratto :"<<u<<endl;
//Vado a scorrere la lista di adiacenza del minimo estratto per vedere chi sono i vertici adiacenti
    while(grafo[u]!=nullptr)
    {

//int primo=grafo[u]->get_vertice1();
int v=grafo[u]->get_vertice2();//Quindi in v avrò i vertici adiacenti

//Nel peso ,il peso dell'arco tra le due isole

int peso=grafo[u]->get_peso();

 /* LEGGI VETTORE ADIACENTE*/
//cout<<primo<<"-"<<v<<" con peso:"<<peso<<endl;
/*Se il vertice adiacente non è stato ancora scoperto e il suo peso è minore del valore di key che è stato settato di inizializzazione a infinito
Allora aggiorna i valori*/

  if( scoperto[v]==false && peso<key[v])
    {
  //aggiorno il peso
key[v]=peso;
parent[v]=u;   //Aggiorno il padre
nuovo_heap->insertKey(v,peso); //inserisco i vertici adiacenti nell'miniheap e vedrò se è violata la prioprietà dell'heap in quel caso la ripristino
    }

grafo[u]=grafo[u]->ritorna_next();
    }


}

}



