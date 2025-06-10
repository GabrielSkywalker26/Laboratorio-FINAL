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
	cout <<"1. Iniciar sesión" << endl;
	cout <<"2. Cerrar sesión" << endl;
	cout <<"3. Alta usuario" << endl;
	cout <<"4. Alta película" << endl;
	cout <<"5. Alta cine" << endl;
	cout <<"6. Alta función" << endl;
	cout <<"7. Crear reserva" << endl;
	cout <<"8. Ver reservas por película" << endl;
	cout <<"9. Eliminar película" << endl;
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
	cout << "=== Alta cine ===" << endl;
	
    string direccion;
    int numero;

    cout << "Direccion: ";
    cin >> direccion;
    cout << "Numero: ";
    scanf("%d", &numero);

	DtDireccion dtDir = DtDireccion(direccion, numero);

    iAltaCine->altaCine(dtDir);
	
    int capacidad, opcion;
    bool seguir = true;

    // usuario quiere agregar sala
    while(seguir){
        
        cout << "Capacidad: ";
        scanf("%d", &capacidad);

		iAltaCine->ingresarCap(capacidad);

        cout << "Continuar agregando salas? " << endl;
        cout << "1. Seguir" << endl;
	    cout << "2. Terminar" << endl;
        scanf("%d", &opcion);
        
        if (opcion == 2) seguir = false;
    }


    cout << "Cine registrado correctamente." << endl;
}

void altaFuncion() {
	system("clear");
	cout << "=== Alta función ===" << endl;
	// TO DO: implementar lógica con iAltaFuncion
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
