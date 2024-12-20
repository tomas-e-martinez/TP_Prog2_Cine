#pragma once

#include <iostream>
#include <cstring>

#include "Fecha.h"
#include "Tiempo.h"

class Venta {
private:
    int _idVenta, _idCliente, _idFuncion, _cantidadEntradas;
    Fecha _fecha;
    bool _activo;
    float _importeTotal;

public:
    Venta();  // Constructor por defecto
    Venta(int idCliente, int idFuncion, int cantidadEntradas, Fecha fecha, float importeTotal);  // Constructor con par metros

    void Cargar();
    void Mostrar();
    bool Modificar();

    int getIdVenta();
    int getIdCliente();
    int getIdFuncion();
    Fecha& getFecha();
    int getCantidadEntradas();
    bool getActivo();
    float getImporteTotal();

    void setIdVenta(int idVenta);
    void setIdCliente(int idCliente);
    void setIdFuncion(int idFuncion);
    void setFecha(Fecha fecha);
    void setCantidadEntradas(int cantidadEntradas);
    void setActivo(bool activo);
    void setImporteTotal(float importe);
};
