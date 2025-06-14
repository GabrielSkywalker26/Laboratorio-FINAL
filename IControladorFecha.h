#ifndef ICONTROLADORFECHA
#define ICONTROLADORFECHA

#include "DtFecha.h"
#include "DtHorarioSistema.h"

class IControladorFecha {
public:
    virtual void modificarFecha(DtFecha, DtHorarioSistema) = 0;
    virtual DtFecha getFecha() = 0;
    virtual DtHorarioSistema getHorario() = 0;

    virtual ~IControladorFecha() {}
};

#endif
