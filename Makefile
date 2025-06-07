main: Fabrica.o ControladorAltaCine.o ControladorAltaFuncion.o ControladorPelicula.o ControladorReserva.o ControladorSesion.o ControladorUsuario.o ManejadorCine.o ManejadorFinanciera.o ManejadorFuncion.o ManejadorPelicula.o ManejadorUsuario.o DtFecha.o DtDireccion.o DtHorario.o Cine.o Credito.o Debito.o Financiera.o Funcion.o Pelicula.o Reserva.o Sala.o Sesion.o Usuario.o main.o

	g++ Fabrica.o ControladorAltaCine.o ControladorAltaFuncion.o ControladorPelicula.o ControladorReserva.o ControladorSesion.o ControladorUsuario.o ManejadorCine.o ManejadorFinanciera.o ManejadorFuncion.o ManejadorPelicula.o ManejadorUsuario.o DtFecha.o DtDireccion.o DtHorario.o Cine.o Credito.o Debito.o Financiera.o Funcion.o Pelicula.o Reserva.o Sala.o Sesion.o Usuario.o main.o -o pelicenter


ControladorAltaCine.o: ControladorAltaCine.cpp
ControladorAltaFuncion.o: ControladorAltaFuncion.cpp
ControladorPelicula.o: ControladorPelicula.cpp
ControladorReserva.o: ControladorReserva.cpp
ControladorSesion.o: ControladorSesion.cpp
ControladorUsuario.o: ControladorUsuario.cpp


ManejadorCine.o: ManejadorCine.cpp
ManejadorFinanciera.o: ManejadorFinanciera.cpp
ManejadorFuncion.o: ManejadorFuncion.cpp
ManejadorPelicula.o: ManejadorPelicula.cpp
ManejadorUsuario.o: ManejadorUsuario.cpp


DtCine.o: DtCine.cpp
DtDireccion.o: DtDireccion.cpp
DtFecha.o: DtFecha.cpp
DtFinanciera.o: DtFinanciera.cpp
DtFuncion.o: DtFuncion.cpp
DtHorario.o: DtHorario.cpp
DtPelicula.o: DtPelicula.cpp
DtSala.o: DtSala.cpp
DtUsuario.o: DtUsuario.cpp


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
