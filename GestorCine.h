#pragma once

#include "Pelicula.h"
#include "Cliente.h"
#include "Sala.h"
#include "Funcion.h"
#include "Venta.h"

#include "ArchivoPeliculas.h"
#include "ArchivoClientes.h"
#include "ArchivoSalas.h"
#include "ArchivoFunciones.h"
#include "ArchivoVentas.h"

class GestorCine{
public:
    void AgregarCliente();
    void AgregarFuncion();
    void AgregarPelicula();
    void AgregarSala();
    void AgregarVenta();
    void ModificarCliente();
};
