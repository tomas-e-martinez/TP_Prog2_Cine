#pragma once

#include "Cliente.h"

class ArchivoClientes{
private:
    char _nombre[30];
public:
    ArchivoClientes(const char* nombre = "clientes.dat");

    int ContarRegistros();
    int BuscarID(int id, bool todos = true);
    int BuscarDni(int dni, bool todos = true);
    Cliente LeerRegistro(int pos);
    bool Guardar(Cliente cliente); //Agregar registro al archivo
    bool Guardar(Cliente cliente, int pos); //Sobreescribir registro del archivo
};
