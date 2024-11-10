#pragma once

#include <iostream>
#include <cstring>

#include "Fecha.h"
#include "Tiempo.h"

using namespace std;

class Pelicula{
private:
    int _id, _clasificacionEdad;
    char _titulo[100], _sinopsis[500], _genero[20];
    float _calificacion;
    Fecha _fechaEstreno;
    Tiempo _duracion;
public:
    Pelicula();
    Pelicula(int id, int clasificacionEdad, const char* titulo, const char* sinopsis, const char* genero, float calificacion, Fecha fechaEstreno, Tiempo duracion);

    void Cargar();
    void Mostrar();

    int getId();
    const char* getTitulo();
    const char* getSinopsis();
    const char* getGenero();
    int getClasificacionedad();
    float getCalificacion();
    Fecha& getFechaEstreno();
    Tiempo& getDuracion();

    void setId(int id);
    void setTitulo(const char* titulo);
    void setSinopsis(const char* sinopsis);
    void setGenero(const char* genero);
    void setClasificacionEdad(int clasificacionEdad);
    void setCalificacion(float calificacion);
    void setFechaEstreno(Fecha fechaEstreno);
    void setDuracion(Tiempo duracion);
};
