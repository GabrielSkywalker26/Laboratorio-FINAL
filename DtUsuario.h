#ifndef DTUSUARIO
#define DTUSUARIO

#include <string>
using namespace std;

class DtUsuario {
private:
    string nickname;
    string contrasenia;
public:
    DtUsuario();
    DtUsuario(string, string);
    string getNickname();
    string getContrasenia();
    ~DtUsuario();
};

#endif