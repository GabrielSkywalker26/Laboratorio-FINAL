#ifndef MANEJADORFINANCIERA
#define MANEJADORFINANCIERA

#include "Financiera.h"
#include <map>
#include <list>
#include <string>

using namespace std;

class ManejadorFinanciera{
    private:
        static ManejadorFinanciera* instancia;
        map<string,Financiera*> financieras;
        ManejadorFinanciera();
    public:
        static ManejadorFinanciera* getInstancia();
        list<Financiera*> getFinancieras();
        Financiera* buscarFinanciera(string);
        void agregarFinanciera(Financiera*);
        bool existeFinanciera(string);
        void eliminarFinanciera(string);
        virtual ~ManejadorFinanciera();
};
#endif
