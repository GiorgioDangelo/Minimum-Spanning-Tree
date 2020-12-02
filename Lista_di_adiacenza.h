#ifndef LISTA_DI_ADIACENZA_H
#define LISTA_DI_ADIACENZA_H
#include <climits>

class Lista_di_adiacenza
{
    public:
    Lista_di_adiacenza();



     void inserisci_isola1(int isola1);
     void inserisci_isola2(int isola2);
     void inserisci_arco(int arco);
     int get_vertice1();
     int get_vertice2();
     int get_peso();
     Lista_di_adiacenza* ritorna_next();
     void inserisci_next(Lista_di_adiacenza *next_1);


    private:
    Lista_di_adiacenza *next;
    int peso;
    int vertice;
    int vertice_collegato;
};

#endif // LISTA_DI_ADIACENZA_H
