#ifndef MANEJADORSOCIO
#define MANEJADORSOCIO
#include "Usuario.h"
#include <map>
#include <list>
#include <string>

using namespace std;

class ManejadorSocio{
    private:
        static ManejadorSocio* instancia;
        map<string,Socio*> socios;
        ManejadorSocio();
    public:
        static ManejadorSocio* getInstancia();
        list<Socio*> getSocios();
        Socio* buscarSocio(string);
        void agregarSocio(Socio*);
        bool existeSocio(string);
        void eliminarSocio(string);
        virtual ~ManejadorSocio();
};
#endif
