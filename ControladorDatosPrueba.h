#ifndef CONTROLADORDATOSPRUEBA
#define CONTROLADORDATOSPRUEBA

#include "IControladorDatosPrueba.h"
#include "ManejadorFinanciera.h"
#include "ManejadorBanco.h"
#include "Fabrica.h"
#include "Financiera.h"
#include "Banco.h"

class ControladorDatosPrueba : public IControladorDatosPrueba {
    private:
        static ControladorDatosPrueba* instancia;
        IControladorUsuario* controladorUsuario;
        IControladorPelicula* controladorPelicula;
        IControladorAltaCine* controladorCine;
        ControladorDatosPrueba();
    public:
        static ControladorDatosPrueba* getInstancia();
        ~ControladorDatosPrueba();
        void cargarDatos();
};

#endif
