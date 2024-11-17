#pragma once

#include "Funcion.h"

class ArchivoFunciones{
private:
    char _nombre[30];
public:
    ArchivoFunciones(const char* nombre = "funciones.dat");

    int ContarRegistros();
    int BuscarID(int id, bool todos = true);
    Funcion LeerRegistro(int pos);
    bool Guardar(Funcion funcion); //Agregar registro al archivo
    bool Guardar(Funcion funcion, int pos); //Sobreescribir registro del archivo
};

