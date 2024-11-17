#pragma once

#include "Sala.h"

class ArchivoSalas{
private:
    char _nombre[30];
public:
    ArchivoSalas(const char* nombre = "salas.dat");

    int ContarRegistros();
    int BuscarID(int idSala, bool todos = true);
    Sala LeerRegistro(int pos);
    bool Guardar(Sala sala); //Agregar registro al archivo
    bool Guardar(Sala sala, int pos); //Sobreescribir registro del archivo
};
