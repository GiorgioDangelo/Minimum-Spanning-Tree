#include <iostream>
#include "Vector_adiacenze.h"
#include "Lista_di_adiacenza.h"
#include "heap.h"
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string nome;
cout<<"Inserisci il nome del file "<<endl;
cin>>nome;


ifstream file;
file.open(nome,ios::in);
int N;
int P;
int vertice1;
int vertice2;
int max1=0;
int max2=0;
int minimo=INT_MAX;
int max_final;
int peso;
if (!file)
{
    cout<<"Il file nn esiste"<<endl;
    exit(0);
}

   file>>N;
file>>P;
   if(N<=2 ||N>1000 || P<=1 || P>10000)
   {
    cout<<"hai superato il numero di vertici o archi"<<endl;
    exit(0);
   }

     while (file>>vertice1>>vertice2>>peso){
     if(vertice1>max1)
        max1=vertice1;
     if(vertice2>max2)
        max2=vertice2;
        if(vertice1<minimo)
            minimo=vertice1;
        if(vertice2<minimo)
            minimo=vertice2;



    }

    if(minimo<=0)
    {
    cout<<"Hai inserito un vertice uguale o minore di 0 !!"<<endl;
    exit(0);
    }
if(max1>max2)
{
max_final=max1;
}
else{
    max_final=max2;
}


  file.close();


// *************************************************************************************

Vector_adiacenze *nuovo=new Vector_adiacenze(max_final+1);//Se ho 11 di size ad esempio significa che il vettore va da 0 a 10 poichè io
ifstream file1;
file1.open(nome,ios::in);


if (!file1)
{
    cout<<"Il file nn esiste"<<endl;
    exit(0);
}
file1>>N;
file1>>P;



     while (file1>>vertice1>>vertice2>>peso){

nuovo->inserisci_vertice(vertice1,vertice2,peso);
nuovo->inserisci_vertice_opposto(vertice1,vertice2,peso);

    }
      file1.close();



int resp=1;
int sorg;
bool ok = true;
  do {
   cout << "\n**** MENU ****\n\n";
    cout << " 1. Prim\n";
    cout << " 0. Exit\n";
    cout << ">_ ";
    cin >> resp;
    switch (resp) {
          case 0:
        ok = false;
        break;

      case 1:
       cout << "PRIM "<<endl;
       cout<<"INSERISCI IL NODO SORGENTE :";
       cin>>sorg;

    nuovo->prim(sorg);
   nuovo->stampa_risultato();
 exit(1);
        break;
        
      default:
        cout << "riprova \n";
        continue;
    }
  } while (ok);

}
