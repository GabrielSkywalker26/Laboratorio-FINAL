#include <iostream>
#include <cstdlib> // system()
#include <unistd.h> // sleep()

#include "Fabrica.h"
#include "IControladorAltaCine.h"
#include "IControladorAltaFuncion.h"
#include "IControladorPelicula.h"
#include "IControladorReserva.h"
#include "IControladorSesion.h"
#include "IControladorUsuario.h"
#include "IControladorFecha.h"
#include "ManejadorCine.h"
#include "Sala.h"
#include "Cine.h"
#include "Financiera.h"
#include "ManejadorFinanciera.h"
#include "ManejadorBanco.h"
#include "Banco.h"
#include "DtBanco.h"
#include "ManejadorFuncion.h"
#include "DtFinanciera.h"

using namespace std;

// Instancias globales
Fabrica* fabrica = Fabrica::getInstancia();
IControladorAltaCine* iAltaCine = fabrica->getIControladorAltaCine();
IControladorAltaFuncion* iAltaFuncion = fabrica->getIControladorAltaFuncion();
IControladorPelicula* iPelicula = fabrica->getIControladorPelicula();
IControladorReserva* iReserva = fabrica->getIControladorReserva();
IControladorSesion* iSesion = fabrica->getIControladorSesion();
IControladorUsuario* iUsuario = fabrica->getIControladorUsuario();
IControladorFecha* iFecha = fabrica->getIControladorFecha();


// Declaracion de operaciones
void iniciarSesion();
void cerrarSesion();
void altaUsuario();
void altaPelicula();
void altaCine();
void altaFuncion();
void crearReserva();
void verReservasPorPelicula();
void eliminarPelicula();
void modificarFechaSistema();
void consultarFechaSistema();
void cargarDatosPrueba();

void menu();

// Implementacion del menu
void menu(){
	system("clear");
	cout <<"_____________________________________________" <<endl;
	cout <<"_____________S I S T E M A__C I N E__________"<< endl;
	cout <<"1. Iniciar sesion" << endl;
	cout <<"2. Cerrar sesion" << endl;
	cout <<"3. Alta usuario" << endl;
	cout <<"4. Alta pelicula" << endl;
	cout <<"5. Alta cine" << endl;
	cout <<"6. Alta funcion" << endl;
	cout <<"7. Crear reserva" << endl;
	cout <<"8. Ver reservas por pelicula" << endl;
	cout <<"9. Eliminar pelicula" << endl;
	cout <<"10. Modificar fecha del sistema" << endl;
	cout <<"11. Consultar fecha del sistema" << endl;
	cout <<"12. Cargar datos de prueba" << endl;
	cout <<"13. Salir" << endl;
	cout <<"_____________________________________________" <<endl;
	cout <<"OPCION: ";
}

// Estructura de funciones (vacias por ahora)
void iniciarSesion() {
    system("clear");
    cout << "________I N I C I A R  S E S I O N________" << endl;
    string nickname, contrasenia;
    cout << "Nickname: ";
    cin >> nickname;
    cout << "Contrasenia: ";
    cin >> contrasenia;
    if (iSesion->iniciarSesion(nickname, contrasenia))
        cout << "Sesion iniciada correctamente." << endl;
	else
        cout << "Error al iniciar sesion." << endl;
}

void cerrarSesion() {
    system("clear");
    cout << "________C E R R A R  S E S I O N________" << endl;
    iSesion->cerrarSesion();
    cout << "Sesion cerrada." << endl;
}

void altaUsuario() {
    system("clear");

    if (!iSesion->sesionIniciada()){
        cout << "\nDebes iniciar sesion para acceder a esta opcion." << endl;
		return;
	}

    cout << "_________A L T A   U S U A R I O_________" << endl;
    
    string nickname, contrasena, url;
    cout << "Nickname: ";
    cin >> nickname;
    cout << "Contrasena: ";
    cin >> contrasena;
    cout << "URL de la foto: ";
    cin >> url;

    iUsuario->altaUsuario(nickname, contrasena, url);

}


void altaPelicula() {
	system("clear");

    if (!iSesion->sesionIniciada()){
        cout << "\nDebes iniciar sesion para acceder a esta opcion." << endl;
		return;
	}

	cout << "_________A L T A   P E L I C U L A_________" << endl;

	string titulo, sinopsis, poster;

	cout << "Titulo: ";
	cin.ignore(); // limpia el salto de linea previo
	getline(cin, titulo);

	cout << "Sinopsis: ";
	getline(cin, sinopsis);

	cout << "URL del poster: ";
	getline(cin, poster);

	if (iPelicula->altaPelicula(titulo, sinopsis, poster))
		cout << "Pelicula registrada correctamente." << endl;
	else
		cout << "Error: ya existe una pelicula con ese titulo." << endl;
}


void altaCine() {
	system("clear");

    if (!iSesion->sesionIniciada()){
        cout << "\nDebes iniciar sesion para acceder a esta opcion." << endl;
		return;
	}

	cout << "_________A L T A   C I N E_________" << endl;
	
    string calle;
    int numero;

    cout << "Calle: ";
    cin.ignore();
	getline(cin, calle);
    cout << "Numero de puerta: ";
    cin.ignore();
    cin >> numero;

	iAltaCine->ingresarDir(calle, numero);

    int capacidad, opcion;
    bool seguir = true;

    // usuario quiere agregar sala
    while(seguir){
        cout << "Capacidad de la sala: ";
        cin >> capacidad;

		iAltaCine->ingresarCap(capacidad);

        cout << "Continuar agregando salas? " << endl;
        cout << "1. Seguir" << endl;
	    cout << "2. Terminar" << endl;
		cout << "Opcion: ";
        cin >> opcion;
        
        if (opcion == 2) seguir = false;
    }

    if (iAltaCine->altaCine())
		cout << "\n Cine registrado correctamente." << endl;
	else
		cout << "\n Error al registrar cine." << endl;
}

void altaFuncion() {
    system("clear");

    if (!iSesion->sesionIniciada()){
        cout << "\nDebes iniciar sesion para acceder a esta opcion." << endl;
		return;
	}

    cout << "_________A L T A   F U N C I O N_________" << endl;

    list<DtPelicula*> pelis = iAltaFuncion->listarPeliculas();
    cout << "Peliculas disponibles:\n";
    for (DtPelicula* p : pelis) {
        cout << "- " << *p << endl;
    }

    string titulo;
    cout << "Ingrese el titulo de la pelicula: ";
    cin.ignore();
    getline(cin, titulo);
	
	iAltaFuncion->ingresarTitulo(titulo);

	// Filtramos por los cines donde se pasa la pelicula?
	// O le sumamos esta pelicula al cine si no la tiene?

	int idCine;
    list<DtCine*> cines = iAltaFuncion->listarCines();
    cout << "Cines disponibles:\n";
    for (DtCine* c : cines) {
        cout << "- " << *c << endl;
    }

	cout << "Ingrese id del cine: ";
    cin >> idCine;

	iAltaFuncion->ingresarIdCine(idCine);

	// Listar salas del cine seleccionado

    list<DtSala*> salas = iAltaFuncion->listarSalas();
    cout << "Salas disponibles:\n";
    for (DtSala* s : salas) {
        cout << "- " << *s << endl;
    }

	cout << "Ingrese id de la sala: ";
	int idSala;
    cin >> idSala;

    // imprimir funciones de esa sala
    Sala* salaSeleccionada = NULL;
    Cine* cineSeleccionado = ManejadorCine::getInstancia()->buscarCine(idCine);
    if (cineSeleccionado != NULL) {
        for (Sala* s : cineSeleccionado->obtenerSalas()) {
            if (s->getId() == idSala) {
                salaSeleccionada = s;
                break;
            }
        }
    }
    if (salaSeleccionada != NULL) {
        list<DtFuncion*> funciones = salaSeleccionada->obtenerDtFunciones();
        cout << "Funciones de la sala seleccionada:\n";
        for (DtFuncion* f : funciones) {
            Funcion* fun = ManejadorFuncion::getInstancia()->buscarFuncion(f->getId());
            if (fun)
                cout << "- " << *f << ", Precio: $" << fun->getPrecio() << endl;
            else
                cout << "- " << *f << endl;
        }
    } else {
        cout << "Sala no encontrada." << endl;
    }

    // Pedir precio de la funcion
    float precioFuncion;
    cout << "Ingrese el precio de la funcion: $";
    cin >> precioFuncion;
    iAltaFuncion->ingresarPrecioFuncion(precioFuncion);

    int dia, mes, anio;
    cout << "Ingrese la fecha de la funcion: " << endl;
    cout << "Dia: ";
    cin >> dia;
    cout << "\nMes: ";
    cin >> mes;
    cout << "\nAnio: ";
    cin >> anio;

    int horaComienzo, minComienzo, horaFin, minFin;
    cout << "Ingrese la hora de comienzo de la funcion (hora y minutos separados): " << endl;
    cout << "Hora: ";
    cin >> horaComienzo;
    cout << "Minutos: ";
    cin >> minComienzo;
    cout << "Ingrese la hora de finalizacion de la funcion (hora y minutos separados): " << endl;
    cout << "Hora: ";
    cin >> horaFin;
    cout << "Minutos: ";
    cin >> minFin;

    DtFecha fechaFuncion(dia, mes, anio);
    DtHorario horarioFuncion(horaComienzo, minComienzo, horaFin, minFin);

    iAltaFuncion->altaFuncion(idSala, horarioFuncion, fechaFuncion);
	
	cout << "Funcion registrada correctamente." << endl;
}



void crearReserva() {
    system("clear");
    cout << "_________C R E A R__R E S E R V A_________" << endl;
    
    if (!iSesion->sesionIniciada()) {
        cout << "\nDebes iniciar sesion para acceder a esta opcion." << endl;
        return;
    }

    // Listar peliculas disponibles
    list<DtPelicula*> pelis = iReserva->listarPeliculas();
    if (pelis.empty()) {
        cout << "No hay peliculas disponibles." << endl;
        return;
    }

    cout << "\nPeliculas disponibles:\n";
    for (DtPelicula* p : pelis) {
        cout << "- " << *p << endl;
    }

    // Seleccion de pelicula
    string titulo;
    cout << "\nIngrese el titulo de la pelicula (o 'cancelar' para salir): ";
    cin.ignore();
    getline(cin, titulo);
    
    if (titulo == "cancelar") {
        iReserva->finalizar();
        return;
    }

    // Obtener informacion de la pelicula
    DtPeliInfo* dtPeliInfo = iReserva->selectPeli(titulo);
    if (!dtPeliInfo) {
        cout << "Pelicula no encontrada." << endl;
        iReserva->finalizar();
        return;
    }

    cout << "\nInformacion de la pelicula:\n" << *dtPeliInfo << endl;

    // Preguntar si desea ver informacion adicional de la pelicula
    int eleccionInfo;
    cout << "\nDesea ver informacion adicional de la pelicula?" << endl;
    cout << "1. Si" << endl;
    cout << "2. No" << endl;
    cout << "Opcion: ";
    cin >> eleccionInfo;

    if (eleccionInfo == 1) {
        // Listar cines donde se pasa la pelicula
        list<DtCine*> cines = iReserva->listarCinesPeli();
        if (cines.empty()) {
            cout << "No hay cines disponibles para esta pelicula." << endl;
            iReserva->finalizar();
            return;
        }

        cout << "\nCines disponibles:\n";
        for (DtCine* c : cines) {
            cout << "- " << *c << endl;
        }

        // Seleccion de cine
        int eleccionCine;
        cout << "\nDesea continuar?" << endl;
        cout << "1. Seleccionar cine" << endl;
        cout << "2. Finalizar" << endl;
        cout << "Opcion: ";
        cin >> eleccionCine;

        if (eleccionCine == 1) {
            int idCine;
            cout << "\nIngrese id del cine: ";
            cin >> idCine;

            // Listar funciones disponibles
            list<DtFuncion*> funciones = iReserva->selectCine(idCine);
            if (funciones.empty()) {
                cout << "No hay funciones disponibles para esta pelicula en este cine." << endl;
                iReserva->finalizar();
                return;
            }

            cout << "\nFunciones disponibles:\n";
            for (DtFuncion* f : funciones) {
                cout << "- " << *f << endl;
            }

            // Seleccion de funcion
            int idFuncion;
            cout << "\nIngrese id de la funcion: ";
            cin >> idFuncion;
            iReserva->selectFuncion(idFuncion);

            // Ingreso de cantidad de asientos
            int cantidadAsientos;
            cout << "\nIngrese cantidad de asientos: ";
            cin >> cantidadAsientos;
            if (!iReserva->reservarAsientos(cantidadAsientos)) {
                cout << "No hay suficientes asientos disponibles." << endl;
                iReserva->finalizar();
                return;
            }

            // Seleccion de modo de pago
            int tipoPago;
            cout << "\nSeleccione el modo de pago:" << endl;
            cout << "1. Tarjeta de debito" << endl;
            cout << "2. Tarjeta de credito" << endl;
            cout << "Opcion: ";
            cin >> tipoPago;
            iReserva->ingresarModoPago(tipoPago);

            string bancoFinanciera;
            if (tipoPago == 1) {
                // Mostrar bancos disponibles
                list<DtBanco*> bancos = iReserva->listarBancos();
                if (!bancos.empty()) {
                    cout << "\nBancos disponibles:" << endl;
                    for (DtBanco* b : bancos) {
                        cout << "- " << *b << endl;
                    }
                } else {
                    cout << "No hay bancos cargados en el sistema." << endl;
                }
                cout << "Ingrese nombre del banco: ";
                cin.ignore();
                getline(cin, bancoFinanciera);
                iReserva->ingresarBanco(bancoFinanciera);
            } else {
                // Mostrar financieras disponibles antes de pedir el nombre
                list<Financiera*> financieras = ManejadorFinanciera::getInstancia()->getFinancieras();
                if (!financieras.empty()) {
                    cout << "\nFinancieras disponibles:" << endl;
                    for (Financiera* f : financieras) {
                        DtFinanciera dtf(f->getNombre(), f->getDescuento());
                        cout << "- " << dtf << endl;
                    }
                } else {
                    cout << "No hay financieras cargadas en el sistema." << endl;
                }
                cout << "Ingrese nombre de la financiera: ";
                cin.ignore();
                getline(cin, bancoFinanciera);
                iReserva->ingresarFinanciera(bancoFinanciera);
                float descuento = iReserva->obtenerDescuento(bancoFinanciera);
                if (descuento > 0) {
                    cout << "Descuento disponible: " << descuento << "%" << endl;
                }
            }

            // Mostrar precio total y confirmar
            float precioTotal = iReserva->calcularPrecioTotal(idFuncion, cantidadAsientos, tipoPago, bancoFinanciera);
            cout << "\nPrecio total: $" << precioTotal << endl;

            int confirmar;
            cout << "\nDesea confirmar la reserva?" << endl;
            cout << "1. Si" << endl;
            cout << "2. No" << endl;
            cout << "Opcion: ";
            cin >> confirmar;

            if (confirmar == 1) {
                iReserva->ingresarUsuario(iSesion->obtenerUsuario());
                if (iReserva->confirmar()) {
                    cout << "Reserva creada exitosamente." << endl;
                } else {
                    cout << "Error al crear la reserva." << endl;
                }
            }
        }
    }

    iReserva->finalizar();
}

void verReservasPorPelicula() {
	cout << "=== Ver reservas por pelicula ===" << endl;
	// TO DO: implementar logica con iReserva
}

void eliminarPelicula() {
	system("clear");

    if (!iSesion->sesionIniciada()){
        cout << "\nDebes iniciar sesion para acceder a esta opcion." << endl;
		return;
	}

	cout << "_______E L I M I N A R   P E L I C U L A______" << endl;

	list<DtPelicula*> pelis = iPelicula->listarPeliculas();
	cout << "Peliculas disponibles:\n";
	for (DtPelicula* p : pelis) {
		cout << "- " << *p << endl;
	}

	string titulo;
	cout << "Ingrese el titulo de la pelicula a eliminar: ";
	cin.ignore(); // limpia el salto de linea previo
	getline(cin, titulo);
	iPelicula->ingresarTitulo(titulo);

	if (iPelicula->eliminarPelicula())
		cout << "Pelicula eliminada correctamente." << endl;
	else
		cout << "Error: no se encontro la pelicula." << endl;
}


void modificarFechaSistema() {
    system("clear");

    if (!iSesion->sesionIniciada()){
        cout << "\nDebes iniciar sesion para acceder a esta opcion." << endl;
		return;
	}

    cout << "_____M O D I F I C A R   F E C H A   D E L   S I S T E M A_____" << endl;

    int dia, mes, anio, horaS, minS;
    cout << "Ingrese el dia: ";
    cin >> dia;
    cout << "Ingrese el mes: ";
    cin >> mes;
    cout << "Ingrese el anio: ";
    cin >> anio;
    cout << "Ingrese la hora del sistema (hora y minutos separados): ";
    cout << "Hora: ";
    cin >> horaS;
    cout << "Minutos: ";
    cin >> minS;

    DtFecha nuevaFecha(dia, mes, anio);
    DtHorarioSistema nuevoHorario(horaS, minS);

    // Aplicar en controlador
    iFecha->modificarFecha(nuevaFecha, nuevoHorario);

    cout << "Fecha del sistema actualizada a: " << nuevaFecha << " " << nuevoHorario << endl;
}





void consultarFechaSistema() {
    system("clear");

    if (!iSesion->sesionIniciada()){
        cout << "\nDebes iniciar sesion para acceder a esta opcion." << endl;
		return;
	}

    cout << "_____F E C H A   D E L   S I S T E M A_____" << endl;

    DtFecha fecha = iFecha->getFecha();
    DtHorarioSistema horario = iFecha->getHorario();

    cout << "Fecha del sistema: " << fecha << " " << horario << endl;
}



void cargarDatosPrueba() {
	system("clear");

    if (!iSesion->sesionIniciada()){
        cout << "\nDebes iniciar sesion para acceder a esta opcion." << endl;
		return;
	}

	cout << "_____C A R G A R   D A T O S   D E   P R U E B A_____" << endl;

	// --- Alta de usuarios ---
	cout << "Cargando usuarios..." << endl;
	iUsuario->altaUsuario("bob", "bobpass", "https://img.com/bob.jpg");
	iUsuario->altaUsuario("alice", "alicepass", "https://img.com/alice.jpg");
	iUsuario->altaUsuario("trudy", "trudypass", "https://img.com/trudy.jpg");

	// --- Alta de peliculas ---
	cout << "Cargando peliculas..." << endl;
	iPelicula->altaPelicula("Pulp Fiction", "Historias entrecruzadas del crimen en Los Angeles", "pulpfiction.jpg");
	iPelicula->altaPelicula("Kill Bill", "Una ex asesina busca venganza", "killbill.jpg");
	iPelicula->altaPelicula("Django Unchained", "Un esclavo liberado en busca de su esposa", "django.jpg");

	// --- Alta de Cine 1: Life 21 (21 de Setiembre) ---
	cout << "Cargando Cine 1..." << endl;
	iAltaCine->ingresarDir("21 de Setiembre", 2721);
	iAltaCine->ingresarCap(120); // Sala 1
	iAltaCine->ingresarCap(80);  // Sala 2
	iAltaCine->altaCine(); // ID asumido: 1

	// --- Alta de Cine 2: Cinemateca (Bartolome Mitre) ---
	cout << "Cargando Cine 2..." << endl;
	iAltaCine->ingresarDir("Bartolome Mitre", 1236);
	iAltaCine->ingresarCap(90); // Sala 3
	iAltaCine->ingresarCap(60); // Sala 4
	iAltaCine->altaCine(); // ID asumido: 2

	// --- Alta de funciones ---
	cout << "Cargando funciones..." << endl;

	// Funcion Pulp Fiction en Cine 1, Sala 1
	cout << "Creando funcion Pulp Fiction..." << endl;
	iAltaFuncion->ingresarTitulo("Pulp Fiction");
	iAltaFuncion->ingresarIdCine(1);
	iAltaFuncion->ingresarPrecioFuncion(350);
	iAltaFuncion->altaFuncion(1, DtHorario(20, 0, 23, 0), DtFecha(14, 6, 2025));

	// Funcion Kill Bill en Cine 1, Sala 2
	cout << "Creando funcion Kill Bill..." << endl;
	iAltaFuncion->ingresarTitulo("Kill Bill");
	iAltaFuncion->ingresarIdCine(1);
	iAltaFuncion->ingresarPrecioFuncion(300);
	iAltaFuncion->altaFuncion(2, DtHorario(18, 0, 20, 0), DtFecha(15, 6, 2025));

	// Funcion Django en Cine 2, Sala 3
	cout << "Creando funcion Django..." << endl;
	iAltaFuncion->ingresarTitulo("Django Unchained");
	iAltaFuncion->ingresarIdCine(2);
	iAltaFuncion->ingresarPrecioFuncion(400);
	iAltaFuncion->altaFuncion(3, DtHorario(21, 0, 23, 30), DtFecha(16, 6, 2025));

	// --- Alta de financieras ---
	cout << "Cargando financieras..." << endl;
	ManejadorFinanciera::getInstancia()->agregarFinanciera(new Financiera("Visa", 10));
	ManejadorFinanciera::getInstancia()->agregarFinanciera(new Financiera("Mastercard", 15));
	ManejadorFinanciera::getInstancia()->agregarFinanciera(new Financiera("OCA", 5));
	ManejadorFinanciera::getInstancia()->agregarFinanciera(new Financiera("Diners", 20));
	ManejadorFinanciera::getInstancia()->agregarFinanciera(new Financiera("Cabal", 8));

	// --- Alta de bancos ---
	cout << "Cargando bancos..." << endl;
	ManejadorBanco::getInstancia()->agregarBanco(new Banco("Santander"));
	ManejadorBanco::getInstancia()->agregarBanco(new Banco("BBVA"));
	ManejadorBanco::getInstancia()->agregarBanco(new Banco("Itau"));
	ManejadorBanco::getInstancia()->agregarBanco(new Banco("Scotiabank"));
	ManejadorBanco::getInstancia()->agregarBanco(new Banco("HSBC"));

	cout << "Datos de prueba cargados correctamente." << endl;
}


// Main principal
int main() {
	// --- Alta de administrador ---
	iUsuario->altaUsuario("admin", "admin", "https://pelicenter.com/admin.jpg");
	
	int opcion;
	menu();
	cin >> opcion;
	
	

	while(opcion != 13){
		switch(opcion){
			case 1: iniciarSesion(); break;
			case 2: cerrarSesion(); break;
			case 3: altaUsuario(); break;
			case 4: altaPelicula(); break;
			case 5: altaCine(); break;
			case 6: altaFuncion(); break;
			case 7: crearReserva(); break;
			case 8: verReservasPorPelicula(); break;
			case 9: eliminarPelicula(); break;
			case 10: modificarFechaSistema(); break;
			case 11: consultarFechaSistema(); break;
			case 12: cargarDatosPrueba(); break;
			default: cout << "OPCION INCORRECTA" << endl;
		}
		sleep(3); // en Linux/macOS; usar Sleep(3000) en Windows
		menu();
		cin >> opcion;
	}
	cout << "SALIENDO..." << endl;
	return 0;
}
