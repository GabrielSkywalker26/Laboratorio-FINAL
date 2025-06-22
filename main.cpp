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
#include "ManejadorUsuario.h"
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
void puntuarPelicula();
void comentarPelicula();
void verInformacionPelicula();
void verComentariosPuntajesPelicula();

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
	cout <<"13. Puntuar pelicula" << endl;
	cout <<"14. Comentar pelicula" << endl;
	cout <<"15. Ver informacion de pelicula" << endl;
	cout <<"16. Ver comentarios y puntajes de pelicula" << endl;
	cout <<"17. Salir" << endl;
	cout <<"_____________________________________________" <<endl;
	cout <<"OPCION: ";
}


void iniciarSesion() {
    system("clear");

    // Verificar si el usuario ha iniciado sesión
    if (iSesion->sesionIniciada()){
        cout << "\nDebes cerrar sesion para acceder a esta opcion." << endl;
		return;
	}


    cout << "________I N I C I A R  S E S I O N________" << endl;
    string nickname, contrasenia;
    cout << "Nickname: ";
    cin >> nickname;
    bool reingresar = true;
    while (reingresar) {
        cout << "Contrasenia: ";
        cin >> contrasenia;
        if (iSesion->iniciarSesion(nickname, contrasenia)) {
            cout << "Sesion iniciada correctamente." << endl;
            reingresar = false;
        } else {
            cout << "Error al iniciar sesion." << endl;
            cout << "Desea volver a ingresar contrasenia o cancelar?" << endl;
            int opcion;
            cout << "1. Reingresar contrasenia" << endl;
            cout << "2. Cancelar" << endl;
            cout << "Opcion: ";
            cin >> opcion;
            if (opcion == 2) {
                reingresar = false;
                cout << "Regresando al menu de inicio..." << endl;
            }
        }
    }
}

void cerrarSesion() {
        system("clear");

    // Verificar si el usuario ha iniciado sesión
    if (!iSesion->sesionIniciada()){
        cout << "\nDebes iniciar sesion para acceder a esta opcion." << endl;
		return;
	}

    cout << "________C E R R A R  S E S I O N________" << endl;
    iSesion->cerrarSesion();
    cout << "Sesion cerrada." << endl;
}

void altaUsuario() {
    system("clear");

    // Verificar si el usuario ha iniciado sesión
    if (!iSesion->sesionIniciada()){
        cout << "\nDebes iniciar sesion para acceder a esta opcion." << endl;
		return;
	}

    cout << "_________A L T A   U S U A R I O_________" << endl;
    
    string nickname, contrasena, url;

    bool reingresar = true;
    while (reingresar) {
        cout << "Nickname: ";
        cin >> nickname;
        cout << "Contrasena: ";
        cin >> contrasena;
        cout << "URL de la foto: ";
        cin >> url;
        if (iUsuario->altaUsuario(nickname, contrasena, url)){
            cout << "Usuario ingresasdo correctamente." << endl;
            reingresar = false;
        } else {
            cout << "Desea volver a ingresar un usuario?" << endl;
            int opcion;
            cout << "1. Reingresar usuario" << endl;
            cout << "2. Cancelar" << endl;
            cout << "Opcion: ";
            cin >> opcion;
            if (opcion == 2) {
                reingresar = false;
                cout << "Regresando al menu de inicio..." << endl;
            }
        }
    }
}


void altaPelicula() {
	system("clear");

    // Verificar si el usuario ha iniciado sesión
    if (!iSesion->sesionIniciada()){
        cout << "\nDebes iniciar sesion para acceder a esta opcion." << endl;
		return;
	}

	cout << "_________A L T A   P E L I C U L A_________" << endl;

	string titulo, sinopsis, poster;
    
    bool reingresar = true;
    while (reingresar) {

        cout << "Titulo: ";
        cin.ignore(); // limpia el salto de linea previo
        getline(cin, titulo);

        cout << "Sinopsis: ";
        getline(cin, sinopsis);

        cout << "URL del poster: ";
        getline(cin, poster);

        if (iPelicula->altaPelicula(titulo, sinopsis, poster)){
            cout << "Pelicula registrada correctamente." << endl;
            reingresar = false;
        } else {
            cout << "Error! Ya existe una pelicula con ese titulo." << endl;
            cout << "Desea volver a ingresar una pelicula?" << endl;
            int opcion;
            cout << "1. Reingresar pelicula" << endl;
            cout << "2. Cancelar" << endl;
            cout << "Opcion: ";
            cin >> opcion;
            if (opcion == 2) {
                reingresar = false;
                cout << "Regresando al menu de inicio..." << endl;
            }
        }
    }
}


void altaCine() {
	system("clear");

    // Verificar si el usuario ha iniciado sesión
    if (!iSesion->sesionIniciada()){
        cout << "\nDebes iniciar sesion para acceder a esta opcion." << endl;
		return;
	}

	cout << "_________A L T A   C I N E_________" << endl;
	
    string calle;
    int numero;
    
    bool reingresar = true;
    bool seguir = true;
    int capacidad, opcion, opcionReingresar;
    int confirmacion = 1;

    while(reingresar){

        cout << "Calle: ";
        cin.ignore();
        getline(cin, calle);
        cout << "Numero de puerta: ";
        cin >> numero;

        iAltaCine->ingresarDir(calle, numero);

        // usuario quiere agregar sala
        seguir = true;

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

        cout << "Confirmar alta de cine? " << endl;
        cout << "1. Si" << endl;
        cout << "2. No" << endl;
        cout << "Opcion: ";
        cin >> confirmacion;
        
        if (confirmacion == 1) {
            if (iAltaCine->altaCine())
                cout << "Cine registrado correctamente." << endl;
            else
                cout << "Error al registrar cine." << endl;
        }else
            cout << "No se ingreso el cine." << endl;
        
        cout << "\nDesea agregar mas cines? " << endl;
        cout << "1. Si" << endl;
        cout << "2. No" << endl;
        cout << "Opcion: ";
        cin >> opcionReingresar;
                
        if (opcionReingresar == 2) {
            reingresar = false;
            cout << "Regresando al menu de inicio..." << endl;
        }

        iAltaCine->finalizar();
    }

}

void altaFuncion() {
    system("clear");

    // Verificar si el usuario ha iniciado sesión
    if (!iSesion->sesionIniciada()){
        cout << "\nDebes iniciar sesion para acceder a esta opcion." << endl;
		return;
	}

    cout << "_________A L T A   F U N C I O N_________" << endl;

    list<DtPelicula*> pelis = iAltaFuncion->listarPeliculas();
    cout << "Peliculas disponibles:\n";

    // Listar las peliculas ingresadas
    if (pelis.empty()) {
        cout << "No hay peliculas ingresadas." << endl;
        return;
    }

    // Hay peliculas entonces las listo
    for (DtPelicula* p : pelis) {
        cout << "- " << *p << endl;
    }

    string titulo;
    cout << "Ingrese el titulo de la pelicula: ";
    cin.ignore();
    getline(cin, titulo);
	
	if (iPelicula->existePelicula(titulo)){
        iAltaFuncion->ingresarTitulo(titulo);
    } else {
        cout << "No existe la pelicula ingresada." << endl;
        return;
    }
    
    int opcionReingresar;
    bool reingresar = true;
    while(reingresar){
        int idCine;
        list<DtCine*> cines = iAltaFuncion->listarCines();
        cout << "Cines disponibles:\n";
        for (DtCine* c : cines) {
            cout << "- " << *c << endl;
        }

        cout << "Ingrese id del cine: ";
        cin >> idCine;

        iAltaFuncion->ingresarIdCine(idCine);

        // imprimir funciones de esa sala
        Sala* salaSeleccionada = NULL;
        Cine* cineSeleccionado = ManejadorCine::getInstancia()->buscarCine(idCine);
        int idSala;
        if (cineSeleccionado != NULL) {
            // Listar salas del cine seleccionado
            list<DtSala*> salas = iAltaFuncion->listarSalas();
            cout << "Salas disponibles:\n";
            for (DtSala* s : salas) {
                cout << "- " << *s << endl;
            }
            cout << "Ingrese id de la sala: ";
            cin >> idSala;
            for (Sala* s : cineSeleccionado->obtenerSalas()) {
                if (s->getId() == idSala) {
                    salaSeleccionada = s;
                    break;
                }
            }
        } else {
            cout << "Error! Cine no encontrado." << endl;
        }

        if (salaSeleccionada != NULL) {
            list<DtFuncion*> funciones = salaSeleccionada->obtenerDtFunciones();
            cout << "Funciones de la sala seleccionada:\n";
            for (DtFuncion* f : funciones) {
                Funcion* fun = iAltaFuncion->buscarFuncion(f->getId());
                if (fun)
                    cout << "- " << *f << ", Precio: $" << fun->getPrecio() << endl;
                else
                    cout << "- " << *f << endl;
            }
        } else {
            cout << "Error! Sala no encontrada." << endl;
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

        if (!iAltaFuncion->altaFuncion(idSala, horarioFuncion, fechaFuncion)) {
            cout << "Hubo uno o mas errores al registrar la funcion." << endl;
        }
        
        cout << "\nDesea agregar mas funciones? " << endl;
        cout << "1. Si" << endl;
        cout << "2. No" << endl;
        cout << "Opcion: ";
        cin >> opcionReingresar;
                
        if (opcionReingresar == 2) {
            reingresar = false;
            cout << "Regresando al menu de inicio..." << endl;
        }

        iAltaFuncion->finalizar();

    }
	
}



void crearReserva() {
    system("clear");

    // Verificar si el usuario ha iniciado sesión
    if (!iSesion->sesionIniciada()) {
        cout << "\nDebes iniciar sesion para acceder a esta opcion." << endl;
        return;
    }

    cout << "_________C R E A R__R E S E R V A_________" << endl;
    
    list<DtPelicula*> pelis;

    string titulo;
    bool reingresarPelicula = true;
    while(reingresarPelicula){

        // Listar peliculas disponibles
        pelis = iReserva->listarPeliculas();
        if (pelis.empty()) {
            cout << "No hay peliculas disponibles." << endl;
            cout << "Regresando al menu de inicio..." << endl;
            return;
        }

        cout << "\nPeliculas disponibles:\n";
        for (DtPelicula* p : pelis) {
            cout << "- " << *p << endl;
        }

        // Seleccion de pelicula
        cout << "\nIngrese el titulo de la pelicula (o 'cancelar' para salir): ";
        cin.ignore();
        getline(cin, titulo);
        
        if (titulo == "cancelar") {
            cout << "Regresando al menu de inicio..." << endl;
            iReserva->finalizar();
            return;
        }

        // Verificar si la película existe usando el manejador
        Pelicula* pelicula = iPelicula->buscarPelicula(titulo);
        if (!pelicula) {
            cout << "Pelicula no encontrada." << endl;
            cout << "Regresando al menu de inicio..." << endl;
            iReserva->finalizar();
            return;
        }

        cout << "\nInformacion de la pelicula:\n" << *(pelicula->obtenerDtPelicula()) << endl;

        // Preguntar si desea ver informacion adicional de la pelicula
        int eleccionInfo;
        cout << "\nDesea ver informacion adicional de la pelicula?" << endl;
        cout << "1. Si" << endl;
        cout << "2. No" << endl;
        cout << "Opcion: ";
        cin >> eleccionInfo;

        if (eleccionInfo == 1) {
            // Seleccionar la película en el controlador para que listarCinesPeli funcione
            iReserva->selectPeli(titulo);
            
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
                    Funcion* fun = iAltaFuncion->buscarFuncion(f->getId());
                    if (fun)
                        cout << "- " << *f << ", Precio: $" << fun->getPrecio() << endl;
                    else
                        cout << "- " << *f << endl;
                }

                int opcionPelicula;
                cout << "\nDesea elegir una funcion o seleccionar otra pelicula? " << endl;
                cout << "1. Elegir funcion" << endl;
                cout << "2. Seleccionar otra pelicula" << endl;
                cout << "Opcion: ";
                cin >> opcionPelicula;
                        
                if (opcionPelicula == 1) {
                    reingresarPelicula = false;
                }
                
                iReserva->finalizar();

            } else {
                cout << "Regresando al menu de inicio..." << endl;
                return;
            }
        } else {
            cout << "Regresando al menu de inicio..." << endl;
            return;
        }

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
    
    // Obtener la capacidad real de la sala donde se emite la función
    int capacidadSala = iReserva->obtenerCapacidadSala(idFuncion);
    
    if (!iReserva->reservarAsientos(cantidadAsientos, capacidadSala)) {
        cout << "No hay suficientes asientos disponibles." << endl;
        cout << "Capacidad de la sala: " << capacidadSala << " asientos." << endl;
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
        list<Financiera*> financieras = iReserva->getFinancieras();
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
    } else {
        cout << "Reeserva cancelada." << endl;
        cout << "Regresando al menu de inicio..." << endl;
        return;
    }

    iReserva->finalizar();
}

void verReservasPorPelicula() {
    system("clear");

    // Verificar si el usuario ha iniciado sesión
    if (!iSesion->sesionIniciada()) {
        cout << "\nDebes iniciar sesion para acceder a esta opcion." << endl;
        return;
    }
   

    cout << "_________V E R__R E S E R V A S__P O R__P E L I C U L A_________" << endl;
    

    // Listar todas las películas
    list<DtPelicula*> todasLasPelis = iReserva->listarPeliculas();
    if (todasLasPelis.empty()) {
        cout << "No hay peliculas registradas en el sistema." << endl;
        return;
    }

    cout << "\nPeliculas disponibles:\n";
    for (DtPelicula* p : todasLasPelis) {
        cout << "- " << *p << endl;
    }

    // Selección de película
    string titulo;
    cout << "\nIngrese el titulo de la pelicula para ver sus reservas: ";
    cin.ignore();
    getline(cin, titulo);

    // Verificar si la película existe usando el manejador
    Pelicula* pelicula = iPelicula->buscarPelicula(titulo);
    if (!pelicula) {
        cout << "Pelicula no encontrada." << endl;
        // Liberar memoria de los DTOs antes de salir
        for (DtPelicula* p : todasLasPelis) {
            delete p;
        }
        return;
    }

    // Obtener reservas de la película
    list<DtReserva*> reservas = iReserva->obtenerReservasPorPelicula(titulo);
    if (reservas.empty()) {
        cout << "No se encontraron reservas para la pelicula '" << titulo << "'." << endl;
        // Liberar memoria de los DTOs antes de salir
        for (DtPelicula* p : todasLasPelis) {
            delete p;
        }
        return;
    }

    cout << "\n=== RESERVAS PARA '" << titulo << "' ===" << endl;
    cout << "Total de reservas: " << reservas.size() << endl;
    cout << "----------------------------------------" << endl;
    
    for (DtReserva* r : reservas) {
        cout << *r << endl;
        cout << "----------------------------------------" << endl;
    }
    
    // Liberar memoria de los DTOs
    for (DtReserva* r : reservas) {
        delete r;
    }
    
    // Liberar memoria de los DtPelicula
    for (DtPelicula* p : todasLasPelis) {
        delete p;
    }
}

void eliminarPelicula() {
	system("clear");

    // Verificar si el usuario ha iniciado sesión
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

    // Verificar si el usuario ha iniciado sesión
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

    // Verificar si el usuario ha iniciado sesión
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

    // Verificar si el usuario ha iniciado sesión
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

	// --- Crear reservas de prueba ---
	cout << "Creando reservas de prueba..." << endl;
	
	// Reserva 1: Bob reserva 2 asientos para Kill Bill (Débito)
	cout << "Creando reserva 1: Bob - Kill Bill..." << endl;
	iReserva->selectPeli("Kill Bill");
	iReserva->selectFuncion(2); // ID de la función Kill Bill
	iReserva->ingresarUsuario(ManejadorUsuario::getInstancia()->buscarUsuario("bob"));
	// Obtener capacidad real de la sala dinámicamente para mostrar información
	int capacidadSala2 = iReserva->obtenerCapacidadSala(2);
	cout << "Capacidad de la sala 2 (Kill Bill): " << capacidadSala2 << " asientos" << endl;
	iReserva->reservarAsientos(2, capacidadSala2);
	iReserva->ingresarModoPago(1); // Débito
	iReserva->ingresarBanco("Santander");
	if (iReserva->confirmar()) {
		cout << "Reserva 1 creada exitosamente" << endl;
	} else {
		cout << "Error al crear reserva 1" << endl;
	}
	iReserva->finalizar();
	
	// Reserva 2: Alice reserva 1 asiento para Kill Bill (Crédito)
	cout << "Creando reserva 2: Alice - Kill Bill..." << endl;
	iReserva->selectPeli("Kill Bill");
	iReserva->selectFuncion(2); // ID de la función Kill Bill
	iReserva->ingresarUsuario(ManejadorUsuario::getInstancia()->buscarUsuario("alice"));
	iReserva->reservarAsientos(1, capacidadSala2);
	iReserva->ingresarModoPago(2); // Crédito
	iReserva->ingresarFinanciera("Visa");
	if (iReserva->confirmar()) {
		cout << "Reserva 2 creada exitosamente" << endl;
	} else {
		cout << "Error al crear reserva 2" << endl;
	}
	iReserva->finalizar();
	
	// Reserva 3: Trudy reserva 3 asientos para Django (Débito)
	cout << "Creando reserva 3: Trudy - Django..." << endl;
	iReserva->selectPeli("Django Unchained");
	iReserva->selectFuncion(3);
	iReserva->ingresarUsuario(ManejadorUsuario::getInstancia()->buscarUsuario("trudy"));
	int capacidadSala3 = iReserva->obtenerCapacidadSala(3);
	cout << "Capacidad de la sala 3 (Django): " << capacidadSala3 << " asientos" << endl;
	iReserva->reservarAsientos(3, capacidadSala3);
	iReserva->ingresarModoPago(1);
	iReserva->ingresarBanco("BBVA");
	if (iReserva->confirmar()) {
		cout << "Reserva 3 creada exitosamente" << endl;
	} else {
		cout << "Error al crear reserva 3" << endl;
	}
	iReserva->finalizar();

	cout << "Datos de prueba cargados correctamente." << endl;
    cout << "Regresando al menu de inicio..." << endl;
}

void puntuarPelicula() {
    system("clear");

    // Verificar si el usuario ha iniciado sesión
    if (!iSesion->sesionIniciada()) {
        cout << "\nDebes iniciar sesion para acceder a esta opcion." << endl;
        return;
    }

    cout << "_________P U N T U A R__P E L I C U L A_________" << endl;
    
    // Listar películas
    list<DtPelicula*> pelis = iPelicula->listarPeliculas();
    if (pelis.empty()) {
        cout << "No hay peliculas disponibles." << endl;
        return;
    }

    cout << "\nPeliculas disponibles:\n";
    for (DtPelicula* p : pelis) {
        cout << "- " << *p << endl;
    }

    // Seleccionar película
    string titulo;
    cout << "\nIngrese el titulo de la pelicula: ";
    cin.ignore();
    getline(cin, titulo);

    // Verificar si la película existe
    Pelicula* pelicula = iPelicula->buscarPelicula(titulo);
    if (!pelicula) {
        cout << "Pelicula no encontrada." << endl;
        cout << "Regresando al menu de inicio..." << endl;
        // Liberar memoria
        for (DtPelicula* p : pelis) {
            delete p;
        }
        return;
    }

    string usuario = iSesion->obtenerUsuario()->getNickname();
    
    // Verificar si ya puntuó
    if (iPelicula->usuarioYaPunto(titulo, usuario)) {
        int puntajeAnterior = iPelicula->obtenerPuntajeUsuario(titulo, usuario);
        cout << "\nYa puntuaste esta pelicula con " << puntajeAnterior << " estrellas." << endl;
        cout << "Deseas modificar tu puntaje?" << endl;
        cout << "1. Si" << endl;
        cout << "2. No" << endl;
        cout << "Opcion: ";
        int modificar;
        cin >> modificar;
        if (modificar != 1) {
            cout << "Regresando al menu de inicio..." << endl;
            // Liberar memoria
            for (DtPelicula* p : pelis) {
                delete p;
            }
            return;
        }
    }

    // Ingresar puntaje
    int puntaje;
    cout << "\nIngresa tu puntaje (1-5 estrellas): ";
    cin >> puntaje;
    
    if (puntaje < 1 || puntaje > 5) {
        cout << "Puntaje invalido. Debe ser entre 1 y 5." << endl;
        cout << "Regresando al menu de inicio..." << endl;
        // Liberar memoria
        for (DtPelicula* p : pelis) {
            delete p;
        }
        return;
    }

    // Guardar puntaje
    iPelicula->puntuarPelicula(titulo, usuario, puntaje);
    cout << "Puntaje registrado exitosamente." << endl;
    cout << "Regresando al menu de inicio..." << endl;

    // Liberar memoria
    for (DtPelicula* p : pelis) {
        delete p;
    }
}

void comentarPelicula() {
    system("clear");

    if (!iSesion->sesionIniciada()) {
        cout << "\nDebes iniciar sesion para acceder a esta opcion." << endl;
        return;
    }

    cout << "_________C O M E N T A R__P E L I C U L A_________" << endl;
    
    // Listar películas disponibles
    list<DtPelicula*> pelis = iReserva->listarPeliculas();
    if (pelis.empty()) {
        cout << "No hay peliculas disponibles." << endl;
        return;
    }

    cout << "\nPeliculas disponibles:\n";
    for (DtPelicula* p : pelis) {
        cout << "- " << *p << endl;
    }

    // Seleccionar película
    string titulo;
    cout << "\nIngrese el titulo de la pelicula: ";
    cin.ignore();
    getline(cin, titulo);

    // Verificar si la película existe
    Pelicula* pelicula = iPelicula->buscarPelicula(titulo);
    if (!pelicula) {
        cout << "Pelicula no encontrada." << endl;
        // Liberar memoria
        for (DtPelicula* p : pelis) {
            delete p;
        }
        return;
    }

    // Listar comentarios existentes
    cout << "\n=== COMENTARIOS EXISTENTES ===" << endl;
    list<string> comentarios = iPelicula->listarComentarios(titulo);
    if (comentarios.empty()) {
        cout << "No hay comentarios para esta pelicula." << endl;
    } else {
        for (string comentario : comentarios) {
            cout << comentario << endl;
        }
    }

    // Ciclo para agregar comentarios
    bool seguirComentando = true;
    while (seguirComentando) {
        cout << "\n=== AGREGAR COMENTARIO ===" << endl;
        cout << "1. Crear nuevo comentario" << endl;
        cout << "2. Responder a comentario existente" << endl;
        cout << "3. Finalizar" << endl;
        cout << "Opcion: ";
        
        int opcion;
        cin >> opcion;

        if (opcion == 1) {
            // Crear nuevo comentario
            string comentario;
            cout << "\nIngrese su comentario: ";
            cin.ignore();
            getline(cin, comentario);
            
            if (!comentario.empty()) {
                string usuario = iSesion->obtenerUsuario()->getNickname();
                iPelicula->agregarComentario(titulo, usuario, comentario);
                cout << "\nComentario registrado exitosamente." << endl;
            } else {
                cout << "El comentario no puede estar vacio." << endl;
            }
        } else if (opcion == 2) {
            // Responder a comentario existente
            if (comentarios.empty()) {
                cout << "\nNo hay comentarios para responder." << endl;
                continue;
            }
            
            cout << "\nComentarios disponibles para responder:" << endl;
            int contador = 1;
            for (string comentario : comentarios) {
                cout << contador << ". " << comentario << endl;
                contador++;
            }
            
            cout << "\nSeleccione el numero del comentario al que desea responder: ";
            int seleccion;
            cin >> seleccion;
            
            if (seleccion >= 1 && seleccion <= comentarios.size()) {
                string respuesta;
                cout << "\nIngrese su respuesta: ";
                cin.ignore();
                getline(cin, respuesta);
                
                if (!respuesta.empty()) {
                    string usuario = iSesion->obtenerUsuario()->getNickname();
                    // Por simplicidad, usamos el número como ID (en una implementación real usaríamos IDs únicos)
                    iPelicula->agregarRespuestaComentario(titulo, seleccion, usuario, respuesta);
                    cout << "\nRespuesta registrada exitosamente." << endl;
                } else {
                    cout << "La respuesta no puede estar vacia." << endl;
                }
            } else {
                cout << "Seleccion invalida." << endl;
            }
        } else if (opcion == 3) {
            seguirComentando = false;
        } else {
            cout << "Opcion invalida." << endl;
        }
        
        // Actualizar lista de comentarios
        comentarios = iPelicula->listarComentarios(titulo);
    }

    cout << "\nProceso de comentarios finalizado." << endl;
    cout << "Regresando al menu de inicio..." << endl;

    // Liberar memoria
    for (DtPelicula* p : pelis) {
        delete p;
    }
}

void verInformacionPelicula() {
    system("clear");

    // Verificar si el usuario ha iniciado sesión
    if (!iSesion->sesionIniciada()) {
        cout << "\nDebes iniciar sesion para acceder a esta opcion." << endl;
        return;
    }


    cout << "_________V E R__I N F O R M A C I O N__D E__P E L I C U L A_________" << endl;
    
    list<DtPelicula*> todasLasPelis;

    bool reingresarPelicula = true;
    while(reingresarPelicula){
    
        todasLasPelis = iReserva->listarPeliculas();
        if (todasLasPelis.empty()) {
            cout << "No hay peliculas registradas en el sistema." << endl;
            return;
        }

        cout << "\nPeliculas disponibles:\n";
        for (DtPelicula* p : todasLasPelis) {
            cout << "- " << *p << endl;
        }

        // Selección de película
        string titulo;
        cout << "\nIngrese el titulo de la pelicula (o 'cancelar' para salir): ";
        cin.ignore();
        getline(cin, titulo);
        
        if (titulo == "cancelar") {
            cout << "Regresando al menu de inicio..." << endl;
            // Liberar memoria antes de salir
            for (DtPelicula* p : todasLasPelis) {
                delete p;
            }
            return;
        }

        // Obtener información de la película usando el manejador
        Pelicula* pelicula = iPelicula->buscarPelicula(titulo);
        if (!pelicula) {
            cout << "Pelicula no encontrada." << endl;
            // Liberar memoria antes de salir
            for (DtPelicula* p : todasLasPelis) {
                delete p;
            }
            return;
        }
        
        // Mostrar póster y sinopsis
        cout << "\n=== INFORMACION DE LA PELICULA ===" << endl;
        cout << "Poster: " << pelicula->getPoster() << endl;
        cout << "Sinopsis: " << pelicula->getSinopsis() << endl;

        // Preguntar si desea ver información adicional
        int eleccionInfo;
        cout << "\nDesea ver informacion adicional de la pelicula?" << endl;
        cout << "1. Si" << endl;
        cout << "2. No" << endl;
        cout << "Opcion: ";
        cin >> eleccionInfo;

        if (eleccionInfo == 1) {
            // Seleccionar la película en el controlador para que listarCinesPeli funcione
            iReserva->selectPeli(titulo);
            
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
            cout << "\nDesea seleccionar un cine para ver sus funciones?" << endl;
            cout << "1. Si" << endl;
            cout << "2. No" << endl;
            cout << "Opcion: ";
            cin >> eleccionCine;

            if (eleccionCine == 1) {
                int idCine;
                cout << "\nIngrese id del cine: ";
                cin >> idCine;

                // Listar funciones del cine (reciclando función existente)
                list<DtFuncion*> funciones = iReserva->selectCine(idCine);
                if (funciones.empty()) {
                    cout << "No hay funciones disponibles para esta pelicula en este cine." << endl;
                } else {
                    cout << "\nFunciones disponibles:\n";
                    for (DtFuncion* f : funciones) {
                        cout << "- " << *f << endl;
                    }
                }
            } else {
                reingresarPelicula = false;
                iReserva->finalizar();
                cout << "Regresando al menu de inicio..." << endl;
                // Liberar memoria
                for (DtPelicula* p : todasLasPelis) {
                    delete p;
                }
                return;
            }

            int opcionPelicula;
            cout << "\nDesea ver informacion de otra pelicula? " << endl;
            cout << "1. Si" << endl;
            cout << "2. No" << endl;
            cout << "Opcion: ";
            cin >> opcionPelicula;
                    
            if (opcionPelicula == 2) {
                reingresarPelicula = false;
            }
        } else {
            reingresarPelicula = false;
        }
    }
    
    iReserva->finalizar();
    cout << "Regresando al menu de inicio..." << endl;

    // Liberar memoria
    for (DtPelicula* p : todasLasPelis) {
        delete p;
    }

}

void verComentariosPuntajesPelicula() {
    system("clear");

    // Verificar si el usuario ha iniciado sesión
    if (!iSesion->sesionIniciada()) {
        cout << "\nDebes iniciar sesion para acceder a esta opcion." << endl;
        return;
    }

    cout << "_________V E R__C O M E N T A R I O S__Y__P U N T A J E S__D E__P E L I C U L A_________" << endl;
        

    // Listar películas disponibles
    list<DtPelicula*> pelis = iReserva->listarPeliculas();
    if (pelis.empty()) {
        cout << "No hay peliculas disponibles." << endl;
        return;
    }

    cout << "\nPeliculas disponibles:\n";
    for (DtPelicula* p : pelis) {
        cout << "- " << *p << endl;
    }

    // Seleccionar película
    string titulo;
    cout << "\nIngrese el titulo de la pelicula: ";
    cin.ignore();
    getline(cin, titulo);

    // Verificar si la película existe
   Pelicula* pelicula = iPelicula->buscarPelicula(titulo);
    if (!pelicula) {
        cout << "Pelicula no encontrada." << endl;
        // Liberar memoria
        for (DtPelicula* p : pelis) {
            delete p;
        }
        return;
    }

    
    cout << "\n" << pelicula->getTitulo() << endl;
    cout << "Puntaje promedio: " << pelicula->getPuntajePromedio() << " (" << pelicula->getCantidadPuntajes() << " usuarios)" << endl;
    
    // Mostrar comentarios
    cout << "\nComentarios" << endl;
    list<string> comentarios = iPelicula->listarComentarios(titulo);
    if (comentarios.empty()) {
        cout << "No hay comentarios para esta pelicula." << endl;
    } else {
        for (string comentario : comentarios) {
            cout << comentario << endl;
        }
    }
    
    // Mostrar puntajes individuales
    cout << "\nPuntajes" << endl;
    list<string> puntajes = iPelicula->listarPuntajesIndividuales(titulo);
    if (puntajes.empty()) {
        cout << "No hay puntajes para esta pelicula." << endl;
    } else {
        for (string puntaje : puntajes) {
            cout << puntaje << endl;
        }
    }

    // Liberar memoria
    for (DtPelicula* p : pelis) {
        delete p;
    }
}

// Main principal
int main() {
	// --- Alta de administrador ---
	iUsuario->altaUsuario("admin", "admin", "https://pelicenter.com/admin/Easteregg.jpg");
	
	int opcion;
	menu();
	cin >> opcion;	
	

	while(opcion != 17){
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
			case 13: puntuarPelicula(); break;
			case 14: comentarPelicula(); break;
			case 15: verInformacionPelicula(); break;
			case 16: verComentariosPuntajesPelicula(); break;
			default: cout << "OPCION INCORRECTA" << endl;
		}
		sleep(3);
		menu();
		cin >> opcion;
	}
	cout << "SALIENDO..." << endl;
	return 0;
}
