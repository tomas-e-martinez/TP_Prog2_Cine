#pragma once

#include "Cliente.h"
#include "Funcion.h"
#include "Pelicula.h"
#include "Sala.h"
#include "ArchivoClientes.h"
#include "ArchivoFunciones.h"
#include "ArchivoPeliculas.h"
#include "ArchivoSalas.h"


#include <cstdlib>

class CargarAleatorio{
public:
    Cliente GenerarCliente();
    Funcion GenerarFuncion();

    void CargarClientes(int cantidad);
    void CargarFunciones(int cantidad);

    int DNI();
};
