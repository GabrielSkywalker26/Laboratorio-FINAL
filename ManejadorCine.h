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
        map<int,Cine*> cines;
        ManejadorCine();
    public:
        static ManejadorCine* getInstancia();
        list<Cine*> getCines();
        Cine* buscarCine(int);
        void agregarCine(Cine*);
        bool existeCine(int);
        void eliminarCine(int);
        list<DtSala*> getDtSalas(int);
        virtual ~ManejadorCine();
};
#endif
