#ifndef BANCO
#define BANCO

#include <string>
#include <iostream>

using namespace std;

class Banco {
private:
    string nombre;
    // Puedes agregar mas atributos si lo deseas, como sucursal o codigo
public:
    Banco();
    Banco(string nombre);
    string getNombre();
    void setNombre(string nombre);
    ~Banco();
};

#endif 