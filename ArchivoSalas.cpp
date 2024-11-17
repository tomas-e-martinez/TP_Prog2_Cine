#include "ArchivoSalas.h"

ArchivoSalas::ArchivoSalas(const char* nombre){
    strcpy(_nombre, nombre);
}

int ArchivoSalas::ContarRegistros(){
    FILE* p = fopen(_nombre, "rb");
    if(p == NULL){
        return -1;
    }
    fseek(p, 0, 2);
    int cantidad = ftell(p)/sizeof(Sala);
    fclose(p);
    return cantidad;
}

int ArchivoSalas::BuscarID(int idSala, bool todos){
    FILE* p = fopen(_nombre, "rb");
    if(p == NULL){
        cerr << "No se pudo abrir el archivo para lectura." << endl;
        return -1;
    }
    Sala sala;
    int i = 0;
    while(fread(&sala, sizeof(Sala), 1, p)){
        if(sala.getIdSala() == idSala){
            fclose(p);
            if(todos || sala.getActivo())
                return i;
            else
                return -1;
        }
        i++;
    }
    fclose(p);
    return -1;
}

Sala ArchivoSalas::LeerRegistro(int pos){
    FILE* p = fopen(_nombre, "rb");
    Sala sala;
    if(p == NULL){
        return sala;
    }
    fseek(p, sizeof(Sala) * pos, 0);
    fread(&sala, sizeof(Sala), 1, p);
    fclose(p);
    return sala;
}

bool ArchivoSalas::Guardar(Sala sala){
    int idActual = 0;

    while(BuscarID(idActual) != -1)
        idActual++;

    sala.setIdSala(idActual);

    FILE* p = fopen(_nombre, "ab");
    if(p == NULL){
        return false;
    }

    bool escribio = fwrite(&sala, sizeof(Sala), 1, p);
    fclose(p);
    return escribio;
}

bool ArchivoSalas::Guardar(Sala sala, int pos){
    FILE* p = fopen(_nombre, "rb+");
    if(p == NULL){
        return false;
    }
    fseek(p, sizeof(Sala) * pos, 0);
    bool escribio = fwrite(&sala, sizeof(Sala), 1, p);
    fclose(p);
    return escribio;
}
