#include<iostream>
#include<stdlib.h>

using namespace std;

class vector3{
    int v[3];
public:
    vector3(){int i; for(i=0;i<3;i++) v[i]=0;};
    vector3(int a,int b,int c){v[0]=a;v[1]=b;v[2]=c;};
    int igual(int v1[]){int i=0;
                        while ((v[i] == v1[i]) && (i<3))
                            i++;
                        if(i==3) return 1; else return 0;};
    void muestra(){int i; for(i=0;i<3;i++) cout<<"\n"<<v[i];};
};
int main(){
vector3 ob(1,2,3);
int v1[]{1,2,3};
ob.muestra();
if(ob.igual(v1))
    cout<<"son iguales";
else
    cout<<"son distintos";

return 0;
}
