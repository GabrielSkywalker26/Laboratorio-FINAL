#ifndef USUARIO
#define USUARIO

#include "DtUsuario.h"
#include <string>

using namespace std;

class Usuario {
private:
    string nickname;
    string contrasena;
    string urlFoto;

public:
    Usuario();
    Usuario(string nickname, string contrasena, string urlFoto);

    string getNickname();
    string getContrasena();
    string getUrlFoto();

    void setNickname(string nickname);
    void setContrasena(string contrasena);
    void setUrlFoto(string urlFoto);

    DtUsuario* getDtUsuario();

    //void agregarReserva(string reservaId);

    ~Usuario();
};

#endif
