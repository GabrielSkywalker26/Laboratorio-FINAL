#ifndef CONTROLADOR
#define CONTROLADOR
#include "IControlador.h"
#include <list>
class Controlador: public IControlador{
    public:
        void registrarSocio(string,string,DtMascota&);
        void agregarMascota(string,DtMascota&);
        void ingresarConsulta(string,string,DtFecha&);
        list<DtConsulta*> verConsultasAntesDeFecha(DtFecha&,string,int&);
        void eliminarSocio(string ci);
        list<DtMascota*> obtenerMascotas(string,int&);
        void cargarDatos();
        void existeSocio(string);
   };
#endif

