#ifndef PAGO
#define PAGO

#include <string>

class Pago {
protected:
    float monto;

public:
    Pago();
    virtual ~Pago();
    virtual float getMonto() = 0;
    virtual void setMonto(float m) = 0;
};

#endif 