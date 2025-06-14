#ifndef FECHASISTEMA
#define FECHASISTEMA

#include "DtFecha.h"
#include "DtHorarioSistema.h"

class FechaSistema {
private:
    static FechaSistema* instancia;
    DtFecha fecha;
    DtHorarioSistema horario;

    FechaSistema();

public:
    static FechaSistema* getInstancia();

    void setFecha(DtFecha nuevaFecha);
    void setHorario(DtHorarioSistema nuevoHorario);

    DtFecha getFecha();
    DtHorarioSistema getHorario();

    void setFechaYHora(DtFecha nuevaFecha, DtHorarioSistema nuevoHorario);

    ~FechaSistema();
};

#endif
