#include<iostream>
#include<string>
#include<time.h>

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
Empleado ob[20];
int n,i;
struct fecha f;
struct tm *tiempo;
time_t fecha_sistema;
	time(&fecha_sistema);
	tiempo=localtime(&fecha_sistema);

	f.anio=tiempo->tm_year + 1900;
	f.mes=tiempo->tm_mon + 1;
	f.dia=tiempo->tm_mday;

cout<<"Ingresar cant. empleados\n";
cin>>n;

for(i=0;i<n;i++)
    ob[i].asignadatos();

for(i=0;i<n;i++)
    if (ob[i].f.anio<(f.anio-10) || (ob[i].f.anio==(f.anio-10) && ob[i].f.mes<f.mes) ||
                        (ob[i].f.anio==(f.anio-10) && ob[i].f.mes==f.mes && ob[i].f.dia<=f.dia))
        ob[i].muestra();

return 0;
}
