#pragma once

#include "GestorCine.h"
#include "Cliente.h"
#include "Funcion.h"
#include "Pelicula.h"
#include "Sala.h"
#include "Venta.h"
#include "ArchivoClientes.h"
#include "ArchivoFunciones.h"
#include "ArchivoPeliculas.h"
#include "ArchivoSalas.h"
#include "ArchivoVentas.h"


#include <cstdlib>

class CargarAleatorio{
public:
    Cliente GenerarCliente();
    Funcion GenerarFuncion();
    Sala GenerarSala();
    Venta GenerarVenta();

    void CargarClientes(int cantidad);
    void CargarFunciones(int cantidad);
    void CargarSalas(int cantidad);
    void CargarVentas(int cantidad);

    int DNI();
};
