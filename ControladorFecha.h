#ifndef CONTROLADORFECHA
#define CONTROLADORFECHA

#include "IControladorFecha.h"
#include "FechaSistema.h"

class ControladorFecha : public IControladorFecha {
private:
    static ControladorFecha* instancia;
    ControladorFecha();
public:
    static ControladorFecha* getInstancia();
    ~ControladorFecha();
    void modificarFecha(DtFecha f, DtHorarioSistema h);
    DtFecha getFecha();
    DtHorarioSistema getHorario();
};

#endif
