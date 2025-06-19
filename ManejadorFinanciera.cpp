#include "Financiera.h"
#include <list>
#include "ManejadorFinanciera.h"
using namespace std;

ManejadorFinanciera* ManejadorFinanciera::instancia = NULL;

ManejadorFinanciera::ManejadorFinanciera(){}

ManejadorFinanciera* ManejadorFinanciera::getInstancia(){
    if (instancia == NULL)
        instancia = new ManejadorFinanciera();
    return instancia;
}

list<Financiera*> ManejadorFinanciera::getFinancieras(){
    list<Financiera*> lstFinancieras;
    for (map<string,Financiera*>::iterator it=this->financieras.begin(); it!=financieras.end(); ++it)
        lstFinancieras.push_back(it->second);
    return lstFinancieras;
}

Financiera* ManejadorFinanciera::buscarFinanciera(string financiera){
  map<string,Financiera*>::iterator it = this->financieras.find(financiera);
  return it->second;
}

void ManejadorFinanciera::agregarFinanciera(Financiera* financiera){
    financieras.insert(std::pair<string,Financiera*>(financiera->getNombre(), financiera));
}

bool ManejadorFinanciera::existeFinanciera(string financiera){ 
  map<string,Financiera*>::iterator it = this->financieras.find(financiera);
  return (it != this->financieras.end());
}

void ManejadorFinanciera::eliminarFinanciera(string financiera){
  map<string,Financiera*>::iterator it = this->financieras.find(financiera);
  this->financieras.erase(it);
}

ManejadorFinanciera::~ManejadorFinanciera(){}
