#pragma once

#include "Venta.h"

class ArchivoVentas{
private:
    char _nombre[30];
public:
    ArchivoVentas(const char* nombre = "ventas.dat");

    int ContarRegistros();
    int BuscarID(int id);
    Venta LeerRegistro(int pos);
    bool Guardar(Venta venta); //Agregar registro al archivo
    bool Guardar(Venta venta, int pos); //Sobreescribir registro del archivo
};
