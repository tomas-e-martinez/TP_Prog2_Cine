#pragma once

#include "ArchivoClientes.h"
#include "ArchivoPeliculas.h"
#include "ArchivoSalas.h"
#include "ArchivoFunciones.h"
#include "ArchivoVentas.h"

#include "GestorCine.h"

class Reporte{
public:
    void ListarPeliculas(const char* nombreArchivo = "peliculas.dat");
    void ListarPeliculasOrdenGenero(const char* nombreArchivo = "peliculas.dat");
    void ListarPeliculasOrdenCalificacion(const char* nombreArchivo = "peliculas.dat");
    void ListarPeliculasGenero(int opcionGenero, const char* nombreArchivo = "peliculas.dat");
    void ListarPeliculasCalificacion(float minCalificacion, float maxCalificacion, const char* nombreArchivo = "peliculas.dat");
    void ListarPeliculasTitulo(const char* titulo, const char* nombreArchivo = "peliculas.dat");
    void ListarPeliculasEdad(int edadMax, const char* nombreArchivo = "peliculas.dat");

    void ListarClientes(const char* nombreArchivo = "clientes.dat");
    void ListarClientesEdad(int minimo, int maximo, const char* nombreArchivo = "clientes.dat");
    void ListarClientesApellido(const char* nombreArchivo = "clientes.dat");
    void ListarClientesDNI(int dni, const char* nombreArchivo = "clientes.dat");

    void ListarFunciones(const char* nombreArchivo = "funciones.dat");
    void ListarFuncionesFecha(const Fecha& minimo,const Fecha& maximo, const char* nombreArchivo = "funciones.dat");
    void ListarFuncionesSala(int tipo, const char* nombreArchivo = "funciones.dat");
    void VentaDetalle(Funcion& funcion, int cantEntradas, Fecha& fecha, Cliente& cliente, float valorEntrada, const char* nombreArchivo = "funciones.dat");


    void ListarVentas(const char* nombreArchivo = "ventas.dat");
    void ListarVentasOrdenFecha(const char* nombreArchivo = "ventas.dat");

    void ListarSalas(const char* nombreArchivo = "salas.dat");
    void ListarSalasTipo(const char* nombreArchivo = "salas.dat");

    void RecaudacionAnual(Reporte& reporte);
    void RecaudacionTipoSala(Reporte& reporte);
    void RecaudacionTitulo(Reporte& reporte);
    void EntradasVendidasPorPelicula(Reporte& reporte);
};
