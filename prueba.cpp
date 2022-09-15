#include <stdio.h>
#include<string.h>
#include<iostream>
#include<stdlib.h>

using namespace std;

struct hola{int x;};
class prueba{
    int n;
    struct hola h[n];
public:
    prueba(int l){n=l;}
};

main(){
prueba ob(3);

}
