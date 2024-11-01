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

int ArchivoClientes::BuscarDni(int id){
    FILE* p = fopen(_nombre, "rb");
    if(p == NULL){
        return -1;
    }
    Cliente cliente;
    int i = 0;
    while(fread(&cliente, sizeof(Cliente), 1, p)){
        if(cliente.getDni() == id){
            fclose(p);
            return i;
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
    int DniActual = 0;

    while(BuscarDni(DniActual) != -1)
        DniActual++;

    cliente.setDni(DniActual);

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





