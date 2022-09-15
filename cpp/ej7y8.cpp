#include<iostream>
#include<string.h>

using namespace std;
#define maxp 100
typedef char telementop;

class stacks{
    int tope;
    telementop vp[maxp];
public:
    stacks();
    int llenap();
    int vaciap();
    void ponep(telementop p);
    void sacap(telementop *p);
    };
stacks::stacks(){
    tope=0;}
int stacks::llenap(){
    return tope==maxp;};
int stacks::vaciap(){
    return tope==0;};
void stacks::ponep(telementop p){
    vp[tope]=p;
    tope++;};
void stacks::sacap(telementop *p){
    tope--;
    *p=vp[tope];};

void ponep(char cad[],stacks *p);
void muestrap(stacks *p);

int main(){
stacks p;
char cad[100];
cout<<"Ingresar cadena\n";
cin.getline(cad,100);
cout<<"La cadena es: "<<cad<<"\n";

ponep(cad,&p);
cout<<"Muestro cadena: \n";
muestrap(&p);

return 0;
}

void muestrap(stacks *p){
char c;
while(!p->vaciap()){
    p->sacap(&c);
    cout<<c;}
}
void ponep(char cad[],stacks *p){
int tam,i;
tam=strlen(cad);
for(i=0;i<tam;i++){
    if(!p->llenap())
        p->ponep(cad[i]);}
}



