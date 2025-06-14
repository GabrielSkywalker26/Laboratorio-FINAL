#ifndef CONTROLADORFECHA
#define CONTROLADORFECHA

#include "IControladorFecha.h"
#include "FechaSistema.h"

class ControladorFecha : public IControladorFecha {
public:
    void modificarFecha(DtFecha f, DtHorarioSistema h);
    DtFecha getFecha();
    DtHorarioSistema getHorario();
};

#endif
