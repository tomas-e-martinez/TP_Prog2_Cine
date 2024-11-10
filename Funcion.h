#pragma once

#include <iostream>
#include <cstring>

#include "Fecha.h"
#include "Tiempo.h"

using namespace std;

class Funcion{
private:
    int _idFuncion, _idPelicula, _idSala;
    Fecha _fecha;

public:
    Funcion();
    Funcion(int idPelicula, int idSala, Fecha fecha);

    void Cargar();
    void Mostrar();

    int getIdFuncion();
    int getIdPelicula();
    int getIdSala();
    Fecha& getFecha();

    void setIdFuncion(int idFuncion);
    void setIdPelicula(int idPelicula);
    void setIdSala(int idSala);
    void setFecha(Fecha fecha);
};
