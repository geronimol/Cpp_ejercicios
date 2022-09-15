#include<iostream>

using namespace std;

class base{
 public:
     virtual void f(){cout<<"f() clase base \n";}
     void g(){cout<<"g() clase base \n";}
};
class derivada1: public base{
 public:
     void f(){cout<<"f() clase derivada1 \n";}
     void g(){cout<<"g() clase derivada1 \n";}
};
class derivada2:public base{
 public:
     void f(){cout<<"f() clase derivada2 \n";}
     void g(){cout<<"g() clase derivada2 \n";}
};
main(){
base b, *pb;
derivada1 d1,*pd1;
derivada2 d2,*pd2;

pb=&b; pb->f(); pb->g();
pd1=&d1; pd1->f(); pd1->g();
pd2=&d2; pd2->f(); pd2->g();}
