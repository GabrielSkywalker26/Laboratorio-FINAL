#ifndef MANEJADORBANCO
#define MANEJADORBANCO

#include "Banco.h"
#include "ManejadorBanco.h"

#include <map>
#include <list>
#include <string>


using namespace std;

class ManejadorBanco{
    private:
        static ManejadorBanco* instancia;
        map<string,Banco*> bancos;
        ManejadorBanco();
    public:
        static ManejadorBanco* getInstancia();
        list<Banco*> getBancos();
        Banco* buscarBanco(string);
        void agregarBanco(Banco*);
        bool existeBanco(string);
        void eliminarBanco(string);
        virtual ~ManejadorBanco();
};

#endif 