#pragma once

#include "Cliente.h"
#include "ArchivoClientes.h"

#include <cstdlib>

class CargarAleatorio{
public:
    Cliente GenerarCliente();
    void CargarClientes(int cantidad);

    int DNI();
};
