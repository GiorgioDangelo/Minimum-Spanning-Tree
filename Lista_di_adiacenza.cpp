#include "Lista_di_adiacenza.h"

Lista_di_adiacenza::Lista_di_adiacenza()
{
    //ctor
}

void Lista_di_adiacenza::inserisci_isola1(int isola1)
{
    vertice=isola1;
}
void Lista_di_adiacenza::inserisci_isola2(int isola2)
{
    vertice_collegato=isola2;
}
void Lista_di_adiacenza::inserisci_arco(int arco)
{
peso=arco;
}
int Lista_di_adiacenza::get_vertice1()
{
return vertice;
}
int Lista_di_adiacenza::get_vertice2()
{
return vertice_collegato;
}
int Lista_di_adiacenza::get_peso()
{
return peso;
}


Lista_di_adiacenza* Lista_di_adiacenza::ritorna_next()
{
return next;
}

void Lista_di_adiacenza::inserisci_next(Lista_di_adiacenza *next_1)
{
next=next_1;
}
