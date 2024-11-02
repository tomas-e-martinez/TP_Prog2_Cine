#pragma once

#include "ArchivoFunciones.h"
#include "ArchivoClientes.h"
#include "ArchivoPeliculas.h"

class Reporte{
public:
    void ListarPeliculas(const char* nombreArchivo = "peliculas.dat");
    void ListarClientes(const char* nombreArchivo = "clientes.dat");
    void ListarFunciones(const char* nombreArchivo = "funciones.dat");
};
