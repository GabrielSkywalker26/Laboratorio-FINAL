#ifndef DTBANCO
#define DTBANCO

#include <iostream>
#include <string>
using namespace std;

class DtBanco {
private:
    string nombre;
public:
    DtBanco();
    DtBanco(string nombre);
    ~DtBanco();

    friend bool operator<(const DtBanco&, const DtBanco&);
    friend ostream& operator<<(ostream&, const DtBanco&);
};

#endif 