#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;
class Figura{
 public:
     virtual float perimetro()=0;
     virtual float area(){}
     void muestra(){}
};

class Rectangulo:public Figura{
    float b,h;
 public:
     void ponebh(float base,float altura){b=base;h=altura;}
     float perimetro(){float per;per=b*2 + h*2; return per;}
     float area(){float a;a=b*h; return a;}
};

class TrianguloRectangulo:public Figura{
    float c1,c2,h;
 public:
     void ponelados(float cateto1, float cateto2, float hip){c1=cateto1;c2=cateto2;h=hip;}
     float perimetro(){float per;per=c1+c2+h;return per;}
     float area(){float a;a=(c1*c2)/2;return a;}
};

class Circulo:public Figura{
    float r;
 public:
     void poneradio(float radio){r=radio;}
     float perimetro(){float per;per=2*3.1416*r;return per;}
     float area(){float a;a=3.1416*(r*r);return a;}
};

class Geometrica{
    Figura *v[10];
    int tope;
public:
    Geometrica(){tope=0;}
    void agrega(Figura *p){if(tope!=10){v[tope]=p; tope++;}}
    void eliminatodos(){while(tope!=0){tope--;delete v[tope];}}
    void muestra(){while(tope!=0){tope--; v[tope]->muestra();delete v[tope];}}
};

main(){
Figura *pf;
Geometrica geo;
Rectangulo rec;
TrianguloRectangulo tri;
rec.ponebh(10,6);
cout<<rec.perimetro()<<"\n";
cout<<rec.area()<<"\n";
tri.ponelados(3,4,6);
cout<<tri.perimetro()<<"\n";
cout<<tri.area()<<"\n";

geo.agrega(pf);
geo.muestra();
}
