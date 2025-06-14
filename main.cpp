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


    int dia, mes, anio;
    cout << "Ingrese la fecha de la funcion: " << endl;
    cout << "Dia: ";
    cin >> dia;
    cout << "\nMes: ";
    cin >> mes;
    cout << "\nAnio: ";
    cin >> anio;

	string horaComienzo, horaFin;
    cout << "Ingrese la hora de comienzo de la funcion: " << endl;
    cin >> horaComienzo;
    cout << "Ingrese la hora de finalizacion de la funcion: " << endl;
    cin >> horaFin;

	DtFecha fechaFuncion(dia, mes, anio);
	DtHorario horarioFuncion(horaComienzo, horaFin);

	iAltaFuncion->altaFuncion(idSala, horarioFuncion, fechaFuncion);
	
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
    cout << "_____M O D I F I C A R   F E C H A   D E L   S I S T E M A_____" << endl;

    int dia, mes, anio;
    string horaS;

    // Ingreso paso a paso
    cout << "Ingrese el dia: ";
    cin >> dia;
    
    cout << "Ingrese el mes: ";
    cin >> mes;
    
    cout << "Ingrese el anio: ";
    cin >> anio;

    cout << "Ingrese la hora del sitema (formato HH:MM): ";
    cin >> horaS;

    // Crear objetos de fecha y horario
    DtFecha nuevaFecha(dia, mes, anio);
    DtHorarioSistema nuevoHorario(horaS);

    // Aplicar en controlador
    iFecha->modificarFecha(nuevaFecha, nuevoHorario);

    cout << "Fecha del sistema actualizada a: " << nuevaFecha << " " << nuevoHorario << endl;
}





void consultarFechaSistema() {
    system("clear");
    cout << "_____F E C H A   D E L   S I S T E M A_____" << endl;

    DtFecha fecha = iFecha->getFecha();
    DtHorarioSistema horario = iFecha->getHorario();

    cout << "Fecha del sistema: " << fecha << " " << horario << endl;
}



void cargarDatosPrueba() {
	system("clear");
	cout << "_____C A R G A R   D A T O S   D E   P R U E B A_____" << endl;

	// --- Alta de usuarios ---
	iUsuario->altaUsuario("bob", "bobpass", "https://img.com/bob.jpg");
	iUsuario->altaUsuario("alice", "alicepass", "https://img.com/alice.jpg");
	iUsuario->altaUsuario("trudy", "trudypass", "https://img.com/trudy.jpg");

	// --- Alta de películas ---
	iPelicula->altaPelicula("Pulp Fiction", "Historias entrecruzadas del crimen en Los Angeles", "pulpfiction.jpg");
	iPelicula->altaPelicula("Kill Bill", "Una ex asesina busca venganza", "killbill.jpg");
	iPelicula->altaPelicula("Django Unchained", "Un esclavo liberado en busca de su esposa", "django.jpg");

	// --- Alta de Cine 1: Life 21 (21 de Setiembre) ---
	iAltaCine->ingresarDir("21 de Setiembre", 2721);
	iAltaCine->ingresarCap(120); // Sala 1
	iAltaCine->ingresarCap(80);  // Sala 2
	iAltaCine->altaCine(); // ID asumido: 1

	// --- Alta de Cine 2: Cinemateca (Bartolomé Mitre) ---
	iAltaCine->ingresarDir("Bartolome Mitre", 1236);
	iAltaCine->ingresarCap(90); // Sala 3
	iAltaCine->ingresarCap(60); // Sala 4
	iAltaCine->altaCine(); // ID asumido: 2

	// --- Alta de funciones ---

	// Función Pulp Fiction en Cine 1, Sala 1
	iAltaFuncion->ingresarTitulo("Pulp Fiction");
	iAltaFuncion->ingresarIdCine(1);
	iAltaFuncion->altaFuncion(1, DtHorario("20", "23"), DtFecha(14, 6, 2025));

	// Función Kill Bill en Cine 1, Sala 2
	iAltaFuncion->ingresarTitulo("Kill Bill");
	iAltaFuncion->ingresarIdCine(1);
	iAltaFuncion->altaFuncion(2, DtHorario("18", "20"), DtFecha(15, 6, 2025));

	// Función Django en Cine 2, Sala 3
	iAltaFuncion->ingresarTitulo("Django Unchained");
	iAltaFuncion->ingresarIdCine(2);
	iAltaFuncion->altaFuncion(3, DtHorario("21", "00"), DtFecha(16, 6, 2025));

	cout << "Datos de prueba cargados correctamente." << endl;
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
