#pragma once

#include "Cliente.h"

class ArchivoClientes{
private:
    char _nombre[30];
public:
    ArchivoClientes(const char* nombre = "clientes.dat");

    int ContarRegistros();
    int BuscarID(int id);
    int BuscarDni(int dni);
    Cliente LeerRegistro(int pos);
    bool Guardar(Cliente cliente); //Agregar registro al archivo
    bool Guardar(Cliente cliente, int pos); //Sobreescribir registro del archivo
};
