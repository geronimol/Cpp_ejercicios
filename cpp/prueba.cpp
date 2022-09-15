#include<stdio.h>
#include<conio.h>
#include<string>
#include<iostream>

using namespace std;

class base {
    int a,total;
    long int go;
public:
    base(int n, int m){a=n;total=m;}
    void asigna_valor(int v){total=v;}
    virtual void muestra(){cout <<a<<" "<<total<<"\n";}
};

class sub: public base{
    char c;
public:
    sub(int n, int m, char ca):base(n,m){c=ca;}
    void asigna_car(char k){c=k;}
    void muestra(){base::muestra();cout<<c<<"\n";}
};

class subsub:public sub{
    float f;
public:
    subsub(int n, int m, char ca,float g):sub(n,m,ca){f=g;}
    void asigna_float(float h){f=h;}
    void muestra(){sub::muestra();cout<<f<<"\n";}
};

main(){
    subsub ob(1,2,'a',7.2);
    sub *punt;
    punt = &ob;
    punt->asigna_valor(-1);
    punt->asigna_car('b');

    punt->muestra();
}
