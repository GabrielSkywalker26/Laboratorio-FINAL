main: Fabrica.o Controlador.o ManejadorSocio.o DtFecha.o DtConsulta.o DtMascota.o DtPerro.o DtGato.o Mascota.o Perro.o Gato.o Consulta.o Socio.o main.o
	g++ Fabrica.o Controlador.o ManejadorSocio.o DtFecha.o DtConsulta.o DtMascota.o DtPerro.o DtGato.o Mascota.o Perro.o Gato.o Consulta.o Socio.o main.o -o veterinaria

ManejadorSocio.o: ManejadorSocio.cpp

Controlador.o: Controlador.cpp

Fabrica.o: Fabrica.cpp

DtFecha.o: DtFecha.cpp

DtConsulta.o: DtConsulta.cpp

DtMascota.o: DtMascota.cpp

DtPerro.o: DtPerro.cpp

DtGato.o: DtGato.cpp

Mascota.o: Mascota.cpp

Perro.o: Perro.cpp

Gato.o: Gato.cpp

Consulta.o: Consulta.cpp

Socio.o: Socio.cpp

main.o: main.cpp

clean:
	rm -rf *.o veterinaria
