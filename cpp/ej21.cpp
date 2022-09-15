#include<iostream>
using namespace std;
struct fecha{
    int dia,mes,anio;};
struct movimientos{
    char tipo[20];
    float monto;
    struct fecha f;};
class CUENTA{
    int CODCLIENTE,NROCUENTA;
    struct fecha FECHAAPERTURA;
    struct movimientos MOVIMIENTOS[20];
    float SALDO,INTERES;
 public:
     void cierre();
     void deposito();
     void extraccion();
     void resumen();
     void descuentos();
};
class AHORRO:public CUENTA{
    int CANTEXTRACCIONES;
    char DEPOSITACHEQUE;
 public:
     void autorizacion();
};
class CORRIENTE:public CUENTA{
    float MONTODESMAX;
 public:
     void CIERRE();
};
class BANCO{
    CUENTA *pc[1000];
    int CLIENTES[500];
 public:
     void apertura();
     void cierre();
     void resumen();
     void depositos();
     void extracciones();
     void listados();
     void ingreso();
     void egreso();
};
