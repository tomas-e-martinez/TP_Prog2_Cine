#pragma once

#include <iostream>
#include <cstring>

#include "Fecha.h"
#include "Tiempo.h"

using namespace std;

class Sala{
private:
    int _idSala, _capacidad;
    char _tipo[5];

public:
    Sala();
    Sala(int idSala, int capacidad, const char* tipo);

    void Cargar();
    void Mostrar();

    int getIdSala();
    int getCapacidad();
    const char* getTipo();

    void setIdSala(int idSala);
    void setCapacidad(int capacidad);
    void setTipo(const char* tipo);
};

