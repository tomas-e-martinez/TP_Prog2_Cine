#pragma once

#include <iostream>
#include <cstring>

#include "Fecha.h"
#include "Tiempo.h"

class Venta {
private:
    int _idVenta, _dniCliente, _idFuncion, _cantidadEntradas;
    Fecha _fecha;

public:
    Venta();  // Constructor por defecto
    Venta(int idVenta, int dniCliente, int idFuncion, int cantidadEntradas, Fecha fecha);  // Constructor con par metros

    void Cargar();
    void Mostrar();

    int getIdVenta();
    int getDniCliente();
    int getIdFuncion();
    Fecha getFecha();
    int getCantidadEntradas();

    void setIdVenta(int idVenta);
    void setDniCliente(int dniCliente);
    void setIdFuncion(int idFuncion);
    void setFecha(Fecha fecha);
    void setCantidadEntradas(int cantidadEntradas);

};
