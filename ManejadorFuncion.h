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
        map<string,Funcion*> funciones;
        ManejadorFuncion();
    public:
        static ManejadorFuncion* getInstancia();
        list<Funcion*> getFunciones();
        Funcion* buscarFuncion(string);
        void agregarFuncion(Funcion*);
        bool existeFuncion(string);
        void eliminarFuncion(string);
        virtual ~ManejadorFuncion();
};
#endif
