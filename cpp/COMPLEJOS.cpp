#include<stdio.h>
#include<string.h>
#include<iostream>
#include <math.h>

using namespace std;

class Complejo{
    float real,imaginaria;
public:
    Complejo();
    float getReal();
    float getImaginaria();
    void setImaginaria(float i);
    void setReal(float r);
    void suma(Complejo c1, Complejo c2);
    void muestra(){cout<<real<<" "<<imaginaria;}
    void lee(){cin>>real;cin>>imaginaria;}

};

Complejo::Complejo(){
    real=1;imaginaria=0;}
float Complejo::getReal(){
    return real;}
float Complejo::getImaginaria(){
    return imaginaria;}
void Complejo::setImaginaria(float i){
    imaginaria=i;}
void Complejo::setReal(float r){
    real=r;}
void Complejo::suma(Complejo c1, Complejo c2){
    real=c1.getReal()+c2.getReal();
    imaginaria=c1.getImaginaria()+c2.getImaginaria();}

main(){
    Complejo c,c1,c2;
    c.suma(c1,c2);
    c.muestra();
}
