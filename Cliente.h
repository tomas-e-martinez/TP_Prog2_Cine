#pragma once

#include <iostream>
#include <cstring>

#include "Fecha.h"
#include "Tiempo.h"

using namespace std;

class Cliente{
private:
    int _id, _dni;
    char _nombre[30], _apellido[30], _telefono[20];
    Fecha _fechaNacimiento;

public:
    Cliente();
    Cliente(int dni, const char* nombre, const char* apellido, const char* telefono, Fecha fechaNacimiento);

    void Cargar(int dni = 0);
    void Mostrar();
    bool Modificar();

    int getId();
    int getDni();
    const char* getNombre();
    const char* getApellido();
    const char* getTelefono();
    Fecha& getFechaNacimiento();

    void setId(int id);
    void setDni(int dni);
    void setNombre(const char* nombre);
    void setApellido(const char* apellido);
    void setTelefono(const char* tlefono);
    void setFechaNacimiento(Fecha fechaNacimiento);
};
