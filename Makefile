main: Fabrica.o ControladorAltaCine.o ControladorAltaFuncion.o ControladorPelicula.o ControladorReserva.o ControladorSesion.o ControladorUsuario.o 
	ManejadorCine.o ManejadorFinanciera.o ManejadorFuncion.o ManejadorPelicula.o ManejadorUsuario.o 
	DtFecha.o DtDireccion.o DtHorario.o 
	Cine.o Credito.o Debito.o Financiera.o Funcion.o Pelicula.o Reserva.o Sala.o Sesion.o Usuario.o main.o

	g++ Fabrica.o ControladorAltaCine.o ControladorAltaFuncion.o ControladorPelicula.o ControladorReserva.o ControladorSesion.o ControladorUsuario.o 
	ManejadorCine.o ManejadorFinanciera.o ManejadorFuncion.o ManejadorPelicula.o ManejadorUsuario.o 
	DtFecha.o DtDireccion.o DtHorario.o 
	Cine.o Credito.o Debito.o Financiera.o Funcion.o Pelicula.o Reserva.o Sala.o Sesion.o Usuario.o main.o -o pelicenter


Controlador.o: ControladorAltaCine.cpp
Controlador.o: ControladorAltaFuncion.cpp
Controlador.o: ControladorPelicula.cpp
Controlador.o: ControladorReserva.cpp
Controlador.o: ControladorSesion.cpp
Controlador.o: ControladorUsuario.cpp


ManejadorSocio.o: ManejadorCine.cpp
ManejadorSocio.o: ManejadorFinanciera.cpp
ManejadorSocio.o: ManejadorFuncion.cpp
ManejadorSocio.o: ManejadorPelicula.cpp
ManejadorSocio.o: ManejadorUsuario.cpp


DtCine.o: DtCine.cpp

DtConsulta.o: DtDireccion.cpp

DtFecha.o: DtFecha.cpp

DtFecha.o: DtFinanciera.cpp

DtFecha.o: DtFuncion.cpp

DtMascota.o: DtHorario.cpp

DtMascota.o: DtPelicula.cpp

DtMascota.o: DtSala.cpp

DtMascota.o: DtUsuario.cpp


Fabrica.o: Fabrica.cpp


Cine.o: Cine.cpp

Credito.o: Credito.cpp

Debito.o: Debito.cpp

Financiera.o: Financiera.cpp

Funcion.o: Funcion.cpp

Pelicula.o: Pelicula.cpp

Reserva.o: Reserva.cpp

Sala.o: Sala.cpp

Sesion.o: Sesion.cpp

Usuario.o: Usuario.cpp


main.o: main.cpp

clean:
	rm -rf *.o pelicenter
