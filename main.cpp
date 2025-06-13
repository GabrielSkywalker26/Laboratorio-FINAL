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

using namespace std;

// Instancias globales
Fabrica* fabrica = Fabrica::getInstancia();
IControladorAltaCine* iAltaCine = fabrica->getIControladorAltaCine();
IControladorAltaFuncion* iAltaFuncion = fabrica->getIControladorAltaFuncion();
IControladorPelicula* iPelicula = fabrica->getIControladorPelicula();
IControladorReserva* iReserva = fabrica->getIControladorReserva();
IControladorSesion* iSesion = fabrica->getIControladorSesion();
IControladorUsuario* iUsuario = fabrica->getIControladorUsuario();

// Declaración de operaciones
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

// Implementación del menú
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

// Estructura de funciones (vacías por ahora)
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
    cout << "_________A L T A   U S U A R I O_________" << endl;
    
    string nickname, contrasena, url;
    cout << "Nickname: ";
    cin >> nickname;
    cout << "Contrasena: ";
    cin >> contrasena;
    cout << "URL de la foto: ";
    cin >> url;

    iUsuario->altaUsuario(nickname, contrasena, url);

    cout << "Usuario registrado correctamente." << endl;
}


void altaPelicula() {
	system("clear");
	cout << "_________A L T A   P E L I C U L A_________" << endl;

	string titulo, sinopsis, poster;

	cout << "Titulo: ";
	cin.ignore(); // limpia el salto de línea previo
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
	cout << "_________A L T A   C I N E_________" << endl;
	
    string direccion;
    int numero;

    cout << "Direccion: ";
    cin.ignore();
	getline(cin, direccion);
    cout << "Numero de puerta: ";
    cin.ignore();
    cin >> numero;

	iAltaCine->ingresarDir(direccion, numero);

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
	// Guardo el titulo ingresado
	iAltaFuncion->ingresarTitulo(titulo);

	// Filtramos por los cines donde se pasa la pelicula?
	// O le sumamos esta pelicula al cine si no la tiene?

	int idCine;
    list<DtCine*> cines = iAltaFuncion->listarCines();
    cout << "Cines disponibles:\n";
    for (DtCine* c : cines) {
        cout << "- " << *c << endl;
    }
    cin.ignore();
    cin >> idCine;
	// Guardo el id del cine ingresado
	iAltaFuncion->ingresarIdCine(idCine);

	// Listar salas del cine seleccionado
	int idSala;
    list<DtSala*> salas = iAltaFuncion->listarSalas();
    cout << "Salas disponibles:\n";
    for (DtSala* s : salas) {
        cout << "- " << *s << endl;
    }
    cin.ignore();
    cin >> idSala;


    int dia, mes, anio;
    cout << "Ingrese la fecha de la funcion: " << endl;
    cout << "Dia: ";
    cin.ignore();
    cin >> dia;
    cout << "\nMes: ";
    cin.ignore();
    cin >> mes;
    cout << "\nAnio: ";
    cin.ignore();
    cin >> anio;

	string horaComienzo, horaFin;
    cout << "Ingrese la hora de comienzo de la funcion: " << endl;
    cin.ignore();
    cin >> horaComienzo;
    cout << "Ingrese la hora de finalizacion de la funcion: " << endl;
    cin.ignore();
    cin >> horaFin;

	// Ver de agregar la funcion
	// Si todo salio bien agrego la peli a la lista de pelis del cine
	// preguntar si el usuario quiere seguir agregando funciones


}



void crearReserva() {
	system("clear");
	cout << "=== Crear reserva ===" << endl;
	// TO DO: implementar lógica con iReserva
}

void verReservasPorPelicula() {
	system("clear");
	cout << "=== Ver reservas por película ===" << endl;
	// TO DO: implementar lógica con iReserva
}

void eliminarPelicula() {
	system("clear");
	cout << "_______E L I M I N A R   P E L I C U L A______" << endl;

	string titulo;
	cout << "Titulo de la pelicula a eliminar: ";
	cin.ignore(); // limpia el salto de línea previo
	getline(cin, titulo);

	if (iPelicula->eliminarPelicula(titulo))
		cout << "Pelicula eliminada correctamente." << endl;
	else
		cout << "Error: no se encontro la pelicula." << endl;
}


void modificarFechaSistema() {
	system("clear");
	cout << "=== Modificar fecha del sistema ===" << endl;
	// TO DO: usar clase FechaSistema
}

void consultarFechaSistema() {
	system("clear");
	cout << "=== Consultar fecha del sistema ===" << endl;
	// TO DO: usar clase FechaSistema
}

void cargarDatosPrueba() {
	system("clear");
	cout << "=== Cargar datos de prueba ===" << endl;
	// TO DO: invocar cargas en todos los controladores
}

// Main principal
int main() {
	
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
			default: cout << "OPCIÓN INCORRECTA" << endl;
		}
		sleep(3); // en Linux/macOS; usar Sleep(3000) en Windows
		menu();
		cin >> opcion;
	}
	cout << "SALIENDO..." << endl;
	return 0;
}
