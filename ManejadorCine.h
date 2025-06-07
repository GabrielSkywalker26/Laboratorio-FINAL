#ifndef MANEJADORCINE
#define MANEJADORCINE
#include "Cine.h"
#include <map>
#include <list>
#include <string>

using namespace std;

class ManejadorCine{
    private:
        static ManejadorCine* instancia;
        map<string,Cine*> cines;
        ManejadorCine();
    public:
        static ManejadorCine* getInstancia();
        list<Cine*> getCines();
        Cine* buscarCine(string);
        void agregarCine(Cine*);
        bool existeCine(string);
        void eliminarCine(string);
        virtual ~ManejadorCine();
};
#endif
