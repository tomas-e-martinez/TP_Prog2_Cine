#pragma once

#include "ArchivoClientes.h"
#include "ArchivoPeliculas.h"
#include "ArchivoSalas.h"
#include "ArchivoFunciones.h"
#include "ArchivoVentas.h"

class Reporte{
public:
    void ListarPeliculas(const char* nombreArchivo = "peliculas.dat");

    void ListarClientes(const char* nombreArchivo = "clientes.dat");
    void ListarClientesEdad(int minimo, int maximo, const char* nombreArchivo = "clientes.dat");

    void ListarFunciones(const char* nombreArchivo = "funciones.dat");
    void ListarVentas(const char* nombreArchivo = "ventas.dat");
    void ListarSalas(const char* nombreArchivo = "salas.dat");
};
