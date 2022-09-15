#include <stdio.h>
#include<string.h>
#include<iostream>
#include<stdlib.h>

using namespace std;

class Auto{
    int licencia,modelo,cant_pasajeros,anio;
    char nombre_chofer[25],nombre_duenio[25];
public:
    Auto(int L,int M,int P,int anio,char chofer[],char duenio[]);
    virtual float calculaPrecio(float km)=0;
    float aplicaDescuento(float precio);
    virtual float CalculaViaje(float km,int pasajeros)=0;
    void Muestra();
    int getAnioAct(){return 2015;}
    int getLicencia(){return licencia;}
    int getCantPasajeros(){return cant_pasajeros;}
    void setCantPasajeros(int cant){cant_pasajeros=cant;}
    int getAnio(){return anio;}
    virtual int verificaDNI(long int dni)=0;
};

class Taxis:public Auto{
    float bandera,precio;
public:
    Taxis(int L,int M,int P,int anio,char chofer[],char duenio[]);
    float calculaPrecio(float km);
    float CalculaViaje(float km,int pasajeros);
    float getPrecio(){return precio;}
    int verificaDNI(long int dni){return 0;}
};

class Remises:public Auto{
    float precio;
public:
    Remises(int L,int M,int P,int anio,char chofer[],char duenio[]);
    float calculaPrecio(float km);
    float CalculaViaje(float km,int pasajeros);
    int verificaDNI(long int dni){return 0;}
};
typedef struct nododni{
    long int dni;
    struct nododni *sig;}NODODNI;
typedef NODODNI *TLISTADNI;

class Combis:public Auto{
    float precio1,precio2,precio3;
    int capacidad;
    TLISTADNI lista;
public:
    Combis(int L,int M,int P,int anio,char chofer[],char duenio[],int capacidad_pasajeros);
    float calculaPrecio(float km);
    float CalculaViaje(float km,int pasajeros);
    int verificaDNI(long int dni);
    void agregaDNI(long int dni);
    ~Combis();
};

typedef struct nodo{
    Auto *A;
    struct nodo *sig;}NODO;
typedef NODO *TLISTA;

class Agencia{
    TLISTA lista;
public:
    Agencia(){lista=NULL;}
    void Agrega(Auto *A);
    void Elimina(int L);
    void MuestraViaje(int L,float K,int P);
    int GenteEnViaje();
    void MuestraLista();
    void ViajaDNI(long int dni);
    ~Agencia();
};

Auto::Auto(int L,int M,int P,int anio,char chofer[],char duenio[]){
    licencia=L;modelo=M;cant_pasajeros=P;this->anio=anio;
    strcpy(nombre_chofer,chofer);strcpy(nombre_duenio,duenio);
}

float Auto::aplicaDescuento(float precio){
    int antiguedad;
    antiguedad=getAnioAct()-getAnio();
    if (antiguedad>=1 && antiguedad<4)
        precio-=precio*0.10;
    else
        if(antiguedad>=4)
            precio-=precio*0.20;
    return precio;
}

void Auto::Muestra(){
    cout<<"Licencia: "<<licencia;cout<<"\nModelo: "<<modelo;cout<<"\nCant Pasajeros: "<<cant_pasajeros;
    cout<<"\nAnio: "<<anio;cout<<"\nNombre chofer: "<<nombre_chofer;cout<<"\nNombre duenio: "<<nombre_duenio;
}

Taxis::Taxis(int L,int M,int P,int anio,char chofer[],char duenio[]):Auto(L,M,P,anio,chofer,duenio){
    precio=10;
    bandera=20;
}

float Taxis::calculaPrecio(float km){
    return aplicaDescuento((precio*km)+bandera);
}

float Taxis::CalculaViaje(float km,int pasajeros){
    return calculaPrecio(km);

}

Remises::Remises(int L,int M,int P,int anio,char chofer[],char duenio[]):Auto(L,M,P,anio,chofer,duenio){
    precio=1;
}

float Remises::calculaPrecio(float km){
    return aplicaDescuento(precio*km);
}

float Remises::CalculaViaje(float km,int pasajeros){
    return calculaPrecio(km);
}

Combis::Combis(int L,int M,int P,int anio,char chofer[],char duenio[],int capacidad_pasajeros):Auto(L,M,P,anio,chofer,duenio){
    capacidad=capacidad_pasajeros;
    precio1=10;precio2=9;precio3=17;
    lista=NULL;
}

float Combis::calculaPrecio(float km){
    int pasajeros;
    pasajeros=getCantPasajeros();
    if(km<100)
        if(pasajeros<capacidad/2)
            return aplicaDescuento(precio1);
        else
            return aplicaDescuento(precio2);
    else
        return aplicaDescuento(precio3);
}

float Combis::CalculaViaje(float km, int pasajeros){
    int aux; float precio;
    aux=getCantPasajeros();
    setCantPasajeros(pasajeros);
    precio=calculaPrecio(km);
    setCantPasajeros(aux);
    return precio*pasajeros;
}
void Combis::agregaDNI(long int dni){
    TLISTADNI nuevo,ant,act;
    nuevo=(TLISTADNI)malloc(sizeof(NODODNI));
    nuevo->dni=dni;
    if(lista==NULL || dni<lista->dni){
        nuevo->sig=lista;lista=nuevo;
    }
    else{
        act=lista;
        while(act!=NULL && act->dni < dni){
            ant=act; act=act->sig;
        }
        ant->sig=nuevo;nuevo->sig=act;
    }
}
int Combis::verificaDNI(long int dni){
    TLISTADNI aux=lista;
    while(aux!=NULL && dni!=aux->dni)
        aux=aux->sig;
    if(aux!=NULL)
        return 1;
    else
        return 0;
}
Combis::~Combis(){
    TLISTADNI ant,act=lista;
    while(act!=NULL){
        ant=act;act=act->sig;
        free(ant);
    }
}

void Agencia::MuestraViaje(int L,float K,int P){
    TLISTA aux=lista;
    while(aux!=NULL && L!=aux->A->getLicencia())
        aux=aux->sig;
    if(aux!=NULL){
        aux->A->Muestra();
        cout<<aux->A->CalculaViaje(K,P);
    }
    else{
        cout<<"No se encontro Licencia";
    }
}

int Agencia::GenteEnViaje(){
    TLISTA aux=lista;
    int pasajeros=0;
    while(aux!=NULL){
        pasajeros+=aux->A->getCantPasajeros();
        aux=aux->sig;}
    return pasajeros;
}

void Agencia::Agrega(Auto *A){
    TLISTA ant,act,nuevo;
    nuevo=(TLISTA)malloc(sizeof(NODO));
    nuevo->A=A;
    if(lista==NULL || A->getLicencia() < lista->A->getLicencia()){
        nuevo->sig=lista; lista=nuevo;
    }
    else{
        act=lista;
        while(act!=NULL && A->getLicencia() > act->A->getLicencia()){
            ant=act; act=act->sig;
        }
        ant->sig=nuevo; nuevo->sig=act;
    }
}

void Agencia::MuestraLista(){
    TLISTA aux=lista;
    while(aux!=NULL){
        aux->A->Muestra();
        aux=aux->sig;
    }
}
void Agencia::Elimina(int L){
    TLISTA ant,act=lista;
    if(lista!=NULL){
            if(lista->A->getLicencia() == L){
                ant=lista;lista=lista->sig;
                free(ant);}
            else{
                while(act!=NULL && L!=act->A->getLicencia()){
                    ant=act;act=act->sig;}
                if(act!=NULL){
                    ant->sig=act->sig;
                    free(act);
                }
            }
    }
}
void Agencia::ViajaDNI(long int dni){
    TLISTA aux=lista;
    while(aux!=NULL && !aux->A->verificaDNI(dni))
        aux=aux->sig;
    if(aux!=NULL){
        cout<<"Se encuentra viajando en: ";
        aux->A->Muestra();
    }
    else
        cout<<"No se encuentra";
}
Agencia::~Agencia(){
    TLISTA ant,act=lista;
    while(act!=NULL){
      ant=act; act=act->sig;
      delete ant->A;
      free(ant);}
    }

int main(){
    Agencia A; Auto *Au;
    Au=new Taxis(1,2,3,2007,"-","-");
    cout<<Au->calculaPrecio(10)<<"\n";
    A.Agrega(Au);
    Au=new Remises(4,5,7,2008,"-","-");
    cout<<Au->calculaPrecio(10)<<"\n";
    A.Agrega(Au);
    Combis *Co=new Combis(7,8,9,2014,"-","-",10);
    Co->agregaDNI(1);
    Co->agregaDNI(2);
    Au=Co;
    cout<<Au->calculaPrecio(10)<<"\n";
    A.Agrega(Au);
    cout<<A.GenteEnViaje();
    A.Elimina(7);
    A.MuestraLista();
    //A.MuestraViaje(7,10,3);
    //A.ViajaDNI(2);
    return 0;
}
