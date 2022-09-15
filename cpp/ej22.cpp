#include<iostream>
using namespace std;
class AUTO{
    int licencia,modelo,pasajeros;
    char chofer[25],duenio[25];
 public:
     virtual void precio()=0;
     int obtlicencia(){return licencia;}
     int obtmodelo(){return modelo;}
     char*obtchofer(){return chofer;}
     char*obtduenio(){return duenio;}
     int obtpasajeros(){return pasajeros;}
     };
class TAXI:public AUTO{

};
class REMIS:public AUTO{
};
class COMBI:public AUTO{
};

typedef struct nodo{
    AUTO *pa;
    struct nodo *sig;}NODO;
typedef NODO *TLISTA;

class AGENCIA{
    TLISTA lista;
 public:
     AGENCIA(){lista=NULL;}
     void cargalista();
     void manejaautos();
     void MuestraViaje(int L,float K,int P);
     void GenteEnViaje();
};
void AGENCIA::MuestraViaje(int L,float K,int P){
    TLISTA aux=lista;
    while(aux->pa->obtlicencia() != L)
        aux=aux->sig;
    if(aux!=NULL){
        cout<<"Licencia\n"<<L;
        cout<<"Chofer\n"<<aux->pa->obtchofer();
        cout<<"Dueño\n"<<aux->pa->obtduenio();
        cout<<"Modelo\n"<<aux->pa->obtmodelo();
        cout<<"Pasajeros\n"<<aux->pa->obtpasajeros();

    }
}
