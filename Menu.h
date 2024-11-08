#pragma once

#include <iostream>

#include "Reporte.h"

using namespace std;

class Menu{
    int _opcion;
public:
    void Principal();
    void Clientes();
    void Funciones();
    void Peliculas();
    void Salas();
    void Ventas();
    void Reportes();
};
