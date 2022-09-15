#include<iostream>
#include<string>

using namespace std;

struct fecha{
    int dia,mes,anio;};

class Empleado{
public:
    char nombre[25];
    int numero;
    struct fecha f;
public:
    void asignadatos();
    void muestra();
    /*~Empleado(){}*/
};

void Empleado::asignadatos(){
    cout<<"Nombre?\n";
    cin>>nombre;
    cout<<"Numero de empleado?\n";
    cin>>numero;
    cout<<"Fecha de ingreso?\n";
    cin>>f.dia>>f.mes>>f.anio;
};
void Empleado::muestra(){
    cout<<"Nombre: "<<nombre<<"\n";
    cout<<"Numero de empleado: "<<numero<<"\n";
    cout<<"Fecha de ingreso: "<<f.dia<<"/"<<f.mes<<"/"<<f.anio<<"\n";
};

int main(){
Empleado *p[20];
int i,n=3;

for(i=0;i<n;i++){
    p[i]=new Empleado;
    p[i]->asignadatos();}

for(i=0;i<n;i++)
    if(p[i]->f.anio==2004){
        p[i]->muestra();
        delete p[i];}

for(i=0;i<n;i++)
    if (p[i]!=NULL)
        p[i]->muestra();

for(i=0;i<n;i++)
    delete p[i];

return 0;}
