#ifndef DTRESERVA
#define DTRESERVA

#include <string>
#include <iostream>

using namespace std;

class DtReserva {
private:
    int idFuncion;
    string tituloPelicula;
    int idCine;
    int dia;
    int mes;
    int anio;
    int horaComienzo;
    int minComienzo;
    int cantEntradas;
    float costo;
    string tipoPago;
    string bancoFinanciera;

public:
    DtReserva();
    DtReserva(int idFuncion, string tituloPelicula, int idCine, 
              int dia, int mes, int anio, int horaComienzo, int minComienzo,
              int cantEntradas, float costo, string tipoPago, string bancoFinanciera);
    
    ~DtReserva();
    
    friend ostream& operator <<(ostream& salida, const DtReserva& dtReserva);
};

#endif 