#ifndef MANEJADORFUNCION
#define MANEJADORFUNCION

#include "Funcion.h"
#include "Usuario.h"
#include <map>
#include <list>
#include <string>

using namespace std;

class ManejadorFuncion{
    private:
        static ManejadorFuncion* instancia;
        map<int,Funcion*> funciones;
        ManejadorFuncion();
    public:
        static ManejadorFuncion* getInstancia();
        list<Funcion*> getFunciones();
        Funcion* buscarFuncion(int);
        void agregarFuncion(Funcion*);
        bool existeFuncion(int);
        void eliminarFuncion(int);
        virtual ~ManejadorFuncion();
};
#endif
