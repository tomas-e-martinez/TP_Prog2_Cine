#pragma once

#include "Pelicula.h"

class ArchivoPeliculas{
private:
    char _nombre[30];
public:
    ArchivoPeliculas(const char* nombre = "peliculas.dat");

    int ContarRegistros();
    int BuscarID(int id);
    int BuscarTitulo(const char* titulo);
    Pelicula LeerRegistro(int pos);
    bool Guardar(Pelicula pelicula); //Agregar registro al archivo
    bool Guardar(Pelicula pelicula, int pos); //Sobreescribir registro del archivo
};
