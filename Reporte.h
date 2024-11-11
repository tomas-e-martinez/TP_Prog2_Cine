#pragma once

#include "ArchivoClientes.h"
#include "ArchivoPeliculas.h"
#include "ArchivoSalas.h"
#include "ArchivoFunciones.h"
#include "ArchivoVentas.h"

class Reporte{
public:
    void ListarPeliculas(const char* nombreArchivo = "peliculas.dat");
    void ListarPeliculasOrdenGenero(const char* nombreArchivo = "peliculas.dat"); ///TODO
    void ListarPeliculasOrdenCalificacion(const char* nombreArchivo = "peliculas.dat"); ///TODO
    void ListarPeliculasGenero(int opcionGenero, const char* nombreArchivo = "peliculas.dat"); ///TODO
    void ListarPeliculasCalificacion(float calificacion, const char* nombreArchivo = "peliculas.dat"); ///TODO
    void ListarPeliculasTitulo(const char* titulo, const char* nombreArchivo = "peliculas.dat"); ///TODO
    void ListarPeliculasEdad(int edad, const char* nombreArchivo = "peliculas.dat"); ///TODO

    void ListarClientes(const char* nombreArchivo = "clientes.dat");
    void ListarClientesEdad(int minimo, int maximo, const char* nombreArchivo = "clientes.dat");
    void ListarClientesApellido(const char* nombreArchivo = "clientes.dat");
    void ListarClientesDNI(int dni, const char* nombreArchivo = "clientes.dat");

    void ListarFunciones(const char* nombreArchivo = "funciones.dat");
    void ListarFuncionesFecha(Fecha& minimo, Fecha& maximo, const char* nombreArchivo = "funciones.dat");
    void ListarFuncionesSala(int tipo, const char* nombreArchivo = "funciones.dat");


    void ListarVentas(const char* nombreArchivo = "ventas.dat");

    void ListarSalas(const char* nombreArchivo = "salas.dat");
    void ListarSalasTipo(const char* nombreArchivo = "salas.dat");
};
