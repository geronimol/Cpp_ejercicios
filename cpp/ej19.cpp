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
typedef struct nodo{
    Figura *pf;
    struct nodo *sig;}NODO;
typedef NODO *TLISTA;

class Geometrica{
    TLISTA lista;
public:
    Geometrica(){lista=NULL;}
    void agrega(Figura *p){TLISTA nuevo;nuevo=(TLISTA)malloc(sizeof(NODO));nuevo->pf=p;nuevo->sig=lista;lista=nuevo;}
    void elimina(){TLISTA aux=lista;lista=lista->sig;delete aux->pf; free(aux);}
    void muestra(){TLISTA aux=lista;lista=lista->sig;aux->pf->muestra();delete aux->pf;free(aux);}
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
