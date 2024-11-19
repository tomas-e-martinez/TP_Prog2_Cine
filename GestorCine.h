#pragma once

#include "Pelicula.h"
#include "Cliente.h"
#include "Sala.h"
#include "Funcion.h"
#include "Venta.h"
#include "Reporte.h"
#include "rlutil.h"

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
    void AgregarVenta(); ///DE PRUEBA
    void ProcesarVenta();

    void ModificarCliente();
    void ModificarFuncion();
    void ModificarPelicula();
    void ModificarSala();
    void ModificarVenta();

    void BajaCliente();
    void BajaFuncion();
    void BajaPelicula();
    void BajaSala();
    void BajaVenta();

    float CalcularPrecioEntrada(Funcion funcion);
    int AsientosLibres(Funcion funcion);
};
