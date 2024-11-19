#pragma once

#include <iostream>

#include "Reporte.h"
#include "GestorCine.h"
#include "rlutil.h"

#include "ArchivoClientes.h"

using namespace std;

class Menu{
    int _opcion;
public:
    void Principal(GestorCine& gestor, Reporte& reporte);
    void Clientes(GestorCine& gestor, Reporte& reporte);
    void Funciones(GestorCine& gestor, Reporte& reporte);
    void Peliculas(GestorCine& gestor, Reporte& reporte);
    void Salas(GestorCine& gestor, Reporte& reporte);
    void Ventas(GestorCine& gestor, Reporte& reporte);
    void Reportes(Reporte& reporte);
};
