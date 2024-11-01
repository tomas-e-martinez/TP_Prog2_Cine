#include "ArchivoFunciones.h"

ArchivoFunciones::ArchivoFunciones(const char* nombre){
    strcpy(_nombre, nombre);
}

int ArchivoFunciones::ContarRegistros(){
    FILE* p = fopen(_nombre, "rb");
    if(p == NULL){
        return -1;
    }
    fseek(p, 0, 2);
    int cantidad = ftell(p)/sizeof(Funcion);
    fclose(p);
    return cantidad;
}

int ArchivoFunciones::BuscarID(int id){
    FILE* p = fopen(_nombre, "rb");
    if(p == NULL){
        return -1;
    }
    Funcion funcion;
    int i = 0;
    while(fread(&funcion, sizeof(Funcion), 1, p)){
        if(funcion.getIdFuncion() == id){
            fclose(p);
            return i;
        }
        i++;
    }
    fclose(p);
    return -1;
}

Funcion ArchivoFunciones::LeerRegistro(int pos){
    FILE* p = fopen(_nombre, "rb");
    Funcion funcion;
    if(p == NULL){
        return funcion;
    }
    fseek(p, sizeof(Funcion) * pos, 0);
    fread(&funcion, sizeof(Funcion), 1, p);
    fclose(p);
    return funcion;
}

bool ArchivoFunciones::Guardar(Funcion funcion){
    int idActual = 0;

    while(BuscarID(idActual) != -1)
        idActual++;

    funcion.setIdFuncion(idActual);

    FILE* p = fopen(_nombre, "ab");
    if(p == NULL){
        return false;
    }

    bool escribio = fwrite(&funcion, sizeof(Funcion), 1, p);
    fclose(p);
    return escribio;
}

bool ArchivoFunciones::Guardar(Funcion funcion, int pos){
    FILE* p = fopen(_nombre, "rb+");
    if(p == NULL){
        return false;
    }
    fseek(p, sizeof(Funcion) * pos, 0);
    bool escribio = fwrite(&funcion, sizeof(Funcion), 1, p);
    fclose(p);
    return escribio;
}



