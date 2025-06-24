#include "ControladorDatosPrueba.h"
#include "DtHorario.h"
#include "DtFecha.h"

ControladorDatosPrueba* ControladorDatosPrueba::instancia = NULL;

ControladorDatosPrueba* ControladorDatosPrueba::getInstancia() {
    if (instancia == NULL)
        instancia = new ControladorDatosPrueba();
    return instancia;
}

ControladorDatosPrueba::ControladorDatosPrueba() {}

ControladorDatosPrueba::~ControladorDatosPrueba() {}

void ControladorDatosPrueba::cargarDatos() {
    // --- Alta de usuarios ---
    controladorUsuario = Fabrica::getInstancia()->getIControladorUsuario();
    controladorUsuario->altaUsuario("bob", "bobpass", "https://img.com/bob.jpg");
    controladorUsuario->altaUsuario("alice", "alicepass", "https://img.com/alice.jpg");
    controladorUsuario->altaUsuario("trudy", "trudypass", "https://img.com/trudy.jpg");

    // --- Alta de peliculas ---
    controladorPelicula = Fabrica::getInstancia()->getIControladorPelicula();
    controladorPelicula->altaPelicula("Pulp Fiction", "Historias entrecruzadas del crimen en Los Angeles", "pulpfiction.jpg");
    controladorPelicula->altaPelicula("Kill Bill", "Una ex asesina busca venganza", "killbill.jpg");
    controladorPelicula->altaPelicula("Django Unchained", "Un esclavo liberado en busca de su esposa", "django.jpg");

    // --- Alta de financieras ---
    ManejadorFinanciera* manejadorFinanciera = ManejadorFinanciera::getInstancia();
    manejadorFinanciera->agregarFinanciera(new Financiera("Visa", 10));
    manejadorFinanciera->agregarFinanciera(new Financiera("Mastercard", 15));
    manejadorFinanciera->agregarFinanciera(new Financiera("OCA", 5));
    manejadorFinanciera->agregarFinanciera(new Financiera("Diners", 20));
    manejadorFinanciera->agregarFinanciera(new Financiera("Cabal", 8));

    // --- Alta de bancos ---
    ManejadorBanco* manejadorBanco = ManejadorBanco::getInstancia();
    manejadorBanco->agregarBanco(new Banco("Santander"));
    manejadorBanco->agregarBanco(new Banco("BBVA"));
    manejadorBanco->agregarBanco(new Banco("Itau"));
    manejadorBanco->agregarBanco(new Banco("Scotiabank"));
    manejadorBanco->agregarBanco(new Banco("HSBC"));

    // --- Alta de Cine 1: Life 21 (21 de Setiembre) ---
    controladorCine = Fabrica::getInstancia()->getIControladorAltaCine();
    controladorCine->ingresarDir("21 de Setiembre", 2721);
    controladorCine->ingresarCap(120); // Sala 1
    controladorCine->ingresarCap(80);  // Sala 2
    controladorCine->altaCine(); // ID asumido: 1

    // --- Alta de Cine 2: Cinemateca (Bartolome Mitre) ---
    controladorCine->ingresarDir("Bartolome Mitre", 1236);
    controladorCine->ingresarCap(90); // Sala 3
    controladorCine->ingresarCap(60); // Sala 4
    controladorCine->altaCine(); // ID asumido: 2

    // --- Alta de funciones ---
    IControladorAltaFuncion* iAltaFuncion = Fabrica::getInstancia()->getIControladorAltaFuncion();

    // Funcion Pulp Fiction en Cine 1, Sala 1
    iAltaFuncion->ingresarTitulo("Pulp Fiction");
    iAltaFuncion->ingresarIdCine(1);
    iAltaFuncion->ingresarPrecioFuncion(350);
    iAltaFuncion->altaFuncion(1, DtHorario(20, 0, 23, 0), DtFecha(14, 6, 2025));

    // Funcion Kill Bill en Cine 1, Sala 2
    iAltaFuncion->ingresarTitulo("Kill Bill");
    iAltaFuncion->ingresarIdCine(1);
    iAltaFuncion->ingresarPrecioFuncion(300);
    iAltaFuncion->altaFuncion(2, DtHorario(18, 0, 20, 0), DtFecha(15, 6, 2025));

    // Funcion Django en Cine 2, Sala 3
    iAltaFuncion->ingresarTitulo("Django Unchained");
    iAltaFuncion->ingresarIdCine(2);
    iAltaFuncion->ingresarPrecioFuncion(400);
    iAltaFuncion->altaFuncion(3, DtHorario(21, 0, 23, 30), DtFecha(16, 6, 2025));
}
