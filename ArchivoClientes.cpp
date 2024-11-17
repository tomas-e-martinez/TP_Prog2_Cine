#include "ArchivoClientes.h"

ArchivoClientes::ArchivoClientes(const char* nombre){
    strcpy(_nombre, nombre);
}

int ArchivoClientes::ContarRegistros(){
    FILE* p = fopen(_nombre, "rb");
    if(p == NULL){
        return -1;
    }
    fseek(p, 0, 2);
    int cantidad = ftell(p)/sizeof(Cliente);
    fclose(p);
    return cantidad;
}

int ArchivoClientes::BuscarID(int id, bool todos){
    FILE* p = fopen(_nombre, "rb");
    if(p == NULL){
        return -1;
    }
    Cliente cliente;
    int i = 0;
    while(fread(&cliente, sizeof(Cliente), 1, p)){
        if(cliente.getId() == id){
            fclose(p);
            if(todos || cliente.getActivo())
                return i;
            else
                return -1;
        }
        i++;
    }
    fclose(p);
    return -1;
}

int ArchivoClientes::BuscarDni(int dni, bool todos){
    FILE* p = fopen(_nombre, "rb");
    if(p == NULL){
        return -1;
    }
    Cliente cliente;
    int i = 0;
    while(fread(&cliente, sizeof(Cliente), 1, p)){
        if(cliente.getDni() == dni){
            fclose(p);
            if(todos || cliente.getActivo())
                return i;
            else
                return -1;
        }
        i++;
    }
    fclose(p);
    return -1;
}

Cliente ArchivoClientes::LeerRegistro(int pos){
    FILE* p = fopen(_nombre, "rb");
    Cliente cliente;
    if(p == NULL){
        return cliente;
    }
    fseek(p, sizeof(Cliente) * pos, 0);
    fread(&cliente, sizeof(Cliente), 1, p);
    fclose(p);
    return cliente;
}

bool ArchivoClientes::Guardar(Cliente cliente){
    if(BuscarDni(cliente.getDni()) != -1){
        cout << "ERROR: YA EXISTE UN CLIENTE CON ESE DNI." << endl;
        system("pause");
        return false;
    }

    int idActual = 0;

    while(BuscarID(idActual) != -1)
        idActual++;

    cliente.setId(idActual);

    FILE* p = fopen(_nombre, "ab");
    if(p == NULL){
        return false;
    }

    bool escribio = fwrite(&cliente, sizeof(Cliente), 1, p);
    fclose(p);
    return escribio;
}

bool ArchivoClientes::Guardar(Cliente cliente, int pos){
    FILE* p = fopen(_nombre, "rb+");
    if(p == NULL){
        return false;
    }
    fseek(p, sizeof(Cliente) * pos, 0);
    bool escribio = fwrite(&cliente, sizeof(Cliente), 1, p);
    fclose(p);
    return escribio;
}
